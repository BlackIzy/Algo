/* ---------------------------------------------------------
   Fonctionnalités du module liste 
   ---------------------------------------------------------
   20/10/21	SR	creation
   ---------------------------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"



/* -----------------------------------------------------------------
   Creation d'une nouvelle liste vide
   -----------------------------------------------------------------
   pas de paramètre
   -----------------------------------------------------------------
   retourne un noeud vide
   -----------------------------------------------------------------
*/

s_node * list_create(void){
    return NULL;
}

/* -----------------------------------------------------------------
   Lire la donnee d'un noeud
   -----------------------------------------------------------------
   node : noeud à lire 
   -----------------------------------------------------------------
   retourne la donnée du noeud passé en paramètre
   -----------------------------------------------------------------
*/

void * list_get_data(s_node * node){
    if(node == NULL){
        exit(1);
    }
    else{
        return node -> val;
    }
    
}

/* -----------------------------------------------------------------
   Ecrire la donnee d'un noeud
   -----------------------------------------------------------------
   node : la donnée du noeud à mettre à jour
   data : la donnée pour mettre à jour le noeud 
   -----------------------------------------------------------------
   pas de retour
   -----------------------------------------------------------------
*/

void list_set_data(s_node * node, void * data){

    node -> val = data;    
}

/* -----------------------------------------------------------------
   Creation et insertion d'un noeud en tete de liste
   -----------------------------------------------------------------
   head : la tête de liste  
   data : la donnée pour la nouvelle tête de liste 
   -----------------------------------------------------------------
   retourne la tete de liste
   -----------------------------------------------------------------
*/
s_node * list_insert(s_node * head, void * data){
    // allocation mémoire pour le nouveau noeud
    s_node * nv_node = (s_node*) malloc(sizeof (s_node));
    if(nv_node == NULL){
        printf("Erreur malloc");
        exit(1);
    }
    // affectation de data au nouveau noeud
    nv_node -> val = data;
    // affectation de la donnée suivante du nouevau noeud à l'ancienne tête de liste
    nv_node -> next = head;
    // retour du nouveau noeud étant la nouvelle tête de liste
    return nv_node;
}

/* -----------------------------------------------------------------
   Creation et ajout d'un noeud en queue de liste
   -----------------------------------------------------------------
   head : la tête de liste  
   data : la donnée pour la nouvelle queue de liste 
   -----------------------------------------------------------------
   retourne la tete de liste
   -----------------------------------------------------------------
*/

s_node * list_append(s_node * head, void * data){
    // allocation mémoire pour le nouveau noeud
    s_node * nv_node = (s_node*) malloc(sizeof (s_node));
    if(nv_node == NULL){
        printf("Erreur malloc");
        exit(1);
    }
    // affectation de data au nouveau noeud
    list_set_data(nv_node, data);
    // affectation de la donnée suivante du noeud à null(queue de liste)
    nv_node -> next = NULL;
    // si la tête de liste est vide on retourne le nouveau noeud crée
    if(head == NULL){
        return nv_node;    
    }
    // sinon 
    else{
        // affectation d'une variable tmp à la tête de liste
        s_node *tmp = head;
        // parcours de la liste tant qu'on est pas en fin de liste 
        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }
        // affectation de la fin de liste au nouveau noeud
        tmp -> next = nv_node ;
        nv_node -> val = data;
        nv_node -> next = NULL;
        // retourne la tête de liste
        return head;
    }
}

/* -----------------------------------------------------------------
   Comparaison d'un noeud avec la donnée à inserer 
   -----------------------------------------------------------------
   node : donnée du noeud à comparer à la donnée passée en paramètre  
   data : donnée à comparer au noeud passé en paramètre
   -----------------------------------------------------------------
   retourne la tete de liste
   -----------------------------------------------------------------
*/

int compare (s_node * node, void * data){
    // si la donnée(en paramètre) est plus grande que la donnée du noeud retourne 1
    int * n = (int*) list_get_data(node);
    int * d =  (int*) data;
    if(*n < *d){
        return 1;
    }
    // si la donnée(en paramètre) est plus petite que la donnée du noeud retourne -1
    else if(*n > *d){

        return -1;
    }
    // si la donnée est egale retourne 0
    else if(*n == *d){

        return 0;    
    }
    // sinon retourne -2
    else{
        return -2;
    }
      
}

