// SPDX-License-Identifier: APSL-2.0

// Derive `nlist.h` from LLVM to avoid macro conflicts.

#pragma once

#include <llvm/BinaryFormat/MachO.h>

using llvm::MachO::nlist;
using llvm::MachO::nlist_64;

using llvm::MachO::N_ARM_THUMB_DEF;

using llvm::MachO::N_ABS;
using llvm::MachO::N_EXT;
using llvm::MachO::N_INDR;
using llvm::MachO::N_PBUD;
using llvm::MachO::N_PEXT;
using llvm::MachO::N_SECT;
using llvm::MachO::N_STAB;
using llvm::MachO::N_TYPE;
using llvm::MachO::N_UNDF;

using llvm::MachO::N_ALT_ENTRY;
using llvm::MachO::N_NO_DEAD_STRIP;
using llvm::MachO::N_SYMBOL_RESOLVER;
using llvm::MachO::N_WEAK_DEF;
using llvm::MachO::N_WEAK_REF;

#define N_REF_TO_WEAK 0x80 // Not defined in LLVM headers

using llvm::MachO::DYNAMIC_LOOKUP_ORDINAL;

using llvm::MachO::EXECUTABLE_ORDINAL;

using llvm::MachO::GET_COMM_ALIGN;
using llvm::MachO::SET_COMM_ALIGN;

using llvm::MachO::GET_LIBRARY_ORDINAL;
using llvm::MachO::SET_LIBRARY_ORDINAL;

using llvm::MachO::REFERENCE_FLAG_DEFINED;
using llvm::MachO::REFERENCE_FLAG_PRIVATE_DEFINED;
using llvm::MachO::REFERENCE_FLAG_PRIVATE_UNDEFINED_LAZY;
using llvm::MachO::REFERENCE_FLAG_PRIVATE_UNDEFINED_NON_LAZY;
using llvm::MachO::REFERENCE_FLAG_UNDEFINED_LAZY;
using llvm::MachO::REFERENCE_FLAG_UNDEFINED_NON_LAZY;
using llvm::MachO::REFERENCE_TYPE;

using llvm::MachO::REFERENCED_DYNAMICALLY;

using llvm::MachO::MAX_SECT;
using llvm::MachO::NO_SECT;

using llvm::MachO::SELF_LIBRARY_ORDINAL;

template<typename T>
inline constexpr int operator| (llvm::MachO::NListType lhs, T rhs) { return (int) lhs | (int) rhs; }

template<typename T>
inline constexpr int operator| (T lhs, llvm::MachO::NListType rhs) { return (int) lhs | (int) rhs; }
