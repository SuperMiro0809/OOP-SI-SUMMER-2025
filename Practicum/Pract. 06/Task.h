class Task {
    char* description;
    unsigned int priority;
    bool isCompleted;
    unsigned int duration;

    void free();

    void copyFrom(const Task& other);

    public:
      Task();

      Task(const char* description, unsigned int priority, unsigned int duration);

      Task(const Task& other);

      ~Task();

      Task& operator=(const Task& other);

      void completeTask();

      void saveToFile(const char* filename) const;

      void readFromFile(const char* filename);

      void compareTasks(const Task& other) const;

      void print() const;
};
