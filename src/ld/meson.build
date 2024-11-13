subdir('parsers')

InputFiles_cpp = configure_file(
    configuration : {
        'libllvm_path' : get_option('libllvm_path'),
        # Silence warnings
        'APPLE_LICENSE_HEADER_START' : '@APPLE_LICENSE_HEADER_START@',
        'APPLE_LICENSE_HEADER_END' : '@APPLE_LICENSE_HEADER_END@',
    },
    input : 'InputFiles.cpp',
    output : '@PLAINNAME@',
)

executable(
    'ld',
    cpp_args : [
        '-Wno-c23-extensions',
        '-Wno-vla-cxx-extension',
    ],
    dependencies : [
        abstraction_dep,
        libcodedirectory_dep,
        libtapi_dep,
        llvm_dep,
        mach_o_dep,
        openssl_dep,
        parsers_dep,
        xar_dep,
    ],
    include_directories : [
        'code-sign-blobs',
        'parsers',
        'passes',
    ],
    install : true,
    # These linker flags mirror those used in a release build of the Xcode project.
    # See: https://github.com/apple-oss-distributions/ld64/blob/47f477cb721755419018f7530038b272e9d0cdea/ld64.xcodeproj/project.pbxproj#L1292-L1299.
    link_args : [
        '-Wl,-exported_symbol,__mh_execute_header',
        '-Wl,-stack_size,0x02000000',
        '-Wl,-client_name,ld',
    ],
    sources : [
        configure_h,
        InputFiles_cpp,
        'FatFile.cpp',
        'Mangling.cpp',
        'Options.cpp',
        'OutputFile.cpp',
        'PlatformSupport.cpp',
        'Resolver.cpp',
        'ResponseFiles.cpp',
        'Snapshot.cpp',
        'SymbolTable.cpp',
        'code-sign-blobs/blob.cpp',
        'code-sign-blobs/blob.h',
        'debugline.c',
        'ld.cpp',
        'passes/bitcode_bundle.cpp',
        'passes/branch_island.cpp',
        'passes/branch_shim.cpp',
        'passes/code_dedup.cpp',
        'passes/compact_unwind.cpp',
        'passes/dtrace_dof.cpp',
        'passes/dylibs.cpp',
        'passes/got.cpp',
        'passes/huge.cpp',
        'passes/inits.cpp',
        'passes/objc.cpp',
        'passes/objc_constants.cpp',
        'passes/objc_stubs.cpp',
        'passes/order.cpp',
        'passes/stubs/stubs.cpp',
        'passes/thread_starts.cpp',
        'passes/tlvp.cpp',
    ],
)
install_man(meson.global_source_root() / 'doc/man/man1/ld-classic.1')
