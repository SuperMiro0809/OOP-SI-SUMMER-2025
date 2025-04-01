#include "Task.h"
#include <iostream>
#include <fstream>

void Task::free() {
  delete[] description;
}

void Task::copyFrom(const Task& other) {
  description = new char[strlen(other.description) + 1];
  strcpy(description, other.description);

  priority = other.priority;
  duration = other.duration;
  isCompleted = other.isCompleted;
}

Task::Task() {
  description = nullptr;
  priority = -1;
  duration = -1;
  isCompleted = false;
}

Task::Task(const char* description, unsigned int priority, unsigned int duration) {
  this->description = new char[strlen(description) + 1];
  strcpy(this->description, description);

  this->priority = priority;
  this->duration = duration;
  this->isCompleted = false;
}

Task::Task(const Task& other) {
  copyFrom(other);
}

Task::~Task() {
  free();
}

Task& Task::operator=(const Task& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

void Task::completeTask() {
  isCompleted = true;
}

void Task::saveToFile(const char* filename) const {
  if (!filename) {
    return;
  }

  std::ofstream ofs(filename);

  if (!ofs.is_open()) {
    return;
  }

  ofs << strlen(description) << '\n';
  ofs << description << '\n';
  ofs << priority << '\n';
  ofs << isCompleted << '\n';
  ofs << duration;

  ofs.close();
}

void Task::readFromFile(const char* filename) {
  if (!filename) {
    return;
  }

  std::ifstream ifs(filename);

  if (!ifs.is_open()) {
    return;
  }

  size_t descriptionSize;
  ifs >> descriptionSize;

  ifs.ignore();

  delete[] description;
  description = new char[descriptionSize + 1];
  ifs.getline(description, descriptionSize + 1);

  ifs >> priority;
  ifs >> isCompleted;
  ifs >> duration;
}

void Task::compareTasks(const Task& other) const {
  if (priority > other.priority) {
    std::cout << "Current task is higher priority" << std::endl;
  } else if (priority < other.priority) {
    std::cout << "Second task is higher priority" << std::endl;
  } else {
    if (duration > other.duration) {
      std::cout << "Second task is higher priority" << std::endl;
    } else {
      std::cout << "Current task is higher priority" << std::endl;
    }
  }
}

void Task::print() const {
  std::cout << "Description: " << description << std::endl;
  std::cout << "Priority: " << priority << std::endl;
  std::cout << "Duration: " << duration << std::endl;
  std::cout << "Is completed: " << isCompleted << std::endl;
  std::cout << std::endl;
}
