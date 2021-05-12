#include "Plateau.h"
#include "Piece.h"
#include "Pion.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Dame.h"
#include "Roi.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

Plateau::Plateau(bool normal) { // Crée le plateau de jeu
    m_pieces = vector<vector<Piece*>>(8, vector<Piece*>(8,NULL));
    if (normal) {

        //Joueur 0
        m_pieces[0][0]=new Tour(0,0, 0);
        m_pieces[1][0]=new Cavalier(1,0, 0);
        m_pieces[2][0]=new Fou(2,0,0);
        m_pieces[3][0]=new Dame(3,0, 0);
        m_pieces[4][0]=new Roi(4,0,0);
        m_pieces[5][0]=new Fou(5,0,0);
        m_pieces[6][0]=new Cavalier(6,0,0);
        m_pieces[7][0]=new Tour(7,0,0);
        m_pieces[0][1]=new Pion(0,1,0);
        m_pieces[1][1]=new Pion(1,1,0);
        m_pieces[2][1]=new Pion(2,1,0);
        m_pieces[3][1]=new Pion(3,1,0);
        m_pieces[4][1]=new Pion(4,1,0);
        m_pieces[5][1]=new Pion(5,1,0);
        m_pieces[6][1]=new Pion(6,1,0);
        m_pieces[7][1]=new Pion(7,1,0);

        // Joueur 1
        m_pieces[0][7]=new Tour(0,7, 1);
        m_pieces[1][7]=new Cavalier(1,7, 1);
        m_pieces[2][7]=new Fou(2,7,1);
        m_pieces[3][7]=new Dame(3,7, 1);
        m_pieces[4][7]=new Roi(4,7,1);
        m_pieces[5][7]=new Fou(5,7,1);
        m_pieces[6][7]=new Cavalier(6,7,1);
        m_pieces[7][7]=new Tour(7,7,1);
        m_pieces[0][6]=new Pion(0,6,1);
        m_pieces[1][6]=new Pion(1,6,1);
        m_pieces[2][6]=new Pion(2,6,1);
        m_pieces[3][6]=new Pion(3,6,1);
        m_pieces[4][6]=new Pion(4,6,1);
        m_pieces[5][6]=new Pion(5,6,1);
        m_pieces[6][6]=new Pion(6,6,1);
        m_pieces[7][6]=new Pion(7,6,1);
    }
    recup_nb_pieces();
}

Plateau::~Plateau() {
    for (unsigned int i=0;i<m_pieces.size();i++) {
        for (unsigned int j=0;j<m_pieces[i].size();j++) {
            delete m_pieces[i][j];
            m_pieces[i][j]=NULL;
        }
    }
}

int Plateau::recup_nb_pieces() {
    m_nb_pieces=0;
    for (unsigned int i=0;i<m_pieces.size();i++) {
        for (unsigned int j=0;j<m_pieces[i].size();j++) {
            if (m_pieces[i][j]!=0) {
                m_nb_pieces++;
            }
        }
    }
    return m_nb_pieces;
}

void Plateau::afficher_plateau(ostream& flux) const { //Injecte l'affichage du plateau dans un flux sortant pour l'afficher à l'aider d'un simple "cout"
    flux << "   ┌───┬───┬───┬───┬───┬───┬───┬───┐ " << endl;
    for (unsigned int i=0;i<m_pieces.size();i++) {
        flux << " " << 7-i << " │ ";
        for (unsigned int j=0;j<m_pieces[7-i].size();j++) {
            if (m_pieces[j][7-i]==0) {
                flux << "  │ ";
            } else {
                if (m_pieces[j][7-i]->recup_joueur()==0) {
                    flux << "\033[1;31m" << m_pieces[j][7-i]->recup_nom() << "\033[0m" << " │ ";
                } else {
                    flux << "\033[1;32m" << m_pieces[j][7-i]->recup_nom() << "\033[0m" << " │ ";
                }
            }
        }
        if (i==7) {
            flux << endl << "   └───┴───┴───┴───┴───┴───┴───┴───┘ " << endl;
            flux << "     A   B   C   D   E   F   G   H   ";
        } else {
            flux << endl << "   ├───┼───┼───┼───┼───┼───┼───┼───┤ " << endl;
        }

    }
}

ostream& operator<<(ostream& flux, Plateau const& plateau) {
    plateau.afficher_plateau(flux);
    return flux;
}

Piece* Plateau::recup_pointeur(int x, int y) {
    return m_pieces[x][y];
}

