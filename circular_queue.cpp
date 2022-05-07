#include <iostream>
using namespace std;

typedef int itemType;
typedef class Node {
public:
  itemType data;
  Node *next;
} Node;

typedef class cqueue {
public:
  int len;
  Node *front, *rear, *temp;
  cqueue() {
    front = NULL;
    rear = NULL;
    temp = NULL;
  }

  void enqueue(itemType value) {
    if (rear == NULL) {
      rear = new (Node);
      rear->data = value;
      rear->next = front;
      front = rear;
    } else {
      temp = new (Node);
      temp->data = value;
      temp->next = front;
      rear->next = temp;
      rear = temp;
    }
  }

  void dequeue() {
    temp = front;
    if (front == NULL) {
      cout << "underflow" << endl;
      return;
    } else {
      if (temp->next != NULL) {
        temp = temp->next;
        cout << "element deleted from queue is: " << front->data << endl;
        delete front;
        front = temp;
        rear->next = front;
      } else {
        cout << "element deleted is: " << front->data << endl;
        delete front;
        front = NULL;
        rear = NULL;
      }
    }
  }

  void display() {
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
      cout << "Queue is empty" << endl;
      return;
    }
    cout << "Queue elements are: ";
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
      if (temp == front) {
        temp = NULL;
      }
    }
    cout << endl;
  }
} cqueue;

int main() {
  cqueue queue;
  for (int i = 1; i <= 10; i++) {
    queue.enqueue(i);
  }

  queue.display();
  queue.dequeue();
  queue.display();
}
