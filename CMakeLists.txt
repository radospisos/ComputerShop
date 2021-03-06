cmake_minimum_required(VERSION 3.10)
project(ComputerShop)

set(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

######## CORE ########

#file(GLOB_RECURSE core_sources "src/core/*.cpp")
#file(GLOB_RECURSE core_headers "src/core/*.h")

######## CLI ########

#file(GLOB_RECURSE cli_sources "src/CLI/*.cpp")
#file(GLOB_RECURSE cli_headers "src/CLI/*.h")

#file(GLOB main "src/main.cpp")

#add_executable(ToDoList ${core_sources} ${core_headers} ${cli_sources} ${cli_headers} ${main})
add_executable(ComputerShop main.cpp MemoryModel/Goods/Component/Component.cpp MemoryModel/Goods/Component/Component.h MemoryModel/Goods/Component/GraphicsCard.cpp MemoryModel/Goods/Component/GraphicsCard.h MemoryModel/Goods/Computer.cpp MemoryModel/Goods/Computer.h MemoryModel/Storage/ComponentsStorage.cpp MemoryModel/Storage/ComponentsStorage.h)

######## TESTS ########
#file(GLOB_RECURSE core_tests "tests/core/*.cpp")
#file(GLOB_RECURSE cli_tests "tests/CLI/*.cpp")

######## BOOST ########

set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS      ON)
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.65.1 COMPONENTS date_time REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

######## PROTOBUF ########

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#file(GLOB_RECURSE PROTO_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/core/Persister/Serialization/Proto/*.proto")
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCES})
#message("generated ${PROTO_SRCS} ${PROTO_HDRS}")

SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)

######## GTEST ########

#include_directories(src/core)
#include_directories(src/CLI)
#include_directories(tests)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")

include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GMOCK_INCLUDE_DIR})
enable_testing()

#add_executable(Tests ${core_tests} ${core_sources} ${cli_sources} ${cli_tests} ${PROTO_SRCS} ${PROTO_HDRS})
add_executable(Tests main.cpp)

set(GMOCK_L "/usr/local/lib/gmock/")
target_link_libraries(Tests GTest::GTest GTest::Main /usr/local/lib/libgmock.a /usr/local/lib/libgmock_main.a)
target_link_libraries(Tests ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})

target_link_libraries(ComputerShop ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})

gtest_discover_tests(Tests)
