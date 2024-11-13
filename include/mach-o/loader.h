// SPDX-License-Identifier: APSL-2.0

// Derive `loader.h` from LLVM to avoid macro conflicts.

#pragma once

#include <mach/vm_prot.h>

#include <llvm/BinaryFormat/MachO.h>

using llvm::MachO::mach_header;
using llvm::MachO::mach_header_64;

using llvm::MachO::data_in_code_entry;

using llvm::MachO::dylib_table_of_contents;

using llvm::MachO::dylib_module;
using llvm::MachO::dylib_module_64;

using llvm::MachO::section;
using llvm::MachO::section_64;

using llvm::MachO::build_tool_version;
using llvm::MachO::build_version_command;
using llvm::MachO::dyld_info_command;
using llvm::MachO::dylib;
using llvm::MachO::dylib_command;
using llvm::MachO::dylinker_command;
using llvm::MachO::dysymtab_command;
using llvm::MachO::encryption_info_command;
using llvm::MachO::encryption_info_command_64;
using llvm::MachO::entry_point_command;
using llvm::MachO::linkedit_data_command;
using llvm::MachO::linker_option_command;
using llvm::MachO::load_command;
using llvm::MachO::routines_command;
using llvm::MachO::routines_command_64;
using llvm::MachO::rpath_command;
using llvm::MachO::segment_command;
using llvm::MachO::segment_command_64;
using llvm::MachO::source_version_command;
using llvm::MachO::sub_client_command;
using llvm::MachO::sub_framework_command;
using llvm::MachO::sub_library_command;
using llvm::MachO::sub_umbrella_command;
using llvm::MachO::symtab_command;
using llvm::MachO::thread_command;
using llvm::MachO::twolevel_hints_command;
using llvm::MachO::uuid_command;
using llvm::MachO::version_min_command;

using llvm::MachO::LC_BUILD_VERSION;
using llvm::MachO::LC_CODE_SIGNATURE;
using llvm::MachO::LC_DATA_IN_CODE;
using llvm::MachO::LC_DYLD_ENVIRONMENT;
using llvm::MachO::LC_DYLD_INFO;
using llvm::MachO::LC_DYLD_INFO_ONLY;
using llvm::MachO::LC_DYSYMTAB;
using llvm::MachO::LC_ENCRYPTION_INFO;
using llvm::MachO::LC_ENCRYPTION_INFO_64;
using llvm::MachO::LC_FUNCTION_STARTS;
using llvm::MachO::LC_ID_DYLIB;
using llvm::MachO::LC_ID_DYLINKER;
using llvm::MachO::LC_LINKER_OPTION;
using llvm::MachO::LC_LOAD_DYLIB;
using llvm::MachO::LC_LOAD_DYLINKER;
using llvm::MachO::LC_LOAD_UPWARD_DYLIB;
using llvm::MachO::LC_LOAD_WEAK_DYLIB;
using llvm::MachO::LC_MAIN;
using llvm::MachO::LC_REEXPORT_DYLIB;
using llvm::MachO::LC_REQ_DYLD;
using llvm::MachO::LC_ROUTINES;
using llvm::MachO::LC_ROUTINES_64;
using llvm::MachO::LC_RPATH;
using llvm::MachO::LC_SEGMENT;
using llvm::MachO::LC_SEGMENT_64;
using llvm::MachO::LC_SEGMENT_SPLIT_INFO;
using llvm::MachO::LC_SOURCE_VERSION;
using llvm::MachO::LC_SUB_CLIENT;
using llvm::MachO::LC_SUB_FRAMEWORK;
using llvm::MachO::LC_SUB_LIBRARY;
using llvm::MachO::LC_SUB_UMBRELLA;
using llvm::MachO::LC_SYMTAB;
using llvm::MachO::LC_UNIXTHREAD;
using llvm::MachO::LC_UUID;
using llvm::MachO::LC_VERSION_MIN_IPHONEOS;
using llvm::MachO::LC_VERSION_MIN_MACOSX;
using llvm::MachO::LC_VERSION_MIN_TVOS;
using llvm::MachO::LC_VERSION_MIN_WATCHOS;
using llvm::MachO::LC_DYLIB_CODE_SIGN_DRS;
using llvm::MachO::LC_NOTE;
using llvm::MachO::LC_LAZY_LOAD_DYLIB;
using llvm::MachO::LC_PREBIND_CKSUM;
using llvm::MachO::LC_TWOLEVEL_HINTS;

