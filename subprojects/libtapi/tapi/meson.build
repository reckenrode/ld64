version_components = meson.project_version().split('.')
version_inc = configure_file(
    configuration : {
        'TAPI_VERSION' : meson.project_version(),
        'TAPI_VERSION_MAJOR' : version_components[0],
        'TAPI_VERSION_MINOR' : version_components[1],
        'TAPI_VERSION_PATCH' : version_components[2],
    },
    input : 'Version.inc.in',
    output : '@BASENAME@',
)
