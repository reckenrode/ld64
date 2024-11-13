project(
    'libcodedirectory',
    'c',
    default_options : {'c_std': 'c23'},
    license : 'APSL-2.0',
    license_files : 'APPLE_LICENSE',
    meson_version : '>=1.6.0',
    version : '819.6.1',
)


cc = meson.get_compiler('c')

openssl_dep = dependency('openssl', version : '>=3.0')


libcodedirectory = library(
    'codedirectory',
    c_args : [ '-Wno-gnu-folding-constant' ],
    dependencies : [ openssl_dep ],
    install : true,
    sources : [ 'libcodedirectory.c' ],
    soversion : 1,
)
install_headers(
    'cs_blobs.h',
    'libcodedirectory.h',
)

libcodedirectory_dep = declare_dependency(
    include_directories : [ '.' ],
    link_with : libcodedirectory,
)
