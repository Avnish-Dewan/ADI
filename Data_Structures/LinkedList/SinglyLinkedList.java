package DS;

public class SinglyLinkedList < E extends Comparable < E >> {
	//---------------- nested Node class ----------------
	/**
	 * Node of a singly linked list, which stores a reference to its
	 * element and to the subsequent node in the list (or null if this
	 * is the last node).
	 */
	private static class Node < E extends Comparable < E >> {
		/** The element stored at this node */
		private E element; // reference to the element stored at this node

		/** A reference to the subsequent node in the list */
		private Node < E > next; // reference to the subsequent node in the list

		/**
		 * Creates a node with the given element and next node.
		 *
		 * @param e  the element to be stored
		 * @param n  reference to a node that should follow the new node
		 */
		public Node(E e, Node < E > n) {
			element = e;
			next = n;
		}

		// Accessor methods
		/**
		 * Returns the element stored at the node.
		 * @return the element stored at the node
		 */
		public E getElement() {
			return element;
		}

		public void setElement(E element) {
			this.element = element;
		}
		/**
		 * Returns the node that follows this one (or null if no such node).
		 * @return the following node
		 */
		public Node < E > getNext() {
			return next;
		}

		// Modifier methods
		/**
		 * Sets the node's next reference to point to Node n.
		 * @param n    the node that should follow this one
		 */
		public void setNext(Node < E > n) {
			next = n;
		}
	} //----------- end of nested Node class -----------


	// instance variables of the SinglyLinkedList
	/** The head node of the list */

	private Node < E > head = null; // head node of the list (or null if empty)


	/** The last node of the list */
	private Node < E > tail = null; // last node of the list (or null if empty)


	/** Number of nodes in the list */
	private int size = 0; // number of nodes in the list


	/** Constructs an initially empty list. */
	public SinglyLinkedList() {} // constructs an initially empty list


	// access methods
	/**
	 * Returns the number of elements in the linked list.
	 * @return number of elements in the linked list
	 */
	public int size() {
		return size;
	}

	private void setSize(int size) {
		this.size = size;
	}


	/**
	 * Tests whether the linked list is empty.
	 * @return true if the linked list is empty, false otherwise
	 */
	public boolean isEmpty() {
		return size == 0;
	}

	/**
	 * Returns (but does not remove) the first element of the list
	 * @return element at the front of the list (or null if empty)
	 */
	public E first() { // returns (but does not remove) the first element
		if (isEmpty()) return null;
		return head.getElement();
	}

	/**
	 * Returns (but does not remove) the last element of the list.
	 * @return element at the end of the list (or null if empty)
	 */
	public E last() { // returns (but does not remove) the last element
		if (isEmpty()) return null;
		return tail.getElement();
	}

	// update methods
	/**
	 * Adds an element to the front of the list.
	 * @param e  the new element to add
	 */
	public void addFirst(E e) { // adds element e to the front of the list
		head = new Node < > (e, head); // create and link a new node
		if (size == 0)
			tail = head; // special case: new node becomes tail also
		size++;
	}

	public void insertBetween(E data, int index) {
		if (index > size) {

		} else {
			Node < E > temp = head;
			while (index-- > 1) {
				temp = temp.getNext();
			}
			Node < E > temp1 = temp.getNext();
			Node < E > newest = new Node < E > (data, temp1);
			temp.setNext(newest);
			size++;
		}
	}

	/**
	 * Adds an element to the end of the list.
	 * @param e  the new element to add
	 */
	public void addLast(E e) { // adds element e to the end of the list
		Node < E > newest = new Node < > (e, null); // node will eventually be the tail
		if (isEmpty())
			head = newest; // special case: previously empty list
		else
			tail.setNext(newest); // new node after existing tail
		tail = newest; // new node becomes the tail
		size++;
	}



	/**
	 * Removes and returns the first element of the list.
	 * @return the removed element (or null if empty)
	 */
	public E removeFirst() { // removes and returns the first element
		if (isEmpty()) return null; // nothing to remove
		E answer = head.getElement();
		head = head.getNext(); // will become null if list had only one node
		size--;
		if (size == 0)
			tail = null; // special case as list is now empty
		return answer;
	}

	public boolean isPalindrome()
	{
		if(head == null)
			return true;
		// checkPalindrome()
		return false;
	}

	public void reverse() {
		Node < E > temp = head;
		Node < E > prev = null;
		Node < E > current = head;
		Node < E > next = null;
		while (current != null) {
			next = current.getNext();
			current.setNext(prev);
			prev = current;
			current = next;
		}
		head = prev;
		tail = temp;
	}

	private void sort() {
		Node < E > start = head;
		while (start != null) {
			Node < E > next = start.getNext();
			while (next != null) {
				E x = start.getElement();
				E y = next.getElement();
				if (x.compareTo(y) > 0) {
					start.setElement(y);
					next.setElement(x);
				}
				next = next.getNext();
			}
			start = start.getNext();
		}
	}

	private Node < E > sortedMerge(Node < E > A, Node < E > B) {
		if (A == null) return B;
		if (B == null) return A;

		if (A.getElement().compareTo(B.getElement()) < 0) {
			A.setNext(sortedMerge(A.getNext(), B));
			return A;
		} else {
			B.setNext(sortedMerge(A, B.getNext()));
			return B;
		}

	}

	public void merge(SinglyLinkedList < E > list) {
		sort();
		list.sort();

		head = sortedMerge(head, list.head);

		if (tail.getElement().compareTo(list.tail.getElement()) < 0) {
			tail = list.tail;
		}
		size += list.size();

		list.setSize(0);
	}

	/**
	 * utility for return slow pointer
	 * @return Node where loop matched
	 */

	private Node<E> getSlow()
	{
		Node < E > slow = head;
		Node < E > fast = head;
		while (slow != null && fast != null && fast.getNext() != null) {
			slow = slow.getNext();
			fast = fast.getNext().getNext();
			if (fast == slow)
				return slow;
		}
		return null;
	}

	/**
	 * Checks Whether there is a loop in list or not
	 * @return true if there is a loop in list
	 */
	 public boolean loopInList() 
	{
		Node<E> node= getSlow();
		if(node==null)
			return false;
		return true;
	}



	/**
	 * Removes the loop present in the list
	 */
	void removeLoop() {
		Node<E> slow = getSlow();
		if(slow == null)
			return ;
		Node<E> ptr1 = slow;
		Node<E> ptr2 = slow;
		int k = 1, i;
		while (ptr1.getNext() != ptr2) {
			ptr1 = ptr1.getNext();
			k++;
		}

		ptr1 = head;

		ptr2 = head;
		for (i = 0; i < k; i++) {
			ptr2 = ptr2.getNext();
		}

		while (ptr2 != ptr1) {
			ptr1 = ptr1.getNext();
			ptr2 = ptr2.getNext();
		}

		while (ptr2.getNext() != ptr1) {
			ptr2 = ptr2.getNext();
		}

		ptr2.setNext(null);
	}

	/**
	 * Produces a string representation of the contents of the list.
	 * This exists for debugging purposes only.
	 */
	public String toString() {
		StringBuilder sb = new StringBuilder("[");
		Node < E > walk = head;
		while (walk != null) {
			sb.append(walk.getElement());
			if (walk != tail)
				sb.append(", ");
			walk = walk.getNext();
		}
		sb.append("]");
		return sb.toString();
	}
}