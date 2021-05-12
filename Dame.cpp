#include <string>
#include "Dame.h"
#include "Piece.h"

using namespace std;

Dame::Dame(int x, int y, int joueur) : Piece(x,y,joueur) {}

string Dame::recup_nom() const {
    return "D";
}
