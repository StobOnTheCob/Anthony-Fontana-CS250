#ifndef WORD_H
#define WORD_H

#include <list>
#include <string>

class Word {
private:
    std::list<char> m_currentWord;
    std::string m_word;

public:
    Word(std::string word); // Constructor
    std::string getWord();  // Return current word as a string
    void addLetter(char letter); // Replace underscores with the guessed letter
    bool findLetter(char letter); // Check if letter exists in the word
    bool solved(); // Return if the word is fully guessed
};

#endif
