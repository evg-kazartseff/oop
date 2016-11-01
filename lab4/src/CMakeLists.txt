set(CF_HEADERS ellipse.h rhombus.h circle.h rectangle.h triangle.h line.h point.h)
set(CF_SOURCES ellipse.cpp rhombus.cpp circle.cpp rectangle.cpp triangle.cpp line.cpp point.cpp main.cpp)

add_executable(${PROJECT_NAME} ${CF_HEADERS} ${CF_SOURCES})
target_link_libraries(${PROJECT_NAME} GL GLU X11 glut m)
