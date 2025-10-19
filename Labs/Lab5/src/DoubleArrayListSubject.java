/* File: DoubleArrayListSubject.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * Double array subject implementation
*/
import java.util.*;

public class DoubleArrayListSubject implements Subject {
    private List<Observer> observers;
    private ArrayList<Double> data;
    
    // basic methods
    public DoubleArrayListSubject() {
        this.observers = new ArrayList<>();     // initialize observers list
        this.data = new ArrayList<>();
    }
    

    // data manipulation methods
    public void addData(Double newVal) {
        this.data.add(newVal);
        notifyObservers();
    }
    public void setData(int index, Double newVal) {
        this.data.set(index, newVal);
        notifyObservers();
    }
    public void populate(double[] populateWith) {
        //this.data.clear();
        for (double num : populateWith) {
            this.data.add(num);
        }
        notifyObservers();
    }
    public void display() {
        System.out.println(this.data);
    }
    
    // Observer related methods
    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(this.data);
        }
    }
    public void register(Observer ob) {
        this.observers.add(ob);
        this.notifyObservers();
    }
    public void remove(Observer ob) {
        this.observers.remove(ob);
        this.notifyObservers();
    }
}