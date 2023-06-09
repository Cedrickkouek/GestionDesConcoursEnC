#ifndef MAIN_H
#define MAIN_H

typedef struct {
    int ncin;
    int age;
    char nom[20];
    char prenom[20];
    int notes[10];
    char decison[7];
} candidat;

void saisir(void);

#endif