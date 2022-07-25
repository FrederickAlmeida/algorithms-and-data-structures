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

class LinkedList : public Node {
private:
  Node* head;    // ponteiro para o header
  Node* tail;
  Node* curr;
  int size;

  void init() {
    curr = tail = head = new Node();
    size = 0;
  }

  void removeall() {        // vai 
    while(head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  void insert(int value) {
    curr->next = new Node(value, curr->next);
    size++;
    
    if (tail == curr)
      tail = curr->next;
  }

  void moveToStart() {
    curr = head;
  }

  void next() {
    if (curr != tail) 
      curr = curr->next;
  }

  void prev() {
    if (curr != head) {
      Node* temp = head;

      while (temp->next != curr) {
        temp = temp->next;
      }
      curr = temp;
    } else return;
  }

  int remove() {
    if (curr->next == NULL)             // caso nao tenha nenhum node após o cursor
        return NULL;
    
    int value = curr->next->element;       // salvar o elemento para retornar ele depois
    Node* ntemp = curr->next;              // guardar a localização do node em uma variável, para nao perder ele

    if (tail = curr->next)                 // caso seja o ultimo node, atualizar o tail
        tail = curr;
    
    delete ntemp;                          // recuperar o espaço
    curr->next = curr->next->next;
    size--;

    return value;
  }

  void append(int i) {
    tail->next = new Node(i, NULL);
    size++;
  }

  int length() {
    return size;
  }

  int currPos() {
    Node* temp = head;

    int i;
    for (i = 0; temp->next != curr; i++) {
        temp = temp->next;
    }

    return i;
  }

  int getValue() {
    if (curr->next != NULL) {
        return curr->element;
    }

    return NULL;
  }
};

int main() {

  
}