#include "StringLinkedList.h"
#include "../../misc/extendExceptions.h"

using namespace std;

StringLinkedList::StringLinkedList() {
  head = NULL;
}

StringLinkedList::~StringLinkedList() {
  while (!empty()) removeFront();
}

bool StringLinkedList::empty() {
  return (head == NULL);
}

const string& StringLinkedList::front() const {
  if (empty()) throw ListEmpty("Get front of empty StringLinkedList");
  return head->elem;
}

void StringLinkedList::addFront(const string& e) {
  StringNode* sp = new StringNode;
  sp->elem = e;
  sp->next = head;
  head = sp;
}

void StringLinkedList::removeFront() {
  if (empty()) throw ListEmpty("Remove front of empty StringLinkedList");
  StringNode* old = head;
  head = old->next;
  delete old;
}
