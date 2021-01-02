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
//crée une nouvelle régle et le pointeur qui lui est associé puis renvoie le pointeur 

void addProp(Premisse* bf, Proposition str);
//Prend en argument une prémisse et une proposition puis parcours la premisse pour ajouter la propositio nen queue dans un nouvel élément

int createConclusion(Regle* rule);
// prend en entré le pointeur vers une règle et va crée une conclusion puis l'attribuer à cette règle

int testProp(Premisse rulePrem, Proposition prop);
//la fonction va prendre en entré une prémisse et une proposition puis parcourir la prémisse pour chercher si la proposition ets dans la prémisse, la fonction va renvoyer 1 si elle y est et 0 si elle n'y est pas

int isPremisseEmpty(Regle rule);
//prend une régle en entré et renvoie 1 si sa prémisse est vide et 0 si elle ne l'est pas

Premisse deleteProp(Premisse head, Proposition prop);


int isNULL(Premisse head);
//prend une prémisse en entré et renvoie 1 si elle est vide et 0 si elle ne l'est pas

Premisse PremisseHead(Regle* rule);
//Prend une règle en entré et renvoie le pointeur vers sa prémisse

Proposition RuleConclusion(Regle* rule);
//Prend une règle en entré et renvoie le pointeur vers sa conclusion

#endif
