parsers = static_library(
    'parsers',
    cpp_args : [ '-Wno-vla-cxx-extension' ],
    dependencies : [
        abstraction_dep,
        libtapi_dep,
    ],
    include_directories : [
        '..',    # For ld64 headers
    ],
    sources : [
        configure_h,
        'archive_file.cpp',
        'generic_dylib_file.cpp',
        'lto_file.cpp',
        'macho_dylib_file.cpp',
        'macho_relocatable_file.cpp',
        'opaque_section_file.cpp',
        'textstub_dylib_file.cpp',
    ],
)

parsers_dep = declare_dependency(
    include_directories : [ '.' ],
    link_with : parsers,
)
