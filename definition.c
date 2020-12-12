#include "definition.h"

Regle* createRule(){
    Regle* new = (Regle*) malloc(sizeof(Regle));
    return new;
}

void addProp(Regle rule, Proposition str){
  Premisse rulePremisse = rule.premisse;
  ElemPremisse *newElem = malloc(sizeof(ElemPremisse));
  Proposition nprop = malloc(sizeof(char)*255);
  strcpy(nprop, str);
  newElem->proposition = nprop;
  newElem->next = NULL;
  if(rulePremisse == NULL){
    rulePremisse = newElem;
  }
  while(rulePremisse->next != NULL){
    rulePremisse = rulePremisse->next;
  }
  rulePremisse->next = newElem;
}

void createConclusion(Regle rule){
    Proposition* newConc = (Proposition*) malloc(sizeof(Proposition));
    rule.conclusion=newConc;
}

Bool testProp(Premisse rulePrem, Proposition prop){
  if(rulePrem == NULL){
    return false;
  }else if (!strcmp(rulePrem->proposition, prop)){
    return true;
  }else{
    return testProp(rulePrem->next, prop);
  }
}

Bool isPremisseEmpty(Regle rule){
  if(rule.premisse == NULL){
    return true;
  }else{
    return false;
  }
}

Bool deleteProp(Premisse head, Proposition prop){
    if (head->next!=NULL){
        return NULL;
    }
    else if(!strcmp(head->next->proposition,prop)){
        head->next=head->next->next;
        free(head->next);
        return NULL;
    }
    else{
        return deleteProp( head->next, prop);
    }
}
///////////////////////////////////
Bool isNULL(Premisse head){
  if (head==NULL){
    return true;
  }
  else{
    return false;
  }
}

Premisse PremisseHead(Regle rule){
  return rule.premisse;
}/* vriament pas sur de celle la*/

Proposition RuleConclusion(Regle rule){
  return rule.conclusion;
}