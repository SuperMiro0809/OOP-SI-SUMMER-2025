#include "Order.h"
#include <iostream>

void Order::free() {
  delete[] products;
}

void Order::copyFrom(const Order& other) {
  number = other.number;
  size = other.size;
  capacity = other.capacity;

  products = new Item[capacity];

  for (int i = 0; i < size; i++) {
    products[i] = other.products[i];
  }
}

void Order::resize(int newCap) {
  capacity = newCap;

  Item* newProducts = new Item[capacity];

  for (int i = 0; i < size; i++) {
    newProducts[i] = products[i];
  }

  delete[] products;
  newProducts = products;
}

Order::Order() {
  number = 1;
  size = 0;
  capacity = 8;
  products = new Item[capacity];
}

Order::Order(const Order& other) {
  copyFrom(other);
}

Order::~Order() {
  free();
}

Order& Order::operator=(const Order& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

void Order::addItem(const Item& item) {
  if (size == capacity) {
    resize(capacity * 2);
  }

  products[size++] = item;
}

void Order::cancel() {
  size = 0;
}

void Order::print() const {
  std::cout << "Order number: " << number << std::endl;
  std::cout << "Items: ";

  for (int i = 0; i < size; i++) {
    std::cout << products[i].name << ", ";
  }
  std::cout << std::endl;
}
