#include "../include/SongNode.h"
using namespace std;

// Initializes a node with song data and null pointers
SongNode::SongNode(Song song)
    : data(song), prev(nullptr), next(nullptr) {}
