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

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using namespace std;

#include "Track.h"
#include "MediaPlayer.h"

Track::Track(){
    trackId = -1;
    albumId = -1;
    songId = -1;
    trackNumber = -1;
}
Track::~Track(){
	cout << "~Track(void) "  << this << endl;
}

string Track::toString() {
    song = mediaPlayer->allSongs.findByID(songId);
    return to_string(trackId) + ": " + song->getTitle() + " mp3: " + song->isMP3();
}

ostream & operator<<(ostream & out, Track & aTrack){
	out << aTrack.toString() << endl;
	return out;
}
