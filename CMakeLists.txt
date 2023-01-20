cmake_minimum_required(VERSION 3.0.0)
project(2D-Top-down-shooter VERSION 1.0)

add_executable(game 
    src/2D-Top-down-shooter.cpp
    src/Bullet.cpp
    src/Character.cpp
    src/Enemy.cpp
    src/Entity.cpp
    src/Game.cpp
    src/MenuObject.cpp
    src/Player.cpp
    src/RgbImage.cpp
    src/Sprite.cpp
)

find_package(OpenGL REQUIRED) 
find_package(GLUT REQUIRED)
include_directories(library ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(game SDL2main SDL2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
