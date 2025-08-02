#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "SongNode.h"
#include <string>
using namespace std;

// Doubly linked list to manage playlist operations
class Playlist {
private:
    SongNode* head;
    SongNode* tail;
    int size;

    SongNode* getNodeAt(int index);              // Helper to get node at specific index
    SongNode* findNodeById(const string& id);    // Helper to find a node by Song ID

public:
    Playlist();      // Constructor
    ~Playlist();     // Destructor to free memory

    void addSong(Song song);                     // Append song at the end
    void deleteSong(int index);                  // Delete song at position
    void removeSong(const string& id);           // Remove song by ID
    void moveSong(int fromIndex, int toIndex);   // Move song from one position to another
    void reversePlaylist();                      // Reverse the entire playlist

    void printPlaylist();                        // Print the playlist
    void displaySongs();                         // Alias for printPlaylist
};

#endif // PLAYLIST_H
