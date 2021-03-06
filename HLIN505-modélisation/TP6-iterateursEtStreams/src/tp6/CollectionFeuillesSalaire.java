package tp6;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class CollectionFeuillesSalaire {
	private List<FeuilleSalaire> feuilles = new ArrayList<>();
	
	public CollectionFeuillesSalaire() {
		
	}

	public void print() {
		feuilles.stream().forEach(f->System.out.println(f));
	}
	
	public void sortv2() {
		Collections.sort(feuilles, 
			new Comparator<FeuilleSalaire>() {
				public int compare(FeuilleSalaire f1, FeuilleSalaire f2) {
					return -1 ; // A COMPLETE
				}
			}
		);
	}
	
	public void sortv3() {
		//Collections.sort(feuilles,(f1,f2) ->)
	}
	
	public void sortv4() {
		//feuilles.sort((f1,f2);->double.compare(...));
	}
	
	public List<FeuilleSalaire> getByNomEl(String nom) {
		return feuilles.stream()
				.filter(f->f.getEmployeur().equals(nom)).collect(Collectors.toList());
	}

	public static void main(String[] args) {
		CollectionFeuillesSalaire a = new CollectionFeuillesSalaire();
	}
}