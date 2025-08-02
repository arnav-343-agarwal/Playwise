#include "../include/Song.h"
using namespace std;

// Constructs a song with full metadata
Song::Song(string id, string title, string artist, int duration, long long timestamp)
    : id(id), title(title), artist(artist), duration(duration), timestamp_added(timestamp) {}

// Default constructor for an empty song
Song::Song() : id(""), title(""), artist(""), duration(0), timestamp_added(0) {}
