#include <stdio.h>
#include "main.h"


void saisir(void)
{
    FILE *fptr;
    char new='O';
    fptr = fopen("concours.txt", "w");
    candidat c1;
    while (new=='O')
    {
        printf("Veuillez entrer la CNI du candidat");
        scanf(c1.ncin);
        printf("Veuillez entrer le nom du candidat");
        scanf(c1.nom);
        printf("Veuillez entrer le prenom du candidat");
        scanf(c1.prenom);
        printf("Veuillez entrer l'age du candidat");
        scanf(c1.age);
        
        for(int i=1; i<10; i++)
        {
            printf("Entrer la note n°: %d\n", i);
            scanf(c1.notes[i]);
        }
    }
}