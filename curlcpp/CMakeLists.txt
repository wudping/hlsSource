cmake_minimum_required(VERSION 2.8)
SET(CURL_MIN_VERSION "7.28.0")

# Setting up project
PROJECT(CURLCPP)


# Add MacPorts
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CMAKE_PREFIX_PATH /opt/local ${CMAKE_PREFIX_PATH})
endif()

# Checking for dependencies
FIND_PACKAGE(CURL ${CURL_MIN_VERSION} REQUIRED)

# Set up include pathes
INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CURLCPP_SOURCE_DIR}/include)

# Set up source directories
ADD_SUBDIRECTORY(src)


