#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>
#include <list>

class GameState {
private:
    std::list<std::string> m_state;
    std::string m_allStates[7]; // Array to hold the different hangman states
    int m_nextState;

public:
    GameState();
    std::string getState();
    void addState();
    bool gameOver();
};

#endif
