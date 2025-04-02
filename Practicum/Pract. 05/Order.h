#pragma once

struct Item {
    char name[30];
    int code;
};

class Order {
    int number;
    Item* products;
    int size;
    int capacity;

    void free();

    void copyFrom(const Order& other);

    void resize(int newCap);

    public:
      Order();

      Order(const Order& other);

      ~Order();

      Order& operator=(const Order& other);

      void addItem(const Item& item);

      void cancel();

      void print() const;
};
