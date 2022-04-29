struct _list_node {
    void * val;
    struct _list_node * next;
};
typedef struct _list_node s_node;
s_node * list_create(void);
        // creation d'une nouvelle liste vide
void * list_get_data(s_node * node);
        // lire la donnee d'un noeud
void list_set_data(s_node * node, void * data);
        // ecrire la donnee d'un noeud
s_node * list_insert(s_node * head, void * data);
        // creation et insertion d'un noeud en tete de liste
        //   retourne la tete de liste
s_node * list_append(s_node * head, void * data);
        // creation et ajout d'un noeud en queue de liste
        //   retourne la tete de liste
int compare(s_node * node, void * data);
s_node * list_orderedAppend(s_node ** head,
                            int (*compare)(s_node *, void *),
                            void *data);
        // ajout d'un noeud dans une liste ordonnee
        // selon le resulat de "compare" ;
        // si la donnee existe deja, elle n'est pas ajoutee
s_node * list_remove(s_node * head, void * data);
        // suppression de la premiere instance d'une
        // donnee dans la liste, retourne la tete de liste
s_node * list_headRemove(s_node * head);
        // suppression de la tete de liste
        // retourne la nouvelle tete de liste
void list_destroy(s_node * head);
        // destruction d'une liste
        //  (La liberation des donnees n'est pas prise en charge)
struct _list_node;
typedef struct _list_node s_node;

/* -----------------------------------------------------------------
   Conversion d'un noeud pointant sur une donnée de type int
	en chaine de caracteres
   -----------------------------------------------------------------
   node		: pointeur sur le noeud à convertir
   buffer (PS) 	: tampon contenant la chaine obtenue
   size		: taille maximum de la chaine
   -----------------------------------------------------------------
   retourne 1 si la chaine converti est trop longue pour le tampon
	    0 sinon
   -----------------------------------------------------------------
*/
int node_int_to_string(s_node * node, 
		       char *buffer, 
		       int size);


/* -----------------------------------------------------------------
   Conversion des données d'une liste en chaine de caracteres
	Les donnéees sont separees par ->
   -----------------------------------------------------------------
   head		 : pointeur sur la tete de liste
   node_to_string: fonction pour convertir la valeur d'un noeud
   -----------------------------------------------------------------
   retourne  la chaine de caractères representant la liste
   -----------------------------------------------------------------
*/
char *  list_to_string (s_node * head,  
		        int (*node_to_string)(s_node * node, char * buffer, 
			int buffer_size));

/* -----------------------------------------------------------------
   Compare la chaine representant une liste a une chaine attendu 
   -----------------------------------------------------------------
   head		 : pointeur sur la tete de liste
   node_to_string: fonction pour convertir la valeur d'un noeud
   waites	 : chaine de caractère attendue
   -----------------------------------------------------------------
   retourne 1 si le résultat recu est celui attendu
            0 sinon
   -----------------------------------------------------------------
*/
int check_list_state (s_node * head,  
		      int (*node_to_string)(s_node * node, char * buffer, int size),
		      const char * waited);



