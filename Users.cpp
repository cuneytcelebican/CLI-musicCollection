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
#include "Users.h"
#include "User.h"
#include "MediaPlayer.h"

vector<User*> userCollection;

Users::Users(){
}
Users::~Users(void){
	for(vector<User*>::size_type i=0; i<userCollection.size(); i++)
		delete userCollection[i];
}

vector<User*>::iterator Users::findPosition(User & anUser){
	for (vector<User*>::iterator it = userCollection.begin() ; it != userCollection.end(); ++it)
		if(*it == &anUser) return it;
	return userCollection.end();
}

// RETURNS AN USER OBJECT FOR GIVEN ID
User * Users::findByID(string anID){
	for (vector<User*>::iterator it = userCollection.begin() ; it != userCollection.end(); ++it){
		if(!(*it)->getUserID().compare(anID))
			return *it;
	}		
	return NULL;
}

// ADDS A USER
void Users::add(User & anUser){
	userCollection.push_back(&anUser);
}

// REMOVES A USER
void Users::remove(User & anUser){
	vector<User*>::iterator index = findPosition(anUser);
	if(index != userCollection.end()) {
		myUser = *index;
		userCollection.erase(index);
		delete myUser; //free the memory of theUser
	}
}

// PRINTS ALL USERS WITH THEIR PLAYLISTS AND ITS TRACKS
void Users::printOn(ostream & out) const {
  mediaPlayer->view.print("USERS:");
  for(vector<User*>::size_type i=0; i<userCollection.size(); i++){
	mediaPlayer->view.print((*userCollection[i]).toString());
	userCollection[i]->printOn(cout);
  }  
}

// PRINTS A SINGLE USER WITH PLAYLISTS AND TRACKS
void Users::printOnSingleUser(string anUserID) {
	mediaPlayer->view.print("USER:");
	for(vector<User*>::size_type i=0; i<userCollection.size(); i++){
		if(!(*userCollection[i]).getUserID().compare(anUserID)){
			mediaPlayer->view.print((*userCollection[i]).toString());
			userCollection[i]->printOn(cout);
		}
	}  
  }

ostream & operator<<(ostream & out, const Users & users){
  users.printOn(out);
  return out;
}

// DELETE TRACK FROM USER PLAYLIST
void Users::deleteUserPlaylistTracks(int aTrackID){
	for(vector<User*>::size_type i=0; i<userCollection.size(); i++){
		userPlaylistsContainer = userCollection[i]->getUserPlaylist();
		for(vector<Playlist*>::iterator it = userPlaylistsContainer.begin() ; it != userPlaylistsContainer.end(); ++it){
			if((*it)->checkPlaylistTrack(aTrackID) == 1){
				(*it)->removePlaylistTrack(aTrackID);
			}
		}
	}
}
