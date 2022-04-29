#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

typedef class Node {
public:
  int data;
  Node *next;
} Node;

typedef class mystack {
public:
  int len;
  Node *top;

  mystack() { top = NULL; }

  void push(int value) {
    Node *newNode = new (Node);
    newNode->data = value;
    newNode->next = top;
    top = newNode;
  }

  void pop() {
    if (top == NULL) {
      cout << "stack is underflow." << endl;
    } else {
      Node *temp = top;
      top = top->next;
      delete temp;
    }
  }

  int getTop() { return top->data; }

  int prec(char c) {
    if (c == '^')
      return 3;
    else if (c == '*' || c == '/')
      return 2;
    else if (c == '+' || c == '-')
      return 1;
    else
      return -1;
  }

  int isOperator(char c) {
    if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-') {
      return 1;
    }
    return -1;
  }

  int isOperand(char c) {
    if (c >= '0' && c <= 9) {
      return 1;
    }
    return -1;
  }

  int operation(int a, int b, char op) {
    switch (op) {
    case '+':
      return (b + a);
      break;
    case '-':
      return (b - a);
      break;
    case '*':
      return (b * a);
      break;
    case '/':
      return (b / a);
      break;
    case '^':
      return (pow(b, a));
      break;
    default:
      return INT32_MIN; // garbage
    }
  }

  float scanNum(char n) {
    int value;
    value = n;
    return float(value - '0');
  }

  string infixToPostfix(string exp) {
    push('N');
    string result;
    int expLen = exp.length();

    for (int i = 0; i < expLen; i++) {
      if ((exp[i] >= '0' && exp[i] <= '9')) {
        result += exp[i];
      } else if (exp[i] == '(') {
        push('(');
      } else if (exp[i] == ')') {
        while (getTop() != 'N' && getTop() != '(') {
          char op = getTop();
          pop();
          result += op;
        }
        if (getTop() == '(')
          pop();
      } else {
        while (getTop() != 'N' && prec(exp[i]) <= prec(getTop())) {
          char op = getTop();
          pop();
          result += op;
        }
        push(exp[i]);
      }
    }

    while (getTop() != 'N') {
      char op = getTop();
      pop();
      result += op;
    }
    return result;
  }

  int PostfixEval(string postfix) {

    int len = postfix.length();

    for (int i = 0; i < len; i++) {

      if (postfix[i] >= '0' && postfix[i] <= '9') {
        push(scanNum(postfix[i]));
      } else {
        int a = getTop();
        pop();
        int b = getTop();
        pop();
        push(operation(a, b, postfix[i]));
      }
    }

    return getTop();
  }

} mystack;

int main() {
  mystack stack;
  string exp = "9+(8+7)*6+5*(4+(3*2+1))";

  string postfix = stack.infixToPostfix(exp);
  cout << "postfix: " << postfix << endl;

  cout << "postfix eval: " << stack.PostfixEval(postfix) << endl;
}