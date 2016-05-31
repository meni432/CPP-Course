#include <string>
using namespace std;


class MyLinkedList
{
public:
  // Regular constructor
  MyLinkedList();
  // initialize with arrays constructor
  MyLinkedList(const string keysArr[], const double valsArr[], size_t arrayLength);
  // copy constructor
  MyLinkedList(const MyLinkedList& other);
  // distrucator
  ~MyLinkedList();
  // operator '=' function
  MyLinkedList& operator=(const MyLinkedList& other);
  // add (key,data) to linked list
  void add(const string key, const double data);
  // remove from linked list
  size_t remove(string str);
  // check if (key, data) in list
  bool isInList(string key, double data) const;
  // return sum list
  double sumList() const;
  // return size of list
  size_t size() const;
  // operator '==' function
  bool operator==(const MyLinkedList& other) const;
  // operator '!=' function
  bool operator!=(const MyLinkedList& other) const;

private:
  // Inner class
  struct MyLinkedListNode
  {
    MyLinkedListNode * _next;
    MyLinkedListNode * _prev;
    string key;
    double data;
  };

  MyLinkedListNode * _head;
  MyLinkedListNode * _tail;
  size_t _size; // number of nodes in list

  // delete all node from current list, set size to 0
  void deleteAllNodes();
  // add all node from other list to the current list in order,
  // but without change current list (not delete any node from current list)
  void copy(const MyLinkedList& other);
  // initialize pointer and size (not distruct data)
  void initializePointer();
};
