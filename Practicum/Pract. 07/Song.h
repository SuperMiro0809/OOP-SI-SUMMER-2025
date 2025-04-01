#include <cstdint>
#include <cstddef>

enum Genre: uint8_t {
    ROCK = 1 << 0,
    POP = 1 << 1,
    HIP_HOP = 1 << 2,
    ELECTRONIC = 1 << 3,
    JAZZ = 1 << 4
};

class Song {
    char* title;
    double duration;
    uint8_t genre;
    uint8_t* content;
    size_t contentSize;

    void free();

    void copyFrom(const Song& other);

    uint8_t convertGenre(const char* genreStr);

    public:
      Song();

      Song(const Song& other);

      Song(const char* title, double duration, const char* genre, const uint8_t* content, size_t contentSize);

      ~Song();

      Song& operator=(const Song& other);

      void createRytm(int k);

      void mixSongs(const Song& other);

      void print() const;
};
