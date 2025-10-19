/* File: ThreeColumnTableObserver.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * Three column table concrete implementation of observer.
*/
import java.util.*;

public class ThreeColumnTable_Observer implements Observer {
    private ArrayList<Double> dataCopy;
    private Subject dataSubject;

    // class implementation methods
    public ThreeColumnTable_Observer(Subject s) {
        this.dataSubject = s;
        this.dataSubject.register(this);
    }
    public void display() {
        int columnCount = 0;
        System.out.println("ThreeColumnTable observed change: ");
        for (Double dataPoint : dataCopy) {
            if (columnCount < 3) {
                System.out.print(dataPoint);
                System.out.print("  ");
                columnCount++;
            } else {
                columnCount = 0;
                System.out.print("\n");
            }
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
