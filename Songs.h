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

// Songs represents a collection of compositions, specifically Song objects.
// A Songs container OWNS the songs within it.
// If the container is destroyed it deletes the Song objects it contains
// If a Song is removed from the container the Song object is deleted from heap space.

#ifndef _SONGS_H
#define _SONGS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "Song.h"

class MediaPlayer;
class Songs {
	public:
	Songs(); 
	~Songs(void);
	Song * findByID(int anID);
	void add(Song & aSong);
	void remove(Song & aSong);
	//void showOn(UI & aView) const;
	void printOn(ostream & out) const;
	int giveMeSongID();
	
	private:
	vector<Song*>::iterator findPosition(Song & aSong);
	MediaPlayer* mediaPlayer;
};

ostream & operator<<(ostream & out, const Songs & songs);
#endif