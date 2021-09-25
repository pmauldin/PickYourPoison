cmake_minimum_required(VERSION 3.16)

project(RogueHeavy VERSION 1.0.0)

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

# FILE(
#   GLOB
#   SOURCES
#   "main.cpp"
# )

set(
  SRC_FILES 
  ${PROJECT_SOURCE_DIR}/main.cpp 
  ${PROJECT_SOURCE_DIR}/player.cpp
  ${PROJECT_SOURCE_DIR}/room.cpp
)

file(COPY assets DESTINATION .)

add_executable(RogueHeavy ${SRC_FILES})

target_link_libraries(RogueHeavy sfml-graphics)
