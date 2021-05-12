#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <string>

class Piece {
public:
    Piece(int x, int y, int joueur);
    int recup_position_x() const;
    int recup_position_y() const;
    int recup_coups() const;
    int recup_joueur() const;
    bool def_position(int x, int y);
    virtual bool pos_valide(int x, int y) const;
    virtual std::string recup_nom() const = 0;

private:
    int m_x;
    int m_y;
    int nb_coups;
    int m_joueur;

};

/*class Pion: public Piece {
public:
    Pion();
    Pion(int x, int y);
};

class Tour: public Piece {

};

class Cavalier: public Piece {

};

class Fou: public Piece {

};

class Dame: public Piece {

};

class Roi: public Piece {

};*/

#endif // PIECE_H_INCLUDED
