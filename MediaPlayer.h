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

// This is contoroller class. This class controls each object and program flow.
// In the class you'll see if statements and these are sending message to class
// also for each if statament, program checks errors.
// This class also edits the input according to assignment requirements.

#ifndef MEDIAPLAYER
#define MEDIAPLAYER

// our include statements
#include "View.h"
#include "Model.h"
#include "Song.h"
#include "Songs.h"

#include "Recording.h"
#include "Recordings.h"


#include "Track.h"
#include "Tracks.h"

#include "User.h"
#include "Users.h"

#include "Playlist.h"

#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

// declaring class
class MediaPlayer {
    public:
        MediaPlayer();
        void run(int, char*[]);
        Songs allSongs;
        Tracks allTracks;
        Users allUsers;
        View view;
        
    private:
        Model model;
        vector<string> myCommands;
        vector<string> result;
        vector<string> argResult;
        vector<string> textResult;
        int parseCommand(string);
        string toTitleCase (string);
        bool checkFirstLetter(string, string);
        string currentWord;
        string multiWord;
        bool multiWordChecker = false;
        int showLog(int command);
        
        
        Song *mySong;
        Recordings allRecordings;
        Recording *myRecording;
        Recording *checkAlbumID = new Recording;
        Song *checkSongID = new Song;
        Track *myTrack;
        User *myUser;

        Playlist *myPlaylist;
        

};

#endif