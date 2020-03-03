import java.util.Scanner;
import java.io.*;

public class Exo3 {
  private String name;
  private int nb;

  public Exo3(String name){
    this.name = name;
    nb = 0;
  }

  public String getName() { return name; }
  public void setName(String name) {this.name = name; }

  public int getNb() { return nb; }
  public void setNb(int nb) {this.nb = nb; }

  public void createFile() throws IOException {
    BufferedReader lectureClavier = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter ecritureFichier = new BufferedWriter(new FileWriter(name));
    System.out.println("Entrez des lignes (Return pour terminer)");
    
    String s = lectureClavier.readLine();
    while (s.length() != 0) {
      ecritureFichier.write(s); // TQ pas chaine vide
      ecritureFichier.newLine();
      s = lectureClavier.readLine();
    }
    ecritureFichier.close(); // ferme le fichier associe
    System.out.println("Fin saisie");
  }

  public void readFile() throws IOException {
    BufferedReader lectureFichier = new BufferedReader(new FileReader(name));
    System.out.println("Lecture du fichier " + name);

    String s = lectureFichier.readLine();
    while(s != null) {
      System.out.println(s);
      s = lectureFichier.readLine();
    }
    lectureFichier.close();
    System.out.println("Fin du fichier");
  }
  
  public void countWithoutSpace() throws IOException {
    BufferedReader lectureFichier = new BufferedReader(new FileReader(name));
    nb = 0;
    int i = lectureFichier.read();
    System.out.println(i);
    while(i != 0) {
      if (i != ' ') {
        nb++;
      }
      i = lectureFichier.read();
    }
  }

  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    System.out.println("Entrez le nom du fichier :");
    String s = sc.nextLine();
    Exo3 a = new Exo3(s);
    System.out.println("file name is : " + s);

    a.createFile();
    a.readFile();
    a.countWithoutSpace();
    System.out.println("Le nombre de caractères du fichier " 
      + a.getName() + " est : " + a.getNb());
  }
}