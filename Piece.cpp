#include "Piece.h"
#include <string>

using namespace std;

Piece::Piece(int x, int y, int joueur) {
    m_x=x;
    m_y=y;
    nb_coups=0;
    m_joueur=joueur;
}

bool Piece::def_position(int x, int y) {
    if (pos_valide(x,y)) {
        m_x=x;
        m_y=y;
        nb_coups++;
        return true;
    } else {
        return false;
    }

}

int Piece::recup_coups() const {
    return nb_coups;
}

int Piece::recup_position_x() const {
    return m_x;
}

int Piece::recup_position_y() const {
    return m_y;
}

int Piece::recup_joueur() const {
    return m_joueur;
}

bool Piece::pos_valide(int x, int y) const {
    if ((x==m_x && y==m_y) || !((x>=0 && x<=7) && (y>=0 && y<=7))) {
        return false;
    } else {
        return true;
    }
}
