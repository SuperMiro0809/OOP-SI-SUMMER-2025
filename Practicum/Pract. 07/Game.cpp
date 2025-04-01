//
// Created by Miroslav Balev on 31.03.25.
//

#include <iostream>
#include <fstream>
#include "Game.h"

Game::Game() {
  title = nullptr;
  price = -1;
  heroes = nullptr;
  heroCount = 0;
}

Game::Game(const char* title, double price, const char* const* heroes, size_t heroCount) {
  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);

  this->price = price;

  this->heroes = new char* [heroCount];
  for (int i = 0; i < heroCount; i++) {
    this->heroes[i] = new char[strlen(heroes[i]) + 1];
    strcpy(this->heroes[i], heroes[i]);
  }
  this->heroCount = heroCount;
}

Game::Game(const Game& other) {
  copyFrom(other);
}

Game::~Game() {
  free();
}

void Game::free() {
  delete[] title;

  deleteHeroes();
}

void Game::copyFrom(const Game& other) {
  title = new char[strlen(other.title) + 1];
  strcpy(title, other.title);

  price = other.price;
  heroCount = other.heroCount;

  heroes = new char*[heroCount];

  for (int i = 0; i < heroCount; i++) {
    heroes[i] = new char[strlen(other.heroes[i]) + 1];
    strcpy(heroes[i], other.heroes[i]);
  }
}

void Game::deleteHeroes() {
  for (int i = 0; i < heroCount; i++) {
    delete[] heroes[i];
  }
  delete[] heroes;
}

Game& Game::operator=(const Game& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

bool Game::isFree() const {
    return price == 0;
}

void Game::print() const {
    std::cout << "Game title: " << title << std::endl;
    std::cout << "Game price: " << price << std::endl;

    for (int i = 0; i < heroCount; i++) {
      std::cout << heroes[i] << ", ";
    }
    std::cout << std::endl;
}

void Game::saveToFile(const char* filename) const {
  if (!filename) {
    return;
  }

  std::ofstream ofs(filename, std::ios::binary);

  if (!ofs.is_open()) {
    return;
  }

  size_t titleSize = strlen(title);

  ofs.write((const char*) &titleSize, sizeof(titleSize));
  ofs.write(title, strlen(title));
  ofs.write((const char*) &price, sizeof(price));
  ofs.write((const char*) &heroCount, sizeof(heroCount));

  for (int i = 0; i < heroCount; i++) {
    size_t currentHeroSize = strlen(heroes[i]);

    ofs.write((const char*) &currentHeroSize, sizeof(currentHeroSize));
    ofs.write(heroes[i], currentHeroSize);
  }
}

void Game::readFromFile(const char* filename) {
  if (!filename) {
    return;
  }

  std::ifstream ifs(filename, std::ios::binary);

  if (!ifs.is_open()) {
    return;
  }

  size_t titleSize;
  ifs.read((char*) &titleSize, sizeof(titleSize));

  delete[] title;
  title = new char[titleSize];
  ifs.read(title, titleSize);

  ifs.read((char*) &price, sizeof(double));
  ifs.read((char*) &heroCount, sizeof(size_t));

  if (heroes) {
    deleteHeroes();
  }
  heroes = new char* [heroCount];

  for (int i = 0; i < heroCount; i++) {
    size_t currentHeroSize;
    ifs.read((char*) &currentHeroSize, sizeof(size_t));

    heroes[i] = new char[currentHeroSize];
    ifs.read(heroes[i], currentHeroSize);
  }
}