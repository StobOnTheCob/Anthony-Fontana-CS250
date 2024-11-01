#include "GuessedLetters.h"

GuessedLetters::GuessedLetters() {
    // Empty constructor, list starts empty
}

std::string GuessedLetters::getLetters() {
    std::string guessed;
    for (char c : m_guessed) {
        guessed += c;
        guessed += ' '; // Space between guessed letters
    }
    return guessed;
}

void GuessedLetters::addLetter(char letter) {
    m_guessed.push_back(letter);
}
