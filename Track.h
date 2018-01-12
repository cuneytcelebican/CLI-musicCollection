/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program     : MyTunes Music Player               */
/*  Author1     : Cuneyt Celebican                   */
/*  Student ID  : 101050732                          */
/*                                                   */
/*  Author2     : Adam Lopez                         */
/*  Student ID  : 100940559                          */
/*                                                   */
/*  Date        : 31-October-2017                    */
/*                                                   */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

// Track represents audio recording(mp3) of a composition
// This class creates a track object and points to Song

#ifndef _TRACK_H
#define _TRACK_H

#include <sstream>
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include "Songs.h"
#include "Song.h"

class MediaPlayer;

class Track {
	public:
    Track();
    void setTrackId(int aTrackId) { trackId = aTrackId; }
    void setAlbumId(int anAlbumId) { albumId = anAlbumId; }
    void setSongId(int aSongId) { songId = aSongId; }
    void setTrackNumber(int aTrackNumber) { trackNumber = aTrackNumber; }
	
	~Track(void);
    int getID() { return trackId; }
    int getAlbumID() { return albumId; }
    int getSongID() { return songId; }
    string toString();
	
	private:
    int trackId;
    int albumId;
    int songId;
    int trackNumber;
    MediaPlayer* mediaPlayer;
    Song *song;
};

ostream & operator<<(ostream & out,  Track & aTrack);

#endif