/* ENSF 480 - Lab 5 Exercise A and B
 * M. Moussavi, October 2022
 * 
 */

class Item <E extends Number & Comparable<E> >{
	private E item;
	public Item(E value) {
		item = value;
	}
	// copy constructor (safe due to Number immutability)
	public Item(Item<E> other) {
		this.item = other.item;
	}
	
	public void setItem(E value){
		item = value;
	}
	
	public E getItem(){
		return item;
	}
}
