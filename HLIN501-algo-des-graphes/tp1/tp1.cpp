#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void afficheEdge(int n, int m, int tab[][2]) {
  cout << "Edge : [";
  for (int i = 0; i < m; i++) {
    cout << tab[i][0] << "." << tab[i][1]; 
    (i != m-1) ? cout << ", " : cout << "";	
  }
  cout << "]" << endl;
}

void afficheComp(int n, int tab[]) {
  cout << "Comp : [";
  for (int i = 0; i < n; i++) {
    cout << tab[i]; 
    (i != n-1) ? cout << ", " : cout << "";	
  }
  cout << "]" << endl;
}

// void afficheNbComp(int n, int tab[]) {
//   cout << endl;
//   for (int i = 1; i < n; i++) {
//     if (i == 0 && tab[i] != 0) {
//       cout << "Il y a " << tab[0] << " point(s) isole(s)." << endl;
//     }
//     if (tab[i] != 0) {
//       cout << "Il y a " << tab[i] << " composante(s) de taille " << i << "." << endl;     
//     }
//   }
//   cout << endl;
// }

void grapheRandom(int n, int m, int edge[][2]) {    
  for (int i = 0; i < m; i++) {
    edge[i][0] = rand()%n;
    edge[i][1] = rand()%n;
  }
}

/*  Entrée: Un graphe (liste d'arêtes)
    Sortie: Un tableau comp, de tel sorte que si comp[x] = comp[y], 
      alors x et y appartiennent à la même composante 
      (il existe un chemin de x à y)
    Complexité: O(n²)
*/
void composantes(int n, int m, int edge[][2], int comp[]) {
  for (int v = 0; v < n; v++) {
    comp[v] = v;
  }
  for (int e = 0; e < m; e++) {
    int x = edge[e][0];
    int y = edge[e][1];
    if (comp[x] != comp[y]) {
      int aux = comp[x];
      for (int v = 0; v < n; v++) {
	      if (comp[v] == aux) {
	        comp[v] = comp[y];
	      }
      }
    }
  }
}

/*  Entrée: Un graphe (liste d'arêtes)
    Sortie: Un tableau comp, de tel sorte que si comp[x] = comp[y], 
      alors x et y appartiennent à la même composante 
      (il existe un chemin de x à y)
    Complexité: O(m + n*log(n)) car un sommet change au plus log(n) fois 
      de numéro de composante.
*/
void composantesOpti(int n, int m, int edge[][2], int comp[]) {
  stack<int> L[n]; // liste des sommets de comp[x], gérée par une pile
  int t[n]; // taille de comp[x]
	
  for (int i=0; i<n; i++) {
    t[i] = 0;
  } 
  for (int i=0; i<n; i++) {
    comp[i] = i;
    L[comp[i]].push(i);
    t[comp[i]] = 1;
  }
  for (int i=0; i<m; i++) { 
    int x = edge[i][0];
    int y = edge[i][1];
    if (comp[x] != comp[y]) {
      if (t[comp[x]] > t[comp[y]]) {
	      swap(x, y);
      }
      int aux = comp[x];
      t[comp[y]] += t[aux];
      while (!L[aux].empty()) {
	      comp[L[aux].top()] = comp[y];
	      L[comp[y]].push(L[aux].top());
	      L[aux].pop();
      }
    }
  }
}

void ecritureTailles(int n, int m, int comp[]) {
  int nbeComp[n]; // tableau contenant le nombre de la même composante
  int nbOcc[n]; // tableau contenant le nombre pour chaque taille de composante
  for (int i=0; i<n; i++) {
    nbeComp[i] = 0;
    nbOcc[i] = 0;  
  } 

  for(int i = 0; i < n; i++) {
    nbeComp[comp[i]]++;
  }
  for(int j = 0; j < n; j++) {
    if (nbeComp[j] > 0) {
      nbOcc[nbeComp[j]]++;
    }
  }
  for(int k = 0; k < n; k++) {
    if (nbOcc[k] > 0) {
      cout << "Il y a " << nbOcc[k] << " composantes de taille " << k << endl;
    }
  }
}

int main() { 
  srand(time(NULL));
  int n;     // Nombre de sommets.	
  int m;     // Nombre d'aretes.	
  cout << "Entrer le nombre de sommets : ";
  cin >> n;
  cout << "Entrer le nombre d'aretes : ";
  cin >> m;
  int edge[m][2];    // Tableau des aretes.
  int comp[n];       // comp[i] est le numero de la composante contenant i.
  // int tailleComp[n];
  // int nbComp[n];

  grapheRandom(n, m, edge);
  afficheEdge(n, m, edge);
  composantesOpti(n, m, edge, comp);
  afficheComp(n, comp);
  ecritureTailles(n, m, comp);

  return EXIT_SUCCESS;
}
/*
  n : 10000
  m : 5000
  points isolés : 3676 / 3646 / 3718

  n : 10000
  m : 7500
  points isolés : 2240 / 2196 / 2268

  n : 10000
  m : 10000
  points isolés : 1312 / 1399 / 1367

  pour n = m :
  nb sommet isolés = 1/e^2 = 0.1353
*/

/*
  tableau statique de piles
  vider la plus petite pile dans la plus grande pile
  page 21 : canva de l'implémentation de l'optimisation
*/
