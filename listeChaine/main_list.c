/* ---------------------------------------------------------
   Programme principale du module liste
   ---------------------------------------------------------
   20/10/21	SR	creation
   ---------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "list.h"
void parcours(s_node * head){
    s_node * tmp = head;
    int i = 1;
    while(tmp -> next != NULL && i != 10){
        printf("Element %d : %d \n",i, *(int*) tmp -> val);
        tmp = tmp -> next;
        i++;
    }
    printf("Element %d : %d \n",i, *(int*) tmp -> val);
    
}



int main(){
    // declaration d'entiers à mettre dans la liste
    int  d1 = 50, d2 = 7, d3 = 2, d4 = 20, d5 = 4;
    
    // creation de la liste avec un pointeur sur sa tête
    s_node * head = list_create();
    
    printf("Test fonction list_insert : \nRésultat attendu \nElement 1 : %d\n", d2);
    
    // insertion d'un premier entier en tête de liste
    head = list_insert(head, (void *) &d1);
    
    // insertion d'un autre entier en tête de liste
    head = list_insert(head, (void*) &d2);
    
    printf("Résultat obtenu : \n");
    
    // affichage de l'entier inseré en tête de liste
    printf("Element 1 : %d\n", *(int*) (head -> val));
    
    printf("Test de la fonction list_get_data :\nRésultat attendu : Element 1 : %d\n", d2);
    
    // recuperation de la tête de liste avec la fonction get
    int * p = (int*) list_get_data(head);
    
    // affichage de l'entier
    printf("Element 1 : %d\n", *p);
    
    printf("Test de la fonction list_append\nRésulat attendu : ajout de %d et %d en fin de liste\n", d3, d4);
    
    // ajout d'un entier en queue de liste
    head = list_append(head, (void*) &d3);
    
    // ajout d'un autre entier en queue de liste
    head = list_append(head, (void*) &d4);
    
    printf("Résultat obteue : \n");
    // parcours de la liste avec la fonction parcous 
    parcours(head);
    
    // affichage de la liste avec la fonction list_to_string
    char * liste = list_to_string (head, &node_int_to_string); 
    puts(liste);

    
    // creation d'une nouvelle liste ordonnée
    s_node * head_ord = list_create();
    
    // déclaration des variable entier ordonnées
    int x1 =10, x2 = 15, x3 = 30, x4 = 35;
    
    // ajour du premier entier en tête de la liste ordonnée
    head_ord = list_insert(head_ord, &x1);
    
    // ajout du deuxième entier comme queue de la liste ordonnée
    head_ord = list_append(head_ord, &x2);
    
    // ajout du troisième entier comme queue de la liste ordonnée 
    head_ord = list_append(head_ord, &x3);
    
    // ajout du quatrième entier comme queue de la liste ordonnée 
    head_ord = list_append(head_ord, &x4);
    
    // affichage de la liste ordonnée avec la fonction parcours
    printf("Liste ordonnée : \n");
    parcours(head_ord);
    
    printf("Test de la fonction compare :\nRésultat voulu de la comparaison entre %d et %d : \n", x1, x2);    
    // test de la fonction compare
    int comp = compare(head_ord, &x2);
    
    // affichage du résultat de la fonction compare
    printf("Résultat obtenue : %d\n", comp);
    
    // declaration d'un double pointeur pour son utilisation dans la fonction list_orderedAppend
    s_node ** head_p = &head_ord;
    
    printf("Test de la fonction list_orderedAppend\nRésultat voulu :\nAjout de %d en tête de liste\nAjout de %d en milieu de liste\nAjout de %d en fin de liste\n", d3, d4, d1);
    // ajout d'un entier dans la liste ordonnée avec la fonction liste_orderedAppend
    head_ord = list_orderedAppend(head_p,&compare, &d3);
    
    // ajout d'un deuxième entier dans la liste ordonnée avec la fonction liste_orderedAppend
    head_ord = list_orderedAppend(head_p,&compare, &d4);
    
    // ajout d'un entier dans la liste ordonnée avec la fonction liste_orderedAppend
    head_ord = list_orderedAppend(head_p,&compare, &d1);
    
    // vérification de l'ajout avec affichage de la liste fonction parcours
    printf("Résultat obtenue :\n");
    parcours(head_ord);
    char * liste1 = list_to_string (head_ord, &node_int_to_string); 
    puts(liste);
    
    //ajout d'un entier déjà dans la liste ordonnée avec la fonction liste_orderedAppend
    head_ord = list_orderedAppend(head_p,&compare, &d3);
    liste1 = list_to_string (head_ord, &node_int_to_string);
    puts(liste1);
    
    printf("Test de la fonction list_remove :\nRésultat voulu : suppression du deuxième entier de la liste %d\n", x2);
    
    // supression de l'entier x2 de la liste ordonnée avec la fonction list_remove
    head_ord = list_remove(head_ord, &x2);
    parcours(head_ord);
    
    // verification avec affichage de la liste 
    printf("Résulat obtenue :\n"); 
    liste1 = list_to_string (head_ord, &node_int_to_string);
    puts(liste1);
    
    printf("Test de la fonction list_headRemove\nRésultat voulu : Supprimer la tête de la liste ordonnée %d\n", d3);
    
    // suppression de la tête de liste avec la fonction liste_headRemove
    head_ord = list_headRemove(head_ord);
    
    // verification avec affichage de la liste 
    parcours(head_ord);
    liste1 = list_to_string (head_ord, &node_int_to_string);
    puts(liste1);
    
    printf("Test de la fonction list_destroy\nRésultat voulu : Plus aucun entier dans la liste\n");
    // destruction de la liste avec la fonction list_destroy
    list_destroy(head_ord);
    
    // verification avec affichage de la liste fonction parcours
    printf("Résulat obtenu :\n");
    liste1 = list_to_string (head_ord, &node_int_to_string);
    puts(liste1);
    parcours(head_ord);
    

   
    
}
