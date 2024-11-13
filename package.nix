{
  lib,
  llvmPackages,
  meson,
  ninja,
  openssl,
  pkg-config,
  stdenv,
  xar,
}:

llvmPackages.libcxxStdenv.mkDerivation (finalAttrs: {
  pname = "ld64";
  version = "951.9.99";

  outputs = [
    "out"
    "dev"
    "lib"
  ];

  src = builtins.path {
    name = "ld64";
    path = ./.;
  };

  postPatch = ''
    # Match the version format used by upstream.
    sed -i src/ld/Options.cpp \
      -e '1iconst char ld_classicVersionString[] = "@(#)PROGRAM:ld PROJECT:ld64-${finalAttrs.version}\\n";'
  '';

  nativeBuildInputs = [
    meson
    ninja
    openssl
    pkg-config
  ];

  buildInputs = [
    llvmPackages.llvm
    openssl
    xar
  ];

  # Note for overrides: ld64 cannot be built as a debug build because of UB in its iteration implementations,
  # which trigger libc++ debug assertions due to trying to take the address of the first element of an emtpy vector.
  mesonBuildType = "release";

  mesonFlags = [
    (lib.mesonOption "b_ndebug" "if-release")
    (lib.mesonOption "default_library" (if stdenv.hostPlatform.isStatic then "static" else "shared"))
    (lib.mesonOption "libllvm_path" "${lib.getLib llvmPackages.llvm}")
  ];

  doInstallCheck = stdenv.buildPlatform.canExecute stdenv.hostPlatform;

  # ld64 has a test suite, but many of the tests fail (even with ld from Xcode). Instead
  # of running the test suite, rebuild ld64 using itself to link itself as a check.
  # LTO is enabled only to confirm that it is set up and working properly in nixpkgs.
  installCheckPhase = ''
    runHook preInstallCheck

    cd "$NIX_BUILD_TOP/$sourceRoot"

    export NIX_CFLAGS_COMPILE+=" --ld-path=$out/bin/ld"
    export NIX_CFLAGS_LINK+=" -L$SDKROOT/usr/lib"
    meson setup build-install-check --buildtype=$mesonBuildType ${
      lib.escapeShellArgs [
        (lib.mesonBool "b_lto" true)
        (lib.mesonOption "libllvm_path" "${lib.getLib llvmPackages.llvm}")
      ]
    }

    cd build-install-check
    ninja src/ld/ld "-j$NIX_BUILD_CORES"

    # Confirm that ld found the LTO library and reports it.
    if ./src/ld/ld -v 2>&1 | grep -q 'LTO support'; then
        echo "LTO: supported"
    else
        echo "LTO: not supported" && exit 1
    fi

    runHook postInstallCheck
  '';

  postInstall = ''
    ln -s ld-classic.1 "$out/share/man/man1/ld.1"
    ln -s ld.1 "$out/share/man/man1/ld64.1"
    moveToOutput lib/libprunetrie.a "$dev"
  '';

  __structuredAttrs = true;

  meta = {
    description = "The classic linker for Darwin";
    homepage = "https://opensource.apple.com/releases/";
    license = lib.licenses.apple-psl20;
    mainProgram = "ld";
    maintainers = lib.teams.darwin.members;
    platforms = lib.platforms.unix;
  };
})
