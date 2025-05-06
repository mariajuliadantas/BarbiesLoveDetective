cmake_minimum_required(VERSION 3.10)
project(BarbiesLoveDetective C)

set(CMAKE_C_STANDARD 99)

# Adiciona o executável
add_executable(BarbiesLoveDetective sources/main.c
        sources/pistas.c)

# Detecta o sistema operacional
if(WIN32)
    # Ajustes para Windows
    set(RAYLIB_DIR "C:/raylib")
    target_include_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_DIR}/src)
    target_link_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_DIR}/w64devkit/lib)
    target_link_libraries(BarbiesLoveDetective raylib opengl32 gdi32 winmm)
else()
    # Ajustes para Linux/WSL
    target_include_directories(BarbiesLoveDetective PRIVATE /usr/local/include)
    target_link_libraries(BarbiesLoveDetective raylib m pthread dl rt X11)
endif()

# Define macro para o caminho de assets
target_compile_definitions(BarbiesLoveDetective PRIVATE ASSETS_PATH="./assets/")