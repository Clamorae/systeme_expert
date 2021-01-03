#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"

void moteur(Premisse BF, KB BC){
    system("clear");
    if (BF==NULL){
        printf("La base de fait est vide\n");
    }else if (BC->head==NULL){
        printf("La base de connaissance est vide\n");
    }else{
        printf("Les faits vrais sont :\n\n");
        KB save = BC;
        Premisse saveBF = BF;
        int buffer;
        Premisse end=BF;
        while (end->next!=NULL){
            end=end->next;
        }

        do{
            printf(">%s\n",BF->proposition);
            do{
                buffer=testProp(BC->head->premisse,BF->proposition);
                if (buffer==1){
                    BC->head->premisse=deleteProp(BC->head->premisse,BF->proposition);
                    if (BC->head->premisse==NULL){
                        Premisse newel=(Premisse)malloc(sizeof(ElemPremisse));
                        newel->proposition=BC->head->conclusion;
                        end->next=newel;
                        end=newel;
                    }
                }
                BC=BC->next;
            }while (BC!=NULL);
            BC=save;
            BF=BF->next;
        } while (BF!=NULL);
    }
    Premisse r;
    while (!isNULL(BF)){
        r=BF->next;
        free(BF->proposition);
        free(BF);
        BF=r;
    }
    KB p;
    while (BC!=NULL){
        while(!isNULL(BC->head->premisse)){
            r=BC->head->premisse->next;
            free(BC->head->premisse->proposition);
            free(BC->head->premisse);
            BC->head->premisse=r;
        }
        free(r);
        free(BC->head->conclusion);
        p=BC->next;
        free(BC);
        BC=p;
    }
    free(p);
}
