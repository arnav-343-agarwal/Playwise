#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

// Represents metadata of a single song
class Song {
public:
    string id;                 // Unique song identifier
    string title;              // Title of the song
    string artist;             // Name of the artist
    int duration;              // Duration in seconds
    long long timestamp_added; // Timestamp when song was added

    Song(string id, string title, string artist, int duration, long long timestamp); // Parameterized constructor
    Song(); // Default constructor
};

#endif // SONG_H
