#include "MyLinkedList.hpp"

//Default constructor
MyLinkedList::MyLinkedList()
{
    initializePointer();
}

 // initialize with arrays constructor
MyLinkedList::MyLinkedList(const string keysArr[], const double valsArr[],
                           size_t arrayLength)
{
    size_t i;
    initializePointer();

    for (i = 0; i < arrayLength; i++)
    {
        add(keysArr[i], valsArr[i]);
    }

}

// Copy constructor
MyLinkedList::MyLinkedList(const MyLinkedList & other)
{
    initializePointer();
    copy(other);
}

// Distructor
MyLinkedList::~MyLinkedList()
{
    MyLinkedList::MyLinkedListNode * current = _head;
    if (_size > 0)
    {
        while (current != _tail)
        {
            current = current->_next;
            delete current->_prev;
        }
        delete _tail;
        _size = 0;
    }
}

 // operator '=' function
MyLinkedList & MyLinkedList::operator=(const MyLinkedList & other)
{
    if (this != &other)
    {
        deleteAllNodes();
        copy(other);
    }

    return *this;
}

// add (key,data) to linked list
void MyLinkedList::add(const string key, const double data)
{
    MyLinkedList::MyLinkedListNode * newElement = new MyLinkedListNode();
    newElement->key = key;
    newElement->data = data;

    if (_size == 0)             // if this is the first node in the list, set the node as head and tail
    {
        _head = newElement;
        _tail = newElement;
    } else                      // if not, connect the node to te neighbor
    {
        newElement->_prev = _tail;
        _tail->_next = newElement;
        _tail = newElement;
    }
    _size++;
}

// remove from linked list
size_t MyLinkedList::remove(string str)
{
    size_t removeCounter = 0;
    if (_size > 0)              // check if there is node in list
    {
        MyLinkedList::MyLinkedListNode * current = _head;
        while (current != nullptr)
        {
            if (current->key == str)
            {
                if (_size == 1) // if the node is the last node in the list (current = head = tail)
                {
                    delete _head;
                    _head = nullptr;
                    _tail = nullptr;
                    current = _head;
                } else
                {
                    if (current == _head)
                    {
                        _head = _head->_next;
                        delete _head->_prev;
                        _head->_prev = nullptr;
                        current = _head;
                    } else if (current == _tail)
                    {
                        _tail = _tail->_prev;
                        delete _tail->_next;
                        _tail->_next = nullptr;
                        current = nullptr;
                    } else      // the node is "regular node" e.g. not head/tail, need to connect neighbor nodes
                    {
                        MyLinkedList::MyLinkedListNode * temp = current;
                        current->_prev->_next = current->_next;
                        current->_next->_prev = current->_prev;
                        current = current->_next;
                        delete temp;
                    }
                }
                removeCounter++;
                _size--;
            } else              // if the key not equal, check in the next node
            {
                current = current->_next;
            }
        }
    }
    return removeCounter;
}

// check if (key, data) in list
bool MyLinkedList::isInList(string key, double data) const
{
    MyLinkedList::MyLinkedListNode * current = _head;
    while (current != nullptr)
    {
        if (current->key == key && current->data == data)
        {
            return true;
        }
        current = current->_next;
    }
    return false;
}

// return sum list
double MyLinkedList::sumList() const
{
    double totalSum = 0;
    MyLinkedList::MyLinkedListNode * current = _head;
    while (current != nullptr)
    {
        totalSum += current->data;
        current = current->_next;
    }

    return totalSum;
}

// return size of list
size_t MyLinkedList::size() const
{
    return _size;
}

// operator '==' function
bool MyLinkedList::operator==(const MyLinkedList & other) const
{
    if (_size != other.size())  // check if the size of two list is equals, if not, isn't passible that list are equals
    {
        return false;
    }
    if (this != &other)         // check if other is not this list
    {
        MyLinkedList::MyLinkedListNode * currentThis = _head;
        MyLinkedList::MyLinkedListNode * currentOther = other._head;
        while (currentThis != nullptr && currentOther != nullptr)
        {
            if (currentThis->key != currentOther->key
                || currentThis->data != currentOther->data)
            {
                // if there is one node that not equal in order and value, return false
                return false;
            }
            currentThis = currentThis->_next;
            currentOther = currentOther->_next;
        }
    }
    // if not find any out of order/value node, return true
    return true;
}

 // operator '!=' function
bool MyLinkedList::operator!=(const MyLinkedList & other) const
{
    // retrun the inverse from operator '=='
    return !operator==(other);
}

// delete all node from current list, set size to 0
void MyLinkedList::deleteAllNodes()
{
    MyLinkedList::MyLinkedListNode * current = _head;
    if (_size > 0)
    {
        while (current != _tail)
        {
            current = current->_next;
            delete current->_prev;
        }
        delete _tail;
        _size = 0;
    }
}

// add all node from other list to the current list in order,
// but without change current list (not delete any node from current list)
void MyLinkedList::copy(const MyLinkedList & other)
{
    MyLinkedList::MyLinkedListNode * current = other._head;

    while (current != nullptr)
    {
        add(current->key, current->data);
        current = current->_next;
    }

}

// initialize pointer and size (not distruct data)
void MyLinkedList::initializePointer()
{
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}
