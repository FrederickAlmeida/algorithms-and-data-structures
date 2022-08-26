#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

class BSTNode {
public:
    long long int element;
    int height;
    int leftnodes;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int e) {
        height = 0;
        element = e;
        left = right = NULL;
        leftnodes = 0;
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

    void insert(long long int value) {
        root = inserthelp(root, value);
        nodecount++; 
    }

    BSTNode* inserthelp(BSTNode* rt, long long int value) {
        if (rt == NULL) {
        return new BSTNode(value);
        }

        if (rt->element > value) {
        rt->leftnodes++;
        rt->left = inserthelp(rt->left, value);

        } else {
        rt->right = inserthelp(rt->right, value);

        }

        // implementar a função max, left rotate, right rotate
        rt->height = 1 + max(h(rt->left), h(rt->right));
        int balance = getbalance(rt);

        if (balance < -1 && value >= rt->right->element) {
            return leftrotate(rt);

        }
        if (balance > 1 && value < rt->left->element) {
            return rightrotate(rt);

        }
        if (balance > 1 && value >= rt->left->element) {
            rt->left = leftrotate(rt->left);
            return rightrotate(rt);

        }
        if (balance < -1 && value < rt->right->element) {
            rt->right = rightrotate(rt->right);
            return leftrotate(rt);

        }

        return rt;
    }

    int getbalance(BSTNode* rt) {
        if (rt == NULL) {
            return 0;
        }

        return (h(rt->left) - h(rt->right));
    }

    int h(BSTNode* rt) {
        if (rt == NULL) {
            return -1;
        }

        return rt->height;
    }

    int max(int a, int b) {
        if (a < b) {
            return b;
        }

        return a;
    }

    BSTNode* rightrotate(BSTNode* rt) {
        // quando ele rotacionar para a direita, vai perder todos os nós
        // da subarvore à esquerda dele, mais 1 do node que "subiu"
        rt->leftnodes -= (rt->left->leftnodes + 1);

        BSTNode* l = rt->left;
        BSTNode* lr = l->right;

        l->right = rt;
        rt->left = lr;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;

        return l;
    }

    BSTNode* leftrotate(BSTNode* rt) {
        BSTNode* r = rt->right;
        BSTNode* rl = r->left;

        r->left = rt;
        rt->right = rl;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;

        // quando o node do meio rotaciona, ele ganha um novo node à esquerda
        // e ganha também todos os nodes do novo node que está à esquerda dele
        r->leftnodes++;
        r->leftnodes += r->left->leftnodes;
        return r;
    }

    int find(long long int key) {
        return findhelp(root, key, 0);
    }

    int findhelp(BSTNode* rt, long long int key, int index) {
        if (rt == NULL) return 0;

        if (rt->element > key) return findhelp(rt->left, key, index);
        else if (rt->element == key) {
            return index + rt->leftnodes + 1;

        } else {
            index += rt->leftnodes + 1;
            return findhelp(rt->right, key, index);

        }
    }

};


int main() {
    BST test;
    int amount_operations, operacao, index;
    long long int numero;

    // quantidade de operações
    scanf("%d", &amount_operations);
    for (int i = 0; i < amount_operations; i++) {
        // pegar a operação
        scanf("%d", &operacao);

        // inserção
        if (operacao == 1) {
            scanf("%lld", &numero);
            test.insert(numero);

        // procurar a posição de um elemento
        } else if (operacao == 2) {
            scanf("%lld", &numero);
            index = test.find(numero);

            if (index == 0) printf("Data tidak ada\n");
            else printf("%d\n", index);
        }
    }
}
