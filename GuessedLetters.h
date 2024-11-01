#ifndef GUESSEDLETTERS_H
#define GUESSEDLETTERS_H

#include <list>
#include <string>

class GuessedLetters {
private:
    std::list<char> m_guessed;

public:
    GuessedLetters(); // Constructor
    std::string getLetters(); // Return guessed letters as a string
    void addLetter(char letter); // Add a letter to the guessed letters list
};

#endif
