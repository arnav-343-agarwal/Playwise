#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <string>
#include <unordered_map>
#include "Playlist.h"
using namespace std;

// Handles creation and management of multiple playlists
class PlaylistManager {
private:
    unordered_map<string, Playlist> playlists;  // Map from playlist name to Playlist object

public:
    // Creates a new playlist
    void createPlaylist(const string& name);

    // Retrieves a playlist by name
    Playlist* getPlaylist(const string& name);

    // Deletes a playlist
    void deletePlaylist(const string& name);

    // Lists all playlists
    void listAllPlaylists() const;
};

#endif // PLAYLISTMANAGER_H
