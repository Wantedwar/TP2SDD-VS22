//
// Created by jser on 17/03/2022.
//

#ifndef TP2_SDD_NOEUD_H
#define TP2_SDD_NOEUD_H
#include <iostream>
#include <string>
#include "uniqueID.h"
#include <random>
#include "utils.h"

using std::string;
using std::cout;

struct noeud {

    const uniqueID uid;
    //char chromocell[4][2]; //à faire genre bientôt
    int colorcell[3];
    struct noeud* gauche;
    struct noeud* droite;

    noeud();
    noeud(int* colorcell[3]);
    noeud(int R, int G, int B);
    noeud(int cell, char* chromocell[4][2], int* colorcell[3]);

    noeud* operator+(const noeud& n1);

};


//const string affichenoeud(noeud temp);

std::ostream& operator<<(std::ostream& retour, noeud& temp);
noeud operator+(const noeud& n1);

//ajouter constructeurs et destructeurs
//ajouter fonctions de lecture


#endif //TP2_SDD_NOEUD_H
