#pragma once

#include <iostream>

static unsigned roundToPowerOfTwo(unsigned v);

class Vector {
    int* elements;
    int capacity;
    size_t size;

    void freeDynamic();

    void copyFromDynamic(const Vector& other);

    void resize(int newCapacity);

    public:
      Vector();

      Vector(int capacity);

      Vector(size_t size, int* initialValue);

      Vector(const Vector& other);

      ~Vector();

      Vector& operator=(const Vector& other);

      void pushBack(int newElement);

      void popBack();

      bool isEmpty() const;

      int getSize() const;

      int getCapacity() const;

      const int* getElements() const;

      void clear();

      void insertAt(int position, int value);

      void removeAt(int position);

      int& at(int index);

      const int& at(int index) const;

      void sort(bool ascending = true);

      void shrinkToFit();

      void operator+=(int scalar);

      void operator+=(const Vector& other);

      void operator-=(int scalar);

      void operator-=(const Vector& other);

      void operator*=(int scalar);

      void operator*=(const Vector& other);

      void operator/=(int scalar);

      void operator/=(const Vector& other);

      Vector& operator++();

      Vector operator++(int);

      Vector& operator--();

      Vector operator--(int);

      friend std::istream& operator>>(std::istream& is, const Vector& vector);

      int& operator[](int index);

      const int& operator[](int index) const;
};

Vector operator+(const Vector& vector, int scalar);

Vector operator+(int scalar, const Vector& vector);

Vector operator-(const Vector& vector, int scalar);

Vector operator-(int scalar, const Vector& vector);

Vector operator*(const Vector& vector, int scalar);

Vector operator*(int scalar, const Vector& vector);

Vector operator/(const Vector& vector, int scalar);

Vector operator/(int scalar, const Vector& vector);

Vector operator+(const Vector& lhs, const Vector& rhs);

Vector operator-(const Vector& lhs, const Vector& rhs);

Vector operator*(const Vector& lhs, const Vector& rhs);

Vector operator/(const Vector& lhs, const Vector& rhs);

std::ostream& operator<<(std::ostream& os, const Vector& vector);
std::istream& operator>>(std::istream& is, const Vector& vector);
