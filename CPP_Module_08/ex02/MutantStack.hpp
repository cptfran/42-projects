#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

//The stack adapter follows the Last In, First Out (LIFO) principle, and the insertion and removal of elements can be
//done only from the top of the queue container.
//The following are the key operations of the stack:
//push(elm): Insert the element elm at the top.
//pop(): Removes the top element.
//top(): Returns a reference to the top element.
//empty(): Checks whether the stack is empty.
//size(): Returns the number of elements.

//The stack is an adapter container, means they are created based on other containers like deque, vector, list
//with '::c' we can access base container in adapter container.

// Note: '::c' is an implementation detail and is not part of the official C++ specification.
// It may not be available in all C++ implementations.

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Define a type 'iterator' that is the same as the iterator type of the underlying container used by std::stack<T>
    typedef typename std::stack<T>::container_type::iterator  iterator;
    // Function that returns an iterator pointing to the beginning of the underlying container
    iterator begin() {
        return this->c.begin();
    }
    // Function that returns an iterator pointing to the end of the underlying container
    iterator end() {
        return this->c.end();
    }
};

#endif