#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "TAD_ABR.h"


// creation d'un ABR (retourne un accès à une feuille-racine initialisée)
ABR creer_feuilleABR(Info v)
{
  ABR abr = (ABR)malloc(sizeof(Noeud));

  abr->val = v;
  abr->g = NULL;
  abr->d = NULL;

  return abr;
}

// teste si un ABR est vide
int est_videABR(ABR abr)
{
  return (abr == NULL);
}

// teste si un ABR est une feuille
int est_feuilleABR(ABR abr)
{
  assert(!(abr==NULL));		/* l'arbre ne doit pas être vide */
  return (est_videABR(abr->g) && est_videABR(abr->d));
}

// rend la valeur de la racine d'un ABR
Info valracABR(ABR abr)
{
  assert(!(abr==NULL));		/* l'arbre ne doit pas être vide */
  return (abr->val);
}

// retourne le fils gauche d'un ABR
ABR gaucheABR(ABR abr)
{
  assert(!(abr==NULL));		/* l'arbre ne doit pas être vide */
  return abr->g;
}

// retourne le fils droit d'un ABR
ABR droitABR(ABR abr)
{
  assert(!(abr==NULL));		/* l'arbre ne doit pas être vide */
  return abr->d;
}

// libère la mémoire allouée à un ABR
void detruireABR(ABR abr)
{
  if (abr!=NULL) {
                 detruireABR(abr->g);
                 detruireABR(abr->d);
                 free(abr);
                 }
}

ABR ajout_f(Info v, ABR A)
{
   if(est_videABR(A))
    {
        A = creer_feuilleABR(v);
    }
    else if( v > (A->val))
    {
        A->d = ajout_f(v,A->d);
    }
    else
    {
        A->g = ajout_f(v,A->g);
    }

    return A;
}

void affiche_prefixe(ABR A)
{
    if(A == NULL)
    {
        return;
    }
    else
    {
        printf("(%d) ", A->val);
        if(A->g != NULL)
        {
            affiche_prefixe(A->g);
        }
        if(A->d != NULL)
        {
            affiche_prefixe(A->d);
        }

    }
}

void affiche_infixe(ABR A)
{
     if(A == NULL)
    {
        return;
    }
    else
    {
        if(A->g != NULL)
        {
            affiche_prefixe(A->g);
        }
        printf("(%d) ", A->val);
        if(A->d != NULL)
        {
            affiche_prefixe(A->d);
        }

    }
}

void affiche_postfixe(ABR A)
{
      if(A == NULL)
    {
        return;
    }
    else
    {
        if(A->g != NULL)
        {
            affiche_postfixe(A->g);
        }

        if(A->d != NULL)
        {
            affiche_postfixe(A->d);
        }
        printf("(%d) ", A->val);

    }
}

Info min (ABR A)
{
    Info min_abre;
    if (A != NULL)
    {
        if (A->g == NULL)
        {
            min_abre = A->val;
        }
        else
        {
           min_abre = min(A->g);
        }
    }
    return min_abre;
}

Info max (ABR A)
{
    Info max_arbre;
    if (A != NULL)
    {
        if (A->d == NULL)
        {
            max_arbre = A->val;
        }
        else
        {
            max_arbre = max(A->d);
        }
    }
    return max_arbre;
}

