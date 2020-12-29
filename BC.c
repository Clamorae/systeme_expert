#include "BC.h"

void afficheBC(KB BC){
    while (BC!=NULL){
        Premisse prem=PremisseHead(BC->head);
        Proposition conc=RuleConclusion(BC->head);
        while (prem!=NULL){
            printf("%s\n",prem->proposition);
            printf("\n");
            prem = prem->next;
        }
        printf("\n");
        puts(conc);
        printf("\n__________________________________________________________________");
        BC=BC->next;
    }
}

KB menuBC(KB BC){
    int menu;
    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - Afficher la base de connaissance\n\n");
    printf("2 - Ajouter une règle à la base de connaissance\n\n" );
    //printf("3 - Ajouter une proposition à une régle\n\n");
    printf("4 - Supprimer une régle\n\n");
    //printf("5 - Supprimer la proposition d'une régle\n\n");
    printf("6 - Quitter\n\n");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        afficheBC(BC);//////////////////TODO
        break;
    case 2:
        addruletoBC(BC);///////////////////TODO
        afficheBC(BC);
        break;
    case 3:
        return 0;
        break;
    default:
        return 0;
        break;
    }
}
