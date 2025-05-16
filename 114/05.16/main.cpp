#include "iostream"
#include "Linked_List.h"
#include "Album.h"

using namespace std;

bool compareTracksByCount(Track a, Track b) {
    return a.count > b.count;
}

enum CmdType {
    PLAY,
    NEXT,
    PUSH_FRONT_ALBUM, 
    PUSH_BACK_ALBUM,
    INSERT_ALBUM,
    PUSH_FRONT_TRACK,
    PUSH_BACK_TRACK,
    INSERT_TRACK,
    POP_ALBUM, 
    REMOVE_LAST_ALBUM,
    REMOVE_ALBUM_AT,
    POP_TRACK,
    REMOVE_LAST_TRACK,
    REMOVE_AT_TRACK,
    REVERSE_ALBUMS,
    REVERSE_TRACKS, 
    PRINT_ALBUMS, 
    PRINT_TRACKS, 
    END, 
    UNKNOWN
};

CmdType parseCmd(string cmd) {
    if (cmd == "Play") return PLAY;
    if (cmd == "Next") return NEXT;
    if (cmd == "PushFrontAlbum") return PUSH_FRONT_ALBUM;
    if (cmd == "PushBackAlbum") return PUSH_BACK_ALBUM;
    if (cmd == "InsertAlbum") return INSERT_ALBUM;
    if (cmd == "PushFrontTrack") return PUSH_FRONT_TRACK;
    if (cmd == "PushBackTrack") return PUSH_BACK_TRACK;
    if (cmd == "InsertTrack") return INSERT_TRACK;
    if (cmd == "PopAlbum") return POP_ALBUM;
    if (cmd == "RemoveLastAlbum") return REMOVE_LAST_ALBUM;
    if (cmd == "RemoveAlbumAt") return REMOVE_ALBUM_AT;
    if (cmd == "PopTrack") return POP_TRACK;
    if (cmd == "RemoveLastTrack") return REMOVE_LAST_TRACK;
    if (cmd == "RemoveAtTrack") return REMOVE_AT_TRACK;
    if (cmd == "ReverseAlbums") return REVERSE_ALBUMS;
    if (cmd == "ReverseTracks") return REVERSE_TRACKS;
    if (cmd == "PrintAlbums") return PRINT_ALBUMS;
    if (cmd == "PrintTracks") return PRINT_TRACKS;
    if (cmd == "END") return END;
    return UNKNOWN;
};

int main() {
    LinkedList<Album> playlist;

    string cmd;
    while (1) {
        cin >> cmd;
        switch (parseCmd(cmd)) {
            case PLAY: {
                playlist.play();
                break;
            }

            case NEXT: {
                playlist.next();
                break;
            }

            case PUSH_FRONT_ALBUM: {
                string albumName;
                cin >> albumName;
                playlist.pushfront({albumName});
                break;
            }

            case PUSH_BACK_ALBUM: {
                string albumName;
                cin >> albumName;
                playlist.pushback({albumName});
                break;
            }

            case INSERT_ALBUM: {
                int pos;
                string albumName;
                cin >> albumName >> pos;
                playlist.insert({albumName}, pos);
                break;
            }

            case PUSH_FRONT_TRACK: {
                string trackName, albumName;
                int count;
                cin >> trackName >> count >> albumName;
                playlist.find(albumName, "TrackPF", 0, trackName, count);
                break;
            }

            case PUSH_BACK_TRACK: {
                string trackName, albumName;
                int count;
                cin >> trackName >> count >> albumName;
                playlist.find(albumName, "TrackPB", 0, trackName, count);
                break;
            }

            case INSERT_TRACK: {
                string trackName, albumName;
                int count, pos;
                cin >> trackName >> count >> albumName >> pos;
                playlist.find(albumName, "TrackIns", pos, trackName, count);
                break;
            }
            
            case POP_ALBUM: {
                playlist.pop();
                break;
            }

            case REMOVE_LAST_ALBUM: {
                playlist.removelast();
                break;
            }

            case REMOVE_ALBUM_AT: {
                int pos;
                cin >> pos;
                playlist.removeat(pos);
                break;
            }

            case POP_TRACK: {
                string albumName;
                cin >> albumName;
                playlist.find(albumName, "pt", 0, "", 0);
                break;
            }

            case REMOVE_LAST_TRACK: {
                string albumName;
                cin >> albumName;
                playlist.find(albumName, "rlt", 0, "", 0);
                break;
            }

            case REMOVE_AT_TRACK: {
                string albumName;
                int pos;
                cin >> albumName >> pos;
                playlist.find(albumName, "rat", pos, "", 0);
                break;
            }

            case REVERSE_ALBUMS: {
                playlist.reverse();
                break;
            }

            case REVERSE_TRACKS: {
                string albumName;
                cin >> albumName;
                playlist.find(albumName, "rev", 0, "", 0);
                break;
            }

            case PRINT_ALBUMS: {
                playlist.printList();
                break;
            }
            
            case PRINT_TRACKS: {
                string albumName;
                cin >> albumName;
                playlist.find(albumName, "print", 0, "", 0);
                break; 
            }

            case END: {
                cout << "\n";
                LinkedList<Track> all;
                while (!playlist.isEmpty()) {
                    all.pushback({playlist.getTrack(), playlist.getCnt()});
                    playlist.next();
                    playlist.reverse();
                }
                all.mergeSort(compareTracksByCount);
                all.printAll();
                playlist.~LinkedList();
                all.~LinkedList();

                return 0;
            }

            case UNKNOWN:;
        }
    }


    return 0;
}