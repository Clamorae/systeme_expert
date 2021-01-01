#include "definition.h"

Regle* createRule(){
  Regle* new = (Regle*) malloc(sizeof(Regle));
  return new;
}

void addProp(Premisse* temp, Proposition str){
  //Premisse rulePremisse = rule->premisse;
  //
  //Proposition nprop = malloc(sizeof(char)*255);
  //strcpy(nprop, str);
  //
  //ElemPremisse *newElem = malloc(sizeof(ElemPremisse));
  //newElem->proposition = nprop;
  //newElem->next = NULL;
  //
  //if(rulePremisse == NULL){
  //  rulePremisse = newElem;
  //}else{
  //  while(rulePremisse->next != NULL){
  //    rulePremisse = rulePremisse->next;
  //  }
  //  rulePremisse->next = newElem;
  //}
  //printf("RESULTAT DE ADDPROP____________________\n");
  //printf("%s\n",rulePremisse->proposition);

  //Premisse *temp = &(rule->premisse);

  while(&((*temp)->proposition) != NULL){
    temp = &((*temp)->next);
  }

  ElemPremisse *newElem = malloc(sizeof(ElemPremisse));
  Proposition nprop = malloc(sizeof(char)*255);
  strcpy(nprop, str);
  newElem->proposition = nprop;
  newElem->next = NULL;
  *temp = newElem;

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
