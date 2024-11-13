project(
    'libtapi',
    'c', 'cpp',
    default_options : {'c_std': 'c23', 'cpp_std': 'c++23'},
    license : 'NCSA',
    license_files : 'LICENSE.TXT',
    meson_version : '>=1.6.0',
    version : '1600.0.11.8',
)


cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

# libtapi only needs a subset of functionality from LLVM, so link only what it needs statically
# to avoid ODR violations when loading LTO plugins (which don’t use these APIs).
llvm_dep = dependency(
    'llvm',
    modules : [
        'Demangle',
        'TargetParser',
        'TextAPI',
    ],
    static : true,
    version : '>=19.1'
)


subdir('tapi')

libtapi = static_library(
    'tapi',
    sources : [
        'APIVersion.cpp',
        'LinkerInterfaceFile.cpp',
        'Version.cpp',
    ],
)

libtapi_dep = declare_dependency(
    dependencies : [ llvm_dep ],
    include_directories : [ '.' ],
    link_with : libtapi,
)
