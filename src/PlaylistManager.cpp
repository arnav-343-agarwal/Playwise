#include "../include/PlaylistManager.h"
#include <iostream>
using namespace std;

void PlaylistManager::createPlaylist(const string& name) {
    if (playlists.find(name) != playlists.end()) {
        cout << "Playlist '" << name << "' already exists." << endl;
        return;
    }
    playlists[name] = Playlist();
    cout << "Created playlist: " << name << endl;
}

Playlist* PlaylistManager::getPlaylist(const string& name) {
    if (playlists.find(name) != playlists.end()) {
        return &playlists[name];
    }
    cout << "Playlist '" << name << "' not found." << endl;
    return nullptr;
}

void PlaylistManager::deletePlaylist(const string& name) {
    if (playlists.erase(name)) {
        cout << "Deleted playlist: " << name << endl;
    } else {
        cout << "Playlist '" << name << "' not found." << endl;
    }
}

void PlaylistManager::listAllPlaylists() const {
    if (playlists.empty()) {
        cout << "No playlists available." << endl;
        return;
    }

    cout << "Available playlists:" << endl;
    for (const auto& pair : playlists) {
        cout << "- " << pair.first << endl;
    }
}
