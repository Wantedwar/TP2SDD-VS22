//
// Created by jser on 17/03/2022.
//

#include "noeud.h"


noeud::noeud()
{
    std::cout << "noeud cree : " << uid.id << std::endl;
    colorcell[0] = getrn();
    colorcell[1] = getrn();
    colorcell[2] = getrn();
    droite = nullptr;
    gauche = nullptr;
}

noeud::noeud(int R, int G, int B) { //azy j'ai la flemme de commencer le bonus
    //note, faudra sans doute modifier le truc pour que les enfants soient à la racine
    std::cout << "noeud cree : " << uid.id << std::endl;


    this->colorcell[0] = R;
    this->colorcell[1] = G;
    this->colorcell[2] = B;

    droite = nullptr;
    gauche = nullptr;
}



noeud::noeud(int cell, char* chromocell[4][2], int* colorcell[3]) { //créé la racine je sais pas ce que je fait
    //this->cell = cell;
    //code basique, ptet ajouter de la récurrence


    /*for (int i = 0; i < 4; i++) {
        this->chromocell[i][0] = *chromocell[i][0];
        this->chromocell[i][1] = *chromocell[i][1];
    }*/

    for (int i = 0; i < 3; i++)
        this->colorcell[i] = *colorcell[i];

    droite = nullptr;
    gauche = nullptr;

}

std::ostream& operator<< (std::ostream& retour, noeud& temp)
{

    for (int i = 0; i < 3; i++)
        retour << std::to_string(temp.colorcell[i]) + " ";
    //std::cout << std::to_string(temp.colorcell[i]) << std::endl;
    retour << "\n";

    //pas nécessaire car on est toujours censé avoir deux parents
    if (temp.droite != nullptr) {   //mesure temporaire, plus pour empécher les bugs pendant le dev
        retour << std::to_string(temp.droite->uid.id);
    }
    else
    {
        retour << "pas d'enfant droite (ou parents jsp)\n";
    }
    if (temp.gauche != nullptr) {   //mesure temporaire, plus pour empécher les bugs pendant le dev
        retour << std::to_string(temp.gauche->uid.id);
    }
    else
    {
        retour << "pas d'enfant gauche (ou parents jsp)\n";
    }

    return retour;
}



noeud* noeud::operator+(const noeud& n1)
{
    int r, g, b;

    //copier calculs
    r = (colorcell[0] + n1.colorcell[0]) / 2;
    g = (colorcell[1] + n1.colorcell[1]) / 2;
    b = (colorcell[2] + n1.colorcell[2]) / 2;
    return new noeud(r,g,b);

    //ou
    //return new noeud(((colorcell[0] + n1.colorcell[0]) / 2), ((colorcell[1] + n1.colorcell[1]) / 2), ((colorcell[2] + n1.colorcell[2]) / 2));
}

/*
const string affichenoeud(noeud temp) //plus utile après surcharge mais fallback au cas où
{
    string retour;

    for (int i = 0; i < 3; i++)
        retour += std::to_string(temp.colorcell[i]) + " ";
        //std::cout << std::to_string(temp.colorcell[i]) << std::endl;
    retour += "\n";

    //pas nécessaire car on est toujours censé avoir deux parents
    if (temp.droite != nullptr) {   //mesure temporaire, plus pour empécher les bugs pendant le dev
        retour += std::to_string(temp.droite->uid.id);
    }
    else
    {
        retour += "pas d'enfant droite (ou parents jsp)\n";
    }
    if (temp.gauche != nullptr) {   //mesure temporaire, plus pour empécher les bugs pendant le dev
        retour += std::to_string(temp.gauche->uid.id);
    }
    else
    {
        retour += "pas d'enfant gauche (ou parents jsp)\n";
    }


    return retour;
}
*/