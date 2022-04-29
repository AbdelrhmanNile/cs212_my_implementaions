#include <iostream>
using namespace std;

typedef int itemType;
typedef class Node {
public:
  itemType data;
  Node *next;
} Node;

typedef class clist {
public:
  int len;
  Node *current, *head;

  clist() {
    head = NULL;
    len = 0;
  }

  void createNode(itemType value) {
    Node *newNode = new (Node);
    newNode->data = value;

    if (head == NULL) {
      head = newNode;
      current = newNode;
      newNode->next = head;
      newNode = NULL;
    } else {
      newNode->next = head;
      current->next = newNode;
      current = newNode;
    }
    len++;
  }

  void display() {
    Node *temp;
    temp = head;

    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
      if (temp == head)
        temp = NULL;
    }
  }

  int josephus(int skipCounter) {
    Node *ptr = new (Node);
    ptr = head;

    for (int i = 1; i < len; i++) {
      for (int j = 0; j < skipCounter - 1; j++) {
        ptr = ptr->next;
      }

      ptr->next = ptr->next->next;
    }
    return ptr->data;
  }
} clist;

int main() {

  int size;
  int skipCounter;

  clist list;

  cout << "enter the list size: ";
  cin >> size;

  for (int i = 1; i <= size; i++) {
    list.createNode(i);
  }

  cout << "the list before the game:" << endl;
  list.display();
  cout << "\n enter the skip counter: ";
  cin >> skipCounter;
  while (skipCounter > size || skipCounter == 1) {
    if (skipCounter > size) {
      cout << "skip counter cannot be > size: ";
      cin >> skipCounter;
    } else {
      cout << "skip counter cannot = 1: ";
      cin >> skipCounter;
    }
  }

  cout << "the winnig number is: " << list.josephus(skipCounter) << endl;
}