#ifndef BASE_CONNAISSANCE_H
#define BASE_CONNAISSANCE_H


#include "definition.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


KB createbasis();
// fonction qui va créer une base de connaissance et renvoyer le pointeur vers cette base

Regle* firstRule(KB base);
// focntion renvoyant la premiere règle d'une base de connaissance(prise en entrée)

#endif