package tp6;
import java.util.*;

public interface IPile<A> {
  void empile(A a);
  A depile(); // retourne l'element en sommet de pile et depile
  int nbElements();
  A sommet(); // retourne le sommet de pile

  public static void main(String[] args) {
    
  }
}