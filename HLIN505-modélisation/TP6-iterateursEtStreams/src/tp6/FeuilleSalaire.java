package tp6;

public class FeuilleSalaire 
{
    private String employeur, salaire;
    private Integer nombreHeures;
    private Double montantNet;
    
     public FeuilleSalaire(String employeur, String salaire,
            Integer nombreHeures, Double montantNet) {
        super();
        this.employeur = employeur;
        this.salaire = salaire;
        this.nombreHeures = nombreHeures;
        this.montantNet = montantNet;
    }

    public String getEmployeur() {
        return employeur;
    }

    public void setEmployeur(String employeur) {
        this.employeur = employeur;
    }

    public String getsalaire() {
        return salaire;
    }

    public void setsalaire(String salaire) {
        this.salaire = salaire;
    }

    public Integer getNombreHeures() {
        return nombreHeures;
    }

    public void setNombreHeures(Integer nombreHeures) {
        this.nombreHeures = nombreHeures;
    }

    public Double getMontantNet() {
        return montantNet;
    }

    public void setMontantNet(Double montantNet) {
        this.montantNet = montantNet;
    }

    public static void main(String[] args) {
		FeuilleSalaire a = new FeuilleSalaire("Alex", "1000", 60, 666.6);
	}
}