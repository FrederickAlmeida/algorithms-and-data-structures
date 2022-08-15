#include <iostream>

using std::cout;
using std::cin;

class BSTNode {
public:
  int element;
  BSTNode* left;
  BSTNode* right;

  BSTNode(int e) {
    element = e;
    left = right = NULL;
  }

};


class BST {
public:
  BSTNode* root;
  int nodecount;

  BST() {
    root = NULL;
    nodecount = 0;
  }

  void insert(int value) {
    root = inserthelp(root, value);
    nodecount++; 
  }

  BSTNode* inserthelp(BSTNode* rt, int value) {
    if (rt == NULL) {
      return new BSTNode(value);
    }

    if (rt->element > value) {
      rt->left = inserthelp(rt->left, value);

    } else {
      rt->right = inserthelp(rt->right, value);

    }

    return rt;
  }

  int find(int value) {
    return findhelp(root, value);
  }

  int findhelp(BSTNode* rt, int value) {
    if (rt == NULL) {
      return -1;

    } else if (rt->element > value) {
      return findhelp(rt->left, value);

    } else if (rt->element == value) {
      return rt->element;

    } else {
      return findhelp(rt->right, value);
    }
    
  }

  int remove(int e) {
    int temp = findhelp(root, e);

    if (temp != -1) {
      root = removehelp(root, e);
      nodecount--;
    }
    return temp;
  }

  BSTNode* removehelp(BSTNode* rt, int e) {
    if (rt == NULL) {
      return NULL;
    }

    if (rt->element > e) {
      rt->left = removehelp(rt->left, e);

    } else if(rt->element < e) {
      rt->right = removehelp(rt->right, e);

    } else {
      if (rt->left == NULL) {
        BSTNode* temp = rt->right;
        delete rt;
        return temp;

      } else if (rt->right == NULL) {
        BSTNode* temp = rt->left;
        delete rt;
        return temp;

      } else {
        BSTNode* temp = getmin(rt->right);
        BSTNode* temp2 = rt;

        rt->element = temp->element;
        rt->right = deletemin(rt->right);
        delete temp2;
      }
    }
  }

  BSTNode* getmin(BSTNode* rt) {
    if (rt->left == NULL) {
      return rt;
    }

    return getmin(rt->left);
  }

  BSTNode* deletemin(BSTNode* rt) {
    if (rt->left == NULL) {
      BSTNode* temp = rt->right;
      delete rt;
      return temp;
    }

    rt->left = deletemin(rt->left);
    return rt;
  }

  void preorder(BSTNode* rt) {
    if (rt != NULL) {
      cout << rt->element << ' ';

      preorder(rt->left);
      preorder(rt->right);
    }
  }

  void inorder(BSTNode* rt) {
    if (rt != NULL) {
      inorder(rt->left);

      cout << rt->element << ' ';

      inorder(rt->right);
    }
  }

  void posorder(BSTNode* rt) {
    if (rt != NULL) {
      posorder(rt->left);
      posorder(rt->right);

      cout << rt->element << ' ';
    }
  }
};


int main() {
  int n_elements, element;
  cin >> n_elements;

  BST arvore;
  for(int i = 0; i < n_elements; i++) {
    cin >> element;
    arvore.insert(element);
  }

  cout << "Pre order : ";
  arvore.preorder(arvore.root);
  cout << "\nIn order  : ";
  arvore.inorder(arvore.root);
  cout << "\nPost order: ";
  arvore.posorder(arvore.root);
}
