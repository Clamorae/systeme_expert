#include "definition.h"
#include "base_connaissance.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int menu;
    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - accéder à la base de connaissance\n\n");
    printf("2 - Entrer une base de faits" );
    printf("3 - quitter\n\n");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        afficheBC();//////////////////TODO
        break;
    case 2:
        createBF();///////////////////TODO
        break;
    default:
        break;
    }
}