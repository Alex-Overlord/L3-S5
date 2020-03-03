package tp6_généricité;
import java.util.*;

public class FileAttente<A> 
{
  protected ArrayList<A> contenu;

  public FileAttente() { 
    contenu = new ArrayList<A>(); 
  }

  public void entre(A p) { 
    contenu.add(p); 
  }

  public A sort() {
    A a = null;
    if (!contenu.isEmpty()) {
      a = contenu.get(contenu.size()-1);
      contenu.remove(contenu.size()-1);
    }
    return a;
  }

  public boolean estVide() {
    return contenu.isEmpty(); 
  }

  public String toString() {
    return ""+contenu;
  }
}