using llvm::MachO::MH_ALLOW_STACK_EXECUTION;
using llvm::MachO::MH_APP_EXTENSION_SAFE;
using llvm::MachO::MH_BINDS_TO_WEAK;
using llvm::MachO::MH_BUNDLE;
using llvm::MachO::MH_CIGAM;
using llvm::MachO::MH_CIGAM_64;
using llvm::MachO::MH_DEAD_STRIPPABLE_DYLIB;
using llvm::MachO::MH_DYLDLINK;
using llvm::MachO::MH_DYLIB;
using llvm::MachO::MH_DYLIB_STUB;
using llvm::MachO::MH_DYLINKER;
using llvm::MachO::MH_EXECUTE;
using llvm::MachO::MH_LAZY_INIT;
using llvm::MachO::MH_INCRLINK;
using llvm::MachO::MH_HAS_TLV_DESCRIPTORS;
using llvm::MachO::MH_KEXT_BUNDLE;
using llvm::MachO::MH_MAGIC;
using llvm::MachO::MH_MAGIC_64;
using llvm::MachO::MH_NOUNDEFS;
using llvm::MachO::MH_NO_HEAP_EXECUTION;
using llvm::MachO::MH_NO_REEXPORTED_DYLIBS;
using llvm::MachO::MH_OBJECT;
using llvm::MachO::MH_PIE;
using llvm::MachO::MH_PREBOUND;
using llvm::MachO::MH_PRELOAD;
using llvm::MachO::MH_SPLIT_SEGS;
using llvm::MachO::MH_SUBSECTIONS_VIA_SYMBOLS;
using llvm::MachO::MH_TWOLEVEL;
using llvm::MachO::MH_WEAK_DEFINES;

using llvm::MachO::BIND_IMMEDIATE_MASK;

using llvm::MachO::BIND_OPCODE_ADD_ADDR_ULEB;
using llvm::MachO::BIND_OPCODE_DONE;
using llvm::MachO::BIND_OPCODE_DO_BIND;
using llvm::MachO::BIND_OPCODE_DO_BIND_ADD_ADDR_IMM_SCALED;
using llvm::MachO::BIND_OPCODE_DO_BIND_ADD_ADDR_ULEB;
using llvm::MachO::BIND_OPCODE_DO_BIND_ULEB_TIMES_SKIPPING_ULEB;
using llvm::MachO::BIND_OPCODE_SET_ADDEND_SLEB;
using llvm::MachO::BIND_OPCODE_SET_DYLIB_ORDINAL_IMM;
using llvm::MachO::BIND_OPCODE_SET_DYLIB_ORDINAL_ULEB;
using llvm::MachO::BIND_OPCODE_SET_DYLIB_SPECIAL_IMM;
using llvm::MachO::BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB;
using llvm::MachO::BIND_OPCODE_SET_SYMBOL_TRAILING_FLAGS_IMM;
using llvm::MachO::BIND_OPCODE_SET_TYPE_IMM;
using llvm::MachO::BIND_OPCODE_MASK;

using llvm::MachO::BIND_SPECIAL_DYLIB_FLAT_LOOKUP;
using llvm::MachO::BIND_SPECIAL_DYLIB_MAIN_EXECUTABLE;
using llvm::MachO::BIND_SPECIAL_DYLIB_SELF;

using llvm::MachO::BIND_SYMBOL_FLAGS_NON_WEAK_DEFINITION;
using llvm::MachO::BIND_SYMBOL_FLAGS_WEAK_IMPORT;

using llvm::MachO::BIND_TYPE_POINTER;
using llvm::MachO::BIND_TYPE_TEXT_ABSOLUTE32;
using llvm::MachO::BIND_TYPE_TEXT_PCREL32;

using llvm::MachO::DICE_KIND_ABS_JUMP_TABLE32;
using llvm::MachO::DICE_KIND_DATA;
using llvm::MachO::DICE_KIND_JUMP_TABLE16;
using llvm::MachO::DICE_KIND_JUMP_TABLE32;
using llvm::MachO::DICE_KIND_JUMP_TABLE8;

