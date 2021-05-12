#ifndef TOUR_H_INCLUDED
#define TOUR_H_INCLUDED

#include <string>
#include "Piece.h"

class Tour: public Piece {
public:
    Tour(int x, int y, int joueur);
    /*virtual pos_valide() const;*/
    virtual std::string recup_nom() const;
};

#endif // TOUR_H_INCLUDED
