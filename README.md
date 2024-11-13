This repo contains the fork of ld64 used by nixpkgs (to maintain the patches it uses). Currently,
only Darwin is supported, but other platforms will be supported in the future (provided that they
are supported by nixpkgs). Support for other ecosystems or platforms is a non-goal of this fork.

## Requirements

This repo contains a flake with the required dependencies. The required versions are those on the
target branch in nixpkgs. Currently, that is:

### Build

- Meson 1.6; and
- Ninja 1.12

### Runtime

- Clang 19.1 with libc++ 19.1 (GCC and libstdc++ are not supported);
- LLVM 19.1;
- OpenSSL 3.x; and
- xar 400+.

## Differences from Upstream

This fork aims to eventually clean up and modernize the ld64 code. The largest change is it
replaced the build system with Meson and moved around some of the code to better support that.
The following is a list of other, notable changes:

- corecrypto and CommonCrypto have been replaced by OpenSSL;
- libtapi is a vendored fork with only the `LinkerInterfaceFile` API needed by ld64;
- LLVM is required dependency; and
- Use of Darwin private APIs are being phased out with standards-based APIs.
