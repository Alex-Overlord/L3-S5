package tp6_généricité;
import java.util.*;

public class Tableau<G extends Comparable<G>> {
  private G[] T;

  public Tableau (G[] T) {
    this.T = T; // on fait ici une recopie "superficielle"
  }

  public void triBulles() {
    int i = T.length - 2;
    boolean ech = true;
    while (i >= 2 && ech) {
      ech = false;
      for (int j=0; j<=i; j++) {
        if (T[j].compareTo(T[j+1]) > 0) {
          G aux = T[j];
          T[j] = T[j+1];
          T[j+1] = aux;
          ech = true;
        }
      }
      i--;
    }
  }

  public void affiche() {
    for (int i=0; i<T.length; i++) {
      System.out.print(T[i]+" ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    Integer T[] = {10, 2, 6, 11, 7, 2, -1, 0, 9};
    Tableau<Integer> obj = new Tableau<>(T);
    obj.triBulles();
    obj.affiche();
  }
}