#ifndef SENTRY_H
#define SENTRY_H

class Game;

class Sentry: public Monster
{
    private:
        Position start_position;
        void copy (const Sentry& original);
        void assignValue (const Position& position);
    
    public:
        Sentry ();
        Sentry (const Position& start);
        Sentry (const Sentry& original);
        virtual ~Sentry ();
        Sentry& operator= (const Sentry& original);
        virtual char getDisplayChar () const;
        virtual Monster* getClone () const;
        virtual Position calculateMove (const Game& game,
                                        const Position& player_Posiiton);
};

#endif
