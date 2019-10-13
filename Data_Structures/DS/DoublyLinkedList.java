package DS;

public class DoublyLinkedList<E extends Comparable<E>> 
{

  //---------------- nested Node class ----------------
  /**
   * Node of a doubly linked list, which stores a reference to its
   * element and to both the previous and next node in the list.
   */
  private static class Node<E extends Comparable<E>>
  {
    /** The element stored at this node */
    private E element;               // reference to the element stored at this node

    /** A reference to the preceding node in the list */
    private Node<E> prev;            // reference to the previous node in the list

    /** A reference to the subsequent node in the list */
    private Node<E> next;            // reference to the subsequent node in the list

    /**
     * Creates a node with the given element and next node.
     *
     * @param e  the element to be stored
     * @param p  reference to a node that should precede the new node
     * @param n  reference to a node that should follow the new node
     */
    public Node(E e, Node<E> p, Node<E> n) 
    {
      this.prev=p;
      this.next=n;
      this.element=e;
    }

    // public accessor methods
    /**
     * Returns the element stored at the node.
     * @return the element stored at the node
     */
    public E getElement() { return element; }

    /**
     * Returns the node that precedes this one (or null if no such node).
     * @return the preceding node
     */
    public Node<E> getPrev() { return prev; }

    /**
     * Returns the node that follows this one (or null if no such node).
     * @return the following node
     */
    public Node<E> getNext() { return next; }

    // Update methods
    /**
     * Sets the node's previous reference to point to Node n.
     * @param p    the node that should precede this one
     */
    public void setPrev(Node<E> p) { prev = p; }

    /**
     * Sets the node's next reference to point to Node n.
     * @param n    the node that should follow this one
     */
    public void setNext(Node<E> n) { next = n; }

    public void setElement(E element)
    {
      this.element=element;
    }
  } //----------- end of nested Node class -----------

  // instance variables of the DoublyLinkedList
  /** node at the beginning of the list */
  private Node<E> head;                    // header

  /** node at the end of the list */
  private Node<E> tail;                   // trailer

  /** Number of elements in the list  */
  private int size = 0;                      // number of elements in the list

  /** Constructs a new empty list. */
  public DoublyLinkedList() {
  }

  // public accessor methods
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
   * Returns (but does not remove) the first element of the list.
   * @return element at the front of the list (or null if empty)
   */
  public E first() 
  {
    if(isEmpty())
    {
      return null;
    } 
    else
      return head.getElement();
  }

  /**
   * Returns (but does not remove) the last element of the list.
   * @return element at the end of the list (or null if empty)
   */
  public E last() 
  {
    if(isEmpty())
    {
      return null;
    }
    else
      return tail.getElement();
  }

  // public update methods
  /**
   * Adds an element to the front of the list.
   * @param e   the new element to add
   */
  public void addFirst(E e) 
  {
    Node<E> n=head;
    //head.setPrev(head);
    head=new Node<E>(e,null,head);
    
    if(size==0)
    {
      tail=head;
    }
    else{
      n.setPrev(head);
    }
    size++;
  }

  /**
   * Adds an element to the end of the list.
   * @param e   the new element to add
   */
  public void addLast(E e) 
  {
    Node<E> newNode= new Node<E>(e,tail,null);
    if(isEmpty())
    {
      head=newNode;
    }
    else{
      tail.setNext(newNode);
    }
    tail=newNode;
    size++;
  }

  public void reverse()
  {
    Node<E> temp1=head;
    Node<E> temp=null;
    Node<E> current=head;
    while(current!=null)
    {
      temp=current.getPrev();
      current.setPrev(current.getNext());
      current.setNext(temp);
      current=current.getPrev();
    }

    if(temp!=null)
    {
      head=temp.getPrev();
    }
    tail=temp1;
  }

  /**
   * Removes and returns the first element of the list.
   * @return the removed element (or null if empty)
   */
  public E removeFirst() 
  {
    if(isEmpty())
      return null;
    E ans=head.getElement();
    head=head.getNext();
    size--;
    if(size==0)
    {
      tail=null;
    }
    else
    {
      head.setPrev(null);
    }
    return ans;
  }

  /**
   * Removes and returns the last element of the list.
   * @return the removed element (or null if empty)
   */
  public E removeLast() 
  {
    if(isEmpty())
    {
      return null;
    }
    E ans = tail.getElement();
    tail=tail.getPrev();
    tail.setNext(null);
    size--;
    if(size==0)
    {
      head=null;
    }
    return ans;
  }

  public void insertAt(int index,E data)
  {
    Node<E> temp=head;
    while(index-->1)
    {
      temp=temp.getNext();
    }
    addBetween(data, temp, temp.getNext());
  }

  // private update methods
  /**
   * Adds an element to the linked list in between the given nodes.
   * The given predecessor and successor should be neighboring each
   * other prior to the call.
   *
   * @param predecessor   node just before the location where the new element is inserted
   * @param successor     node just after the location where the new element is inserted
   */
  private void addBetween(E e, Node<E> predecessor, Node<E> successor) 
  {
    Node<E> newNode=new Node<E>(e, predecessor, successor);
    predecessor.setNext(newNode);
    successor.setPrev(newNode);
  }

  public E removeAt(int index)
  {
    Node<E> temp=head;
    while(index-->0)
    {
      temp=temp.getNext();
    }
    return remove(temp);
  }

  //Sort The Given Linked List
  public void sort()
  {
    Node<E> start=head;
    while(start!=null)
    {
      Node<E> next=start.getNext();
      while(next!=null)
      {
        E x=start.getElement();
        E y=next.getElement();
        if(x.compareTo(y)>0)
        {
          start.setElement(y);
          next.setElement(x);
        }
        next=next.getNext();
      }
      start=start.getNext();
    }
  }

  /**
   * Removes the given node from the list and returns its element.
   * @param node    the node to be removed (must not be a sentinel)
   */
  private E remove(Node<E> node) 
  {
    Node<E> temp=head;
    while(temp!=node)
    {
      temp=temp.getNext();
    }
    Node<E> t=temp.getNext();
    E ans=temp.getElement();
    temp=temp.getPrev();
    temp.setNext(t);
    return ans;
  }

  /**
   * Produces a string representation of the contents of the list.
   * This exists for debugging purposes only.
   */
  public String toString() 
  {
    StringBuilder sb = new StringBuilder("[");
    Node<E> walk = head;
    while (walk != null) {
      sb.append(walk.getElement());
      if (walk != tail)
        sb.append(", ");
      walk = walk.getNext();
    }
    sb.append("]");
    return sb.toString();
  }
} //----------- end of DoublyLinkedList class -----------