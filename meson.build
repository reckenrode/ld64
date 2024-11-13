project(
    'ld64',
    'c', 'cpp',
    default_options : {'c_std': 'c23', 'cpp_std': 'c++23'},
    license : 'APSL-2.0',
    license_files : 'APPLE_LICENSE',
    meson_version : '>=1.6.0',
    version : '951.9',
)

add_project_arguments(
    # Avoid needing to link libSupport, which helps avoid a dependency on LLVM in packages
    # that link libprunetrie.a (such as cctools).
    '-DLLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1',
    language : 'cpp',
)


cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')


libcodedirectory_dep = dependency(
    'libcodedirectory',
    version : '=819.6.1',
)
libtapi_dep = dependency(
    'libtapi',
    version : [ '>=1500' , '<1600' ],
)
llvm_dep = dependency(
    'llvm',
    version : '>=19.1'
).partial_dependency(includes : true) # ld64 only needs LLVM headers for ADTs.
openssl_dep = dependency(
    'openssl',
    version : '>=3.0'
)
xar_dep = cc.find_library('xar')


subdir('src')
