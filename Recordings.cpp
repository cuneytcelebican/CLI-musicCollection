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

#include "Recordings.h"
#include "Recording.h"
#include "MediaPlayer.h"
	
Recordings::Recordings(){
}
Recordings::~Recordings(void){
	for(vector<Recording*>::size_type i=0; i<collection.size(); i++)
		delete collection[i]; //delete songs in this container
}

// Return position of the recording
vector<Recording*>::iterator Recordings::findPosition(Recording & aRecording){
	for (vector<Recording*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aRecording) return it;
	return collection.end();
}

// Return recording object for giving ID
Recording * Recordings::findByID(int anID){
	for (vector<Recording*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

// Returns an empty recording ID when you entered ? as a ID
int Recordings::giveMeRecordingID(){
	int emptyRecordingID = 0;
	for (vector<Recording*>::iterator it = collection.begin() ; it != collection.end(); ++it){
		if((*it)->getID() > emptyRecordingID){
			emptyRecordingID = (*it)->getID();
		}
	}
	return emptyRecordingID+1;
}

// Add a recording to recording collection
void Recordings::add(Recording & aRecording){
	collection.push_back(&aRecording);
}

// Remove a recording from recordings
void Recordings::remove(Recording & aRecording){
	vector<Recording*>::iterator index = findPosition(aRecording);
	if(index != collection.end()) {
		Recording * theRecording = *index;
		collection.erase(index);
		delete theRecording; //free the memory of theSong
	}
}

// This function prints recording in the view through controller
void Recordings::printOn(ostream & out) const {
	mediaPlayer->view.print("RECORDINGS:");
	//cout << "RECORDINGS:" << endl;
  
  for(vector<Recording*>::size_type i=0; i<collection.size(); i++){
	  //cout << (*collection[i]).toString() << endl;
	  mediaPlayer->view.print((*collection[i]).toString());
	  mediaPlayer->allTracks.printAlbumTracks(collection[i]->getID(), *mediaPlayer); 
  }
       
}

// PRINTS SINGLE RECORDING
void Recordings::singlePrintOn(Recording & aRecording) {
	mediaPlayer->view.print("RECORDING:");
	mediaPlayer->view.print(aRecording.toString());
	mediaPlayer->allTracks.printAlbumTracks(aRecording.getID(), *mediaPlayer); 
       
}

ostream & operator<<(ostream & out, const Recordings & recordings){
  recordings.printOn(out);
  return out;
}