int dom_inclus(ABR A, ABR B)
{
    if(min(A) >= min(B) && max(A) <= max(B))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//j'ai pris la racine en compte
int hauteur (ABR A)
{
    int hg,hd;
    int h;
    if(A == NULL)
    {
        return 0;
    }
    else
    {
        hg = 1 + hauteur(A->d);
        hd =  1 + hauteur(A->g);
    }
    if(hg > hd)
    {
        h = hg;
    }
    else if(hd > hg)
    {
        h = hd;
    }
    else
    {
        h = hg;
    }
return h;
}
void test1(void)
{
  ABR B1 = NULL, B2 = NULL, B3 = NULL, B4 = NULL, B5 = NULL, B6 = NULL;

      B1 = NULL;
      B1 = ajout_f(10, B1);
      B1 = ajout_f(20, B1);
      B1 = ajout_f(30, B1);
      printf("Affichage prefixe de l'arbre B1 : "); affiche_prefixe(B1); printf("\n");
      printf("Affichage infixe de l'arbre B1 : "); affiche_infixe(B1); printf("\n");
      printf("Affichage postfixe de l'arbre B1 : "); affiche_postfixe(B1); printf("\n\n");

      B2 = NULL;
      B2 = ajout_f(10, B2);
      B2 = ajout_f(30, B2);
      B2 = ajout_f(20, B2);
      printf("Affichage prefixe de l'arbre B2 : "); affiche_prefixe(B2); printf("\n");
      printf("Affichage infixe de l'arbre B2 : "); affiche_infixe(B2); printf("\n");
      printf("Affichage postfixe de l'arbre B2 : "); affiche_postfixe(B2); printf("\n\n");

      B3 = NULL;
      B3 = ajout_f(20, B3);
      B3 = ajout_f(10, B3);
      B3 = ajout_f(30, B3);
      printf("Affichage prefixe de l'arbre B3 : "); affiche_prefixe(B3); printf("\n");
      printf("Affichage infixe de l'arbre B3 : "); affiche_infixe(B3); printf("\n");
      printf("Affichage postfixe de l'arbre B3 : "); affiche_postfixe(B3); printf("\n\n");

      B4 = NULL;
      B4 = ajout_f(20, B4);
      B4 = ajout_f(30, B4);
      B4 = ajout_f(10, B4);
      printf("Affichage prefixe de l'arbre B4 : "); affiche_prefixe(B4); printf("\n");
      printf("Affichage infixe de l'arbre B4 : "); affiche_infixe(B4); printf("\n");
      printf("Affichage postfixe de l'arbre B4 : "); affiche_postfixe(B4); printf("\n\n");

      B5 = NULL;
      B5 = ajout_f(30, B5);
      B5 = ajout_f(10, B5);
      B5 = ajout_f(20, B5);
      printf("Affichage prefixe de l'arbre B5 : "); affiche_prefixe(B5); printf("\n");
      printf("Affichage infixe de l'arbre B5 : "); affiche_infixe(B5); printf("\n");
      printf("Affichage postfixe de l'arbre B5 : "); affiche_postfixe(B5); printf("\n\n");

      B6 = NULL;
      B6 = ajout_f(30, B6);
      B6 = ajout_f(20, B6);
      B6 = ajout_f(10, B6);
      printf("Affichage prefixe de l'arbre B6 : "); affiche_prefixe(B6); printf("\n");
      printf("Affichage infixe de l'arbre B6 : "); affiche_infixe(B6); printf("\n");
      printf("Affichage postfixe de l'arbre B6 : "); affiche_postfixe(B6); printf("\n\n");

  detruireABR(B1);
  detruireABR(B2);
  detruireABR(B3);
  detruireABR(B4);
  detruireABR(B5);
  detruireABR(B6);
}


/* Test de la deuxieme partie */
void test2(void)
{
  ABR A = NULL, B = NULL, B2 = NULL, B3 = NULL;
	A = ajout_f(20, A);
    A = ajout_f(10, A);
	A = ajout_f(30, A);
	A = ajout_f(15, A);
	A = ajout_f(40, A);

	B = ajout_f(10, B);
    B = ajout_f(5, B);
    B = ajout_f(30, B);
    B = ajout_f(52, B);

    B2 = ajout_f(23, B2);
    B2 = ajout_f(15, B2);
    B2 = ajout_f(30, B2);

    B3 = ajout_f(15, B3);
    B3 = ajout_f(5, B3);
    B3 = ajout_f(30, B3);
    B3 = ajout_f(22, B3);

      printf("Affichage infixe de l'arbre A : ");
      affiche_infixe(A);
      printf("\n");
      if (!est_videABR(A))
	     printf("min(A) = %d, max(A) = %d, hauteur(A) = %d\n\n",min(A),max(A),hauteur(A));

      printf("Affichage infixe de l'arbre B : ");
      affiche_infixe(B);
      printf("\n");
      if (!est_videABR(B))
	     printf("min(B) = %d, max(B) = %d, hauteur(B) = %d\n",min(B),max(B),hauteur(B));

      if (dom_inclus(A, B))
	     printf("A est de domaine plus petit que B\n");
      else
          if (dom_inclus(B, A))
	         printf("B est de domaine plus petit que A\n");
	      else printf("A n'est pas de domaine plus petit que B et reciproquement\n");

    printf("\nAffichage infixe de l'arbre B2 : ");
      affiche_infixe(B2);
      printf("\n");
      if (!est_videABR(B2))
	     printf("min(B2) = %d, max(B2) = %d, hauteur(B2) = %d\n",min(B2),max(B2),hauteur(B2));

      if (dom_inclus(A, B2))
	     printf("A est de domaine plus petit que B2\n");
      else
          if (dom_inclus(B2, A))
	         printf("B2 est de domaine plus petit que A\n");
	      else printf("A n'est pas de domaine plus petit que B2 et reciproquement\n");

	printf("\nAffichage infixe de l'arbre B3 : ");
      affiche_infixe(B3);
      printf("\n");
      if (!est_videABR(B3))
	     printf("min(B3) = %d, max(B3) = %d, hauteur(B3) = %d\n",min(B3),max(B3),hauteur(B3));

      if (dom_inclus(A, B3))
	     printf("A est de domaine plus petit que B3\n");
      else
          if (dom_inclus(B3, A))
	         printf("B3 est de domaine plus petit que A\n");
	      else printf("A n'est pas de domaine plus petit que B3 et reciproquement\n");

  detruireABR(A);
  detruireABR(B);
  detruireABR(B2);
  detruireABR(B3);
}





/* corps du programme */
int main(void)
{
  	printf("\nTest de la premiere partie \n\n\n");
	test1();

	printf("\n----------------------------------------------------------------- \n");
	printf("\nTest de la seconde partie \n\n\n");
	test2();

  return 0;
}

