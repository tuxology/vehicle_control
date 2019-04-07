# vehicle_demo
#
# Simulates an attack during iamge-decoding stage which leads to engine shutdown

cmake_minimum_required(VERSION 2.6)

set(CMAKE_PREFIX_PATH /usr/lib64)

set(ECU_FILES
  src/control_loop.c
  src/engine_control.c
  src/logger.c
)

add_executable(control_loop
    ${ECU_FILES}
)