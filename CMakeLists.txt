cmake_minimum_required(VERSION 3.5)
project(shutdown_gz)

find_package(catkin REQUIRED roscpp)
find_package(Gazebo REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package(
   CATKIN_DEPENDS roscpp
   DEPENDS Gazebo
)

###########
## Build ##
###########

add_executable(${PROJECT_NAME}_shutdown_gz src/shutdown_gz.cpp)
set_target_properties(${PROJECT_NAME}_shutdown_gz PROPERTIES OUTPUT_NAME shutdown_gz PREFIX "")
target_link_libraries(${PROJECT_NAME}_shutdown_gz ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
target_include_directories(${PROJECT_NAME}_shutdown_gz PUBLIC ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS})
set_property(TARGET ${PROJECT_NAME}_shutdown_gz PROPERTY CXX_STANDARD 11)

#############
## Install ##
#############

install(TARGETS ${PROJECT_NAME}_shutdown_gz
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

