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

class Queue : public Node {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = rear = new Node();
        size = 0;
    }

    void enqueue(int value) {
        rear->next = new Node(value, NULL);
        rear = rear->next;
        size++;
    }

    int dequeue(int value) {
        if (size > 0) {
            int value = front->next->element;
            Node* temp = front->next;

            front->next = front->next->next;
            delete temp;
            size--;

            if (front->next == NULL) {
                rear = front;
            }

            return value;
        }

        return -1;
    }

    int length() {
        return size;
    }

    int frontvalue() {
        return front->next->element;
    }

    void clear() {
        if (front->next != NULL) {
            do {
                rear = front->next;
                front->next = front->next->next;

                delete rear;
            } while (front->next != NULL);

            rear = front;
            size = 0;
        }
    }

};

int main() {

  
}
