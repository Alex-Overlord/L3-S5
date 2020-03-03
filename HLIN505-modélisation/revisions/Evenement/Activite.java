package Evenement;

import java.util.Scanner;

public class Activite implements IActivite {
    private String nom;
    private boolean exterieur;

    public String getNom() { return nom; }
    public void setNom(String nom) { this.nom = nom; }
    public boolean getExterieur() { return exterieur; }
    public void setExterieur(boolean exterieur) { this.exterieur = exterieur; }

    public Activite(String nom, boolean exterieur) {
	this.setNom(nom);
	this.setExterieur(exterieur);
    }

    public double TTC() {
	return 10.0;
    }

    public static void main(String argv[]) {
	Activite a1 = new Activite("resto", false);
	System.out.println(a1.getNom());
	System.out.println(a1.getExterieur());

	//Scanner s = null;
	//a1.modif(s);
	//System.out.println(a1.getNom());
	//System.out.println(a1.getExterieur());

	Activite a2 = new Activite("resto2", true);
	boolean b = a1.memeNom(a2);
	System.out.println(b);
    }
}
