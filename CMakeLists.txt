cmake_minimum_required(VERSION 3.27)
project(gestao_de_estoque C)

set(CMAKE_C_STANDARD 11)

include_directories(source/menu)
include_directories(source/produto)

add_executable(gestao_de_estoque
        source/menu/menu.c
        source/menu/menu.h
        source/produto/produto.c
        source/produto/produto.h
        source/main.c
        source/utils/utils.c)
