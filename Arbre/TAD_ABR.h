//  TAD ABR


// Types pour implanter le TAD ABR
typedef int Info;

typedef struct noeud {
  Info val;
  struct noeud *g, *d;
} Noeud;

typedef Noeud *ABR;


// creation d'un ABR (retourne un accès à une feuille-racine initialisée)
ABR creer_feuilleABR(Info v);

// teste si un ABR est vide
int est_videABR(ABR abr);

// teste si un ABR est une feuille
int est_feuilleABR(ABR abr);

// rend la valeur de la racine d'un ABR
Info valracABR(ABR abr);

// retourne le fils gauche d'un ABR
ABR gaucheABR(ABR abr);

// retourne le fils droit d'un ABR
ABR droitABR(ABR abr);

// libère la mémoire allouée à un ABR
void detruireABR(ABR abr);

// ajout d'une valeur aux feuilles dans un arbre binaire de recherche
ABR ajout_f(Info v, ABR A);

// affiche l'arbre dans l'ordre prefixe
void affiche_prefixe(ABR A);

// affiche l'arbre dans l'ordre infixe
void affiche_infixe(ABR A);

// affiche l'arbre dans l'ordre postfixe
void affiche_postfixe(ABR A);

// retourne la plus petite valeur d'un arbre
Info min (ABR A);

// retourne la plus grande valeur d'un arbre
Info max (ABR A);

// retourne 1 si A est dans un domaine plus petit que B sinon 0
int dom_inclus(ABR A, ABR B);

// retourne la hauteur d'un arbre
int hauteur(ABR A);

