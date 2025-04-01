#include "Message.h"
#include <iostream>

void Message::free() {
  delete[] sender;
  delete[] receiver;
  delete[] content;
}

void Message::copyFrom(const Message& other) {
  sender = new char[strlen(other.sender) + 1];
  strcpy(sender, other.sender);

  receiver = new char[strlen(other.receiver) + 1];
  strcpy(receiver, other.receiver);

  content = new char[strlen(other.content) + 1];
  strcpy(content, other.content);

  fontSize = other.fontSize;
}

Message::Message() {
  sender = nullptr;
  receiver = nullptr;
  content = nullptr;
  fontSize = 0;
}

Message::Message(const Message& other) {
  copyFrom(other);
}

Message::~Message() {
  free();
}

Message& Message::operator=(const Message& other) {
  if (this != &other) {
      free();
      copyFrom(other);
  }

  return *this;
}