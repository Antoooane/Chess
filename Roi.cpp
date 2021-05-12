#include <string>
#include "Roi.h"
#include "Piece.h"

using namespace std;

Roi::Roi(int x, int y, int joueur) : Piece(x,y,joueur) {}

string Roi::recup_nom() const {
    return "R";
}
