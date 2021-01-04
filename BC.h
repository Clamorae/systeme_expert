#ifndef BC_H
#define BC_H

#include "main.h"
#include "base_connaissance.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


KB createbasis();
// fonction qui va créer une base de connaissance et renvoyer le pointeur vers cette base

Regle* firstRule(KB base);
// focntion renvoyant la premiere règle d'une base de connaissance(prise en entrée)

void afficheBC(KB BC);
// la fonction va parcourir toute la prémisse de la base de connaissance fourni en entrée pour écrire chacuen des propositions puis écrire une flchez et la conclusion

KB menuBC(KB BC,Premisse BF);
//cette fonction va prendre en entrée la base de connaissance et la base et permet de modifier et d'accèder à la base de connaissances

void addruletoBC(KB base);
int deleteRule(KB* BC, int i);
int saveBCtoFile(KB BC);


#endif
