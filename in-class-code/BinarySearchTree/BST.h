#ifndef BST_H
#define BST_H

#include "TreeNode.h"

template <typename T>
class BST{
public:
  BST();
  virtual ~BST();
  int getSize();
  void insert(T d);
  void remove(T d);
  bool contains(T d);
  T getMin();
  T getMax();
  void printTreeInOrder();


private:
  TreeNode<T>* m_root;
  int m_size;
  void insertHelper(TreeNode<T>*& subTreeRoot,TreeNode<T>* newNode);
  bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* target);
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target,TreeNode<T>*& parent);
  TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);

};

template <typename T>
BST<T>::BST(){
  m_root = NULL;
  m_size = 0;
}

template <typename T>
BST<T>::~BST(){
  if(m_root != NULL){
    delete m_root;
  }
}

template <typename T>
int BST<T>::getSize(){
  return m_size;
}

template <typename T>
void BST<T>::insert(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  insertHelper(m_root,newNode);
  ++m_size;
}

template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot,TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    subTreeRoot = newNode;
  } else if(newNode->m_data < subTreeRoot->m_data){
    insertHelper(subTreeRoot->m_left,newNode);
  } else{
    insertHelper(subTreeRoot->m_right,newNode);
  }
}

template <typename T>
void BST<T>::remove(T d){
  // check if tree is empty
  TreeNode<T>* target = NULL;
  TreeNode<T>* parent = NULL;
  target = m_root;
  findTarget(d, target, parent);
  if (target == NULL) {
    return;
  }
  if (target->m_left == NULL && target->m_right == NULL) { // it's a leaf
    if (target == m_root) {
      m_root = NULL;
    } else { // not the root
      if (target == parent->m_left) {
        parent->m_left = NULL;
      } else {
        parent->m_right = NULL;
      }
    }
  } else if (target->m_left != NULL && target->m_right != NULL) { // two children
    TreeNode<T>* suc = getSuccessor(target->m_right);
    T value = suc->m_data;
    remove(value);
    target->m_data = value;
  } else { // one child case
    TreeNode<T>* child;
    if (target->m_left != NULL) {
      child = target->m_left;
    } else {
      child = target->m_right;
    }
    if (target == m_root) {
      m_root = child;
    } else {
      if (target == parent->m_left) {
        parent->m_left = child;
      } else {
        parent->m_right = child;
      }
    }
  }
  --m_size;
}

template <typename T>
bool BST<T>::contains(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  bool ret =  containsHelper(m_root,newNode);
  delete newNode;
  return ret;
}

template <typename T>
bool BST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* target){
  if(subTreeRoot == NULL){
    return false;
  } else if(target->m_data < subTreeRoot->m_data){
    return containsHelper(subTreeRoot->m_left,target);
  } else if (target->m_data > subTreeRoot->m_data){
    return containsHelper(subTreeRoot->m_right,target);
  } else{
    return true;
  }
}

template <typename T>
T BST<T>::getMin(){
  //what if the tree is empty?
  return getMinHelper(m_root);
}

template <typename T>
T BST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}

template <typename T>
T BST<T>::getMax(){
  //what if the tree is empty?
  return getMaxHelper(m_root);
}

template <typename T>
T BST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }
}

template <typename T>
void BST<T>::printTreeInOrder(){
  printTreeInOrderHelper(m_root);
}

template <typename T>
void BST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left != NULL){
    printTreeInOrderHelper(subTreeRoot->m_left);
  }

  cout << subTreeRoot->m_data << endl;
  if(subTreeRoot->m_right != NULL){
    printTreeInOrderHelper(subTreeRoot->m_right);
  }


}

template <typename T>
void BST<T>::findTarget(T key, TreeNode<T>*& target,TreeNode<T>*& parent){
  while (target != NULL && target->m_data != key) {
    parent = target;
    if (key < target->m_data) {
      target = target->m_left;
    } else {
      target = target->m_right;
    }
  }
}

template <typename T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* rightChild){
  while (rightChild->m_left != NULL) {
    rightChild = rightChild->m_left;
  }
  return rightChild;
}

#endif
