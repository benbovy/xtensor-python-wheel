cmake_minimum_required(VERSION 3.15)

project(
  xtensor-python-wheel
  VERSION "0.26.1"
  LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(xtensor-python
      GIT_REPOSITORY https://github.com/xtensor-stack/xtensor-python
      GIT_TAG ${SKBUILD_PROJECT_VERSION}
      GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(xtensor-python)
