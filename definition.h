#ifndef DEFINITION_H
#define DEFINITION_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef char* Proposition;

typedef struct elP{
  Proposition proposition;
  struct elP* next;
}ElemPremisse;

typedef ElemPremisse* Premisse;

typedef struct rl{
  Premisse premisse;
  Proposition conclusion;
}Regle;

typedef struct bc{
  Regle* head;
  struct bc* next;
}ElemBC;

typedef ElemBC* KB;

Regle* createRule();

void addProp(Regle* rule, Proposition str);

int createConclusion(Regle* rule);

int testProp(Premisse rulePrem, Proposition prop);

int isPremisseEmpty(Regle rule);

Premisse deleteProp(Premisse head, Proposition prop);

int isNULL(Premisse head);

Premisse PremisseHead(Regle* rule);

Proposition RuleConclusion(Regle* rule);

#endif
