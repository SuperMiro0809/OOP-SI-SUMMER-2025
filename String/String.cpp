#include "String.h"

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

void String::freeDynamic() {
    delete[] elements;
}

void String::copyFromDynamic(const String& other) {
    size = other.size;
    capacity = other.capacity;

    elements = new char[capacity + 1];
    std::strcpy(elements, other.elements);
}

void String::resize(int newCapacity) {
    capacity = newCapacity;

    char* newElements = new char[capacity + 1];
    std::strcpy(newElements, elements);

    delete[] elements;
    elements = newElements;
}

String::String() {
    size = 0;
    capacity = 0;
    elements = new char[capacity];
    elements[0] = '\0';
}

String::String(int capacity) {
    size = 0;
    this->capacity = capacity;
    elements = new char[capacity];
    elements[0] = '\0';
}

String::String(size_t size, const char* initialValue) {
    if (!initialValue) {
        return;
    }

    this->size = std::strlen(initialValue);
    capacity = roundToPowerOfTwo(size);
    elements = new char[capacity + 1];
    std::strcpy(elements, initialValue);
}

String::String(const String& other) {
    copyFromDynamic(other);
}

String::String(size_t size, char c) {
    this->size = size;
    capacity = roundToPowerOfTwo(size);
    elements = new char[capacity + 1];

    for (int i = 0; i < size; i++) {
        elements[i] = c;
    }
    elements[size] = '\0';
}

String::~String() {
    freeDynamic();
}

String& String::operator=(const String& other) {
    if (this != &other) {
        freeDynamic();
        copyFromDynamic(other);
    }

    return *this;
}

size_t String::getSize() const {
    return size;
}

int String::getCapacity() const {
    return capacity;
}

const char* String::getElements() const {
    return elements;
}

void String::popBack() {
    if (size == 0) {
        throw std::out_of_range("The array is empty");
    }

    size--;
    elements[size] = '\0';
}

void String::pushBack(char newElement) {
    if (size + 1 >= capacity) {
        resize(capacity * 2);
    }

    elements[size++] = newElement;
    elements[size] = '\0';
}

char& String::at(int index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

const char& String::at(int index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

void String::clear() {
    size = 0;
    elements[0] = '\0';
}

bool String::empty() {
    return size == 0;
}

void String::shrinkToFit() {
    if (size == capacity) {
        return;
    }

    char* newElements = new char[size + 1];
    std::strcpy(newElements, elements);

    delete[] elements;
    elements = newElements;
    capacity = size;
}

int String::find(char c) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == c) {
            return i;
        }
    }

    return -1;
}

int String::find(const char* substr) const {
    size_t subLength = std::strlen(substr);

    if (subLength == 0 || subLength > size) {
        return -1;
    }

    for (int i = 0; i <= size - subLength; i++) {
        int j = 0;
        while (j < subLength && elements[i + j] == substr[j]) {
            j++;
        }

        if (j == subLength) {
            return i;
        }
    }

    return -1;
}

int String::find(const String& substr) const {
    return find(substr.elements);
}

char& String::operator[](int index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

const char& String::operator[](int index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return elements[index];
}

String& String::operator+=(const String& str) {
    size_t newLength = size + str.size;
    if (newLength >= capacity) {
        resize(newLength * 2);
    }

    std::strcat(elements, str.elements);
    size += str.size;

    return *this;
}

String& String::operator+=(const char* str) {
    size_t addLength = std::strlen(str);
    size_t newLength = size + addLength;
    if (newLength >= capacity) {
        resize(newLength * 2);
    }

    std::strcat(elements, str);
    size += addLength;

    return *this;
}

String& String::operator+=(char c) {
    pushBack(c);
    return *this;
}

String operator+(const String& lhs, const String& rhs) {
    String lhsCopy(lhs);

    lhsCopy += rhs;
    return lhsCopy;
}

String operator+(const String& lhs, const char* rhs) {
    String lhsCopy(lhs);

    lhsCopy += rhs;
    return lhsCopy;
}

String operator+(const char* lhs, const String& rhs) {
    String str(std::strlen(lhs), lhs);

    str += rhs;
    return str;
}

String operator+(const String& lhs, char rhs) {
    String lhsCopy(lhs);

    lhsCopy += rhs;
    return lhsCopy;
}

String operator+(char lhs, const String& rhs) {
    String str(1, lhs);

    str += rhs;
    return str;
}

bool operator==(const String& lhs, const String& rhs) {
    return std::strcmp(lhs.elements, rhs.elements) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs) {
    return std::strcmp(lhs.elements, rhs.elements) < 0;
}

bool operator>(const String& lhs, const String& rhs) {
    return std::strcmp(lhs.elements, rhs.elements) > 0;
}

bool operator<=(const String& lhs, const String& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.getElements();
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    char buffer[1024];
    is >> buffer;

    size_t inputLen = std::strlen(buffer);
    int newCap = roundToPowerOfTwo(inputLen);
    str.resize(newCap);

    std::strcpy(str.elements, buffer);
    str.size = inputLen;

    return is;
}