configure_h = custom_target(
    'configure_h',
    command : [ find_program('bash'), '@INPUT@' ],
    env : {
        'DERIVED_FILE_DIR' : meson.current_build_dir(),
        'RC_ProjectSourceVersion': meson.project_version(),
    },
    input : 'create_configure',
    output : 'configure.h',
)

subdir('abstraction')
subdir('mach_o')

subdir('ld')
subdir('other')
