package tp1_cercle_sportif;

public class Creneau2 {
	// Attributes
	private Jour jour;
	private Heure heureDebut;
	private Heure heureFin;
	
	// Nested class
	public static class Heure {
		// Attributes
		private int heure;
		private int minute;
		
		// Constructor
		public Heure(int h, int m) {
			if (h >= 0 && h <= 23) {
				heure = h;
			}
			else {
				System.out.println("ERROR : Les heures sont comprisent entre 0 et 23.");
			}
			if (m >= 0 && m <= 59 ) {
				minute = m - m%5;
			} 
			else {
				System.out.println("ERROR : Les minutes sont comprisent entre 0 et 59. (Granularité de 5 minutes)");
			}
		}
		
		// Accessors
		public int getHeure() { 
			return heure; 
		}
		public void setHeure(int h) { 
			if (h >= 0 && h <= 23) {
				this.heure = h; 
			} 
			else {
				System.out.println("ERROR : Les heures sont comprisent entre 0 et 23.");
			}
		}
		public int getMinute() { 
			return minute; 
		}
		public void setMinute(int m) {
			if (m >= 0 && m <= 59) {
				this.minute = m - m%5; 
			}
			else {
				System.out.println("ERROR : Les minutes sont comprisent entre 0 et 59. (Granularité de 5 minutes)");
			}
		}	
		public String toString() {
			String result = "";
	
			if (heure < 10) {
				result += "0";
			}
			result += heure + ":";
	
			if (minute < 10) {
				result += "0";
			}
			result += minute;
	
			return result;
		}
		
		// Methods
		public boolean sup(Heure h) {
			if (this.getHeure() >= h.getHeure() && this.getMinute() >= h.getMinute()) {
				return true;
			}
			else {
				return false;		
			}
		}
	}

	// Constructor
	public Creneau2 (Jour j, Heure hd, Heure hf) {
		jour = j;
		if (hf.sup(hd)) {
			heureDebut = hd;
			heureFin = hf;
		}
		else {
			heureDebut = hf;
			heureFin = hd;
		}
	}

	// Accessors
	public Jour getJour() { 
		return jour; 
	}
	public Heure getHeureDebut() { 
		return heureDebut; 
	}
	public Heure getHeureFin() { 
		return heureFin; 
	}
	public void setJour(Jour jour) { 
		this.jour = jour; 
	}
	public void setHeureDebut(Heure heureDebut) { 
		this.heureDebut = heureDebut; 
	}
	public void setHeureFin(Heure heureFin) { 
		this.heureFin = heureFin; 
	}
	public String toString() {
		String result = getJour() + " ";

		if (getHeureDebut().getHeure() < 10) {
			result += "0";
		}
		result += getHeureDebut().getHeure() + ":";

		if (getHeureDebut().getMinute() < 10) {
			result += "0";
		}
		result += getHeureDebut().getMinute() + " - ";

		if (getHeureFin().getHeure() < 10) {
			result += "0";
		}
		result += getHeureFin().getHeure() + ":";

		if (getHeureFin().getMinute() < 10) {
			result += "0";
		}
		result += getHeureFin().getMinute();

		return result;
	}

	// Methods
	public boolean chevauche(Creneau2 c) {
		boolean result = false;
		int hd1 = this.heureDebut.getHeure();
		int md1 = this.heureDebut.getMinute();
		int hf1 = this.heureFin.getHeure();
		int mf1 = this.heureFin.getMinute();

		int hd2 = c.heureDebut.getHeure();
		int md2 = c.heureDebut.getMinute();
		int hf2 = c.heureFin.getHeure();
		int mf2 = c.heureFin.getMinute();

		if (hf1 > hd2 
			||
			hf1 == hd2 && mf1 > md2 
			||
			hd1 < hf2 
			||
			hd1 == hf2 && md1 < mf2 
			) {
			result = true;
		}
		
		return result;
	}
	public boolean inclus(Creneau2 c) {
		boolean result = false;
		
		if (this.heureDebut.getHeure() <= c.heureDebut.getHeure() &&
			this.heureFin.getHeure() >= c.heureFin.getHeure() ||

			this.heureDebut.getHeure() == c.heureDebut.getHeure() &&
			this.heureDebut.getMinute() <= c.heureDebut.getMinute() &&
			this.heureFin.getHeure() == c.heureFin.getHeure() &&
			this.heureFin.getMinute() >= c.heureFin.getMinute() ||

			this.heureDebut.getHeure() == c.heureDebut.getHeure() &&
			this.heureDebut.getMinute() <= c.heureDebut.getMinute() &&
			this.heureFin.getHeure() >= c.heureFin.getHeure() ||

			this.heureFin.getHeure() == c.heureFin.getHeure() &&
			this.heureFin.getMinute() >= c.heureFin.getMinute() &&
			this.heureDebut.getHeure() >= c.heureDebut.getHeure()) {
			result = true;
		}
		
		return result;
	}

	// Test
	public static void main(String[] args) {
		Creneau2 c1 = new Creneau2(Jour.Lundi, 
			new Heure(8, 0),
			new Heure(13, 0));

		System.out.println(c1); 
	}
}