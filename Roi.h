#ifndef ROI_H_INCLUDED
#define ROI_H_INCLUDED

#include <string>
#include "Piece.h"

class Roi: public Piece {
public:
    Roi(int x, int y, int joueur);
    virtual std::string recup_nom() const;
};

#endif // ROI_H_INCLUDED
