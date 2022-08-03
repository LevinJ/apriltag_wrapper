cmake_minimum_required (VERSION 2.6)

project (test_wrapper)
find_package(OpenCV  REQUIRED)
find_package(Eigen3)
include_directories(
  ../
  include_directories(${OpenCV_INCLUDE_DIRS})
  ${EIGEN3_INCLUDE_DIR}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
add_executable(test_wrapper src/test_wrapper.cpp)

target_link_libraries(test_wrapper  ${OpenCV_LIBS} apriltag)
