#include <string>
#include "Fou.h"
#include "Piece.h"

using namespace std;

Fou::Fou(int x, int y, int joueur) : Piece(x,y,joueur) {}

string Fou::recup_nom() const {
    return "F";
}
