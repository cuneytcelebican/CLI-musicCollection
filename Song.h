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

// Song represents a musical composition (not an audio recording)
// This class creates a song object

#ifndef _SONG_H
#define _SONG_H

#include <ostream>
#include <string>

class Song {
	public:
	Song();
	void setTitle(string aTitle){ title = aTitle;}
	void setComposer(string aComposer) { composer = aComposer;}
	void setId(int anId) { id = anId;}
	string getTitle() const {return title;}
	string isMP3() const { return "Unknown"; }
	//Song(const string & aTitle, const string & aComposer, const int anId = -1);
	~Song(void);
    int getID();
    string toString() const;
	
	private:
	string title;
	string composer;
	int id;
};

ostream & operator<<(ostream & out, const Song & aSong);

#endif