/* File: OneRow_Observer.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * One row table concrete implementation of observer.
*/
import java.util.*;

public class OneRow_Observer implements Observer {
    private ArrayList<Double> dataCopy;
    private Subject dataSubject;

    // class implementation methods
    public OneRow_Observer(Subject s) {
        this.dataSubject = s;
        this.dataSubject.register(this);
    }
    public void display() {
        System.out.println("ThreeColumnTable observed change: ");
        for (Double dataPoint : dataCopy) {
            System.out.print(dataPoint);
            System.out.print("  ");
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
