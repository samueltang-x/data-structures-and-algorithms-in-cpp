#include "StringLinkedList.h"
#include "../../ch2/RuntimeException.h"

using namespace std;

StringLinkedList::StringLinkedList() {
  head = NULL;
}

StringLinkedList::~StringLinkedList() {
  while (!empty()) {
    removeFront();
  }
}

bool StringLinkedList::empty() {
  return (head == NULL);
}

const string& StringLinkedList::front() const {
  if (empty()) throw RuntimeException("get front of empty StringLinkedList");
  return head->elem;
}

void StringLinkedList::addFront(const string& e) {
  StringNode* sp = new StringNode;
  sp->elem = e;
  sp->next = head;
  head = sp;
}

void StringLinkedList::removeFront() {
  if (empty()) throw RuntimeException("remove front of empty StringLinkedList");
  StringNode* old = head;
  head = old->next;
  delete old;
}
