{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs?ref=llvm-19";

  outputs =
    { self, nixpkgs }:
    let
      inherit (nixpkgs) lib;
      supportedSystems = lib.platforms.unix;
    in
    {
      packages = lib.genAttrs supportedSystems (system: {
        ld64 = nixpkgs.legacyPackages.${system}.callPackage ./package.nix { };
      });
    };
}
