class CircularQueue
{
  static int SIZE=10;
  static int front=-1;
  static int rear=-1;
  static int array[]=new int[SIZE];
  
  void enqueue(int item)
  {
    if ((front == 0 && rear == SIZE-1) || (rear == (front-1)%(SIZE-1))) { 
      System.out.println("Queue is FULL.");
      return;
    }
    if(front == -1)
    front = rear = 0;
  else if (rear == SIZE-1 && front != 0)
    rear = 0;
  else
    rear++;

    array[rear] = item;

  }

  int dequeue()
  {
    if (front == -1)
    {
      System.out.println("Queue is Empty.");
      return -1;
    }
    int item = array[front];
    if (front == rear)
      front = rear = -1;
    else if (front == SIZE-1)
      front = 0;
    else
      front++;
    return item;
  }

  public static void main(String args[])
  {
    CicularQueue ob1=new CircularQueue();
    ob1.enqueue(10);
    ob1.enqueue(20);
    ob1.enqueue(30);
    ob1.enqueue(40);

    System.out.println(ob1.dequeue());
    System.out.println(ob1.dequeue());
    System.out.println(ob1.dequeue());
	System.out.println(ob1.dequeue());

    ob1.enqueue(50);
	System.out.println(ob1.dequeue());
  }
}
