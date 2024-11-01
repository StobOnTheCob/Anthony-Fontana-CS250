#include "Word.h"

Word::Word(std::string word) : m_word(word) {
    for (char c : word) {
        if (c == ' ') {
            m_currentWord.push_back(' '); // Add space if there's a space in the word
        } else {
            m_currentWord.push_back('_'); // Otherwise add an underscore
        }
    }
}

std::string Word::getWord() {
    std::string current;
    for (char c : m_currentWord) {
        current += c;
    }
    return current;
}

void Word::addLetter(char letter) {
    auto wordIt = m_word.begin();
    auto currentIt = m_currentWord.begin();

    while (wordIt != m_word.end()) {
        if (*wordIt == letter) {
            *currentIt = letter; // Replace underscore with letter
        }
        ++wordIt;
        ++currentIt;
    }
}

bool Word::findLetter(char letter) {
    return m_word.find(letter) != std::string::npos;
}

bool Word::solved() {
    for (char c : m_currentWord) {
        if (c == '_') {
            return false; // Still unguessed letters
        }
    }
    return true;
}
