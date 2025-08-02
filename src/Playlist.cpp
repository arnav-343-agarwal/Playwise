#include "../include/Playlist.h"
#include <iostream>
using namespace std;

Playlist::Playlist() : head(nullptr), tail(nullptr), size(0) {}

Playlist::~Playlist() {
    SongNode* current = head;
    while (current) {
        SongNode* next = current->next;
        delete current;
        current = next;
    }
}

// Add song to end of playlist
void Playlist::addSong(Song song) {
    SongNode* newNode = new SongNode(song);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// Delete song at given index (0-based)
void Playlist::deleteSong(int index) {
    if (index < 0 || index >= size) return;

    SongNode* nodeToDelete = getNodeAt(index);
    if (!nodeToDelete) return;

    if (nodeToDelete->prev) nodeToDelete->prev->next = nodeToDelete->next;
    else head = nodeToDelete->next;

    if (nodeToDelete->next) nodeToDelete->next->prev = nodeToDelete->prev;
    else tail = nodeToDelete->prev;

    delete nodeToDelete;
    size--;
}

// Remove a song by its unique ID
void Playlist::removeSong(const string& id) {
    SongNode* node = findNodeById(id);
    if (!node) return;

    if (node->prev) node->prev->next = node->next;
    else head = node->next;

    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;

    delete node;
    size--;
}

// Find node by song ID
SongNode* Playlist::findNodeById(const string& id) {
    SongNode* current = head;
    while (current) {
        if (current->data.id == id) return current;
        current = current->next;
    }
    return nullptr;
}

// Move a song from one index to another
void Playlist::moveSong(int fromIndex, int toIndex) {
    if (fromIndex < 0 || fromIndex >= size || toIndex < 0 || toIndex >= size || fromIndex == toIndex) return;

    SongNode* node = getNodeAt(fromIndex);

    // Remove node
    if (node->prev) node->prev->next = node->next;
    else head = node->next;

    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;

    // Re-insert at toIndex
    if (toIndex == 0) {
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
    } else {
        SongNode* target = getNodeAt(toIndex);
        node->next = target;
        node->prev = target->prev;
        if (target->prev) target->prev->next = node;
        target->prev = node;
        if (toIndex == size - 1) tail = node;
    }
}

// Reverse the entire playlist
void Playlist::reversePlaylist() {
    SongNode* current = head;
    SongNode* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Swap head and tail
    if (temp) {
        tail = head;
        head = temp->prev;
    }
}

// Get node at index (0-based)
SongNode* Playlist::getNodeAt(int index) {
    if (index < 0 || index >= size) return nullptr;

    SongNode* current;
    if (index < size / 2) {
        current = head;
        for (int i = 0; i < index; i++) current = current->next;
    } else {
        current = tail;
        for (int i = size - 1; i > index; i--) current = current->prev;
    }
    return current;
}

// Print all songs in the playlist
void Playlist::printPlaylist() {
    SongNode* current = head;
    int index = 0;
    while (current) {
        cout << "[" << index++ << "] "
             << current->data.title << " by "
             << current->data.artist << " (" << current->data.duration << "s)"
             << " [ID: " << current->data.id << "]" << endl;
        current = current->next;
    }
}

// Alias to match PlaylistManager expectation
void Playlist::displaySongs() {
    printPlaylist();
}
