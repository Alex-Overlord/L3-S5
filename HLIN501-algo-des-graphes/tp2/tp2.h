typedef struct coord { int abs; int ord; } coord;

void affichageGraphique(int n, coord point[], int arbre[][2]);

void printEdge(int m, int edge[][3]);
void printArbre(int n, int arbre[][2]);
void pointRandom(int n, coord point[]);
void distances(int n, int m, coord point[], int edge[][3]);
void tri(int m, int edge[][3]);
void kruskal(int n, int m, int edge[][3], int arbre[][2]);