bool Plateau::pos_valide(Piece* ppiece, int x_f, int y_f, int joueur) const { //Teste si la pièce sélectionnée peu se déplacer ) l'emplacement indiqué
    if (ppiece==NULL) {
        return false;
    }

    Piece &piece = *ppiece;
    if (!((x_f>=0 && x_f<=7 && y_f>=0 && y_f<=7) && ((m_pieces[x_f][y_f]!=0 && m_pieces[x_f][y_f]->recup_joueur()!=piece.recup_joueur()) || m_pieces[x_f][y_f]==NULL) && piece.recup_joueur()==joueur)) {
        return false;
    }
    if (piece.recup_nom()=="P") { /* Test si la position est valide pour un pion */
        return (((((y_f==piece.recup_position_y()+1 || (y_f==piece.recup_position_y()+2 && piece.recup_coups()==0)) && x_f==piece.recup_position_x() && m_pieces[x_f][y_f]==NULL) || (m_pieces[x_f][y_f]!=NULL && x_f==piece.recup_position_x()+1 && y_f==piece.recup_position_y()+1 && !(m_pieces[x_f][y_f]->recup_joueur()==piece.recup_joueur())) || (m_pieces[x_f][y_f]!=0 && x_f==piece.recup_position_x()-1 && y_f==piece.recup_position_y()+1 && !(m_pieces[x_f][y_f]->recup_joueur()==piece.recup_joueur()))) && piece.recup_joueur()==0) || ((((y_f==piece.recup_position_y()-1 || (y_f==piece.recup_position_y()-2 && piece.recup_coups()==0)) && x_f==piece.recup_position_x() && m_pieces[x_f][y_f]==NULL) || (m_pieces[x_f][y_f]!=0 && x_f==piece.recup_position_x()+1 && y_f==piece.recup_position_y()-1 && !(m_pieces[x_f][y_f]->recup_joueur()==piece.recup_joueur())) || (m_pieces[x_f][y_f]!=NULL && x_f==piece.recup_position_x()-1 && y_f==piece.recup_position_y()-1 && !(m_pieces[x_f][y_f]->recup_joueur()==piece.recup_joueur()))) && piece.recup_joueur()==1));
    
    } else if (piece.recup_nom()=="T") { /* Test si la position est valide pour une tour */
        if ((x_f == piece.recup_position_x() && y_f != piece.recup_position_y()) || (x_f != piece.recup_position_x() && y_f == piece.recup_position_y())) {
            if ((x_f == piece.recup_position_x() && y_f != piece.recup_position_y()) || (x_f != piece.recup_position_x() && y_f == piece.recup_position_y())) {
                if (x_f != piece.recup_position_x()) {
                    if (x_f < piece.recup_position_x()) {
                        for (int i = x_f + 1; i < piece.recup_position_x(); i++) {
                            if (m_pieces[i][piece.recup_position_y()] != NULL) {
                                return false;
                            }
                        }
                    }
                    else if (x_f > piece.recup_position_x()) {
                        for (int i = x_f - 1; i > piece.recup_position_x(); i--) {
                            if (m_pieces[i][piece.recup_position_y()] != NULL) {
                                return false;
                            }
                        }
                    }
                }
                else {
                    if (y_f < piece.recup_position_y()) {
                        for (int i = y_f + 1; i < piece.recup_position_y(); i++) {
                            if (m_pieces[piece.recup_position_x()][i] != NULL) {
                                return false;
                            }
                        }
                    }
                    else if (y_f > piece.recup_position_y()) {
                        for (int i = y_f - 1; i > piece.recup_position_y(); i--) {
                            if (m_pieces[piece.recup_position_x()][i] != NULL) {
                                return false;
                            }
                        }
                    }
                }
            }
        } else {
            return false;
         }

    } else if (piece.recup_nom()=="C") { /* Test si la position est valide pour un cavalier */
        return (((x_f==piece.recup_position_x()-1 && y_f==piece.recup_position_y()-2) || (x_f==piece.recup_position_x()+1 && y_f==piece.recup_position_y()-2) || (x_f==piece.recup_position_x()+2 && y_f==piece.recup_position_y()-1) || (x_f==piece.recup_position_x()+2 && y_f==piece.recup_position_y()+1) || (x_f==piece.recup_position_x()+1 && y_f==piece.recup_position_y()+2) || (x_f==piece.recup_position_x()-1 && y_f==piece.recup_position_y()+2) || (x_f==piece.recup_position_x()-2 && y_f==piece.recup_position_y()+1) || (x_f==piece.recup_position_x()-2 && y_f==piece.recup_position_y()-1)) && (m_pieces[x_f][y_f]==0 || m_pieces[x_f][y_f]->recup_joueur()!=piece.recup_joueur()));
    
    } else if (piece.recup_nom()=="F") { /* Test si la position est valide pour un fou */
        if (abs(x_f-piece.recup_position_x())==abs(y_f-piece.recup_position_y())) {
            if (x_f>piece.recup_position_x() && y_f>piece.recup_position_y()) {
                for (int i=-1;i>piece.recup_position_x()-x_f;i--) {
                    if (m_pieces[x_f+i][y_f+i]!=NULL) {
                        return false;
                    }
                }
            } else if (x_f>piece.recup_position_x() && y_f<piece.recup_position_y()) {
                for (int i=-1;i>piece.recup_position_x()-x_f;i--) {
                    if (m_pieces[x_f+i][y_f-i]!=NULL) {
                        return false;
                    }
                }
            } else if (x_f<piece.recup_position_x() && y_f>piece.recup_position_y()) {
                for (int i=1;i<piece.recup_position_x()-x_f;i++) {
                    if (m_pieces[x_f+i][y_f-i]!=NULL) {
                        return false;
                    }
                }
            } else if (x_f<piece.recup_position_x() && y_f<piece.recup_position_y()) {
                for (int i=1;i<piece.recup_position_x()-x_f;i++) {
                    if (m_pieces[x_f-i][y_f-i]!=NULL) {
                        return false;
                    }
                }
            }
            return true;
        } else {
            return false;
        }

    } else if (piece.recup_nom()=="D") {
        if (abs(x_f-piece.recup_position_x())==abs(y_f-piece.recup_position_y())) {
            if (x_f>piece.recup_position_x() && y_f>piece.recup_position_y()) {
                for (int i=-1;i>piece.recup_position_x()-x_f;i--) {
                    if (m_pieces[x_f+i][y_f+i]!=NULL) {
                        return false;
                    }
                }
            } else if (x_f>piece.recup_position_x() && y_f<piece.recup_position_y()) {
                for (int i=-1;i>piece.recup_position_x()-x_f;i--) {
                    if (m_pieces[x_f+i][y_f-i]!=NULL) {
                        return false;
                    }
                }
            } else if (x_f<piece.recup_position_x() && y_f>piece.recup_position_y()) {
                for (int i=1;i<piece.recup_position_x()-x_f;i++) {
                    if (m_pieces[x_f+i][y_f-i]!=NULL) {
                        return false;
                    }
                }
            } else if (x_f<piece.recup_position_x() && y_f<piece.recup_position_y()) {
                for (int i=1;i<piece.recup_position_x()-x_f;i++) {
                    if (m_pieces[x_f-i][y_f-i]!=NULL) {
                        return false;
                    }
                }
            }
        } else if ((x_f==piece.recup_position_x() && y_f!=piece.recup_position_y()) || (x_f!=piece.recup_position_x() && y_f==piece.recup_position_y())) {
            if (x_f!=piece.recup_position_x()) {
                if (x_f<piece.recup_position_x()) {
                    for (int i = x_f + 1; i < piece.recup_position_x(); i++) {
                        if (m_pieces[i][piece.recup_position_y()] != NULL) {
                            return false;
                        }
                    }
                }
                else if (x_f > piece.recup_position_x()) {
                    for (int i = x_f - 1; i > piece.recup_position_x(); i--) {
                        if (m_pieces[i][piece.recup_position_y()] != NULL) {
                            return false;
                        }
                    }
                }
            } else {
                if (y_f < piece.recup_position_y()) {
                    for (int i = y_f + 1; i < piece.recup_position_y(); i++) {
                        if (m_pieces[piece.recup_position_x()][i] != NULL) {
                            return false;
                        }
                    }
                }
                else if (y_f > piece.recup_position_y()) {
                    for (int i = y_f - 1; i > piece.recup_position_y(); i--) {
                        if (m_pieces[piece.recup_position_x()][i] != NULL) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;

    } else if (piece.recup_nom()=="R") { /*Test si la position est valide pour un roi */
        return ((x_f==piece.recup_position_x() && y_f==piece.recup_position_y()+1) || (x_f==piece.recup_position_x()+1 && y_f==piece.recup_position_y()+1) || (x_f==piece.recup_position_x()+1 && y_f==piece.recup_position_y()) || (x_f==piece.recup_position_x()+1 && y_f==piece.recup_position_y()-1) || (x_f==piece.recup_position_x() && y_f==piece.recup_position_y()-1) || (x_f==piece.recup_position_x()-1 && y_f==piece.recup_position_y()-1) || (x_f==piece.recup_position_x()-1 && y_f==piece.recup_position_y()) || (x_f==piece.recup_position_x()-1 && y_f==piece.recup_position_y()+1));
    } else {
        return false;
    }
}

bool Plateau::deplacer_piece(Piece* piece, int nouv_x, int nouv_y, int joueur) {
    int x,y;
    if (!pos_valide(piece, nouv_x, nouv_y, joueur)) {
        return false;
    } else {
        if (m_pieces[nouv_x][nouv_y]!=NULL) {
            delete m_pieces[nouv_x][nouv_y];
        }
        x=piece->recup_position_x();
        y=piece->recup_position_y();
        piece->def_position(nouv_x, nouv_y);
        m_pieces[nouv_x][nouv_y]=piece;
        m_pieces[x][y]=0;
        if ((joueur == 0 && nouv_y == 7) || (joueur == 1 && nouv_y == 0)) {
            delete m_pieces[nouv_x][nouv_y];
            m_pieces[nouv_x][nouv_y] = new Dame(nouv_x, nouv_y, joueur);
        }
        return true;
    }
}
