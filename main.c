#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("\nL'Etudiant que vous souhaiter entrer existe déja !\n\n");
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
        for(i=1; i<=10; i++)
        {
            scanf("%f", &can1.notes[i]);
        }

        printf("\nVeuillez entrer la decision sur le candidat : \n\n");
        scanf("%s", can1.decison);

        fprintf(file, "%d\n%d\n%s\n%s\n%f\n%s\n", newcni, can1.age, can1.nom, can1.prenom, can1.notes[10], can1.decison);
    }
    fclose(file);

}


