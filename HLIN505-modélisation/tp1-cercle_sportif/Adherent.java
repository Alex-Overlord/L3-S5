package tp1_cercle_sportif;

public class Adherent {
    // Attributes
    private static int nbA;
    private String name;
    private int num;
    private int lastYear;

    // Constructor
    public Adherent(String name, int lastYear) {
        this.name = name;
        this.num = ++nbA;
        this.lastYear = lastYear;
    }

    // Accessors
    public String getName() {
        return name;
    }
    public void setname(String name) {
        this.name = name;
    }
    public int getNum() {
        return num;
    }
    public String toString() {
        return getName() + " " + getNum();
    }    
    public int getLastYear() {
        return lastYear;
    }
    public void setLastYear(int lastYear) {
        this.lastYear = lastYear;
    }

    // Methods
    public void reAdhesion(int year) {
        setLastYear(year);
    }

    // Test
    public static void main(String[] args) {
        Adherent a1 = new Adherent("Bob", 2019);
        System.out.println(a1);

        Adherent a2 = new Adherent("Alice", 2020);
        System.out.println(a2);
    }
}