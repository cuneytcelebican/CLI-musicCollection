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

// Users represents a collection of user objects.
// A Users container OWNS the users within it.
// If the container is destroyed it deletes the User objects it contains
// If a User is removed from the container the User object is deleted from heap space.

#ifndef _USERS_H
#define _USERS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "User.h"

class MediaPlayer;
class Users {
	public:
	Users(); 
	~Users(void);
	User * findByID(string anID);
	void add(User & anUser);
	void remove(User & anUser);
	void printOn(ostream & out) const;
	void printOnSingleUser(string anUserID);
	void deleteUserPlaylistTracks(int aTrackID);
	
	private:
	vector<User*>::iterator findPosition(User & anUser);
  	MediaPlayer* mediaPlayer;
	User *myUser;
	vector<Playlist*> userPlaylistsContainer;
};

ostream & operator<<(ostream & out, const Users & users);
#endif