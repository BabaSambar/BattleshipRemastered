cmake_minimum_required(VERSION 3.10)
project(BattleshipRemastered VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Add the include folder as include path
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executables
file(GLOB SRC_FILES "src/*.cpp")
add_executable(BattleshipRemastered ${SRC_FILES})

# Link SFML libraries
target_link_libraries(BattleshipRemastered PRIVATE sfml-graphics sfml-window sfml-system)

# Copy the res folder to the build directory (optional)
file(COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/res)

# Platform-specific handling for Windows (copy SFML DLLs)
if(WIN32)
    # Determine the SFML binary directory
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        set(SFML_DLLS
            sfml-graphics-d-2.dll
            sfml-window-d-2.dll
            sfml-system-d-2.dll
        )
    else()
        set(SFML_DLLS
            sfml-graphics-2.dll
            sfml-window-2.dll
            sfml-system-2.dll
        )
    endif()

    # Copy DLLs to the build directory
    foreach(dll ${SFML_DLLS})
        add_custom_command(TARGET BattleshipRemastered POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${SFML_ROOT}/bin/${dll}"
                $<TARGET_FILE_DIR:BattleshipRemastered>
        )
    endforeach()
endif()