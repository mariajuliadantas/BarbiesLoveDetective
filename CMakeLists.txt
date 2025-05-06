cmake_minimum_required(VERSION 3.10)
project(BarbiesLoveDetective C)

set(CMAKE_C_STANDARD 99)

# Adiciona o executável e os arquivos-fonte
add_executable(BarbiesLoveDetective
        sources/main.c
        sources/pistas.c
        sources/cJSON.c
        sources/gemini.c
        include/cJSON.h
        include/gemini.h)

# Inclui o diretório onde estão os headers próprios (como cJSON.h e gemini.h)
target_include_directories(BarbiesLoveDetective PRIVATE include)

# Detecta o sistema operacional
if(WIN32)
    # Caminhos para Raylib no MSYS2 (ajuste conforme sua instalação no Windows)
    set(RAYLIB_DIR "C:/msys64/mingw64/include/raylib")
    set(RAYLIB_LIB_DIR "C:/msys64/mingw64/lib")

    # Incluir headers e bibliotecas
    target_include_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_DIR})
    target_link_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_LIB_DIR})

    # Linkar com Raylib e outras libs do Windows
    target_link_libraries(BarbiesLoveDetective raylib opengl32 gdi32 winmm ws2_32)

elseif(APPLE)
    # Caminhos para Raylib no macOS (via Homebrew)
    set(RAYLIB_INCLUDE_DIR "/opt/homebrew/include")
    set(RAYLIB_LIB_DIR "/opt/homebrew/lib")

    target_include_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_INCLUDE_DIR})
    target_link_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_LIB_DIR})

    # Linkar com Raylib e bibliotecas necessárias no macOS
    target_link_libraries(BarbiesLoveDetective
            raylib
            curl
            m
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit"
    )

else()  # Linux ou WSL
    target_include_directories(BarbiesLoveDetective PRIVATE /usr/local/include)
    target_link_libraries(BarbiesLoveDetective raylib curl m pthread dl rt X11)
endif()

# Definir caminho dos assets em tempo de compilação
target_compile_definitions(BarbiesLoveDetective PRIVATE
        ASSETS_PATH="${CMAKE_CURRENT_BINARY_DIR}/assets/"
)

# Comando para copiar os assets após build
add_custom_command(TARGET BarbiesLoveDetective POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
)
