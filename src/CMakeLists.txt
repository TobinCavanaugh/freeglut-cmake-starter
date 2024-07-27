add_executable(Application ansi_escapes.c ansi_escapes.h sw.h sw.c)

set_target_properties(Application PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF)

#target_compile_options(Application PRIVATE
        #    $<$<C_COMPILER_ID:Clang,AppleClang,GNU>:-Wall -Wextra -Wpedantic -Werror>
#        $<$<C_COMPILER_ID:MSVC>:/W4 /WX>
#        )

target_sources(Application PRIVATE
        main.c fstr/fstr.c sw.c
        )

target_include_directories(Application PRIVATE
        ${LIB_DIR}/freeglut/include
        )

target_link_libraries(Application PRIVATE
        freeglut_static
        )

