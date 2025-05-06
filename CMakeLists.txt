cmake_minimum_required(VERSION 3.10)
project(BarbiesLoveDetective C)

set(CMAKE_C_STANDARD 99)

# Adiciona o executável
add_executable(BarbiesLoveDetective sources/main.c
        sources/pistas.c)

# Detecta o sistema operacional
if(WIN32)
    # Ajustes para Windows com MSYS2 e Raylib
    # Caminho do Raylib no MSYS2
    set(RAYLIB_DIR "C:/msys64/mingw64/include/raylib")  # Altere conforme a instalação do Raylib no MSYS2
    target_include_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_DIR})

    # Caminho para bibliotecas no MSYS2 (ajuste conforme necessário)
    set(RAYLIB_LIB_DIR "C:/msys64/mingw64/lib")
    target_link_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_LIB_DIR})

    # Linkar com Raylib e outras bibliotecas do Windows
    target_link_libraries(BarbiesLoveDetective raylib opengl32 gdi32 winmm)
elseif(APPLE)
    # Ajustes para macOS
    set(RAYLIB_INCLUDE_DIR "/opt/homebrew/include")
    set(RAYLIB_LIB_DIR "/opt/homebrew/lib")

    # Diretórios de inclusão
    target_include_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_INCLUDE_DIR})

    # Diretórios de bibliotecas
    target_link_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_LIB_DIR})

    # Linkar com Raylib e outras bibliotecas (Corrigido para macOS)
    target_link_libraries(BarbiesLoveDetective
            raylib
            m
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit"
    )
else()
    # Ajustes para Linux/WSL
    target_include_directories(BarbiesLoveDetective PRIVATE /usr/local/include)
    target_link_libraries(BarbiesLoveDetective raylib m pthread dl rt X11)
endif()

# Definir o caminho dos assets
target_compile_definitions(BarbiesLoveDetective PRIVATE
        ASSETS_PATH="${CMAKE_CURRENT_BINARY_DIR}/assets/"
)

# Comando pós-compilação para copiar os assets para a pasta de build
add_custom_command(TARGET BarbiesLoveDetective POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
)
