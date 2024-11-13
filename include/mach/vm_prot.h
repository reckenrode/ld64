// SPDX-License-Identifier: APSL-2.0

// Derive `vm_prot.h` from LLVM to avoid macro conflicts.

#pragma once

#include <llvm/BinaryFormat/MachO.h>

using llvm::MachO::VM_PROT_EXECUTE;
using llvm::MachO::VM_PROT_READ;
using llvm::MachO::VM_PROT_WRITE;

#include_next <mach/vm_prot.h>
