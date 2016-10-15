set(CF_HEADERS  point.h)
set(CF_SOURCES point.cpp main.cpp)

add_executable(${PROJECT_NAME} ${CF_HEADERS} ${CF_SOURCES})
target_link_libraries(${PROJECT_NAME} GL GLU X11 glut m)
