#set(HEADERS Matrix.hpp,Ray.hpp,Shapers.hpp)
#set(SOURCES Ray.cpp)

# Добавляем библиотеку
add_library(LinearAlg_libs Ray.cpp Ray.hpp Matrix.hpp Shapes.hpp Mat_types.hpp) 

# Указываем, что это библиотека для использования в других целях
target_include_directories(LinearAlg_libs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})