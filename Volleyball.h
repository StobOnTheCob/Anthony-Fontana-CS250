#ifndef VOLLEYBALL_H
#define VOLLEYBALL_H

#include <string>
#include "Athlete.h"

class VolleyBall : public Athlete {
private:
    std::string m_position;
    float m_reactionTime;

public:
    // Constructors
    VolleyBall();
    VolleyBall(std::string, float);

    // Getters
    std::string getPosition();
    float getReactionTime();

    // Setters
    void setPosition(std::string);
    void setReactionTime(float);
};

#endif