using llvm::MachO::EXPORT_SYMBOL_FLAGS_KIND_MASK;
using llvm::MachO::EXPORT_SYMBOL_FLAGS_KIND_REGULAR;
using llvm::MachO::EXPORT_SYMBOL_FLAGS_KIND_THREAD_LOCAL;
using llvm::MachO::EXPORT_SYMBOL_FLAGS_REEXPORT;
using llvm::MachO::EXPORT_SYMBOL_FLAGS_STUB_AND_RESOLVER;
using llvm::MachO::EXPORT_SYMBOL_FLAGS_WEAK_DEFINITION;

using llvm::MachO::REBASE_IMMEDIATE_MASK;

using llvm::MachO::REBASE_OPCODE_MASK;
using llvm::MachO::REBASE_OPCODE_ADD_ADDR_IMM_SCALED;
using llvm::MachO::REBASE_OPCODE_ADD_ADDR_ULEB;
using llvm::MachO::REBASE_OPCODE_DONE;
using llvm::MachO::REBASE_OPCODE_DO_REBASE_ADD_ADDR_ULEB;
using llvm::MachO::REBASE_OPCODE_DO_REBASE_IMM_TIMES;
using llvm::MachO::REBASE_OPCODE_DO_REBASE_ULEB_TIMES;
using llvm::MachO::REBASE_OPCODE_DO_REBASE_ULEB_TIMES_SKIPPING_ULEB;
using llvm::MachO::REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB;
using llvm::MachO::REBASE_OPCODE_SET_TYPE_IMM;

using llvm::MachO::REBASE_TYPE_POINTER;
using llvm::MachO::REBASE_TYPE_TEXT_ABSOLUTE32;
using llvm::MachO::REBASE_TYPE_TEXT_PCREL32;

using llvm::MachO::S_4BYTE_LITERALS;
using llvm::MachO::S_8BYTE_LITERALS;
using llvm::MachO::S_16BYTE_LITERALS;
using llvm::MachO::S_ATTR_DEBUG;
using llvm::MachO::S_ATTR_EXT_RELOC;
using llvm::MachO::S_ATTR_LIVE_SUPPORT;
using llvm::MachO::S_ATTR_LOC_RELOC;
using llvm::MachO::S_ATTR_LOC_RELOC;
using llvm::MachO::S_ATTR_NO_DEAD_STRIP;
using llvm::MachO::S_ATTR_PURE_INSTRUCTIONS;
using llvm::MachO::S_ATTR_SELF_MODIFYING_CODE;
using llvm::MachO::S_ATTR_SOME_INSTRUCTIONS;
using llvm::MachO::S_COALESCED;
using llvm::MachO::S_CSTRING_LITERALS;
using llvm::MachO::S_DTRACE_DOF;
using llvm::MachO::S_INTERPOSING;
using llvm::MachO::S_LAZY_DYLIB_SYMBOL_POINTERS;
using llvm::MachO::S_LAZY_SYMBOL_POINTERS;
using llvm::MachO::S_LITERAL_POINTERS;
using llvm::MachO::S_MOD_INIT_FUNC_POINTERS;
using llvm::MachO::S_MOD_TERM_FUNC_POINTERS;
using llvm::MachO::S_NON_LAZY_SYMBOL_POINTERS;
using llvm::MachO::S_REGULAR;
using llvm::MachO::S_SYMBOL_STUBS;
using llvm::MachO::S_THREAD_LOCAL_INIT_FUNCTION_POINTERS;
using llvm::MachO::S_THREAD_LOCAL_REGULAR;
using llvm::MachO::S_THREAD_LOCAL_VARIABLES;
using llvm::MachO::S_THREAD_LOCAL_VARIABLE_POINTERS;
using llvm::MachO::S_THREAD_LOCAL_ZEROFILL;
using llvm::MachO::S_ZEROFILL;

using llvm::MachO::SG_NORELOC;

using llvm::MachO::INDIRECT_SYMBOL_ABS;
using llvm::MachO::INDIRECT_SYMBOL_LOCAL;
using llvm::MachO::SECTION_TYPE;
using llvm::MachO::TOOL_LD;

template<typename T>
inline constexpr int operator| (llvm::MachO::SectionType lhs, T rhs) { return (int) lhs | (int) rhs; }
