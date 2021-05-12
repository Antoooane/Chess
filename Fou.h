#ifndef FOU_H_INCLUDED
#define FOU_H_INCLUDED

#include <string>
#include "Piece.h"

class Fou: public Piece {
public:
    Fou(int x, int y, int joueur);
    virtual std::string recup_nom() const;
};

#endif // FOU_H_INCLUDED
