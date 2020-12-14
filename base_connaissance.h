#include"definition.h"

typedef struct bc{
  Regle head;
  struct bc* next;
}ElemBC;

typedef ElemBC* BC;

KB createbasis();
void addRule(Regle rule,KB base);
Regle firstRule(KB base);
