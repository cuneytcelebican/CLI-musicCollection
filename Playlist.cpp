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

// Represents an ordered collection of audio recordings
// Playlist class holds a collection of tracks
// and has a pointer to the User who owns it, as well as a string
// reperesenting the name of the playlist

#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"
#include "MediaPlayer.h"



Playlist::Playlist(){}
Playlist::~Playlist(){
	cout << "~Playlist(void) "  << this << endl;
}

string Playlist::getID(){return userID;}
string Playlist::getPlaylistName(){return playlistName;}

string Playlist::toString()const {
	return userID + " " + playlistName;
}

ostream & operator<<(ostream & out, const Playlist & aPlaylist){
	out << aPlaylist.toString() << endl;
	return out;
}

// ADDS A TRACK TO PLAYLIST
void Playlist::addPlayListTrack(int aPlaylistTrack) {
  playlistTracks.push_back(aPlaylistTrack);
}

// REMOVES A TRACK FROM PLAYLIST
//https://stackoverflow.com/questions/7631996/remove-an-element-from-a-vector-by-value-c
void Playlist::removePlaylistTrack(int _aPlaylistTrack){
	playlistTracks.erase(remove(playlistTracks.begin(), playlistTracks.end(), _aPlaylistTrack), playlistTracks.end()); 
	mediaPlayer->view.print("Track deleted from playlist");
}

// CHECKS THE GIVEN OBJECT AND RETURN 1 IF IT IS INSIDE OTHERWISE 0
int Playlist::checkPlaylistTrack(int aPlaylistTrack){
	for(vector<int>::size_type i=0; i<playlistTracks.size(); i++){
		if(playlistTracks[i] == aPlaylistTrack)
			return 1;
	}
	return 0;
}

// PRINT PLAYLIST TRACKS
void Playlist::printPlaylistTracks() {
	mediaPlayer->view.print("		PLAYLIST TRACKS:");
	int playlistTrackNumber = 0;
	
	for(vector<int>::size_type i=0; i<playlistTracks.size(); i++){
		myTrack = mediaPlayer->allTracks.findByID(playlistTracks[i]);
		string printString = "		" + to_string(playlistTrackNumber) + " " + myTrack->toString();
		mediaPlayer->view.print(printString);
		playlistTrackNumber++;
	}
		
}
