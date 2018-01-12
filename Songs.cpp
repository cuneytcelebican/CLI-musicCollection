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
using namespace std;

#include "Songs.h"
#include "Song.h"
#include "MediaPlayer.h"

vector<Song*> songsCollection;

	
Songs::Songs(){
}
Songs::~Songs(void){
	for(vector<Song*>::size_type i=0; i<songsCollection.size(); i++)
		delete songsCollection[i]; //delete songs in this container
}

// Returns the position of the song
vector<Song*>::iterator Songs::findPosition(Song & aSong){
	for (vector<Song*>::iterator it = songsCollection.begin() ; it != songsCollection.end(); ++it)
		if(*it == &aSong) return it;
	return songsCollection.end();
}

// returns the song by given ID
Song * Songs::findByID(int anID){
	for (vector<Song*>::iterator it = songsCollection.begin() ; it != songsCollection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

// adds song to collection
void Songs::add(Song & aSong){
	songsCollection.push_back(&aSong);
}

// removes song from collection
void Songs::remove(Song & aSong){
	vector<Song*>::iterator index = findPosition(aSong);
	if(index != songsCollection.end()) {
		Song * theSong = *index;
		songsCollection.erase(index);
		delete theSong; //free the memory of theSong
	}
}

// RETURNS EMPTY SONG ID
int Songs::giveMeSongID(){
	int emptySongID = 0;
	for (vector<Song*>::iterator it = songsCollection.begin() ; it != songsCollection.end(); ++it){
		if((*it)->getID() > emptySongID){
			emptySongID = (*it)->getID();
		}
	}
	return emptySongID+1;
}

void Songs::printOn(ostream & out) const {
  mediaPlayer->view.print("SONGS:");
  for(vector<Song*>::size_type i=0; i<songsCollection.size(); i++)
  mediaPlayer->view.print((*songsCollection[i]).toString()); 
}

ostream & operator<<(ostream & out, const Songs & songs){
  songs.printOn(out);
  return out;
}
