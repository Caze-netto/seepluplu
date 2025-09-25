#include <iostream>
#include <memory>
#include <vector>

int a = 10; // global inicializada → .data
int b;      // global não inicializada → .bss

int main() {
    int x = 10; // local → stack
    int z;      // local não inicializada → stack (valor lixo até inicializar)}

    // unique_ptr - único dono
    auto memory = std::make_unique<std::vector<int>>(); //heap
    memory->push_back(10);
    memory->push_back(20);
    std::cout << "Unique_ptr size: " << memory->size() << "\n";

    // shared_ptr - múltiplos donos
    auto shared1 = std::make_shared<std::vector<int>>(); //heap
    shared1->push_back(42);

    const auto& shared2 = shared1; // agora shared1 e shared2 compartilham o mesmo vector
    shared2->push_back(x);

    std::cout << "Shared_ptr size (shared1): " << shared1->size() << "\n";
    std::cout << "Shared_ptr size (shared2): " << shared2->size() << "\n";

    // shared_ptr vazio
    std::shared_ptr<std::vector<int>> emptyPtr; //heap
    if (!emptyPtr) {
        std::cout << "emptyPtr está vazio!\n";
    }
}