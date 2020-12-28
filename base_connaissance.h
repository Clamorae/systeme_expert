#ifndef BASE_CONNAISSANCE_H
#define BASE_CONNAISSANCE_H


#include "definition.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


KB createbasis();
void addruletoBC(KB base);
Regle* firstRule(KB base);

#endif
