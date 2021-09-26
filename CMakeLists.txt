cmake_minimum_required(VERSION 3.16)

project(PickYourPoison VERSION 1.0.0)

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

set(
  SRC_FILES 
  ${PROJECT_SOURCE_DIR}/src/main.cpp 
  ${PROJECT_SOURCE_DIR}/src/player.cpp
  ${PROJECT_SOURCE_DIR}/src/room.cpp
  ${PROJECT_SOURCE_DIR}/src/entity.cpp
  ${PROJECT_SOURCE_DIR}/src/npc.cpp
)

file(COPY assets DESTINATION .)

add_executable(PickYourPoison ${SRC_FILES})

target_link_libraries(PickYourPoison sfml-graphics)
