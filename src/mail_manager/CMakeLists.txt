add_library(mail_manager MailManager MailManager.cpp)
target_include_directories(email PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../common)
