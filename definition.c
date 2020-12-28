#include "definition.h"

Regle* createRule(){
  Regle* new = (Regle*) malloc(sizeof(Regle));
  return new;
}

void addProp(Regle* rule, Proposition str){
  Premisse rulePremisse = rule->premisse;
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

void createConclusion(Regle* rule){
  if (rule->conclusion==NULL){
    Proposition* newConc = (Proposition*) malloc(sizeof(Proposition));
    rule->conclusion=newConc;
  }else{
    return NULL;
  }
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

Premisse deleteProp(Premisse head, Proposition prop){
  int* p;
  int* save;
  save=head;
  if (head==NULL){
    return NULL;
  }
  else if (strcmp(head->proposition,prop)){
    p=head->next;
    free(head);
    return p;
  }
  do{
    if(strcmp(head->next->proposition,prop)){
      p=head->next;
      head->next=head->next->next;
      free(p);
      return save;
    }else{
      head=head->next;
    }
  } while (head!=NULL);
  return save;
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

Premisse PremisseHead(Regle* rule){
  return rule->premisse;
}

Proposition RuleConclusion(Regle* rule){
  return rule->conclusion;
}
