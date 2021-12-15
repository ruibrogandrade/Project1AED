cmake_minimum_required(VERSION 3.20)
project(Projeto1AED)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projeto1AED main.cpp Aeroporto/passageiros.cpp Aeroporto/passageiros.h Aeroporto/voo.cpp Aeroporto/voo.h Aeroporto/aviao.cpp Aeroporto/aviao.h Aeroporto/servico.cpp Aeroporto/servico.h Aeroporto/bilhete.cpp Aeroporto/bilhete.h Aeroporto/transpTerr.cpp Aeroporto/transpTerr.h Aeroporto/Data.cpp Aeroporto/Data.h Aeroporto/bst.h Aeroporto/bagagem.cpp Aeroporto/bagagem.h)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)