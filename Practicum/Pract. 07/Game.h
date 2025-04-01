#pragma once

class Game {
    char* title;
    double price;
    char** heroes;
    size_t heroCount;

    void free();

    void copyFrom(const Game& other);

    void deleteHeroes();

public:
    Game();

    Game(const char* title, double price, const char* const* heroes, size_t heroCount);

    Game(const Game& other);

    ~Game();

    Game& operator=(const Game& other);

    bool isFree() const;

    void print() const;

    void saveToFile(const char* filename) const;

    void readFromFile(const char* filename);
};
