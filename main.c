#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAILLE_FICHIER 1024
#define LINE_MAX 2048

FILE *file, *temp;

typedef struct {
    int ncin;
    int age;
    char nom[100];
    char prenom[100];
    float notes[10];
    char decison[100];
} candidat;

candidat can1;

//void rechercher(int cni);
void saisir(void);
int checkcni(int cni);
void supprimer(int ncni);

int main()
{
    //saisir();
    supprimer(1234567);
    //rechercher(122132);
    return 0;
}

int checkcni(int cni)
{
    FILE *P;
    int i;
    P = fopen("concours.txt", "a+");

    do
    {
        fscanf(P, "%d\n%d\n%s\n%s\n", &can1.ncin, &can1.age, can1.nom, can1.prenom /*&can1.notes[i], /*&can1.decision*/);

        for(i=1; i<=10; i++)
        {
            fscanf(P, "%f\n", &can1.notes[i]);
        }
        
        fscanf(P, "%s\n", can1.decison);

        fflush(stdin);

        if(can1.ncin==cni)
        {
            fclose(P);
            return 1;
        }

    } while (!feof(P));
    fclose(P);
    return -1;
}

void supprimer(int ncni)
{
    //char nomfichier[TAILLE_FICHIER];
    //char nomfichier_temp[TAILLE_FICHIER];
    //char buffer[LINE_MAX];

    char rep;
    
    int i;
    
    //printf("Veuillez entrer le nom")

    fflush(stdin);

    if(checkcni(ncni) == 1)
    {
        printf("\n Voulez vous vraiment supprimer le Candidat ? (o/n)");
        scanf("%c", &rep);
        fflush(stdin);

        if(rep == 'o' || rep == 'O')
        {
            FILE *Prend, *F;

            Prend = fopen("concours.txt", "a+");
            F = fopen("temp_concours.txt", "a+");
            do
            {
                fscanf(Prend, "%d\n%d\n%s\n%s\n", &can1.ncin, &can1.age, can1.nom, can1.prenom /*&can1.notes[i], /*&can1.decision*/);

                 for(i=1; i<=10; i++)
                     {
                         fscanf(Prend, "%f\n", &can1.notes[i]);
                     }
                fscanf(Prend, "%s\n", can1.decison);

                if(ncni != can1.ncin)
                {
                   fprintf(F, "%d\n%d\n%s\n%s\n", ncni, can1.age, can1.nom, can1.prenom);

                    for(i=0; i<10; i++)
                    {
                        fprintf(F, "%f\n", can1.notes[i]);
                    }
                    fprintf(F, "%s\n", can1.decison);
                }
            } while (!feof(Prend));
            fclose(Prend);
            fclose(F);
            remove("concours.txt");
            rename("temp_concours.txt", "concours.txt");
            printf("\nSuppression effectuée avec succès\n");
        }
    }
    else
    {
        printf("\n Cette CNI de candidat n'existe pas\n");
    }

    /*strcpy(nomfichier_temp, "temp___");
    strcat(nomfichier_temp, "concours.txt");

    file = fopen("concours.txt", "r");
    temp = fopen(nomfichier_temp, "w");

    if(file == NULL || temp == NULL)
    {
        printf("Impossible d'ouvrir le(s) fichier(s)");
        return;
    }

    bool toujourslire = true;
    int line_actu = 1;

    do
    {
        fgets(buffer, LINE_MAX, file);
        if(feof(file))
        {
            toujourslire = false;
        }
        else if(line_actu != cni)
        {
            fputs(buffer, temp);
        }
        //else if(line_actu == cni)
        //{
            //for(i=line_actu; i <= line_actu+15; i++)
            //{
                //continue;
            //}
        //}
        line_actu++;

    } while(toujourslire);

    fclose(file);
    fclose(temp);

    remove("concours.txt");
    rename(nomfichier_temp, "concours.txt");*/

}

void saisir(void)
{
    int i, newcni, trouver=0;
    char autre[100];
    bool etatnote[10];
    bool verifnote;
    float sum=0, moy=0;

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

        //strcpy(autre, "-----------------\n");
        //fprintf(file, "%s\n", autre);

        fprintf(file, "%d\n%d\n%s\n%s\n", newcni, can1.age, can1.nom, can1.prenom);

        for(i=0; i<10; i++)
        {
            fprintf(file, "%f\n", can1.notes[i]);
        }
        fprintf(file, "%s\n", can1.decison);
        //strcpy(autre, "-----------------\n");
        //fprintf(file, "%s\n", autre);
    }
    fclose(file);

}

/**void rechercher(int cni)
{
    int i;
    //printf("Veuillez entrer le numero de CNI de l'etudiant à rechercher ?\n");
    //scanf("%d", &supetu);

    file = fopen("concours.txt", "a+");
    do
    {
        //fscanf(file, "%d\n%d\n%s\n%s\n", &can1.ncin, &can1.age, can1.nom, can1.prenom /*&can1.notes[i], /*&can1.decision*/

        /*for(i=1; i<=10; i++)
        {
            fscanf(file, "%f\n", &can1.notes[i]);
        }
        fscanf(file, "%s\n", can1.decison);

        if(cni == can1.ncin)
         {
            printf("-----------Informations sur le candidat--------\n\n");
            printf("Cni\t: %d\n", can1.ncin);
            printf("Age\t: %d \n", can1.age);
            printf("Nom\t: %s \n", can1.nom);
            printf("Prenom\t: %s \n", can1.prenom);
            for(i=0; i<10; i++)
            {
                printf("\n Note numero %d: %f\n", i+1, can1.notes[i]);
            }
            printf("Decision\t: %s\n", can1.decison);
         }
    } while (!feof(file));
    fclose(file);
}*/


