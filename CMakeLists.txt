cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


project ("SpaceInvaders")
add_executable(SpaceInvaders
    src/Bullet.cpp
    src/End.cpp
    src/Entity.cpp
    src/Invader.cpp
    src/Invaders.cpp
    src/Times.cpp
    src/main.cpp
    src/Menu.cpp
    src/InvaderBullet.cpp
    src/Player.cpp
    src/PlayerBullet.cpp
    src/SceneGame.cpp
)

target_include_directories(SpaceInvaders PUBLIC ${PROJECT_SOURCE_DIR}/include/headers)


target_link_libraries(SpaceInvaders ${CMAKE_SOURCE_DIR}/library/sfml-window-d.lib)
target_link_libraries(SpaceInvaders ${CMAKE_SOURCE_DIR}/library/sfml-graphics-d.lib)
target_link_libraries(SpaceInvaders ${CMAKE_SOURCE_DIR}/library/sfml-system-d.lib)


include_directories(${CMAKE_SOURCE_DIR}/include)



FILE(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB DLLS ${CMAKE_SOURCE_DIR}/SFML_dll/*.dll)
file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR})


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SpaceInvaders PROPERTY CXX_STANDARD 20)
endif()
