#include <iostream>

int main() {
    // Reservo 10 espaços na memória stack para inteiros, inicializados de 0 a 9
    int algarismos[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // stack, PC faz isso de forma automática.

    int tamanho;
    std::cout << "Qual o tamanho da lista? ";
    std::cin >> tamanho;

    // Verificação básica para evitar problemas
    if (tamanho <= 0) {
        std::cerr << "Erro: tamanho inválido. Por favor, informe um número positivo." << std::endl;
        return 1; // Sai do programa com erro
    }

    auto *lista = new int[tamanho]; // heap, memória dinâmica

    for (int i = 0; i < tamanho; ++i) {
        std::cout << "Digite o valor do elemento " << i + 1 << ": ";
        std::cin >> lista[i];
    }

    std::cout << "\nImprimindo os elementos da lista:\n";
    for (int i = 0; i < tamanho; ++i) {
        std::cout << "Elemento " << i + 1 << ": " << lista[i] << std::endl;
    }

    delete[] lista; // libera memória da heap
    std::cout << "Memória liberada com sucesso!\n";


    // Parte 2: Matriz dinâmica
    int n, m;
    std::cout << "Digite o número de linhas da matriz: ";
    std::cin >> n;
    std::cout << "Digite o número de colunas da matriz: ";
    std::cin >> m;

    if (n <= 0 || m <= 0) {
        std::cerr << "Erro: dimensões inválidas. Por favor, informe números positivos." << std::endl;
        return 1;
    }
    // Verificação de overflow para n * m
    if (n > 100 || m > 100) {
        std::cerr << "Erro: dimensões muito grandes. Por favor, informe números menores que 100." << std::endl;
        return 1;
    }

    // Alocando memória para matriz dinâmica
    int** matriz = new int*[n]; // cria array de ponteiros (linhas)

    // Alocando colunas para cada linha
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[m];
    }

    // Lendo valores para a matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << "Digite o valor para a posição [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }

    // Imprimindo a matriz
    std::cout << "\nImprimindo os elementos da matriz:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << "Elemento na posição [" << i << "][" << j << "]: " << matriz[i][j] << std::endl;
        }
    } // O(n * m)

    // Liberando memória alocada para cada linha
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }

    // Liberando o array de ponteiros (linhas)
    delete[] matriz;

    return 0;
}