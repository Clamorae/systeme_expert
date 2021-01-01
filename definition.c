#include "definition.h"

Regle* createRule(){
  Regle* new = (Regle*) malloc(sizeof(Regle));
  return new;
}

void addProp(Premisse* bf, Proposition str){
  Proposition nprop = malloc(sizeof(char)*255);
  ElemPremisse *newElem = malloc(sizeof(ElemPremisse));
  strcpy(nprop, str);

  newElem->proposition = nprop;
  newElem->next = NULL;

  if(*bf == NULL){
    *bf = newElem;
  }else{
    Premisse temp = *bf;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newElem;
  }
}

int createConclusion(Regle* rule){
  if (rule->conclusion==NULL){
    Proposition newConc = (Proposition) malloc(sizeof(char)*255);
    rule->conclusion=newConc;
  }else{
    return -1;
  }
}

int testProp(Premisse rulePrem, Proposition prop){
  if(rulePrem == NULL){
    return 0;
  }else if (!strcmp(rulePrem->proposition, prop)){
    return 1;
  }else{
    return testProp(rulePrem->next, prop);
  }
}

int isPremisseEmpty(Regle rule){
  if(rule.premisse == NULL){
    return 1;
  }else{
    return 0;
  }
}

Premisse deleteProp(Premisse head, Proposition prop){
  Premisse p;
  Premisse save;
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
int isNULL(Premisse head){
  if (head==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

Premisse PremisseHead(Regle* rule){
  return rule->premisse;
}

Proposition RuleConclusion(Regle* rule){
  return rule->conclusion;
}
