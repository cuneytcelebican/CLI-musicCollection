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

// Recording represents a commercial recording e.g. CD, Album, Single
// This class creates recoring object.

#ifndef _RECORDING_H
#define _RECORDING_H

#include <ostream>
#include <string>

class Recording {
	public:
    Recording();
    void setId(int anId) { id = anId; }
	void setTitle(string aTitle){ title = aTitle;}
	void setArtist(string anArtist) { artist = anArtist;}
    void setYear(int aYear) {year = aYear;}
    void setProducer(string aProducer) {producer = aProducer;}
    
	~Recording(void);
    int getID();
    string toString() const;
	
    private:
    int id;
	string title;
    string artist;
    int year;
    string producer;
};

ostream & operator<<(ostream & out, const Recording & aRecording);

#endif