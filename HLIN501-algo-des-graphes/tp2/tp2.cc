#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <bits/stdc++.h> 
#include "tp2.h"

using namespace std;

void printEdge(int m, int edge[][3]) {
  cout << endl << "m = " << m << endl;
  for (int i=0; i<m; i++) {
    cout << "(" << edge[i][0] << ", " << edge[i][1] << ", " << edge[i][2] << ") ";
  }
  cout << endl;
}

void printArbre(int n, int arbre[][2]) {
  cout << endl << "n-1 = " << n-1 << endl;
  for (int i=0; i< n-1; i++) {
    cout << "(" << arbre[i][0] << ", " << arbre[i][1] << ") ";
  }
  cout << endl;
}

void pointRandom(int n, coord point[]) {
  for (int i = 0; i < n; i++) {
    point[i].abs = rand() % 612;
    point[i].ord = rand() % 792;
  }
}
void pointRandomCC(int n, coord point[]) {
  int k;
  for (int i = 0; i < n; i++) {
    point[i].abs = 10 * i;
    k = (((60 * i) - (i * i)) / 2);
    if (k < 0) {
      point[i].ord = -k;
    } else {
      point[i].ord = k;
    }
  }
}

// d = (Xa-Xb)² + (Ya-Yb)²
void distance(int n, int m, coord point[], int edge[][3]) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edge[k][0] = i;
      edge[k][1] = j;
      edge[k][2] = (point[i].abs - point[j].abs) * (point[i].abs - point[j].abs) 
      + (point[j].ord - point[i].ord) * (point[j].ord - point[i].ord); 
      k++;
    }
  }
}
// d = (Ya - Yb)²
void distanceCC(int n, int m, coord point[], int edge[][3]) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edge[k][0] = i;
      edge[k][1] = j;
      edge[k][2] = (point[i].ord - point[j].ord) * (point[i].ord - point[j].ord); 
      k++;
    }
  }
}

void tri_old(int m, int edge[][3]) {
  for (int i=0; i<m; i++) {
    for (int j=i; j<m; j++) {
      if (edge[j][2] < edge[i][2]) {
        swap(edge[j][0], edge[i][0]);
        swap(edge[j][1], edge[i][1]);
        swap(edge[j][2], edge[i][2]);
      }
    }
  }
}

void swap(int* a, int* b) {  
  int t = *a;  
  *a = *b;  
  *b = t;  
}  

int partition(int arr[][3], int low, int high) {  
  int pivot = arr[high][3]; // pivot  
  int i = (low - 1); // Index of smaller element  
  
  for (int j = low; j <= high - 1; j++) {  
    // If current element is smaller than the pivot  
    if (arr[j][3] < pivot) {  
      i++; // increment index of smaller element  
      swap(arr[i][0], arr[j][0]);  
      swap(arr[i][1], arr[j][1]);
      swap(arr[i][2], arr[j][2]);
    }  
  }  
  swap(arr[i + 1][0], arr[high][0]);  
  swap(arr[i + 1][1], arr[high][1]);  
  swap(arr[i + 1][2], arr[high][2]);  
  return (i + 1);  
}  
  
void quickSort(int arr[][3], int low, int high) {  
  if (low < high) {  
    /* pi is partitioning index, arr[p] is now  
    at right place */
    int pi = partition(arr, low, high);  
  
    // Separately sort elements before  
    // partition and after partition  
    quickSort(arr, low, pi - 1);  
    quickSort(arr, pi + 1, high);  
  }  
}  

int compare(const void * a,const void * b) {
  return ((int*)a)[2] - ((int*)b)[2];
}
void tri(int m, int edge[][3]) {
  qsort(edge,m,sizeof(edge[0]),compare);
}

/*  Objectif: Relier tous les sommets de G à coût minimum
    Entrée: Un graphe G connexe avec poids sur les arêtes
    Sortie: Un arbre couvrant de G de poids minimum
    Complexité: O(n² + m * log(n))
    Remarque: Est un algorithme glouton
*/
void kruskal(int n, int edge[][3], int arbre[][2]) {
  int comp[n-1];
  int a = 0;
  int m = n * (n-1) / 2;

  tri(m, edge);
	for (int v=0; v<n; v++) {
		comp[v] = v;
	}
	for (int e=0; e<m; e++) {
		int x = edge[e][0];
		int y = edge[e][1];
		if (comp[x] != comp[y]) {
			int aux = comp[x];
      arbre[a][0] = x;
      arbre[a][1] = y;
      a++;
			for (int z=0; z<n; z++) {
				if (comp[z] == aux) {
					comp[z] = comp[y];
				}
			}
		}
	}
}

/*  Objectif: Relier tous les sommets de G à coût minimum
    Entrée: Un graphe G connexe avec poids sur les arêtes
    Sortie: Un arbre couvrant de G de poids minimum
    Complexité: O(m * log(n))
*/
void kruskalOpti(int n, int edge[][3], int arbre[][2]) {
  int comp[n-1];
  int a = 0;
  int m = n * (n-1) / 2;
  int t[n]; // taille de comp[x]
  stack<int> L[n]; // liste des sommets de comp[x], gérée par une pile

  tri(m, edge);
  for (int v=0; v<n; v++) {
    comp[v] = v;
    L[comp[v]].push(v);
    t[comp[v]] = 1;
  }
  for (int e=0; e<m; e++) {
    int x = edge[e][0];
    int y = edge[e][1];
    if (comp[x] != comp[y]) {
      if (t[comp[x]] > t[comp[y]]) {
	      swap(x, y);
      }
      int aux = comp[x];
      arbre[a][0] = x;
      arbre[a][1] = y;
      a++;
      t[comp[y]] += t[aux];
      while (!L[aux].empty()) {
	      comp[L[aux].top()] = comp[y];
	      L[comp[y]].push(L[aux].top());
	      L[aux].pop();
      }
    }
  }
}

void affichageGraphique(int n, coord point[], int arbre[][2]) {
  ofstream output;                           
  output.open("ACPM.ps",ios::out); // Arbre Couvrant de Poid Minimum
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {
      output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
      output << "0 setgray" <<endl;
      output << "fill" <<endl;
      output << "stroke"<<endl;
      output << endl;
    }
  output << endl;
  for(int i=0;i<n-1;i++)
   {
     output << point[arbre[i][0]].abs << " " << point[arbre[i][0]].ord 
	    << " moveto" << endl;
     output << point[arbre[i][1]].abs << " " << point[arbre[i][1]].ord
	    << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
   }
  output << "showpage";
  output << endl;
}

int main() {
  srand (time(NULL));
  int n; // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m = n * (n-1) / 2; // Le nombre de paires de points.
  coord point[n]; // Les coordonnees des points dans le plan.
  int edge[m][3]; // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 

  // pointRandom(n, point);
  pointRandomCC(n, point);
  // distance(n, m, point, edge);
  distanceCC(n, m, point, edge);
  // kruskal(n, edge, arbre);
  kruskalOpti(n, edge, arbre);
  // printEdge(m, edge);
  // printArbre(n, arbre);
  affichageGraphique(n, point, arbre);

  return EXIT_SUCCESS;
}