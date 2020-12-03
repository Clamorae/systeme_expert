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

Bool testProp(Premisse rulePrem, Proposition prop){
  if(rulePrem = NULL){
    return 0
  }else if (!strcmp(rulePrem->proposition, prop)){
    return 1
  }else{
    return testProp(rulePrem->next, prop)
  }
}
