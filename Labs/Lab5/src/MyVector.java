/* File: MyVector.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * Custom vector class for strategy pattern demo.
*/
import java.util.*;

public class MyVector<E extends Number & Comparable<E> > {
    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;
    
    public MyVector(int n) {
        this.storageM = new ArrayList<>(n);
    };
    public MyVector(ArrayList<Item<E>> arr) {
        for (Item<E> item : arr) {
            this.storageM.add(new Item<>(item));
        }
    }

    // methods
    public void add(Item<E> value) {
        this.storageM.add(value);
    }
    public void setSortStrategy(Sorter<E> s) {
        this.sorter = s;
    }
    public void performSort() {
        this.sorter.performSort(storageM);
    }
    public void display() {
        System.out.print("Items in ArrayList: ");
        for (Item<E> item : this.storageM) {
            System.out.print(item.getItem());
            System.out.print("    ");
        }
        System.out.print("\n");
    }
}

interface Sorter<E extends Number & Comparable<E> > {
    public void performSort(ArrayList<Item<E>> aList);
}

