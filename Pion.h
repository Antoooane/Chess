#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

#include <string>
#include "Piece.h"

class Pion: public Piece {
public:
    Pion(int x, int y, int joueur);
    /*virtual bool pos_valide(int x, int y) const;*/
    virtual std::string recup_nom() const;
};

#endif // PION_H_INCLUDED

