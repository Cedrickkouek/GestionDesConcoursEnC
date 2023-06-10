#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int ncin;
    int age;
    char nom[100];
    char prenom[100];
    float notes[10];
    char decison[100];
} candidat;


void saisir(void);

int main()
{
    saisir();
    return 0;
}

void saisir(void)
{
    candidat can1;
    int i, newcni, trouver=0;
    char autre[100];
    bool etatnote[10];
    bool verifnote;
    float sum=0, moy=0;
    FILE *file;
    file=fopen("concours.txt", "at+");

    if(file==NULL)
    {
        printf("Le fichier ne peut pas etre ouvert !");
        exit(1);
    }

    printf("\nEntrez le numéro de la CNI du candidat: \n");
    scanf("%d", &newcni);

    while(!feof(file))
    {
        fscanf(file, "%d\n%d\n%s\n%s\n", &can1.ncin, &can1.age, can1.nom, can1.prenom /*&can1.notes[i], /*&can1.decision*/);

        for(i=1; i<=10; i++)
        {
            fscanf(file, "%f\n", &can1.notes[i]);
        }
        fscanf(file, "%s\n", can1.decison); 

        if(newcni==can1.ncin)
        {
            trouver=1;
            break;
        }
    }

    if(trouver==1)
    {
        printf("\nL'Etudiant que vous souhaiter entrer existe déja !\n");
    }
    else
    {
        printf("\nVeuillez entrer l'age du candidat : \n");
        scanf("%d", &can1.age);
        printf("\nVeuillez entrer le nom du candidat : \n");
        scanf("%s", can1.nom);
        printf("\nVeuillez entrer le prenom du candidat : \n");
        scanf("%s", can1.prenom);

        printf("\nVeuillez entrer les notes: \n");
        for(i=0; i<10; i++)
        {
            printf("\n Entrez la note n° %d du candidat: \n", i);
            scanf("%f", &can1.notes[i]);
            fscanf(file, "%f\n", &can1.notes[i]);
        }

        //printf("\nVeuillez entrer la decision sur le candidat : \n\n");
        //scanf("%s", can1.decison);

        //for(i=1; i<=10; i++)
        //{
            //scanf("%f\n", &can1.notes[i]);
        //}

        /* Ici c'est pour calculer la moyenne d'un candidat */
        for(i=0; i<10; i++)
        {
            sum = sum + can1.notes[i];
            moy = (sum/i);
        }      

        for(i=0; i<10; i++)
        {
            if(can1.notes[i]<10)
            {
                etatnote[i]=false;
            }
            else if(can1.notes[i]>=10)
            {
                etatnote[i]=true;
            }
        }

        //for(i=0; i<10; i++)
        //{
            //if(can1.notes[i]<10)
            //{
                //etatnote=false;
                //break;
            //}
            //else if(can1.notes[i]>=10)
            //{
                //etatnote=true;
                //break;
            //}
        //}

        for(i=0; i<10; i++)
        {
            if((moy>10) && (etatnote[i]==true))
            {
                verifnote=true;
                continue;
            }
            //strcpy(can1.decison, "Admis");

            else if((moy>10) && (etatnote[i]==false))
            {
                strcpy(can1.decison, "Ajourné");
                verifnote=false;
                break;
            }

            else /*if((moy<=10) && (etatnote[i]=false))*/
            {
                strcpy(can1.decison, "Refusé");
                verifnote=false;
                break;
            }
        }

        if((moy>10) && (verifnote==true))
        {
            strcpy(can1.decison, "Admis");
        }

        strcpy(autre, "-----------------\n");
        fprintf(file, "%s\n", autre);

        fprintf(file, "%d\n%d\n%s\n%s\n", newcni, can1.age, can1.nom, can1.prenom);

        for(i=0; i<10; i++)
        {
            fprintf(file, "%f\n", can1.notes[i]);
        }
        fprintf(file, "%s\n", can1.decison);
        strcpy(autre, "-----------------\n");
        fprintf(file, "%s\n", autre);
    }
    fclose(file);

}


