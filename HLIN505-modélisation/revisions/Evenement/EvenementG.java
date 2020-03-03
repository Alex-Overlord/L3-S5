package Evenement;

import java.util.ArrayList;

public class EvenementG {
    private String nom;
    private ArrayList<IActivite> listeActivites = new ArrayList<>();

    public void ajout(IActivite a) {
	if (this.listeActivites.contains(a)) System.out.println("déjà présente");
	else this.listeActivites.add(a);
    }

    public double prixTTC() {
	double res = 0;
	for (IActivite a : this.listeActivites)
	    res += a.TTC();
	return res;
    }

    public double prixTTC_stream() {
	return listeActivites
	    .stream()
	    //.mapToDouble(IActivite::TTC)
	    .mapToDouble(x -> x.TTC())
	    .sum();
    }

    public ArrayList<String> activExt() {
	ArrayList<String> res = new ArrayList<String>();
	for (IActivite a : this.listeActivites)
	    if (a.getExterieur())
		res.add(a.getNom());
	return res;
    }

    public void deplaceEvts(EvenementG e) {
	for (IActivite a : e.listeActivites)
	    this.ajout(a);
    }

    public static void main(String argv[]) {
	EvenementG e1 = new EvenementG();
	EvenementG e2 = new EvenementG();
	IActivite a1 = new Activite("resto", false);
	IActivite a2 = new Activite("concert", true);
	e1.ajout(a1);
	e1.ajout(a2);
	System.out.println(e1.prixTTC());
	System.out.println(e1.prixTTC_stream());
    }
}
