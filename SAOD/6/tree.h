#include <iostream>
using namespace std;

// узел дерева
struct Node {
  double elem;     // содержимое узла
  int height;   // высота узла

  // Node *Prev;   // указатель на предка
  Node *left = NULL;   // указатель на меньшего потомка
  Node *right = NULL;  // указатель на большего потомка
};

class Tree {
public:
  Tree();

  void balance();
  void append(int);
  void pop();
  void show();
  Node *get_root();
  int get_height(Node* ptr);
  void print_recursion(Node* ptr);

private:
  Node *tree = NULL;

};

// конструктор
Tree::Tree() {}

// доавление элемента
void Tree::append(int elem) {
  if (tree == NULL) {
    tree = new Node;
    tree -> elem = elem;
    tree -> height = 1;
  } else {
    Node *root = tree;
    int height = 1;
    while (true) {
      if (tree -> elem == elem) {
        break;
      } else if (tree -> elem > elem) {
        if (tree -> right != NULL) {
          tree = tree -> right;
        } else {
          tree -> right = new Node;
          tree -> right -> height = height;
          tree -> right -> elem = elem;
          break;
        }
      } else {
        if (tree -> left != NULL) {
          tree = tree -> left;
        } else {
          tree -> left = new Node;
          tree -> left -> height = height;
          tree -> left -> elem = elem;
          break;
        }
      }

      height++;
    }
    tree = root;
  }
  // show();
}

void Tree::balance() {

}

Node *Tree::get_root() {
  return tree;
}

int Tree::get_height(Node* ptr) {
  if (ptr != NULL) {
    int left = get_height(ptr -> left);
    int right = get_height(ptr -> right);
    return ((left > right)? left: right) + 1;
  } else {
    return 0;
  }
}

//
void Tree::show() {
  Node *root = tree;
  print_recursion(tree);
  tree = root;
}

//
void Tree::print_recursion(Node* ptr) {
	if (ptr -> left != NULL) { print_recursion(ptr -> left); }
	cout << ptr -> elem << endl;
	if (ptr -> right != NULL) { print_recursion(ptr -> right); }
}
