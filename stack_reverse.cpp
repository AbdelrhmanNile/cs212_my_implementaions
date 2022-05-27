#include <iostream>
using namespace std;

typedef int itemType;
typedef class Node{
public:
  itemType data;
  Node *next;
}Node;

typedef class Stack{
public:
  int len;

  Node *top, *current, *previous;

  Stack(){
    len = 0;
    top = NULL;
  }

  void traverse(int loc){
    previous = NULL;
    current = top;

    if(loc != 1){
      for(int i = 2; i <= loc; i++){
        previous = current;
        current = current->next;
      }
    }
  }

  void push(itemType value){
    traverse(1);
    Node *newNode = new(Node);
    newNode->data = value;
    newNode->next = current;
    top = newNode;
    len = len + 1;
  }

  itemType pop(){
    traverse(1);
    top = current->next;
    len = len - 1;
    return current->data;
  }

  itemType getTop(){
    return top->data;
  }

  void display(){
    current = top;
    for(int i = 1; i <= len; i++){
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  void reverse(){
    current = top;
    previous = NULL;
    Node *temp;

    while(current != NULL){
      temp = current->next;
      current->next = previous;
      previous = current;
      current = temp;
    }
    top = previous;
  }
}Stack;

int main(){
  Stack stk;

  stk.push(1);
  stk.push(5);
  stk.display();
  stk.push(6);
  stk.display();
  stk.reverse();
  stk.display();
}
