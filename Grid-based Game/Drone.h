#ifndef DRONE_H
#define DRONE_H

class Game;

class Drone: public Monster
{
    private:
        int direction;
        void copy (const Drone& original);
        void assignValue (const Position& position);
    
    public:
        Drone ();
        Drone (const Position& start);
        Drone (const Drone& original);
        virtual ~Drone ();
        Drone& operator= (const Drone& original);
        virtual char getDisplayChar () const;
        virtual Monster* getClone () const;
        virtual Position calculateMove (const Game& game,
                                        const Position& player_Posiiton);
};

#endif
