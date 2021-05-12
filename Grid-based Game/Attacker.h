#ifndef ATTACKER_H
#define ATTACKER_H

class Game;

class Attacker: public Monster
{
    private:
        void copy (const Attacker& original);
        void assignValue (const Position& position);
    
    public:
        Attacker ();
        Attacker (const Position& start);
        Attacker (const Attacker& original);
        virtual ~Attacker ();
        Attacker& operator= (const Attacker& original);
        virtual char getDisplayChar () const;
        virtual Monster* getClone () const;
        virtual Position calculateMove (const Game& game,
                                        const Position& player_Posiiton);
};

#endif
