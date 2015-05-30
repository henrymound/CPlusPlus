#ifndef _PRIVATE_CRITTER_H
#define _PRIVATE_CRITTER_H

class Critter
{
public:            // begin public section
    Critter(int hunger = 0);
    int GetHunger() const; 
    void SetHunger(int hunger);
    
private:           // begin private section
    int m_Hunger;
};

#endif
