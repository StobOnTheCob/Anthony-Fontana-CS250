#include "Athlete.h"

// Default constructor
Athlete::Athlete() : m_height(0), m_weight(0), m_gender('U') {}

// Parameterized constructor
Athlete::Athlete(int height, int weight, char gender)
    : m_height(height), m_weight(weight), m_gender(gender) {}

// Getter methods
int Athlete::getHeight() {
    return m_height;
}

int Athlete::getWeight() {
    return m_weight;
}

char Athlete::getGender() {
    return m_gender;
}

// Setter methods
void Athlete::setHeight(int height) {
    m_height = height;
}

void Athlete::setWeight(int weight) {
    m_weight = weight;
}

void Athlete::setGender(char gender) {
    m_gender = gender;
}
