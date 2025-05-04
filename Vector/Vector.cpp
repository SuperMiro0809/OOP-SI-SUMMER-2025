#include "Vector.h"

static unsigned roundToPowerOfTwo(unsigned v) {
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

void Vector::freeDynamic() {
    delete[] elements;
}

void Vector::copyFromDynamic(const Vector& other) {
    size = other.size;
    capacity = other.capacity;

    elements = new int[capacity];

    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

void Vector::resize(int newCapacity) {
    capacity = newCapacity;

    int* newElements = new int[capacity];

    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }

    delete[] elements;
    elements = newElements;
}

Vector::Vector() {
    size = 0;
    capacity = 8;
    elements = new int[capacity];
}

Vector::Vector(int capacity) {
    size = 0;
    this->capacity = capacity;
    elements = new int[capacity];
}

Vector::Vector(size_t size, int* initialValue) {
    if (!initialValue) {
      return;
    }

    this->size = size;
    capacity = roundToPowerOfTwo(size);
    elements = new int[capacity];

    for (int i = 0; i < size; i++) {
        elements[i] = initialValue[i];
    }
}

Vector::Vector(const Vector& other) {
    copyFromDynamic(other);
}

Vector::~Vector() {
    freeDynamic();
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        freeDynamic();
        copyFromDynamic(other);
    }

    return *this;
}

void Vector::pushBack(int newElement) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    elements[size++] = newElement;
}

void Vector::popBack() {
    if (size == 0) {
        throw std::out_of_range("The array is empty");
    }

    size--;
}

bool Vector::isEmpty() const {
    return size == 0;
}

size_t Vector::getSize() const {
    return size;
}

int Vector::getCapacity() const {
    return capacity;
}

const int* Vector::getElements() const {
    return elements;
}

void Vector::clear() {
    size = 0;
}

void Vector::insertAt(int position, int value) {
    if (position > size) {
        throw std::out_of_range("Insert position out of range");
    }

    if (size == capacity) {
        resize(capacity * 2);
    }

    for (int i = size; i > position; i--) {
        elements[i] = elements[i - 1];
    }

    elements[position] = value;
    size++;
}

void Vector::removeAt(int position) {
    if (position >= size) {
        throw std::out_of_range("Remove position out of range");
    }

    for (int i = position; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }

    size--;
}

int& Vector::at(int index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

const int& Vector::at(int index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

void Vector::sort(bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((ascending && elements[j] > elements[j + 1]) || (!ascending && elements[j] < elements[j + 1])) {
                std::swap(elements[j], elements[j + 1]);
            }
        }
    }
}

void Vector::shrinkToFit() {
    if (size == capacity) {
        return;
    }

    int* newElements = new int[size];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }

    delete[] elements;
    elements = newElements;
    capacity = size;
}

void Vector::operator+=(int scalar) {
    for (int i = 0; i < size; i++) {
        elements[i] += scalar;
    }
}

void Vector::operator+=(const Vector& other) {
     if (size != other.size) {
         throw std::out_of_range("Sizes not match");
     }

     const int* otherElements = other.getElements();

     for (int i = 0; i < size; i++) {
         elements[i] += otherElements[i];
     }
}

void Vector::operator-=(int scalar) {
    for (int i = 0; i < size; i++) {
        elements[i] -= scalar;
    }
}

void Vector::operator-=(const Vector& other) {
    if (size != other.size) {
        throw std::out_of_range("Sizes not match");
    }

    const int* otherElements = other.getElements();

    for (int i = 0; i < size; i++) {
        elements[i] -= otherElements[i];
    }
}

void Vector::operator*=(int scalar) {
    for (int i = 0; i < size; i++) {
        elements[i] *= scalar;
    }
}

void Vector::operator*=(const Vector& other) {
    if (size != other.size) {
        throw std::out_of_range("Sizes not match");
    }

    const int* otherElements = other.getElements();

    for (int i = 0; i < size; i++) {
        elements[i] *= otherElements[i];
    }
}

void Vector::operator/=(int scalar) {
    for (int i = 0; i < size; i++) {
        elements[i] /= scalar;
    }
}

void Vector::operator/=(const Vector& other) {
    if (size != other.size) {
        throw std::out_of_range("Sizes not match");
    }

    const int* otherElements = other.getElements();

    for (int i = 0; i < size; i++) {
        elements[i] /= otherElements[i];
    }
}

Vector& Vector::operator++() {
    for (int i = 0; i < size; i++) {
        elements[i]++;
    }

    return *this;
}

Vector Vector::operator++(int) {
    Vector oldVector(*this);

    ++(*this);

    return oldVector;
}

Vector& Vector::operator--() {
    for (int i = 0; i < size; i++) {
        elements[i]--;
    }

    return *this;
}

Vector Vector::operator--(int) {
    Vector oldVector(*this);

    --(*this);

    return oldVector;
}

int& Vector::operator[](int index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

const int& Vector::operator[](int index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

Vector operator+(const Vector& vector, int scalar) {
    Vector vectorCopy(vector);

    vectorCopy += scalar;

    return vectorCopy;
}

Vector operator+(int scalar, const Vector& vector) {
    return vector + scalar;
}

Vector operator-(const Vector& vector, int scalar) {
    Vector vectorCopy(vector);

    vectorCopy -= scalar;

    return vectorCopy;
}

Vector operator-(int scalar, const Vector& vector) {
    return vector - scalar;
}

Vector operator*(const Vector& vector, int scalar) {
    Vector vectorCopy(vector);

    vectorCopy *= scalar;

    return vectorCopy;
}

Vector operator*(int scalar, const Vector& vector) {
    return vector * scalar;
}

Vector operator/(const Vector& vector, int scalar) {
    Vector vectorCopy(vector);

    vectorCopy /= scalar;

    return vectorCopy;
}

Vector operator/(int scalar, const Vector& vector) {
    return vector / scalar;
}

Vector operator+(const Vector& lhs, const Vector& rhs) {
    Vector lhsCopy(lhs);

    lhsCopy += rhs;

    return lhsCopy;
}

Vector operator-(const Vector& lhs, const Vector& rhs) {
    Vector lhsCopy(lhs);

    lhsCopy -= rhs;

    return lhsCopy;
}

Vector operator*(const Vector& lhs, const Vector& rhs) {
    Vector lhsCopy(lhs);

    lhsCopy *= rhs;

    return lhsCopy;
}

Vector operator/(const Vector& lhs, const Vector& rhs) {
    Vector lhsCopy(lhs);

    lhsCopy /= rhs;

    return lhsCopy;
}

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    const int* elements = vector.getElements();
    int size = vector.getSize();

    for (int i = 0; i < size; i++) {
        os << elements[i] << " ";
    }

    return os;
}

std::istream& operator>>(std::istream& is, const Vector& vector) {
    int size = vector.getSize();

    for (int i = 0; i < size; i++) {
        is >> vector.elements[i];
    }

    return is;
}