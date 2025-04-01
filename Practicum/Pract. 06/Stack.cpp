#include "Stack.h"
#include <iostream>

void Stack::free() {
  delete[] elements;
}

void Stack::copyFrom(const Stack& other) {
  size = other.size;
  capacity = other.capacity;

  elements = new int[capacity];

  for (int i = 0; i < size; i++) {
    elements[i] = other.elements[i];
  }
}

void Stack::resize(int newCap) {
  capacity = newCap;

  int* newElements = new int[capacity];

  for (int i = 0; i < size; i++) {
    newElements[i] = elements[i];
  }

  delete[] elements;
  elements = newElements;
}

Stack::Stack() {
  capacity = 8;
  size = 0;
  elements = new int[capacity];
}

Stack::Stack(const Stack& other) {
  copyFrom(other);
}

Stack::~Stack() {
  free();
}

Stack& Stack::operator=(const Stack& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

void Stack::push(int a) {
  if (size == capacity) {
    resize(capacity * 2);
  }

  elements[size++] = a;
}

void Stack::pop() {
  size--;
}

int Stack::peek() const {
  return elements[size - 1];
}

void Stack::print() const {
  for (int i = 0; i < size; i++) {
    std::cout << elements[i] << " ";
  }

  std::cout << std::endl;
}