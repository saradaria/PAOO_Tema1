cmake_minimum_required(VERSION 3.10)
project(EmailProject)

add_subdirectory(email)
add_subdirectory(gmail)
add_subdirectory(mail_manager)

add_executable(main main.cpp)
target_link_libraries(main email gmail mail_manager)
