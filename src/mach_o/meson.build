mach_o = static_library(
    'mach_o',
    cpp_args : [ '-Wno-vla-cxx-extension' ],
    sources : [
        'Error.cpp',
        'ExportsTrie.cpp',
    ],
)

mach_o_dep = declare_dependency(
    include_directories : [ '.' ],
    link_with : mach_o,
)
