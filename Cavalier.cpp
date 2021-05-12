#include <string>
#include "Cavalier.h"
#include "Piece.h"

using namespace std;

Cavalier::Cavalier(int x, int y, int joueur) : Piece(x,y,joueur) {}

string Cavalier::recup_nom() const {
    return "C";
}
