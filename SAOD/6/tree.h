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

#include "balance.h"


class Tree {
public:
  Tree();

  bool append(double);
  void remove_elem(double);
  void show();
  Node* get_root();
  int get_height(Node* ptr);
  Node* find(double);
  Node* balance_node(Node* ptr);
  void inOrder(Node* ptr);
  void print_recursion(string prefix, Node* ptr, bool isLeft);

private:
  Node *tree = NULL;

};

// конструктор
Tree::Tree() {}

// доавление элемента
bool Tree::append(double elem) {
  bool ok = true;
  if (tree == NULL) {
    tree = new Node;
    tree -> elem = elem;
    tree -> height = 1;
  } else {
    Node *root = tree;
    int height = 1;
    while (true) {
      if (tree -> elem == elem) {
        ok = false;
        break;
      } else if (tree -> elem < elem) {
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
    tree = balance_node(tree);
  }

  if (ok)
    return true;
  else
    return false;
}

// удаление дерева
void Tree::remove_elem(double elem) {
  tree = remove(tree, elem);
}

// балансировка всего дерева
Node* Tree::balance_node(Node *ptr) {
  if (ptr -> left != NULL) {
    ptr -> left = balance_node(ptr -> left);
  }
  if (ptr -> right != NULL) {
    ptr -> right = balance_node(ptr -> right);
  }
  ptr = balance(ptr);
  return ptr;
}

// вернуть указатель дерева
Node* Tree::get_root() {
  return tree;
}

// поиск элемента
Node* Tree::find(double elem) {
  Node* find_elem = tree;
  int steps = 0;
  if (tree != NULL) {
    while (true) {
      steps++;
      if (find_elem -> elem < elem) {
        if (find_elem -> right != NULL) {
          find_elem = find_elem -> right;
        } else break;
      } else if (find_elem -> elem > elem) {
        if (find_elem -> left != NULL) {
          find_elem = find_elem -> left;
        } else break;
      } else {
        cout << "Для поисика потребовалось " << steps << " шагов." << endl;
        return find_elem;
      }
    }
  }
  return NULL;
}

// обход дерева (симетрично)
void Tree::inOrder(Node* ptr) {
  if (ptr == NULL) return;
  inOrder(ptr -> left);
  cout << ptr -> elem << " ";
  inOrder(ptr -> right);
}

// получить высоту дерева
int Tree::get_height(Node* ptr) {
  if (ptr != NULL) {
    int left = get_height(ptr -> left);
    int right = get_height(ptr -> right);
    return ((left > right)? left: right) + 1;
  } else {
    return 0;
  }
}

// показать дерево
void Tree::show() {
  print_recursion("", tree, false);
}

// вывод дерева (рекурсивно)
void Tree::print_recursion(string prefix, Node* ptr, bool isLeft) {
  if (ptr != NULL) {
    cout << prefix;
    cout << (isLeft ? "├──" : "└──" );
    cout << ptr-> elem << endl;
    print_recursion(prefix + ((isLeft) ? "│  " : "   "), ptr -> right, true);
    print_recursion(prefix + ((isLeft) ? "│  " : "   "), ptr -> left, false);
  }
}
