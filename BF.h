#ifndef BF_H
#define BF_H

#include "main.h"
#include "base_connaissance.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void addBF(KB BC,Premisse* BF);
// cette fonction va prendre en entrée la base de connaissance et la base de fait pour que l'utilsateur puisse ajouter de nouvelles proposition à la base de fait

void afficheBF(KB BC,Premisse BF);
//cette fonction va parcourir la base de faits pour acchicher chacune des propositions qui la compose les une après les autres

int menuBF(KB BC,Premisse BF);
//cette fonction est appelée depuis le menu et permet à l'utilisateur d'effectuer chacune des actions utiles en rapport avec la base de fait ou de lancer le moteru d'inférence


#endif
