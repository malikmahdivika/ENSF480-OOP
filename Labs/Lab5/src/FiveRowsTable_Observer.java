/* File: FiveRowsTableObserver.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * Five row table concrete implementation of observer.
*/
import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer {
    private ArrayList<Double> dataCopy;
    private Subject dataSubject;

    // class implementation methods
    public FiveRowsTable_Observer(Subject s) {
        this.dataSubject = s;
        this.dataSubject.register(this);
    }
    public void display() {
        int maxRows = 5;
        int maxCols = (int) Math.ceil((double) dataCopy.size() / maxRows);

        System.out.println("FiveRowTable observed change: ");
        for (int row = 0; row < maxRows; row++) {
            for (int col = 0; col < maxCols; col++) {
                int index = col * maxRows + row;
                if (index < dataCopy.size()) {
                    System.out.print(dataCopy.get(index));
                    System.out.print("  ");
                }
            }
            System.out.print("\n");
        }
        System.out.print("\n");
        System.out.print("\n");
    }

    // observer implementation
    public void update(ArrayList<Double> data) {
        this.dataCopy = data;
        this.display();
    }
}
