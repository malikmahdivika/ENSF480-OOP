/* File: SelectionSorter.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * Concrete selection sort implementation of Sorter strategy pattern.
*/
import java.util.*;

public class SelectionSorter<E extends Number & Comparable<E> > implements Sorter<E> {
    public void performSort(ArrayList<Item<E>> aList) {
        int size = aList.size();
        int min_idx;
        for (int i = 0; i < size; i++) {
            min_idx = i;
            for (int j = i + 1; j < size; j++) {
                if (aList.get(j).getItem().compareTo(aList.get(min_idx).getItem()) < 0) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                Item<E> temp = aList.get(i);
                aList.set(i, aList.get(min_idx));
                aList.set(min_idx, temp);
            }
        }
    }
}
