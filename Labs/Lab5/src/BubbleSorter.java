/* File: BubbleSorter.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * Concrete bubble sort implementation of Sorter strategy pattern.
*/
import java.util.ArrayList;

public class BubbleSorter<E extends Number & Comparable<E> > implements Sorter<E> {
    public void performSort(ArrayList<Item<E>> aList) {
        int size = aList.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (aList.get(j).getItem().compareTo(aList.get(j + 1).getItem()) > 0) {
                    Item<E> temp = aList.get(j);
                    aList.set(j, aList.get(j + 1));
                    aList.set(j + 1, temp);
                }
            }
        }
    };
}
