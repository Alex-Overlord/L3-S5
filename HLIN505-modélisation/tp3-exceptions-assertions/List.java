//package tp1_classes_internes;

public class List {
    private Node root;
    private static int size;

    public static class Node {
        private int value;
        private Node next;

	public Node() {
	    this.next = null;
	}
        public Node(int value) {
            this.value = value;
            this.next = null;
        }
        public Node(int value, Node next) {
            super();
            this.next = next;
        }

        public int getValue() { return value; }
        public void setValue(int value) { this.value = value; }
        public Node getNext() { return next; }
        public void setNext(Node next) { this.next = next; }

        public String toString() {
            String result = "" + value;
            if (next != null) {
		result += " " + next;
	    }	    
            return result;
        }
    }

    public List() {
        this.root = null;
        size = 0;
    }
    public List(Node root) {
        this.root = root;
        size = 1; 
    }

    public Node getRoot() { return root; }
    public void setRoot(Node root) { this.root = root; }
    public int getSize() { return size; }
    public void setSize(int size) { this.size = size; }

    public void add(Node n) {
	int assert_size = getSize();
        n.setNext(getRoot());
        setRoot(n);   
        setSize(getSize() + 1);
	assert getSize() == assert_size + 1;
    }
    public String toString() { return root.toString(); }
    public List reverse() {
	List result = new List();
	Node i = new Node();
	while (i != null) {
	    result.add(i);
	    //	    i.getRoot() = this.getNext();
	}
	
	return result;
    }
    /*
	List<Integer> result = new ArrayList<Integer>();
	for(int i=liste.size()-1; i>=0; i--)
	    result.add(liste.get(i));
	return result;
     */

    public static void main(String[] args) {
        System.out.println("-- Liste --");

        Node n1 = new Node(15);
        Node n2 = new Node(24);
        Node n3 = new Node(42);

        List l1 = new List();
	    
        l1.add(n1);
        l1.add(n2);
        l1.add(n3);
	
        System.out.println("List : " + l1);
	System.out.println("List renversé : " + l1.reverse());
	
    }
}
