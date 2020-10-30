
#include "LinkedBinaryTree.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void testLinkedBinaryTree() {
  LinkedBinaryTree<string> tree;
  
  if (tree.empty()) tree.addRoot();

  cout << "tree sise: " << tree.size() << ", is empty: " << (tree.empty() ? "true" : "false") << "." << endl;
  LinkedBinaryTree<string>::Position root = tree.root();
  cout << "root, isRoot: " << boolalpha << root.isRoot() << ", isExternal: " << boolalpha << root.isExternal() << "." << endl;
}

int main() {
  testLinkedBinaryTree();
  return EXIT_SUCCESS;
}

