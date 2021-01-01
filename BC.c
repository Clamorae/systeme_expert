#include "BC.h"

void afficheBC(KB BC){
    while (BC!=NULL){
        Premisse prem=PremisseHead(BC->head);
        Proposition conc=RuleConclusion(BC->head);
        while (prem!=NULL){
            printf(" %s -",prem->proposition);
            prem = prem->next;
        }
        printf(">");
        puts(conc);
        printf("\n");
        BC=BC->next;
    }
}

KB menuBC(KB /*KFC*/ BC, Premisse BF){
    int wait;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    if((BC->head) == NULL){
      printf("Il n'y as acutellement aucune règle dans la base de connaissances\n");
    }else{
      printf("La base de connaissance est:\n");
      afficheBC(BC);
    }

    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - Ajouter une règle à la base de connaissance\n\n" );
    //printf("3 - Ajouter une proposition à une régle\n\n");
    printf("2 - Supprimer une régle\n\n");
    //printf("5 - Supprimer la proposition d'une régle\n\n");
    printf("3 - Quitter\n\n");
    scanf("%d",&wait);
    switch (wait){
    case 1:
        addruletoBC(BC);
        break;
    case 2:
        /////////////////////////////TODO
        break;
    case 3:
        menu(BC,BF);
    default:
        return 0;
        break;
    }
}
