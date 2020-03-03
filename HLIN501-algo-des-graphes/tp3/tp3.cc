#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

typedef struct coord { int abs; int ord; } coord;

// file -> largeur
void print_voisins(int n, vector<int> voisins[]) {
  cout << "> print_voisins:" << endl;
  for (int i=0; i < n; i++) {
    cout << "v(" << i << ") = ";
    for (int j=0; j < voisins[i].size(); j++) {
      cout << voisins[i][j] << " ";
    } 
    cout << endl;
  }
}
// pile -> longueur
void print_voisins_pile(int n, stack<int> p[]) {
  cout << "> print_voisins_pile:" << endl;
  for (int i=0; i < n; i++) {
    stack<int> t = p[i];
    cout << "v(" << i << ") = ";
    while(!t.empty()) {
      cout << t.top() << " ";
      t.pop();     
    }
    cout << endl;
  } 
}
void print_niv(int n, int niv[]) {
  cout << "> print_niv:" << endl;
  for (int i=0; i < n; i++) {
    cout << "niv(" << i << ") = " << niv[i] << endl;
  }
}
void print_pere(int n, int pere[]) {
  cout << "> print_pere:" << endl;
  for (int i=0; i < n; i++) {
    cout << "pere[" << i << "] = " << pere[i] << endl;
  }
}   
void print_debut(int n, int debut[]) {
  cout << "> print_debut:" << endl;
  for (int i=0; i < n; i++) {
    cout << "debut[" << i << "] = " << debut[i] << endl;
  }
}  
void print_fin(int n, int fin[]) {
  cout << "> print_fin:" << endl;
  for (int i=0; i < n; i++) {
    cout << "fin[" << i << "] = " << fin[i] << endl;
  }
} 

bool is_in(vector<int> array, int e) {
  for (int i=0; i<array.size(); i++) {
    if (array[i] == e) {
      return true;
    }
  }
  return false;
}
bool is_in_pile(stack<int> P, int e) {
  stack<int> tmp = P;
  for (int i=0; i < tmp.size(); i++) {
    if (tmp.top() == e) {
      return true;
    } 
    tmp.pop();
  }
  return false;
}

void voisins_random(int n, int m, vector<int> voisins[]) {
  srand(time(NULL));
  int x, y, i = 0;
  while (i < m) {
    x = rand()%n;
    y = rand()%n;
    if (x != y && !is_in(voisins[x], y) && !is_in(voisins[y], x)) {
      voisins[x].push_back(y);
      voisins[y].push_back(x);
      i++;
    } 
  }
}
void voisins_random_pile(int n, int m, stack<int> voisins[]) {
  srand(time(NULL));
  int x, y, i = 0;
  while (i < m) {
    x = rand()%n;
    y = rand()%n;
    if (x != y && !is_in_pile(voisins[x], y) && !is_in_pile(voisins[y], x)) {
      voisins[x].push(y);
      voisins[y].push(x);
      i++;
    } 
  }
}

void ecriture_niveaux(int n, int niv[]) {
  int nb[n];
  int cpt = -1;

  cout << "> ecriture_niveaux:" << endl;
  for (int i=0; i < n; i++) {
    nb[i] = 0;
  }
  for (int i=0; i < n; i++) {
    nb[niv[i]]++; 
  }
  for (int i=0; i < n; i++) {
    if (nb[i] != 0) {
      cout << "Il y a " << nb[i] << " sommets au niveau " << i << "." << endl;
    }
    if (niv[i] == 0) {
      cpt++;
    }
  }
  cout << "Il y a " << cpt << " sommets qui ne sont pas dans la composante de 0." << endl;
}

/*
  Complexité: O(n + m)
 */
void parcours_largeur(int n, vector<int> voisins[], int niv[], int ordre[], int pere[]) {
  queue<int> AT; // à parcourir
  int dv[n]; // sommets déjà vus
  int r = 0; // la racine
  int t = 2;
  int x, v;

  for(int i = 0; i < n; i++) { dv[i] = 0; } 
  
  dv[r] = 1;
  ordre[r] = 1;
  pere[r] = r;
  niv[r] = 0;
  AT.push(r);

  while(!AT.empty()) 
  {
    x = AT.front();
    AT.pop();

    for(int i = 0; i < voisins[x].size(); i++) 
    {
      v = voisins[x][i];  

      if(dv[v] == 0) 
      {
        dv[v] = 1; // on traite i pour la première fois
        AT.push(v);
        ordre[v] = t;
        t++;
        pere[v] = x; 
        niv[v] = niv[x] + 1;
      }
    }
  }
} 

/*
  Complexité: O(n + m)
 */
void parcours_profondeur(int n, stack<int> voisins_pile[], int pere[], int debut[], int fin[], int niv[]) {
  stack<int> AT; // à parcourir
  int dv[n]; // sommets déjà vus
  int r = 0; // la racine
  int t = 2;

  for (int i=0; i < n; i++) { dv[i] = 0; } 

  dv[r] = 1;
  debut[r] = 1;
  pere[r] = r;
  niv[r] = 0;
  AT.push(r);

  while (!AT.empty()) {
    int x = AT.top();
    if (voisins_pile[x].empty()) {
      AT.pop();
      fin[x] = t;
      t++;
    } else {
      int y = voisins_pile[x].top();
      voisins_pile[x].pop();
      if (dv[y] == 0) {
        dv[y] = 1; // on traite y pour la première fois
        AT.push(y);
        debut[y] = t;
        t++;
        pere[y] = x;
        niv[y] = niv[x] + 1;
      }
    }
  }
} 

int niveauMax(int n, int niv[]) {
  int max = -1;
  for (int i = 0; i < n; i++) {
    if (niv[i] > max) {
      max = niv[i];
    }
  }
  return max;
}

int main() {
  int n; // Le nombre de sommets.
  int m; // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets : ";
  cin >> n;
  cout << "Entrer le nombre d'arètes : ";
  cin >> m;
  vector<int> voisins[n]; // Les listes des voisins. 
  stack<int> voisins_pile[n]; // Pile des voisins. 
  int pere[n]; // L'arbre en largeur.
  int ordre[n]; // L'ordre de parcours.
  int niv[n]; // Le niveau du point.
  int debut[n];
  int fin[n];

  for(int i = 0; i < n; i++) 
  { // initialisation des tableaux à -1
    pere[i] = -1; 
    ordre[i] = -1;
    niv[i] = -1;
    debut[i] = -1;
    fin[i] = -1;  
  }

/* Parcours en largeur */
  // cout << endl << ">>> Parcours en largeur:" << endl;
  // voisins_random(n, m, voisins);
  // print_voisins(n, voisins);  
  // parcours_largeur(n, voisins, niv, ordre, pere);
  // ecriture_niveaux(n, niv);  
  // print_niv(n, niv);
  // print_pere(n, pere);

/* Parcours en profondeur */
  cout << endl << ">>> Parcours en profondeur:" << endl;
  voisins_random_pile(n, m, voisins_pile);
  print_voisins_pile(n, voisins_pile);
  parcours_profondeur(n, voisins_pile, pere, debut, fin, niv);
  print_pere(n, pere);
  print_debut(n, debut);
  print_fin(n, fin);
  print_niv(n, niv);

  cout << "niveauMax = " << niveauMax(n, niv) << endl;

  return EXIT_SUCCESS;
}