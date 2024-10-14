#include "Volleyball.h"
#include <string>

// Default constructor
VolleyBall::VolleyBall() : m_position("Unknown"), m_reactionTime(0.0) {}

// Parameterized constructor
VolleyBall::VolleyBall(std::string position, float reactionTime)
    : m_position(position), m_reactionTime(reactionTime) {}

// Getter methods
std::string VolleyBall::getPosition() {
    return m_position;
}

float VolleyBall::getReactionTime() {
    return m_reactionTime;
}

// Setter methods
void VolleyBall::setPosition(std::string position) {
    m_position = position;
}

void VolleyBall::setReactionTime(float reactionTime) {
    m_reactionTime = reactionTime;
}
