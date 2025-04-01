class Message {
    char* sender;
    char* receiver;
    char* content;
    int fontSize;

    void free();

    void copyFrom(const Message& other);

    public:
      Message();

      Message(const char* title, const char* receiver, const char* content, int fontSize);

      Message(const Message& other);

      ~Message();

      Message& operator=(const Message& other);
};

