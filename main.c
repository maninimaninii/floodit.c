#include <stdlib.h>
#include <stdio.h>

// "constantes"
#define TAILLE 12
#define NB_COLORS 6
#define NB_ESSAIS 22

#define FG_SHIFT 30
#define BG_SHIFT 40

// type de donnees
typedef enum {BLACK = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, MAX_COLORS} ColorCode;

// prototypes
//M est un vecteur qui stock l'adresse des valeurs


ColorCode ** creeGrille (){

	int **M;
	M= malloc(TAILLE*sizeof(int *));
	for (int i=0;i<TAILLE;++i){
		M[i]=malloc(TAILLE*sizeof(int *));
	}
	for (int i=0;i<TAILLE;++i){
		for (int j=0;j<TAILLE;++j){
			M[i][j]=0;
		} }
		return **M;
	}
                                         // A FAIRE
void detruitGrille (ColorCode ***M){
	for(int i=0;i<TAILLE;++i){
	free(M[i]);
		}
	free(M);
	}

void afficheGrille (ColorCode **M){
	for (int i=0;i<TAILLE;++i){
 	 for (int j=0;j<TAILLE;++j){
 		 afficheCouleur(M[i][j]);
 	 } }
};
int alea(int a,int b){

	return (a+(rand()%(b-a+1)));
}
                                 // A FAIRE
void randomGrille (ColorCode **, int, int);                     // A FAIRE
int isFlooded (ColorCode **M){
	for (int i=0;i<TAILLE;++i){
		for (int j=0;j<TAILLE;++j){
			M[i][j]=alea(BLACK,MAX_COLORS);
		} }

	};                                      // A FAIRE
void propagate (ColorCode **M, int i, int j, ColorCode new_col, ColorCode anc_col){
	if (M[i][j] != anc_col){return;}
		else
			{
        // met nouveau pixel avec la nouvelle couleur
        M[i][j]= new_col;}
};                          // A FAIRE
void propagate_rec (ColorCode **M, ColorCode new_col, ColorCode anc_col, int i , int j){
	if (M[i][j] != anc_col){return;}
		else
			{
        // met nouveau pixel avec la nouvelle couleur
        M[i][j]= new_col;

        // appel recursif pour le pixel du bas
        propagate_rec(M, new_col, anc_col,i + 1, j);

        // appel recursif pour le pixel du haut
        propagate_rec(M, new_col, anc_col,i - 1, j);

        // appel recursif pour le pixel à droite
        propagate_rec(M, new_col, anc_col,i, j+1);

        // appel recursif pour le pixel à gauche
        propagate_rec(M, new_col, anc_col,i, j-1);
    }

}; // A FAIRE
void play (int, int, int);                                              // A TERMINER


// implementations
void afficheCouleur (int fg, int bg, char c)
{
  printf("\033[%d;%dm %c\033[m", FG_SHIFT + fg, BG_SHIFT + bg, c);
}


/*void play (int t, int nb_col, int n)
{
  ColorCode ** G;
  int res = -1;

  // initialisation
  G = creeGrille (t);
  randomGrille (G, t, nb_col);
  afficheGrille (G);

  // boucle principale
  for (int i = 0; i < n; ++i)
  {
    // A FAIRE
  }

  // resultats
  if (res == -1)
    printf("Bye!\n");
  else if (isFlooded(G))
    printf("GAGNE!\n");
  else
    printf("PERDU!\n");

  // desallocation memoire
  detruitGrille(&G);
}*/



int main ()
{
    ColorCode** M = creeGrille();
	afficheGrille(M);
  return EXIT_SUCCESS;
}

