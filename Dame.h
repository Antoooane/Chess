#ifndef DAME_H_INCLUDED
#define DAME_H_INCLUDED

#include <string>
#include "Piece.h"

class Dame: public Piece {
public:
    Dame(int x, int y, int joueur);
    virtual std::string recup_nom() const;
};

#endif // DAME_H_INCLUDED
