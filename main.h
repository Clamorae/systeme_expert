#ifndef MAIN_H
#define MAIN_H

#include "base_connaissance.h"
#include "BC.h"
#include "BF.h"
#include <stdio.h>
#include <stdlib.h>

void menu(KB BC,Premisse BF);
// Le menu va permettre à l'utilisateur de naviguer à travers les différentes fonctions du programme en lui affichant un menu et lui permettant de choisir quelle fonction appeler.

int main();
// le main est la premiere fonction à se lancer elle inialise les deux base(de fait et de connaissances) puis appelle menu

#endif