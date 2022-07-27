#include <iostream>

using std::cout;

class Node {
public:
  int element;
  Node* next;

  Node(int value, Node* ptrnext=NULL) {
    element = value;
    next = ptrnext;
  }

  Node(Node* ptrnext=NULL) {
    next = ptrnext;
  }
};


class Stack : public Node {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int value) {
        top = new Node(value, top->next);
        size++;
    }

    int pop() {
        if (size > 0) {
            int value = top->element;
            Node* ptr = top;

            top = top->next;
            
            delete ptr;
            size--;

            return value;
        }

        return -1;
    }

    int length() {
        return size;
    }

    int topvalue() {
        return top->element;
    }

    void clear() {
        if (top != NULL) {
            Node* temp;

            do {
                temp = top;
                top = top->next;
                delete temp;
            } while (top != NULL);
        }
    }

};


int main() {
  
}
