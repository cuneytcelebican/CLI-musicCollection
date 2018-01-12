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

#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include <ostream>
#include <string>
#include <vector>
#include<algorithm>
#include "Track.h"
#include "Tracks.h"

class MediaPlayer;

class Playlist {

	public:
	Playlist();
	void setUserID(string anUserID){ userID = anUserID;}
  void setPlaylistName(string aPlaylistName) { playlistName = aPlaylistName;}
  void addPlayListTrack(int aPlaylistTrack);
  void removePlaylistTrack(int _aPlaylistTrack);
  
	~Playlist(void);
  string getID();
  string getPlaylistName();
  string toString() const;
  void printPlaylistTracks();
  int checkPlaylistTrack(int aPlaylistTrack);
	
	private:
	string userID;
  string playlistName;
  vector<int> playlistTracks;
  Track *myTrack;
  MediaPlayer* mediaPlayer;
};

ostream & operator<<(ostream & out, const Playlist & aPlaylist);

#endif
