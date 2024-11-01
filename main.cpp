#include <iostream>
#include <cctype> // For toupper
#include "Word.h"
#include "GuessedLetters.h"
#include "GameState.h"
using namespace std;

int main()
{
    string wordToGuess;
    cout << "Enter the word to guess: ";
    cin >> wordToGuess;

    // Convert the given word to uppercase
    for (char& c : wordToGuess) {
        c = toupper(c);
    }

    Word word(wordToGuess);
    GuessedLetters guessed = GuessedLetters();
    GameState state = GameState();
    char letter;

    do {
       cout << "Game state: " << state.getState() << endl;
       cout << "Guessed letters: " << guessed.getLetters() << endl;
       cout << "Guess this word: " << word.getWord() << endl << endl;
       cout << "Guess a letter: ";
       cin >> letter;
       letter = toupper(letter); // Convert the guessed letter to uppercase

       if (word.findLetter(letter)) {
          word.addLetter(letter);
       }
       else {
          guessed.addLetter(letter);
          state.addState();
       }

    } while ( (!state.gameOver()) && (!word.solved()) );

    if (state.gameOver()) {
       cout << endl << "Game state: " << state.getState() << endl;
       cout << "Sorry you lose"  << endl;
       cout << "The word was: " << wordToGuess << endl; // Display the correct word
    }
    else {
        cout << endl << "Congratulations, you guessed the word: " <<  word.getWord() << endl;
    }

    return 0;
}
