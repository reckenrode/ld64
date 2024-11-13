machocheck = executable(
    'machocheck',
    dependencies : [
        abstraction_dep,
        llvm_dep,
    ],
    include_directories : [ '../ld' ],
    install : true,
    sources : [
        configure_h,
        'machochecker.cpp',
    ],
)

ObjectDump = executable(
    'ObjectDump',
    cpp_args : [ '-Wno-vla-cxx-extension' ],
    dependencies : [
        abstraction_dep,
        libtapi_dep,
        parsers_dep,
    ],
    include_directories : [ '../ld' ],
    install : true,
    sources : [
        configure_h,
        '../ld/PlatformSupport.cpp',
        '../ld/debugline.c',
        'ObjectDump.cpp',
    ],
)

objcimageinfo = executable(
    'objcimageinfo',
    dependencies : [
        abstraction_dep,
        llvm_dep,
    ],
    include_directories : [ '../ld' ],
    install : true,
    sources : [
        configure_h,
        'objcimageinfo.cpp',
    ],
)

unwinddump = executable(
    'unwinddump',
    dependencies : [
        abstraction_dep,
        llvm_dep,
    ],
    include_directories : [ '../ld' ],
    install : true,
    sources : [
        configure_h,
        'UnwindDump.cpp',
    ],
)
install_man(meson.global_source_root() / 'doc/man/man1/unwinddump.1')

static_library(
    'prunetrie',
    cpp_args : [ '-Wno-vla-cxx-extension' ],
    dependencies : [
        abstraction_dep,
        mach_o_dep
    ],
    include_directories : [ '../ld' ],
    install : true,
    override_options : {'b_lto': false},
    sources : [
        configure_h,
        'PruneTrie.cpp',
    ],
)
install_headers(
    'prune_trie.h',
    subdir : 'mach-o',
)
