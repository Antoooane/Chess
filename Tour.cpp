#include <string>
#include "Tour.h"
#include "Piece.h"

using namespace std;

Tour::Tour(int x, int y, int joueur) : Piece(x,y,joueur) {}

/*bool Tour::pos_valide() const {

}*/

string Tour::recup_nom() const {
    return "T";
}
