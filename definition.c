#include "definition.h"

void addProp(Regle rule, Proposition str){
  Premisse rulePremisse = rule.premisse;
  ElemPremisse *newElem = malloc(sizeof(ElemPremisse));
  Proposition nprop = malloc(sizeof(char)*255);
  strcpy(nprop, str);
  newElem->proposition = nprop;
  newElem->next = NULL;
  while(rulePremisse->next != NULL){
    rulePremisse = rulePremisse->next;
  }
  rulePremisse->next = newElem;
}

Regle* createRule(){
    Regle* new = (Regle*) malloc(sizeof(Regle));
    return new;
}

void createConclusion(Regle rule){
    Proposition* newConc = (Proposition*) malloc(sizeof(Proposition));
    rule.conclusion=newConc;
}
