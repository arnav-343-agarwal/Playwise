#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "SongNode.h"
using namespace std;

// Doubly linked list to manage playlist operations
class Playlist {
private:
    SongNode* head;
    SongNode* tail;
    int size;

    SongNode* getNodeAt(int index); // Helper to get node at specific index

public:
    Playlist(); // Constructor
    ~Playlist(); // Destructor to free memory

    void addSong(Song song); // Append song at the end
    void deleteSong(int index); // Delete song at position
    void moveSong(int fromIndex, int toIndex); // Move song from one position to another
    void reversePlaylist(); // Reverse the entire playlist

    void printPlaylist(); // Print the playlist (for testing)
};

#endif // PLAYLIST_H
