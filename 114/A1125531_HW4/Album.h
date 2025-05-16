#ifndef ALBUM_H
#define ALBUM_H

#include "string"
#include "Linked_List.h"

using namespace std;

struct Track {
    string name;
    int count;
};

struct Album {
    string name;
    LinkedList<Track> tracks;
};

#endif