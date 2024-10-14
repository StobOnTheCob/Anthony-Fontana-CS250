#include "Tennis.h"

// Default constructor
Tennis::Tennis() : m_serveSpeed(0), m_serveAndVolley(false) {}

// Parameterized constructor
Tennis::Tennis(int serveSpeed, bool serveAndVolley)
    : m_serveSpeed(serveSpeed), m_serveAndVolley(serveAndVolley) {}

// Getter methods
int Tennis::getServeSpeed() {
    return m_serveSpeed;
}

bool Tennis::getServeAndVolley() {
    return m_serveAndVolley;
}

// Setter methods
void Tennis::setServeSpeed(int serveSpeed) {
    m_serveSpeed = serveSpeed;
}

void Tennis::setServeAndVolley(bool serveAndVolley) {
    m_serveAndVolley = serveAndVolley;
}
