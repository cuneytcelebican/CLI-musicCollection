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

// Recordings represents a ccommercial packaging of audio recordings,
// specifically Recording objects.
// A Recording container OWNS the recordings within it.
// If the container is destroyed it deletes the Recording objects it contains
// If a Recording is removed from the container the Recording object is deleted
// from heap space.

#ifndef RECORDINGS
#define RECORDINGS

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "Recording.h"

class MediaPlayer;

class Recordings {

	public:
	Recordings(); 
	~Recordings(void);
	Recording * findByID(int anID);
	void add(Recording & aRecording);
	void remove(Recording & aRecording);
	int giveMeRecordingID();
	void printOn(ostream & out) const;
	void singlePrintOn(Recording & aRecording);
	
	private:
	vector<Recording*> collection;
	vector<Recording*>::iterator findPosition(Recording & aRecording);
	MediaPlayer* mediaPlayer;

};

ostream & operator<<(ostream & out, const Recordings & recordings);
#endif