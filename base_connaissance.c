#include"base_connaissance.h"

KB createbasis(){
  KB newel=(KB)malloc(sizeof(ElemBC));
  FILE* fp = fopen("BC.sav","r");
  char buffer[255];
  if(fp==NULL ||!(fgets(buffer,255,fp))){

    return newel;

  }else{

    KB save = newel; // Nouvelle BC
    KB oldnewel = newel;
    Proposition nConc = NULL;
    Premisse nPremisse = NULL;
    int keep = 1;

    do{

      Regle* nRule = createRule();
      nPremisse = NULL;

      do{
        strtok(buffer,"\n");
        addProp(&nPremisse,buffer);
        fgets(buffer,255,fp);

      }while(strcmp(buffer,"conk:\n")!=0);

      strtok(buffer,"\n");
      createConclusion(nRule);
      fgets(buffer,255,fp);
      strtok(buffer,"\n");
      strcpy(nRule->conclusion,buffer);

      nRule->premisse = nPremisse;
      newel->head = nRule;
      oldnewel = newel;

      if(fgets(buffer,255,fp)){
        newel->next = malloc(sizeof(ElemBC));
        newel = newel->next;
      }else{
        keep = 0;
      }
    }while(keep);
    return save;
  }
}

Regle* firstRule(KB base){
    return base->head;
}
