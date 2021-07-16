cmake_minimum_required(VERSION 3.17)
project(CormenBook)

set(CMAKE_CXX_STANDARD 14)

add_executable(CormenBook main.cpp polynomial_eval_horner_rule.h polynomial_eval_horner_rule.cpp exercises/exercise2-4-d.cpp exercises/exercise2-4-d.h)