#include <iostream>
#include "Plateau.h"
#include "Piece.h"
#include "Tour.h"

using namespace std;

int coords_lettre(string lettre);

int main()

{
    string commande = "chcp 65001";
    const char *command = commande.c_str();
    system(command);
    int i=0;
    int y, nouv_y;
    string x, nouv_x;
    Plateau echiquier(true);
    cout << echiquier << endl;
    Piece* test;
    while (echiquier.recup_nb_pieces()>1) {
        cout << "Joueur " << i%2 << endl;
        do {
            cout << "Entrez les coordonnees de la piece à deplacer : ";
            cin >> x >> y;
            cout << "Entrez les coordonnees d'arrivee : ";
            cin >> nouv_x >> nouv_y;
            test = echiquier.recup_pointeur(coords_lettre(x),y);
        } while (!(echiquier.deplacer_piece(test, coords_lettre(nouv_x), nouv_y, i % 2)));
        cout << echiquier << endl;
        i++;
    }
    return 0;
}

int coords_lettre(string lettre) {
    if (lettre=="A" || lettre=="a") {
        return 0;
    } else if (lettre=="B" || lettre=="b") {
        return 1;
    } else if (lettre=="C" || lettre=="c") {
        return 2;
    } else if (lettre=="D" || lettre=="d") {
        return 3;
    } else if (lettre=="E" || lettre=="e") {
        return 4;
    } else if (lettre=="F" || lettre=="f") {
        return 5;
    } else if (lettre=="G" || lettre=="g") {
        return 6;
    } else if (lettre=="H" || lettre=="h") {
        return 7;
    } else {
        return 8;
    }
}
