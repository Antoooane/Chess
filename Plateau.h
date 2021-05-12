#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <vector>
#include <iostream>
#include "Piece.h"

class Plateau {

public:
    Plateau(bool normal=false);
    ~Plateau();
    void afficher_plateau(std::ostream& flux) const;
    bool deplacer_piece(Piece* piece, int nouv_x, int nouv_y, int joueur);
    Piece* recup_pointeur(int x, int y);
    bool pos_valide(Piece* piece, int x_f, int y_f, int joueur) const;
    int recup_nb_pieces();

private:
    std::vector<std::vector<Piece*>> m_pieces;
    int m_nb_pieces;

};

std::ostream& operator<<(std::ostream& flux, Plateau const& plateau);

#endif // PLATEAU_H_INCLUDED
