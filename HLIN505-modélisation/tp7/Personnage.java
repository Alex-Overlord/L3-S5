package tp7;

import java.util.*;
import java.lang.*;

public abstract class Personnage
{
  private String nom;
  private int nb_points;
  private int nb_vies;

  public String get_nom() { return nom; }
  public void set_nom(String nom) { this.nom = nom; }
  public int get_nb_points() { return nb_points; }
  public void set_nb_points(int nb_points) { this.nb_points = nb_points; }
  public int get_nb_vies() { return nb_vies; }
  public void set_nb_vies(int nb_vies) { this.nb_vies = nb_vies; }

  public Personnage(String _nom, int _nb_points, int _nb_vies)
  {
    set_nom(_nom);
    set_nb_points(_nb_points);
    set_nb_vies(nb_vies);
  }

  public static void main(String[] args) 
  {
    
  }
}