package tp1_cercle_sportif;

import java.util.ArrayList;

public enum Lieu {
	stade1("stade de foot"),
	piscine2("piscine du centre");
	
	// Attributes
	private String nom;
	private ArrayList<Creneau> creneauDisponibles = new ArrayList<Creneau>();
	
	// Accessors
	public String getNom() { 
		return nom; 
	}
	public void setNom(String nom) { 
		this.nom = nom; 
	}
	public ArrayList<Creneau> getCreneauDisponibles() { 
		return creneauDisponibles; 
	}
	public String toString() {
		return this.getNom();
	}

	// Constructor
	private Lieu(String nom) {
		this.setNom(nom);
	}
	
	// Methods
	public void ajoutCreneau(Creneau c) {
		creneauDisponibles.add(c);
	}
	public boolean estDisponiblePendant(Creneau c) {
		boolean result = false;

		for (Creneau cr:creneauDisponibles) {
			if (cr.getJour() == c.getJour() &&
				cr.getHeureDebut() == c.getHeureDebut() &&
				cr.getHeureFin() == c.getHeureFin()) {
				result = true;
			}
		}

		return result;
	}

	// Test
	public static void main(String[] args) {
		Creneau c = new Creneau(Jour.Jeudi, 
			new HeureSimple(14,21), 
			new HeureSimple(15,21));
		
		Creneau s = new Creneau(Jour.Jeudi,
			new HeureSimple(9, 00),
			new HeureSimple(11, 00));

		stade1.ajoutCreneau(c);
		//stade1.ajoutCreneau(s);

		System.out.println(stade1.estDisponiblePendant(s));
		System.out.println(stade1.getNom());
		System.out.println(stade1.estDisponiblePendant(c));
		System.out.println("Les creneaux de stade1 :");
		for (Creneau cre : stade1.getCreneauDisponibles()) {
			System.out.println(cre.getHeureDebut() + " - " + cre.getHeureFin());
		}
	}
}
