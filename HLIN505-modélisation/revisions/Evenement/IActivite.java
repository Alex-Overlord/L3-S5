package Evenement;

import java.util.Scanner;

public interface IActivite {
    String getNom();
    void setNom(String nom);
    boolean getExterieur();
    void setExterieur(boolean exterieur);
    double TTC();
    
    default void modif(Scanner sc) {
	System.out.println("Saisissez le nom et si c'est en extérieur (ex: concert true)");
	sc = new Scanner(System.in);
	this.setNom(sc.next());
	this.setExterieur(sc.nextBoolean());
    }

    default boolean memeNom(IActivite a) { return this.getNom() == a.getNom(); }
}
