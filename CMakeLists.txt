cmake_minimum_required(VERSION 3.10)
project(BarbiesLoveDetective C)

set(CMAKE_C_STANDARD 99)

# Onde você instalou a raylib
set(RAYLIB_DIR "C:/raylib")

# Adicionar o executável primeiro!
add_executable(BarbiesLoveDetective sources/main.c)

# Agora incluir os headers
target_include_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_DIR}/src)

# Linkar a Raylib (binários)
target_link_directories(BarbiesLoveDetective PRIVATE ${RAYLIB_DIR}/w64devkit/lib)
target_link_libraries(BarbiesLoveDetective raylib opengl32 gdi32 winmm)

# Definir macro para assets
target_compile_definitions(BarbiesLoveDetective PRIVATE ASSETS_PATH="./assets/")