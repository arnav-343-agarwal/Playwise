#ifndef SONGNODE_H
#define SONGNODE_H

#include "Song.h"

// Node of a doubly linked list to hold a song in a playlist
class SongNode {
public:
    Song data;           // Song stored in this node
    SongNode* prev;      // Pointer to the previous node
    SongNode* next;      // Pointer to the next node

    SongNode(Song song); // Constructor
};

#endif // SONGNODE_H
