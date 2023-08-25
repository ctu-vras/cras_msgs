cmake_minimum_required(VERSION 3.7.2)
project(cras_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
)

add_message_files(FILES
  Brightness.msg
  BrightnessStamped.msg
  ColorRGBAStamped.msg
  ElectricCurrent.msg
  ElectricCurrentMeasurement.msg
  ElectricCurrentStamped.msg
  Heartbeat.msg
  Power.msg
  PowerMeasurement.msg
  PowerStamped.msg
  PowerSwitchState.msg
  PowerSwitchStateStamped.msg
  Voltage.msg
  VoltageMeasurement.msg
  VoltageStamped.msg
)

add_service_files(FILES
  SetBrightness.srv
  SetColor.srv
)

generate_messages(DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS message_runtime std_msgs
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

if(CATKIN_ENABLE_TESTING)
  find_package(roslint REQUIRED)

  # catkin_lint - checks validity of package.xml and CMakeLists.txt
  # ROS buildfarm calls this without any environment and with empty rosdep cache,
  # so we have problems reading the list of packages from env
  # see https://github.com/ros-infrastructure/ros_buildfarm/issues/923
  if(DEFINED ENV{ROS_HOME})
    #catkin_lint: ignore_once env_var
    set(ROS_HOME "$ENV{ROS_HOME}")
  else()
    #catkin_lint: ignore_once env_var
    set(ROS_HOME "$ENV{HOME}/.ros")
  endif()

  #catkin_lint: ignore_once env_var
  if(DEFINED ENV{ROS_ROOT} AND EXISTS "${ROS_HOME}/rosdep/sources.cache")
    roslint_custom(catkin_lint "-W2" .)
  endif()

  # Roslint C++ - checks formatting and some other rules for C++ files

  file(GLOB_RECURSE ROSLINT_INCLUDE include/*.h include/*.hpp)
  file(GLOB_RECURSE ROSLINT_TEST test/*.cpp)

  set(ROSLINT_CPP_OPTS "--extensions=h,hpp,hh,c,cpp,cc;--linelength=120;--filter=\
    -build/header_guard,-readability/namespace,-whitespace/braces,-runtime/references,\
    -build/c++11,-readability/nolint,-readability/todo,-legal/copyright")
  roslint_cpp(${ROSLINT_INCLUDE})

  set(ROSLINT_CPP_OPTS "${ROSLINT_CPP_OPTS},-build/namespaces")  # allow "using namespace" in tests
  roslint_cpp(${ROSLINT_TEST})

  roslint_add_test()

  find_package(Boost REQUIRED)
  find_package(sensor_msgs REQUIRED)

  include_directories(include)
  include_directories(${Boost_INCLUDE_DIRS})
  include_directories(${sensor_msgs_INCLUDE_DIRS})

  catkin_add_gtest(test_pool_allocated test/test_pool_allocated.cpp)
  target_link_libraries(test_pool_allocated ${Boost_LIBRARIES} ${sensor_msgs_LIBRARIES})
endif()