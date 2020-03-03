//package tp1_classes_internes;

public class List {
    private Node root;
    private static int size;

    public static class Node {
        private int value;
        private Node next;

        public Node(int value) {
            this.value = value;
            this.next = null;
        }
        public Node(int value, Node next) {
            super();
            this.next = next;
        }

        public int getValue() {
            return value;
        }
        public Node getNext() {
            return next;
        }
        public void setValue(int value) {
            this.value = value;
        }
        public void setNext(Node next) {
            this.next = next;
        }

        public String toString() {
            String result = "" + value;

            //if (next != )

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

    public Node getRoot() {
        return root;
    }
    public int getSize() {
        return size;
    }

    public void add(Node n) {
        n.next = getRoot();
        this.root = n;   
        size++;
    }
    public String toString() {
        return root.toString();
    }

    public static void main(String[] args) {
        System.out.println("-- Liste --");

        Node n1 = new Node(15);
        Node n2 = new Node(24);
        //Node n3 = new Node(42);

        List l1 = new List();
        l1.add(n1);
        l1.add(n2);
        //l1.add(n3);

        System.out.println("List : " + l1);
    }
}