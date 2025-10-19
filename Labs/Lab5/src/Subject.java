/* File: Subject.java
 * Author: Malik Mahdivika
 * Dev Date: Oct. 18, 2025
 * Subject interface.
*/

public interface Subject {
    public void notifyObservers();
    public void notifyRegister(Observer ob);
    public void register(Observer ob);
    public void remove(Observer ob);
}
