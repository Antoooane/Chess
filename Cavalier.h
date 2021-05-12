#ifndef CAVALIER_H_INCLUDED
#define CAVALIER_H_INCLUDED

#include <string>
#include "Piece.h"

class Cavalier: public Piece {
public:
    Cavalier(int x, int y, int joueur);
    virtual std::string recup_nom() const;
};

#endif // CAVALIER_H_INCLUDED
