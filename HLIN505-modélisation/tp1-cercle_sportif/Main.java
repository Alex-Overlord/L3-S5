package tp1_cercle_sportif;

public class Main {
    public static void main(String[] args) {
        Creneau d = new Creneau(Jour.Jeudi, 
        new HeureSimple(14,21), 
        new HeureSimple(15,21));

        Lieu.stade1.ajoutCreneau(d);
        
		System.out.println(Lieu.stade1.getNom());
		System.out.println(Lieu.stade1.estDisponiblePendant(d));
        System.out.println("Les creneaux de stade1 :");
        
		for (Creneau cre : Lieu.stade1.getCreneauDisponibles()) {
			System.out.println(cre.getHeureDebut() + " - " + cre.getHeureFin());
		}
    }
}