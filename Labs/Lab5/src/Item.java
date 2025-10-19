/* File: Item.java
 * Author: Malik Mahdivika, M. Moussavi
 * Dev Date: Oct. 18, 2025
 * Item class implementation.
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
