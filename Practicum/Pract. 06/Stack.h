class Stack {
    int* elements;
    int size;
    int capacity;

    void free();

    void copyFrom(const Stack& other);

    void resize(int newCap);

    public:
      Stack();

      Stack(const Stack& other);

      ~Stack();

      Stack& operator=(const Stack& other);

      void push(int a);

      void pop();

      int peek() const;

      void print() const;
};
