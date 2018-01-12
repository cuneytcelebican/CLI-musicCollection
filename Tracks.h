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

// Tracks represents a collection of Track objects.
// A Tracks container OWNS the tracks within it.
// If the container is destroyed it deletes the Track objects it contains
// If a Track is removed from the container the Track object is deleted from heap space.


#ifndef _TRACKS_H
#define _TRACKS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "Track.h"

class MediaPlayer;

class Tracks {
	public:
	Tracks(); 
	~Tracks(void);
	Track * findByID(int anID);
	Track * findBySongID(int aSongID);
	void add(Track & aTrack);
	void remove(Track & aTrack);
	void printOn(ostream & out) const;
	void printAlbumTracks(int anAlbumID, MediaPlayer & mp);
	int giveMeTrackID();
	
	private:
	vector<Track*>::iterator findPosition(Track & aTrack);
	MediaPlayer* mediaPlayer;
};

ostream & operator<<(ostream & out, const Tracks & tracks);
#endif