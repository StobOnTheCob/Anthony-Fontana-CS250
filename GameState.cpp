#include "GameState.h"

GameState::GameState() : m_nextState(0) {
    // Initialize the list of game states
    m_allStates[0] = "PLATFORM\n"
        "     _______\n"
        "    |       |\n"
        "    |\n"
        "    |\n"
        "    |\n"
        "    |\n";

    m_allStates[1] = "HEAD\n"
        "     _______\n"
        "    |       |\n"
        "    |       O\n"
        "    |\n"
        "    |\n"
        "    |\n";

    m_allStates[2] = "BODY\n"
        "     _______\n"
        "    |       |\n"
        "    |       O\n"
        "    |       |\n"
        "    |\n"
        "    |\n";

    m_allStates[3] = "LEFT_ARM\n"
        "     _______\n"
        "    |       |\n"
        "    |       O\n"
        "    |      /|\n"
        "    |\n"
        "    |\n";

    m_allStates[4] = "RIGHT_ARM\n"
        "     _______\n"
        "    |       |\n"
        "    |       O\n"
        "    |      /|\\\n"
        "    |\n"
        "    |\n";

    m_allStates[5] = "LEFT_LEG\n"
        "     _______\n"
        "    |       |\n"
        "    |       O\n"
        "    |      /|\\\n"
        "    |      /\n"
        "    |\n";

    m_allStates[6] = "RIGHT_LEG\n"
        "     _______\n"
        "    |       |\n"
        "    |       O\n"
        "    |      /|\\\n"
        "    |      / \\\n"
        "    |\n";
}

std::string GameState::getState() {
    if (m_state.empty()) {
        return "No state yet"; // In case no state has been added
    }
    return m_state.back(); // Return only the latest state
}

void GameState::addState() {
    if (m_nextState < 7) {
        m_state.push_back(m_allStates[m_nextState]);
        m_nextState++;
    }
}

bool GameState::gameOver() {
    return m_nextState == 7; // Game over if all states are used
}
