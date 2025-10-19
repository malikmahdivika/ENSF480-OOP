import java.util.ArrayList;

public class InsertionSorter<E extends Number & Comparable<E> > implements Sorter<E> {
    public void performSort(ArrayList<Item<E>> aList) {
        int size = aList.size();
        Item<E> key;
        int j;
        for (int i = 1; i < size; i++) {
            key = aList.get(i);
            j = i - 1;
            while (j >=0 && key.getItem().compareTo(aList.get(j).getItem()) < 0) {
                aList.set(j + 1, aList.get(j));
                j -= 1;
            }
            aList.set(j + 1, key);
        }
    }
}