/* ------------------------------------------------------------------------------
   Ajout d'un noeud dans une liste ordonnee, selon le resulat de "compare"
   -------------------------------------------------------------------------------
   head : pointeur de pointeur sur la tête de liste  
   compare : fonction de comparaison de la donnée en paramètre et du noeud courant
   data : donnée passée en paramètre pour l'ajout dans la liste ordonnée  
   -------------------------------------------------------------------------------
   retourne la tete de liste
   -------------------------------------------------------------------------------
*/

s_node * list_orderedAppend(s_node ** head, int (*compare)(s_node *, void *), void *data){
    s_node * cur;
    s_node * prec;
    cur = *head;
    prec = *head;
    // déclaration de la variable res_compare pour le resultat de la fonction compare
    int * val_data = (int*) data;
    int res_compare = compare(cur, data);
    // allocation mémoire pour un nouveau noeud 
    s_node * node = (s_node*) (malloc(sizeof node));
     if(node == NULL){
        printf("Erreur malloc");
        exit(1);
    }
    node->val = data;
    node -> next = NULL;
     if(*head == NULL){
         node -> val = data;
        *head = node;
    }
    else if(res_compare == -1){
        return list_insert(*head, data);
    }
    else{
        
        while(cur != NULL && res_compare != -1 && res_compare != 0){
           
            prec = cur;
            cur = cur -> next;
            if(cur != NULL){
                res_compare = compare(cur, data);
                
            } 
        }
        if(res_compare == -1){
            node -> next = cur;
            prec -> next = node;
        }
        else if(res_compare == 0){
            return cur;
        }
        else if(cur == NULL){
            node -> next = cur;
            prec -> next = node;
        }
        else{
            printf("Aucun ajout n'a été fait !\n");
        }
    }
    
    
    return *head;
}

/* ------------------------------------------------------------------------------------------
   Suppression de la premiere instance d'une, donnee dans la liste, retourne la tete de liste
   ------------------------------------------------------------------------------------------
   head : la tête de liste  
   data : donnée passée en paramètre pour sa suppression dans la liste 
   ------------------------------------------------------------------------------------------
   retourne la tete de liste
   ------------------------------------------------------------------------------------------
*/


s_node * list_remove(s_node * head, void * data){
    // affectation de la tête de liste à un pointeur
    s_node * cur = head;
    // declaration d'un nouveau pointeur pour accueillir le noeud precedent 
    s_node * prec = NULL;
    // si c'est la tête de liste on l'efface et retourne le noeud suivant 
    if(cur-> val == data){
        head = cur -> next;
        return head;
    }
    // boucle wile tant qu'on atteint pas la fin de la liste et qu'on a pas trouver la donnée dans la liste ou efface l'instance
    while(cur -> next != NULL){
        // si on trouve la donnée 
        if(cur -> val == data){
            // on affecte le pointeur de la donnée suivante du noeud precedent 
            // au pointeur de la donnée suivante du noeud egale à la data
            prec -> next = cur -> next;
            // on libert le noeud egale à la data
            free(cur); 
            // break pour sortir de la boucle
            break;
        }
        // pointeur prec egale au noeud en cours
        prec = cur;
        // pointeur cur egale à la prochaine donnée suivante du noeud (pour le parcours)
        cur = cur -> next;
     
    }
    
    return head;
    
}

/* -----------------------------------------------------------------
   Suppression de la tete de liste 
   -----------------------------------------------------------------
   head : tête de liste à effacer
   -----------------------------------------------------------------
   retourne la nouvelle tete de liste
   -----------------------------------------------------------------
*/
s_node * list_headRemove(s_node * head){
    // affectation de l'adresse de la valeur de la tête de la liste au pointeur cur    
    s_node * cur = head;
    // affectation de l'adresse de la valeur de la prochaine donnée de la liste au pointeur prec 
    s_node * prec = cur -> next;
    // remplacement de la donnée tête de liste avec la prochaine donnée de la liste se trouvant dans prec
    head = prec;
    // on efface la tête de liste 
    free(cur);

    return head;
}

/* -----------------------------------------------------------------
   Destruction d'une liste 
   -----------------------------------------------------------------
   head : tête de liste 
   -----------------------------------------------------------------
   pas de retour
   -----------------------------------------------------------------
*/
void list_destroy(s_node * head){
    // affectation de la tête de liste pour le parcours de la liste
    s_node * cur = head;
    // declaration d'un noeud de pointeur pour affecter la donnée deja lue pour être effacer
    s_node * prec;
    // parcours de la liste avec une boucle while
    while(cur  != NULL){
        // affectation de la donnée deja lue
        prec = cur ;
        // affectation de la donnée suivante dans la liste
        cur = cur ->next;
        // liberation de la memoire pour la donnée deja lue
        free(prec);
    }
    head = NULL;
}

