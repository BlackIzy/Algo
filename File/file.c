#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef int Elt_file;

typedef struct {
  int tete, queue,taille;
  Elt_file F[MAX];
} File;

//Valeuur NULL pour la tête et la queue de la file, et taille à 0
File* creerFile(void) {
    File *f;
    f  = (File*) malloc(sizeof(File));
    if(f==NULL)
    {
        printf("Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
    }
    f -> tete = NULL;
    f -> queue = NULL;
    f -> taille = 0;
}

//Retourne 1 si la liste est vide et 0 si la liste est pas vide
int fileVide(File *f) {
    if( f->taille == 0)
    {
        return 1;
    }
    return 0;
}

//Retourne le premier element de la file
Elt_file premier(File *f) {
    if(fileVide(f))
    {
        printf("Pas d'element dans la file \n\n");
        return;
    }
    return f-> F[f->tete];


}
//Retourne le dernier element de la file
Elt_file dernier(File *f) {
      if(fileVide(f))
    {
        printf("Pas d'element dans la file \n\n");
        return;
    }
    return f->F[f->queue];
}
// ajoute l'elemennt x en parametre a la file
void enfiler(Elt_file x, File *f){

    //Si file vide tete et queu sont egal au meme element
    if(fileVide(f))
    {
        f->F[f->tete] = x;
        f->F[f->queue] = x;
    }
    else if(f->taille > MAX-1)
    {
        printf("La file est au complet \n");
        return;
    }
    else
    {
        //Je pousse la queue pour lui ajouter le paramere x
        f->queue = f->queue+1;
    }
    f->taille++;
    f->F[f->queue] = x;
}
// Retourne l'element de la file enleve
Elt_file defiler(File *f) {
    if(fileVide(f))
    {
        printf("La file est vide \n");
        return;
    }
    // Je cree une variable pour contenir la tete actuelle de la liste
    Elt_file tmp = f->F[f->tete];
    // Si tete et queu sont egal au même element ça veut dire que la liste contient un seul element donc l'indice revient à 0
    if(f->tete == f->queue)
    {
        f->tete = 0;
        f->queue = 0;
    }
    else
    {
        //Je pousse la tete de la file sur l'element suivant de la tete de la file
        f->tete = f->tete +1;
    }
    //Vue que je supprime un element je diminue la taille de ma file
    f->taille--;
    // Je retourne la variable qui a stoker la tete de la file
    return tmp;


}

//J'affiche la file
//Pour l'affichage je vais de la tete de la file a la fin de la file
void affichageFile(File *f) {
    int i;
    if(fileVide(f))
    {
        printf("La file est vide \n");
    }
    else
    {
        printf("Les elements de la file : \n");
        File *tmp = f->tete;
        for(i= f->tete;i<=f->queue;i++)
         {
             printf(" [%d] ",f->F[i]);
             tmp++;
         }
        printf("\n");
    }


}



int main()
{
/*
File *f1;
Elt_file x;
printf("Test 1 :\n\n");
f1=creerFile();
enfiler(1,f1);
enfiler(2,f1);
enfiler(3,f1);
x=defiler(f1);
printf("x = %d \n\n",x);
x=defiler(f1);
printf("x = %d \n\n",x);
enfiler(4,f1);
enfiler(5,f1);
x=defiler(f1);
printf("x = %d \n\n",x);
enfiler(6,f1);
x=premier(f1);
printf("element tete de file = %d. \n\n",x);
x=dernier(f1);
printf("dernier element de file = %d. \n\n",x);
x = fileVide(f1);
printf("file vide 1 sinon 0 : %d\n\n", x);
affichageFile(f1);
printf("\n\n");
*/

/*
File *f2;
Elt_file x;
printf("Test 2 :\n\n");
f2=creerFile();
enfiler(1,f2);
enfiler(2,f2);
enfiler(3,f2);
x=defiler(f2);
printf("x = %d \n\n",x);
x=defiler(f2);
printf("x = %d \n\n",x);
enfiler(4,f2);
enfiler(5,f2);
x=defiler(f2);
printf("x = %d \n\n",x);
enfiler(6,f2);
enfiler(7,f2);
enfiler(8,f2);
enfiler(9,f2);
enfiler(10,f2);
enfiler(11,f2);
enfiler(12,f2);
affichageFile(f2);
printf("\n\n");
*/


/*
File *f3;
Elt_file x;
printf("Test 3 : \n\n");
f3=creerFile();
x=defiler(f3);
printf("x = %d \n\n",x);
x = fileVide(f3);
printf("file vide 1 sinon 0 : %d\n\n", x);
x=premier(f3);
printf("element tete de file = %d. \n\n",x);
x=dernier(f3);
printf("dernier element de file = %d. \n\n",x);
enfiler(2,f3);
enfiler(3,f3);
enfiler(4,f3);
enfiler(1,f3);
enfiler(8,f3);
x=defiler(f3);
printf("x = %d \n\n",x);
enfiler(5,f3);
enfiler(7,f3);
x=premier(f3);
printf("element tete de file = %d. \n\n",x);
x=dernier(f3);
printf("dernier element de file = %d. \n\n",x);
x = fileVide(f3);
printf("file vide 0, file non vide 1 : %d\n", x);
enfiler(9,f3);
enfiler(10,f3);
enfiler(11,f3);
enfiler(12,f3);
enfiler(13,f3);
affichageFile(f3);
printf("\n\n");
*/



File *f4;
Elt_file x;
printf("Test 4 :\n\n");
f4=creerFile();
enfiler(1,f4);
enfiler(2,f4);
enfiler(3,f4);
printf("file = ");
affichageFile(f4);
printf("\n\n");
x=defiler(f4);
printf("x = %d \n\n",x);
x=defiler(f4);
printf("x = %d \n\n",x);
x=defiler(f4);
printf("x = %d \n\n",x);
printf("file = ");
affichageFile(f4);
printf("\n\n");
enfiler(4,f4);
enfiler(5,f4);
enfiler(6,f4);
enfiler(7,f4);
enfiler(8,f4);
enfiler(9,f4);
enfiler(10,f4);
enfiler(11,f4);
enfiler(12,f4);
enfiler(13,f4);
printf("file = ");
affichageFile(f4);
printf("\n\n");
enfiler(14,f4);
x=premier(f4);
printf("element tete de file = %d. \n\n",x);
x=dernier(f4);
printf("dernier element de file = %d. \n\n",x);
printf("file =");
affichageFile(f4);
printf("\n");


return 0;

}


