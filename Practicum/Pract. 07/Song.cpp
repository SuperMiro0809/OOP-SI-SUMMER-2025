#include "Song.h"
#include <iostream>

void Song::free() {
  delete[] title;
  delete[] content;
}

void Song::copyFrom(const Song& other) {
  title = new char[strlen(other.title) + 1];
  strcpy(title, other.title);

  duration = other.duration;
  genre = other.genre;
  contentSize = other.contentSize;
  content = new uint8_t[contentSize];

  for (int i = 0; i < contentSize; i++) {
    content[i] = other.content[i];
  }
}

uint8_t Song::convertGenre(const char* genreStr) {
  if (!genreStr) {
    return 0;
  }

  uint8_t mask = 0;

  for (int i = 0; i < strlen(genreStr); i++) {
    char ch = genreStr[i];

    switch (ch) {
      case 'r':
        mask |= ROCK;
        break;
      case 'p':
        mask |= POP;
        break;
      case 'h':
        mask |= HIP_HOP;
        break;
      case 'e':
        mask |= ELECTRONIC;
        break;
      case 'j':
        mask |= JAZZ;
        break;
      default:
        break;
    }
  }

  return mask;
}

Song::Song() {
  title = nullptr;
  duration = 0;
  genre = 0;
  content = nullptr;
  contentSize = 0;
}

Song::Song(const Song& other) {
  copyFrom(other);
}

Song::Song(const char* title, double duration, const char* genre, const uint8_t* content, size_t contentSize) {
  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);

  this->duration = duration;
  this->genre = convertGenre(genre);

  this->contentSize = contentSize;
  this->content = new uint8_t[contentSize];

  for (int i = 0; i < contentSize; i++) {
    this->content[i] = content[i];
  }
}

Song::~Song() {
  free();
}

Song& Song::operator=(const Song& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

void Song::createRytm(int k) {
  for (int i = contentSize - k; i >= 0; i-=k) {
    content[i] = '0' + 1;
  }
}

void Song::mixSongs(const Song& other) {
  size_t minSize = other.contentSize > contentSize ? contentSize : other.contentSize;

  for (int i = 0; i < minSize; i++) {
    content[i] = '0' + (content[i] ^ other.content[i]);
  }
}

void Song::print() const {
  std::cout << "Song name: " << title << std::endl;
  std::cout << "Song duration: " << duration << std::endl;

  for (int i = 0; i < contentSize; i++) {
    if (i % 4 == 0) {
      std::cout << " ";
    }

    std::cout << content[i];
  }
}

