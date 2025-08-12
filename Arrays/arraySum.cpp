#include <iostream>

int main() {
    int tamanho;
    int soma = 0;

    std::cout << "Soma dos elementos de um array\n";
    std::cout << "Informe o tamanho: ";
    std::cin >> tamanho;

    if (tamanho <= 0) {
        std::cerr << "Tamanho inválido!\n";
        return 1;
    }

    auto* array = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        std::cout << "Informe o " << i + 1 << "º valor: ";
        std::cin >> array[i];
    }

    for (int j = 0; j < tamanho; j++) {
        soma += array[j];
    } // O(n)

    std::cout << "A soma dos elementos do array é: " << soma << "\n";

    delete[] array;
    return 0;
}