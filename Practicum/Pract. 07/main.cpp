#include <iostream>
#include "Game.h"
#include "Song.h"

int main() {
  // char** heroes = new char*[2];
  // heroes[0] = new char[7];
  // heroes[1] = new char[7];
  // strcpy(heroes[0], "Hero 1");
  // strcpy(heroes[1], "Hero 2");
  //
  // Game game;
  // game.readFromFile("gameSave.dat");
  // game.print();

  size_t size1 = 8;
  size_t size2 = 16;
  uint8_t* content1 = new uint8_t[size1];
  uint8_t* content2 = new uint8_t[size2];

  for (int i = 0; i < size1; i++) {
    std::cin >> content1[i];
  }

  for (int i = 0; i < size2; i++) {
    std::cin >> content2[i];
  }

  Song song("Test 1", 200, "h", content1, size1);
  Song song1("Test 2", 300, "h", content2, size2);

  song.mixSongs(song1);
  song.print();
}