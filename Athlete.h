#ifndef ATHLETE_H
#define ATHLETE_H

class Athlete {
protected:
    int m_height;
    int m_weight;
    char m_gender;

public:
    // Constructors
    Athlete();
    Athlete(int, int, char);

    // Getters
    int getHeight();
    int getWeight();
    char getGender();

    // Setters
    void setHeight(int);
    void setWeight(int);
    void setGender(char);
};

#endif
