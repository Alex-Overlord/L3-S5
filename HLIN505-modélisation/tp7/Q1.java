package tp7;
// javac Q1.java && cd .. && java tp7.Q1 && cd tp7

import java.util.*;
import java.lang.*;
import java.lang.reflect.*;

public class Q1 
{
  private ArrayList<Object> list;

  public Method[] get_method(int i)
  {
    Method[] m = list.get(i).getClass().getMethods();
    // return list.get(i).getClass().getMethods();
    ArrayList<Method> list_methods = List.asList(m); // BUG
    // System.out.println("Class :" + list.get(i).)
  }

  public static void main(String[] args) 
  {
    ArrayList<Integer> l1 = new ArrayList<>();
    l1.add(1);
    l1.add(2);
    l1.add(3);

    System.out.println(l1);
  }
}