cmake_minimum_required(VERSION 3.15...3.26)

project(
  "${SKBUILD_PROJECT_NAME}"
  LANGUAGES CXX
  VERSION "${SKBUILD_PROJECT_VERSION}")

find_package(
  Python
  COMPONENTS Interpreter Development.Module NumPy
  REQUIRED)

# TODO: xtensor-python cmake config doesn't find xtl and xtensor
find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)
find_package(xtensor-python REQUIRED)

find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(example src/main.cpp)

target_compile_definitions(example
                           PRIVATE VERSION_INFO=${PROJECT_VERSION})

target_compile_features(example PUBLIC cxx_std_14)

target_link_libraries(example
                      PRIVATE xtensor-python Python::NumPy)

install(TARGETS example LIBRARY DESTINATION .)
