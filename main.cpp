/*
  10/15/2024
  Dr.V
  CS 250
  Author: Anthony Fontana

  Description: This program consists of 3 header files for each class
  and 3 cpp files for each class as well. It all gets put together in
  the main.cpp file. It represents an athlete system with 2 separate
  sports that the athlete can be apart of.

*/
#include <iostream>
#include "Athlete.h"
#include "Volleyball.h"
#include "Tennis.h"

using namespace std;

// Test code given

int main()
{
    Athlete sport(72, 140, 'M');
    cout << "Athlete: " << sport.getHeight() << " "
         << sport.getWeight() << " "
         << sport.getGender() << endl;

    Tennis martina = Tennis();
    martina.setServeSpeed(100);
    martina.setGender('F');
    Tennis bjorn(150, false);
    bjorn.setGender('M');
    if (martina.getGender() == 'F') {
        cout << "Martina serve speed: " << martina.getServeSpeed() << endl;
    }

    VolleyBall kerri = VolleyBall();
    kerri.setGender('F');
    kerri.setPosition("Opposite Hitter");
    VolleyBall giba("Outside Hitter", 23.2);
    giba.setGender('M');
    if (kerri.getGender() == 'F') {
        cout << "Kerri is an " << kerri.getPosition() << endl;
    }

    return 0;
}
