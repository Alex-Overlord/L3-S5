#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h> 
#include <algorithm> // heap (tas)

using namespace std;

const int N = 1400;
const int M = (N*(N-1))/2;
  
typedef struct coord { int abs; int ord; } coord;

void pointRandom(int n, coord point[]);
float distance(coord p1, coord p2);
void voisins(int n, int dmax,coord point[], vector<int> voisin[], int &m);
void voisins2arete(int n, vector<int> voisin[], int arete[][2]);
void affichageGraphique(int n, int m, coord point[], int arete[][2], string name);
bool existe(int n, int dis[], bool traite[], int &x);
void dijkstra(int n, vector<int> voisin[], coord point[], int pere[]);
int construireArbre(int n, int arbre[][2], int pere[]);

void printArete(int m, int arete[][2]) {
  cout << "> printArete :" << endl;
  for (int i=0; i<m; i++) {
    cout << "a" << i << " = (" << arete[i][0] << ", " << arete[i][1] << ")" << " ";
  } 
  cout << endl;
}

void pointRandom(int n, coord point[]) {
  for (int i=0; i<n; i++) {
    point[i].abs = rand()%612;
    point[i].ord = rand()%792;
  }
}
void pointRandomCC(int n, coord point[]) {
  for (int i = 0; i < n; i++) {
    point[i].abs = i * 60;
    point[i].ord = i * 60;
  }
}

float distance(coord p1, coord p2) {
  return sqrt((p1.abs - p2.abs) * (p1.abs - p2.abs) 
      + (p2.ord - p1.ord) * (p2.ord - p1.ord));
}

bool isIn(vector<int> array, int e) {
  for (int i=0; i<array.size(); i++) {
    if (array[i] == e) {
      return true;
    }
  }
  return false;
}

// Rempli le tableau de vector voisin selon le dmax
void voisins(int n, int dmax, coord point[], vector<int> voisin[], int &m) {
  m = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i != j && (distance(point[i], point[j]) <= dmax) 
          && !isIn(voisin[i], j) && !isIn(voisin[i], j)) {
        voisin[i].push_back(j);
        voisin[j].push_back(i);
        m++;
      }
    }
  }
}

// Rempli le tableau arete à l'aide du tableau voisin
void voisins2arete(int n,vector<int>voisin[],int arete[][2]) {
  int m = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < voisin[i].size(); j++) {
      arete[m][0] = i;
      arete[m][1] = voisin[i][j];
      m++;
    }
  }
}
void voisins2areteCC(int n,vector<int>voisin[],int arete[][2]) {
  int m = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < voisin[i].size(); j++) {
      arete[m][0] = i + 1;
      arete[m][1] = voisin[i][j] + 1;
      m++;
    }
  }
}

void affichageGraphique(int n, int m, coord point[], int arete[][2], string name) {
  ofstream output;                           
  output.open(name + ".ps", ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  

  for (int i=0; i<n; i++) {
    output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
    output << "0 setgray" << endl;
    output << "fill" << endl;
    output << "stroke" << endl;
    output << endl;
  }
  output << endl;

  for (int i=0; i<m-1; i++) {
    output << point[arete[i][0]].abs << " " << point[arete[i][0]].ord << " moveto" << endl;
    output << point[arete[i][1]].abs << " " << point[arete[i][1]].ord << " lineto" << endl;
    output << "stroke" << endl;
    output << endl;
  }

  output << "showpage";
  output << endl;
}

bool existe(int n, int dis[], bool traite[], int &x) {
  bool result = false;
  int dmin = -1;
  for (int i=0; i<n; i++) {
    if (traite[i] == false) {
      result = true;
      if (dmin == -1 || dis[i] < dmin) {
        x = i;
        dmin = dis[i];
      }
    }   
  }
  return result;
}

/*
  Complexité: O(n²)
 */
void dijkstra(int n, vector<int> voisin[], coord point[], int pere[]) {
  int r = 0;
  int d[n];
  bool traite[n];
  int x;

  for (int i=0; i<n; i++) {
    d[i] = 100000;
    pere[i] = -1;
    traite[i] = 0;
  }
  d[r] = 0;
  pere[r] = r;

  while (existe(n, d, traite, x)) {
    traite[x] = true;
    for (int i=0; i<voisin[x].size(); i++) {
      int y = voisin[x][i];
      if (traite[y] == 0 && d[y] > d[x] + distance(point[x], point[y])) {
        d[y] = d[x] + distance(point[x], point[y]); // x est racourci pour atteindre y
        pere[y] = x;
      }
    }
  }
}

/* PAS FINI
  Complexité: O(m * log(n))
 */
void dijkstraOpti(int n, vector<int> voisin[], coord point[], int pere[]) {
  int r = 0;
  int d[n];
  bool traite[n];
  int x;

  for (int i=0; i<n; i++) {
    d[i] = 100000;
    pere[i] = -1;
    traite[i] = 0;
  }
  d[r] = 0;
  pere[r] = r;

  while (existe(n, d, traite, x)) {
    traite[x] = true;
    for (int i=0; i<voisin[x].size(); i++) {
      int y = voisin[x][i];
      if (traite[y] == 0 && d[y] > d[x] + distance(point[x], point[y])) {
        d[y] = d[x] + distance(point[x], point[y]); // x est racourci pour atteindre y
        pere[y] = x;
      }
    }
  }
}

int construireArbre(int n, int arbre[][2], int pere[]) {
  int k = 0;
  for (int i=0; i<n; i++) {
    if (pere[i] > -1) {
      arbre[i][0] = i;
      arbre[i][1] = pere[i];
      k++;  
    }
  }
  return k;
}

int main()
{
  srand(time(NULL));
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax = 50;                   // La distance jusqu'à laquelle on relie deux points.
  coord point[N];                  // Les coordonnées des points.
  vector<int> voisin[N];           // Les listes de voisins.        
  int arbre[N-1][2];               // Les arêtes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'arêtes
  int arete[M][2];                 // Les arêtes du graphe
  int k;

  pointRandom(n, point);
  voisins(n, dmax, point, voisin, m);
  // voisins2arete(n, voisin, arete);
  voisins2areteCC(n, voisin, arete);
  affichageGraphique(n, 2*m, point, arete, "Graphe");

  dijkstra(n, voisin, point, pere);
  k = construireArbre(n, arbre, pere);
  affichageGraphique(n, k, point, arbre, "Arbre");
  // printVoisin(n, voisin);
  // printArete(n, arete);

  cout << "m = " << m << endl;
  return EXIT_SUCCESS;
}