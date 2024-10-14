#ifndef TENNIS_H
#define TENNIS_H

#include "Athlete.h"

class Tennis : public Athlete {
private:
    int m_serveSpeed;
    bool m_serveAndVolley;

public:
    // Constructors
    Tennis();
    Tennis(int, bool);

    // Getters
    int getServeSpeed();
    bool getServeAndVolley();

    // Setters
    void setServeSpeed(int);
    void setServeAndVolley(bool);
};

#endif
