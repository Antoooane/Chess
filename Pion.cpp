#include <string>
#include <cmath>
#include "Pion.h"
#include "Piece.h"
#include "Plateau.h"

using namespace std;

Pion::Pion(int x, int y, int joueur) : Piece(x,y,joueur) {}

string Pion::recup_nom() const {
    return "P";
}
