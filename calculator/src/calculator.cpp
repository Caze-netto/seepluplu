#include <iostream>
#include "../include/calculator.hpp"

float result = 0;

int soma(const float value) {
    result += value;
    return result;
}

int sub(const float value){
    result -= value;
    return result;
}

int multiply(const float value){
    result *= value;
    return result;
}

int divide(const float value){
    if(value == 0){
        throw std::runtime_error("Erro: Divisão por zero!");
    }
    result /= value;
    return result;
}

int main() {

    soma(10);
    soma(10);
    multiply(2);

    std::cout << result << std::endl;

    divide(2);

    std::cout << result << std::endl;

    sub(1000);

    std::cout << result << std::endl;
}