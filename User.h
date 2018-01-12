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

// Represents a registered ser of the application.
// Users have a userID, a name and a playlist collection that they own.

#ifndef USER_H
#define USER_H

#include <ostream>
#include <string>
#include <vector>
#include "Playlist.h"

class MediaPlayer;
class User {
	public:
  User();
  ~User(void);
  void setUserID(string anUserID){ userID = anUserID;}
  string getUserID() const {return userID;};
  void setUserName(string anUserName) { userName = anUserName;}
  void newPlaylist(string aPlaylistName);
  void addTrackToPlaylist(Playlist & aPlaylist, int trackID);
  Playlist * findByID(string aPlaylistName);
  Playlist * returnByOrder();
  int numberOfPlaylist();
  void remove(Playlist & aPlaylist);
  vector<Playlist*> getUserPlaylist();
  void _addTrackToPlaylist(int trackID);
  string toString() const;
  void printOn(ostream & out) const;
	
	private:
	string userID;
  string userName;
  Playlist *myPlaylist;
  vector<Playlist*>::iterator findPosition(Playlist & aPlaylist);
  MediaPlayer* mediaPlayer;

};

ostream & operator<<(ostream & out, const User & anUser);

#endif
