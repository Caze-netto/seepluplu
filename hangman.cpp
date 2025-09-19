#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    auto* word = new std::string;
    auto* letter = new char;
    int tentativas = 0;
    int maxTentativas = 6;

    std::cout << "Give me a word to guess: ";
    std::cin >> *word;

    std::unordered_map<std::string, std::string> word_to_guess;
    word_to_guess["word"] = *word;
    word_to_guess["guess"] = std::string(word->size(), '_');

    std::cout << "<===============================>" << std::endl;


    while (tentativas < maxTentativas && word_to_guess["guess"] != word_to_guess["word"]) {
        std::cout << "Current word: " << word_to_guess["guess"] << std::endl;
        std::cout << "Give me a letter to guess: ";
        std::cin >> *letter;

        bool found = false;
        for (size_t i = 0; i < word->size(); i++) {
            if ((*word)[i] == *letter) {
                word_to_guess["guess"][i] = *letter;
                found = true;
            }
        }

        if (!found) {
            tentativas++;
            std::cout << "Wrong guess! Attempts left: " << (maxTentativas - tentativas) << std::endl;
        }

        std::cout << std::endl;
    }

    if (word_to_guess["guess"] == word_to_guess["word"]) {
        std::cout << "You guessed the word: " << word_to_guess["word"] << "!" << std::endl;
    } else {
        std::cout << "Game over! The word was: " << word_to_guess["word"] << std::endl;
    }

    delete word;
    delete letter;

    return 0;
}
