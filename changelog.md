# Changelog

## [1.13.0] - 2020-11-11
### Added
- ListPriorityQueue

## [1.12.0] - 2020-10-31
### Added
- EulerTour: a generic Euler tour of a binary tree.
- EvaluateExpressionTour: to evaluate an arithmetic expression by inherit EulerTour.
- PrintExpressionTour: to print an arithmetic expression by inherit EulerTour.

## [1.11.0] - 2020-10-30
### Added
- LinkedBinaryTree

## [1.10.0] - 2020-10-17
### Changed
- refact test script to use python script with yaml input

## [1.9.0] - 2020-10-17
### Added
- ShrinkingVector and test
- add capacity() interface for ArrayVector
### Changed
- Move ArrayVector private members E* a and int cap to protected
### Fixed
- Fix bug constructor(int c) when c > 0

## [1.8.0] - 2020-10-11
### ch6 exercises
- Add VectorStack: R-6.5 Give an adapter class to support the Stack interface using the functions of the vector ADT
- Change NodeList: R-6.12 Provide the missing housekeeping functions (copy constructor, assignment operator, and destructor) for the class NodeList

## [1.7.0] - 2020-10-10
### Add rotateArray: R-6.3 Give a C++ code fragment for circularly rotating an array by distance d

## [1.6.0] - 2020-10-09
### ch6 exercises
- Add randomArray: R-6.2 Give a C++ code fragment for randomly permuting an array
- Add reverseArray: R-6.1 Give a C++ code fragment for reversing an array

## [1.5.0] - 2020-10-07
### ch6. Add NodeSequence
- Implementing a sequence with a doubly linked list (inherit NodeList) 
- Add overloading operator+/- for NodeList<E>::Iterator

## [1.4.0] - 2020-10-05
### ch6. Add an example of the use of the STL vector and iterators

## [1.3.0] - 2020-10-05
### ch6. Add NodeList: Doubly linked list implementation

## [1.2.0] - 2020-10-04
### ch6. Add ArrayVector: a vector based on an extendable array

## [1.1.0] - 2020-10-01
### implement a queue with a circularly linked list
- add LinkedQueue based on circularly linked list
- add copy constructor and assignment operator for CircleList

## [1.0.1] - 2020-09-26
### Change all test scripts name to pattern test-*.sh

## [1.0.0] - 2020-09-26
### ch5. Deque based on a doubly linked list
- add LinkedDeque
- add copy constructor, assignment operator for DLinkedList
