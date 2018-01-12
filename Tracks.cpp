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
#include "Tracks.h"
#include "Track.h"
#include "MediaPlayer.h"

vector<Track*> trackCollection;

Tracks::Tracks(){
}
Tracks::~Tracks(void){
	for(vector<Track*>::size_type i=0; i<trackCollection.size(); i++)
		delete trackCollection[i];
}
vector<Track*>::iterator Tracks::findPosition(Track & aTrack){
	for (vector<Track*>::iterator it = trackCollection.begin() ; it != trackCollection.end(); ++it)
		if(*it == &aTrack) return it;
	return trackCollection.end();
}

// returns track object for giving object
Track * Tracks::findByID(int anID){
	for (vector<Track*>::iterator it = trackCollection.begin() ; it != trackCollection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

// returns track object for giving song id
Track * Tracks::findBySongID(int aSongID){
	for (vector<Track*>::iterator it = trackCollection.begin() ; it != trackCollection.end(); ++it)
		if((*it)->getSongID() == aSongID) return *it;
	return NULL;	
}

// adds track object to collection
void Tracks::add(Track & aTrack){
	trackCollection.push_back(&aTrack);
}

// removes track object from collection
void Tracks::remove(Track & aTrack){
	vector<Track*>::iterator index = findPosition(aTrack);
	if(index != trackCollection.end()) {
		Track * theTrack = *index;
		trackCollection.erase(index);
		delete theTrack; //free the memory of theTrack
	}
}

// RETURNS AN EMPTY TRACKID
int Tracks::giveMeTrackID(){
	int emptyTrakcID = 0;
	for (vector<Track*>::iterator it = trackCollection.begin() ; it != trackCollection.end(); ++it){
		if((*it)->getID() > emptyTrakcID){
			emptyTrakcID = (*it)->getID();
		}
	}
	return emptyTrakcID+1;
}

// prints tracks
void Tracks::printOn(ostream & out) const {
  //cout << "TRACKS:" << endl;
  mediaPlayer->view.print("TRACKS:");
  for(vector<Track*>::size_type i=0; i<trackCollection.size(); i++)
  	mediaPlayer->view.print((*trackCollection[i]).toString());
       //cout << (*trackCollection[i]).toString() << endl;	  
}

ostream & operator<<(ostream & out, const Tracks & tracks){
  tracks.printOn(out);
  return out;
}

// PRINT TRACKS FOR GIVEN ALBUM ID
void Tracks::printAlbumTracks(int anAlbumID, MediaPlayer & mp) {
	mp.view.print("	TRACKS:");
	int trackSquenceNumber = 0;
	for(vector<Track*>::size_type i=0; i<trackCollection.size(); i++){
		if(trackCollection[i]->getAlbumID() == anAlbumID){
			string myPrintWord = "	" + to_string(trackSquenceNumber) + " " + (*trackCollection[i]).toString();
			mp.view.print(myPrintWord);
			trackSquenceNumber++;
		}
			
	}
		  
}
