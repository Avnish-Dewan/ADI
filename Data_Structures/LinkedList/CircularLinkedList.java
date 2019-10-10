public class CircularLinkedList<E>
{
  //---------------- nested Node class ----------------
  /**
   * Singly linked node, which stores a reference to its element and
   * to the subsequent node in the list.
   */
  private static class Node<E> {

    /** The element stored at this node */
    private E element;     // an element stored at this node

    /** A reference to the subsequent node in the list */
    private Node<E> next;  // a reference to the subsequent node in the list

    /**
     * Creates a node with the given element and next node.
     *
     * @param e  the element to be stored
     * @param n  reference to a node that should follow the new node
     */
    public Node(E e, Node<E> n)
    {
      this.element = e;
      this.next = n;
    }

    // Accessor methods
    /**
     * Returns the element stored at the node.
     * @return the element stored at the node
     */
    public E getElement() { return element; }

    /**
     * Returns the node that follows this one (or null if no such node).
     * @return the following node
     */
    public Node<E> getNext() { return next; }

    // Modifier methods
    /**
     * Sets the node's next reference to point to Node n.
     * @param n    the node that should follow this one
     */
    public void setNext(Node<E> n) { next = n; }
  } //----------- end of nested Node class -----------

  // instance variables of the CircularlyLinkedList
  /** The designated cursor of the list */
  private Node<E> tail = null;                  // we store tail (but not head)

  /** Number of nodes in the list */
  private int size = 0;                         // number of nodes in the list

  /** Constructs an initially empty list. */
  public CircularLinkedList() { }             // constructs an initially empty list

  // access methods
  /**
   * Returns the number of elements in the linked list.
   * @return number of elements in the linked list
   */
  public int size() { return size; }

  /**
   * Tests whether the linked list is empty.
   * @return true if the linked list is empty, false otherwise
   */
  public boolean isEmpty() { return size==0; }

  /**
   * Returns (but does not remove) the first element of the list
   * @return element at the front of the list (or null if empty)
   */
  public E first()
  {
    if(size==0)
      return null;
    return tail.getElement();             // returns (but does not remove) the first element
  }

  /**
   * Returns (but does not remove) the last element of the list
   * @return element at the back of the list (or null if empty)
   */
  public E last()
  {              // returns (but does not remove) the last element
      Node <E> temp = tail;
      while(temp.getNext()!=tail)
      {
        temp=temp.getNext();
      }
      return temp.getElement();
  }

  // update methods
  /**
   * Rotate the first element to the back of the list.
   */
  public void rotate()
  {
    if(size!=0)
        tail = tail.getNext();     // rotate the first element to the back of the list
  }

  /**
   * Adds an element to the front of the list.
   * @param e  the new element to add
   */
  public void addFirst(E e)
  {
    Node <E> temp = new Node<E>(e,null);
    if(size==0)
    {
      temp.setNext(temp);
      tail = temp;
    }
    else
    {
      temp.setNext(tail.getNext());
      tail.setNext(temp);
    }
    size++;
  }
  /**
   * Adds an element to the end of the list.
   * @param e  the new element to add
   */
  public void addLast(E e)
  {
    Node<E> newNode= new Node<E>(e,null);
    if(!isEmpty())
    {
      newNode.setNext(tail.getNext());
      tail.setNext(newNode);
    }
    else
    {
      newNode.setNext(newNode);
    }
    tail=newNode;
    size++;                 // adds element e to the end of the list
  }

  /**
   * Removes and returns the first element of the list.
   * @return the removed element (or null if empty)
   */
  public E removeFirst()
  {
    if(isEmpty())
      return null;
    Node<E> temp=tail.getNext();
    tail.setNext(temp.getNext());
    size--;
    return temp.getElement();                   // removes and returns the first element
  }

  /**
   * Produces a string representation of the contents of the list.
   * This exists for debugging purposes only.
   */
  public String toString() {
    StringBuilder sb = new StringBuilder("(");
    Node<E> walk = tail;
    sb.append(walk.getElement());
    sb.append(" ");
    walk = walk.getNext();
    while (walk != tail) {
      sb.append(walk.getElement());
      sb.append(" ");
      walk = walk.getNext();
    }
    sb.append(")");
    return sb.toString();
   }
}
