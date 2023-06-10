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


        //for(i=0; i<=10; i++)
        //{
          //  sum = sum + can1.notes[i];
        //}

        //moy = sum/10;

        //for(i=1; i<=10; i++)
        //{
            //if(can1.notes[i]<10)
            //{
              //  etatnote=1;
            //    break;
          //  }
        //}

        //if((moy>=10) && (etatnote=0))
        //{
            //can1.decison = "ADMIS";
          //  fscanf(file, "%s\n", can1.decison);
        //}
        //else if((moy>=10) && (etatnote=1))
        //{
          //  printf("\n Le candidat est A! \n\n");
        //}
}