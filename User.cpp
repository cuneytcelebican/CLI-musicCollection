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

#include "User.h"
#include "MediaPlayer.h"

vector<Playlist*> userPlaylistCollection;

// Constructor
User::User(){
}

// Destructure
User::~User(){
  cout << "~User(void) "  << this << endl;
}

string User::toString()const {
  return userID + " " + userName;
}

ostream & operator<<(ostream & out, const User & anUser){
  out << anUser.toString() << endl;
  return out;
}

// USER OWN THEIR PLAYLIST AND CREATES INSIDE THE USER
void User::newPlaylist(string aPlaylistName){
  myPlaylist = new Playlist;
  myPlaylist->setUserID(userID);
  myPlaylist->setPlaylistName(aPlaylistName);
  //allPlaylist->add(*myPlaylist);
  userPlaylistCollection.push_back(myPlaylist);
}

// ADDS A TRACK TO PLAYLIST
void User::_addTrackToPlaylist(int trackID){
	myPlaylist->addPlayListTrack(trackID);
}

// PRINT PLAYLIST
void User::printOn(ostream & out) const {
  mediaPlayer->view.print("   PLAYLISTS*");
  int playListCouter = 0;
  for (vector<Playlist*>::iterator it = userPlaylistCollection.begin() ; it != userPlaylistCollection.end(); ++it){
		if(!(*it)->getID().compare(userID)){
      string printString = "	" + to_string(playListCouter) + " " + (*it)->getPlaylistName();
      mediaPlayer->view.print(printString);
			(*it)->printPlaylistTracks();
			playListCouter++;
		} 
	}     	  
}

// ADDS A TRACT TO GIVEN PLAYLIST
void User::addTrackToPlaylist(Playlist & aPlaylist, int trackID){
	aPlaylist.addPlayListTrack(trackID);
}

vector<Playlist*>::iterator User::findPosition(Playlist & aPlaylist){
	for (vector<Playlist*>::iterator it = userPlaylistCollection.begin() ; it != userPlaylistCollection.end(); ++it)
		if(*it == &aPlaylist) return it;
	return userPlaylistCollection.end();
}

// RETURNS PLAYLIST FOR GIVEN PLAYLISTNAME
Playlist * User::findByID(string aPlaylistName){
	for (vector<Playlist*>::iterator it = userPlaylistCollection.begin() ; it != userPlaylistCollection.end(); ++it)
		if(!(*it)->getPlaylistName().compare(aPlaylistName)) return *it;
	return NULL;
}

// RETURNS PLAYLIST BY ORIGINAL ORDER (TO DELETE PLAYLIST ONE BY ONE)
Playlist * User::returnByOrder(){
	for (vector<Playlist*>::iterator it = userPlaylistCollection.begin() ; it != userPlaylistCollection.end(); ++it)
    if(!(*it)->getID().compare(userID)) return *it;
	return NULL;
}

// RETURNS NUMBER OF PLAYLIST USER OWN
int User::numberOfPlaylist(){
  return userPlaylistCollection.size();
}

// REMOVES A PLAYLIST FROM COLLECTION
void User::remove(Playlist & aPlaylist){
	vector<Playlist*>::iterator index = findPosition(aPlaylist);
	if(index != userPlaylistCollection.end()) {
		Playlist * thePlaylist = *index;
		userPlaylistCollection.erase(index);
		delete thePlaylist; //free the memory of theSong
	}
}

// RETURNS USER PLAYLISTS
vector<Playlist*> User::getUserPlaylist(){
  return userPlaylistCollection;
}

