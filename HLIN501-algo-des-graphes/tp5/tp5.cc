#include <iostream>
#include <vector>

using namespace std;

const int N = 5;
const int M = 6;
const int INF = 9999;                      // La valeur infinie.

void floydWarshall(int longueur[][N], int dist[][N], int chemin[][N]);
void affichage(int dist[][N], int chemin[][N]);
void itineraire(int i, int j, int chemin[][N]);

/*
  Complexité: O(n³)
 */
void floydWarshall(int longueur[][N], int dist[][N], int chemin[][N]) {
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (longueur[i][j] != INF) {
        cout << "dist[" << i << "][" << j << "] := " << longueur[i][j] << endl;
        dist[i][j] = longueur[i][j];
        chemin[i][j] = j;
      } else {
        dist[i][j] = INF;
        chemin[i][j] = -1; // ou 0
      }
    }
    dist[i][i] = 0;
    chemin[i][i] = i;
  }
  for (int k=0; k<N; k++) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j]; // k est un raccourci pour aller de i à j
          chemin[i][j] = chemin[i][k];
        }
      }
    }
  }
  for (int i=0; i<N; i++) {
    if (dist[i][i] < 0) {
      cout << "Il exist un cycle orienté de poids < 0." << endl;
      return;
    }
  }
}

void affichage(int dist[][N], int chemin[][N]) {
  cout << "> dist:" << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (dist[i][j] >= 0) cout << " ";
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
  cout << "> chemin:" << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (chemin[i][j] >= 0) cout << " ";
      cout << chemin[i][j] << " ";
    }
    cout << endl;
  }
}

void itineraire(int i, int j, int chemin[][N]) {
  cout << "Depart: " << i << " ";
  cout << "Destination: " << j << " ";
  cout << "Itinéraire: ";
  int a = i;
  int b = chemin[i][j];
  int tmp;
  cout << i << " ";
  while (a != b) {
    cout << b << " ";
    a = b;
    b = chemin[b][j];
  }
  cout << endl;
}

void allItineraire(int chemin[][N]) {
  for (int l=0; l<N; l++) {
    for (int c=0; c<N; c++) {
      itineraire(l, c, chemin);
    }
  }
}

void afficheM(int tab[][M]) {
  cout << "> afficheM:" << endl;
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) {
      if (tab[i][j] >= 0) cout << " ";
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
}

void fermetureTransitive(int arc[][M], int fermeture[][M]) {  
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) {
      fermeture[i][j] = arc[i][j];
    }
  }
  for (int k=0; k<M; k++) {
    for (int i=0; i<M; i++) {
      for (int j=0; j<M; j++) {
        if (fermeture[i][k] + fermeture[k][j] == 2) {
          fermeture[i][j] = 1;
        }       
      }   
    }
  }
}

void compFortConnexe(int fermeture[][M]) {
  int comp[M]; int aux;
  int c;

  for (int i=0; i<M; i++) {
    comp[i] = i;
  }

  for (int i=0; i<M; i++) {
    for (int j=i; j<M; j++) {
      if (fermeture[i][j] + fermeture[j][i] == 2) {
        aux = i;
        for (int k=0; k<M; k++) {
          if (comp[k] == aux) {
            comp[k] = comp[j];
          }
        }
      }
    }
  }
  
  for (int i=0; i<M; i++) {
    cout << "comp[" << i << "] = " << comp[i] << endl;
  }

  vector<int> element[M];
  
  int nbeComp[M] = {0};
  for (int i=0; i<M; i++) {
    nbeComp[comp[i]]++;
    element[comp[i]].push_back(i);
  }
  int compteur = 0;
  for (int j=0; j<M; j++) {
    if (nbeComp[j] > 0) {
      compteur++;
    }
    if (element[j].size() > 0) {
      cout << " {";
      for (int i=0; i<element[j].size(); i++) {
        cout << element[j][i] << ",";
      }
      cout << "}, ";
    }
  }
  cout << endl << "nombre de composante: " << compteur << endl;
}

int main() {          
  #pragma region Exo 1,2,3,4
                         // 0    1    2    3    4
  int longueurOld[N][N] = {{0  , 2  , INF, 4  , INF},   // Les longueurs des arcs.
	                   	  {INF, 0  , 2  , INF, INF},  // longueur[i][j]=INF si l'arc ij n'existe pas
		                 	  {INF, INF, 0  , 2  , INF},
		                 	  {INF, -3 , INF, 0  , 2},
		                 	  {2  , INF, INF, INF, 0}};
  int dist[N][N];         // Le tableau des distances.
  int chemin[N][N];       // Le tableau de la premiere etape du chemin de i a j.

  // floydWarshall(longueurOld, dist, chemin);
  // affichage(dist, chemin);
  // itineraire(1, 3, chemin);
  // allItineraire(chemin);
  #pragma endregion

  /* Exo 5: Fermeture transitive */
  const int M = 6;
  int arc[M][M]={{0,0,0,1,0,1}, // La matrice d’adjacences du graphe oriente D.
                 {1,0,1,1,0,0},
                 {0,0,0,1,0,0},
                 {0,0,0,0,1,1},
                 {0,0,1,0,0,1},
                 {0,0,1,0,0,0}};
  int fermeture[M][M];         // La matrice de la fermeture transitive de D.

  fermetureTransitive(arc, fermeture);
  afficheM(fermeture);
  compFortConnexe(fermeture);

  return EXIT_SUCCESS;
}