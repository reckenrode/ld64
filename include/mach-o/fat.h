// SPDX-License-Identifier: APSL-2.0

// Derive `fat.h` from LLVM to avoid macro conflicts.

#pragma once

#include <llvm/BinaryFormat/MachO.h>

using llvm::MachO::fat_arch;
using llvm::MachO::fat_arch_64;
using llvm::MachO::fat_header;

using llvm::MachO::FAT_CIGAM;
using llvm::MachO::FAT_CIGAM_64;
using llvm::MachO::FAT_MAGIC;
using llvm::MachO::FAT_MAGIC_64;
