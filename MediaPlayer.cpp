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

#include "MediaPlayer.h"

MediaPlayer::MediaPlayer() : view(&model) {
}

void MediaPlayer::run(int argc, char* argv[]) {
    // starting to program with paramater
    if(argc > 1){
        int textCommand;
        string option(argv[1]);
        vector<string> initialCommand;
        initialCommand.push_back(".read");
        initialCommand.push_back(option);
        model.update(30, initialCommand);

        // checking for any error message
        if(model.getErrorMessage().length() > 0){
            view.print(model.getErrorMessage());
        }
        // if there is no error do it below (read file)
        else{
            // clearing result if there is before entry
            result.clear();
            // copying our model result to result
            result = model.getInputResult();
            if(result.size() > 0){
                for(unsigned int i = 0; i < result.size(); i++){
                    string textInput = result[i];
                    //Parsing our file line
                    int myTextCommand = parseCommand(textInput);

                    if (myTextCommand == 30){
                        // updating our model for file reading
                        model.update(myTextCommand, myCommands);
            
                        // checking for any error message
                        if(model.getErrorMessage().length() > 0){
                            view.print(model.getErrorMessage());
                        }
                        // if there is no error do it below (read file)
                        else{
                            // clearing result if there is before entry
                            argResult.clear();
                            // copying our model result to result
                            argResult = model.getInputResult();
                            if(argResult.size() > 0){
                                for(unsigned int i = 0; i < argResult.size(); i++){
                                    string textInput = argResult[i];
                                    //Parsing our file line
                                    int command2 = parseCommand(textInput);
                                    //updating our model with parsed line
                                    model.update(command2, myCommands);
                                    // clearing textResult if there is before entry
                                    textResult.clear();
                                    // copying our result to textresult which comes from model
                                    textResult = model.getResult();
                                    for(unsigned int j = 0; j < textResult.size(); j++){
                                        view.print(textResult[j]);
                                    }
                                }
                            }
            
                        }
                        
                    }


                    else{
                        //updating our model with parsed line
                        model.update(myTextCommand, myCommands);
                        // clearing textResult if there is before entry
                        textResult.clear();
                        // copying our result to textresult which comes from model
                        textResult = model.getResult();
                        for(unsigned int j = 0; j < textResult.size(); j++){
                            view.print(textResult[j]);
                        }
                        myCommands.clear();
                    }
                }
            }

        }

    }
    else if(argc == 1){
        int textCommand;
        vector<string> initialCommand;
        initialCommand.push_back(".read");
        initialCommand.push_back("populate_program.txt");
        model.update(30, initialCommand);

        // checking for any error message
        if(model.getErrorMessage().length() > 0){
            view.print(model.getErrorMessage());
        }
        // if there is no error do it below (read file)
        else{

            // clearing result if there is before entry
            result.clear();
            // copying our model result to result
            result = model.getInputResult();
            if(result.size() > 0){
                for(unsigned int i = 0; i < result.size(); i++){
                    string textInput = result[i];
                    //Parsing our file line
                    textCommand = parseCommand(textInput);
                    //updating our model with parsed line
                    model.update(textCommand, myCommands);
                    // clearing textResult if there is before entry
                    textResult.clear();
                    // copying our result to textresult which comes from model
                    textResult = model.getResult();
                    for(unsigned int j = 0; j < textResult.size(); j++){
                        view.print(textResult[j]);
                    }
                }
            }

        }
        initialCommand.clear();
        initialCommand.push_back(".help");
        model.update(50, initialCommand);

        // clearing textResult if there is any entry before.
        textResult.clear();
        // copying our result to textresult which comes from model
        textResult = model.getResult();
        //printing our output
        for(unsigned int j = 0; j < textResult.size(); j++){
            view.print(textResult[j]);
        }



    }
    
    while (true) {
        myCommands.clear();    
        view.display();
        
        string userInput;
        view.getInput(userInput);

        // parsing user input
        int command = parseCommand(userInput);
        
        // if command == 1 quit from app.
        if(command == -1){
            // sending bye bye message user if user quited
            view.print("Bye Bye");
            break;
        }
        // reading file command
        else if (command == 30){
            // updating our model for file reading
            model.update(command, myCommands);

            // checking for any error message
            if(model.getErrorMessage().length() > 0){
                view.print(model.getErrorMessage());
            }
            // if there is no error do it below (read file)
            else{
                // clearing result if there is before entry
                result.clear();
                // copying our model result to result
                result = model.getInputResult();
                if(result.size() > 0){
                    for(unsigned int i = 0; i < result.size(); i++){
                        string textInput = result[i];
                        //Parsing our file line
                        command = parseCommand(textInput);
                        //updating our model with parsed line
                        model.update(command, myCommands);
                        // clearing textResult if there is before entry
                        textResult.clear();
                        // copying our result to textresult which comes from model
                        textResult = model.getResult();
                        for(unsigned int j = 0; j < textResult.size(); j++){
                            view.print(textResult[j]);
                        }
                    }
                }

            }
            
        }

        else{
            // updating model
            model.update(command, myCommands);
            // clearing textResult if there is any entry before.
            textResult.clear();
            // copying our result to textresult which comes from model
            textResult = model.getResult();
            //printing our output
            for(unsigned int j = 0; j < textResult.size(); j++){
                view.print(textResult[j]);
            }
        }

    }
    
}

int MediaPlayer::parseCommand(string userInput) {
    // clearing our variables declared in header
    myCommands.clear();
    stringstream ss(userInput);
    currentWord.clear();
    multiWord.clear();

    while (getline(ss, currentWord, ' ')){
        if (currentWord[0] == '"'){
            multiWordChecker = true;
        }
        if (multiWordChecker == true){
            multiWord += currentWord;
            multiWord += " ";
        }
        else{
            myCommands.push_back(currentWord);
        }
        if (currentWord[currentWord.length() - 1] == '"'){
            multiWordChecker = false;
        }

        if (multiWordChecker == false && multiWord.length() > 0){
            multiWord = multiWord.substr(1,(multiWord.length()-3));
            myCommands.push_back(multiWord);
            multiWord.clear();
        }
    }

    

    // Clean the vector (I tried to use .clean() method but we did not find any
    // solution inside the code to impliment it. I asked to TAs and Prof they also
    // did not find any other solution).
    if(myCommands.size() > 2){
        for(int i = myCommands.size(); i < 8; i++){
            myCommands[i] = "";
        }
    }

    // checking our inputs
    if(!myCommands.empty()){
        view.printOthers("PARSED COMMAND: ");
        for(unsigned int i = 0; i < myCommands.size(); i++)
            view.printOthers(myCommands[i]);
    
        if(myCommands[0] == "add"){
            // ADD RECORDING
            if(myCommands[1] == "-r"){
                if(myCommands[2] != "?"){
                    myRecording = allRecordings.findByID(stoi(myCommands[2]));
                    if(myRecording != NULL)
                        return -400;
                }
                // Make it titleCase
                myCommands[3] = toTitleCase(myCommands[3]);
                myCommands[4] = toTitleCase(myCommands[4]);
                myCommands[6] = toTitleCase(myCommands[6]);

                myRecording = new Recording;
                if(myCommands[2] == "?"){
                    myRecording->setId(allRecordings.giveMeRecordingID());
                }
                else{
                    myRecording->setId(stoi(myCommands[2]));
                }
                myRecording->setTitle(myCommands[3]);
                myRecording->setArtist(myCommands[4]);
                myRecording->setYear(stoi(myCommands[5]));
                myRecording->setProducer(myCommands[6]);
                
                allRecordings.add(*myRecording);
                return 0;
            }
            // ADD SONG
            else if(myCommands[1] == "-s"){
                if(myCommands[2] != "?"){
                    mySong = allSongs.findByID(stoi(myCommands[2]));
                    if(mySong != NULL)
                        return -399;
                }

                // Make it titleCase
                myCommands[3] = toTitleCase(myCommands[3]);
                myCommands[4] = toTitleCase(myCommands[4]);

                mySong = new Song;
                if(myCommands[2] == "?"){
                    mySong->setId(allSongs.giveMeSongID());
                }
                else{
                    mySong->setId(stoi(myCommands[2]));
                }
                mySong->setComposer(myCommands[4]);
                mySong->setTitle(myCommands[3]);
                
                allSongs.add(*mySong);
                return 1;
                
            }
            // ADD TRACK
            else if(myCommands[1] == "-t"){
				checkSongID = allSongs.findByID(stoi(myCommands[4]));
				if(checkSongID == NULL){
                    return -401;
                }
                if(myCommands[3] != "null"){
                    
                    if(myCommands[2] != "?"){
                        myTrack = allTracks.findByID(stoi(myCommands[2]));
                        if(myTrack != NULL){
                            return -398;
                        }
                    }
                    checkAlbumID = allRecordings.findByID(stoi(myCommands[3]));
                    
                    if(checkAlbumID == NULL && checkSongID == NULL){
                        return -403;
                    }
                    else if(checkAlbumID == NULL){
                        return -402;
                    }
                    else if(checkSongID == NULL){
                        return -401;
                    }
                    else{
                        myTrack = new Track;
                        if(myCommands[2] == "?"){
                            myTrack->setTrackId(allTracks.giveMeTrackID());
                        }
                        else{
                            myTrack->setTrackId(stoi(myCommands[2]));
                        }
                        
                        myTrack->setAlbumId(stoi(myCommands[3]));
                        myTrack->setSongId(stoi(myCommands[4]));
                        myTrack->setTrackNumber(stoi(myCommands[5]));
                        allTracks.add(*myTrack);
                    }
                }
                else{
                    if(myCommands[2] != "?"){
                        myTrack = allTracks.findByID(stoi(myCommands[2]));
                        if(myTrack != NULL){
                            return -398;
                        }
                    }
                    myTrack = new Track;
                    if(myCommands[2] == "?"){
                        myTrack->setTrackId(allTracks.giveMeTrackID());
                    }
                    else{
                        myTrack->setTrackId(stoi(myCommands[2]));
                    }
                    myTrack->setSongId(stoi(myCommands[4]));
                    myTrack->setTrackNumber(stoi(myCommands[5]));
                    allTracks.add(*myTrack);
                }
                
                
                return 2;
            }
            // ADD USER
            else if(myCommands[1] == "-u"){
                myUser = allUsers.findByID(myCommands[2]);
                
                if(myUser != NULL){
                    return -397;
                }
                
                // Make it titleCase
                myCommands[3] = toTitleCase(myCommands[3]);
                myUser = new User;
                myUser->setUserID(myCommands[2]);
                myUser->setUserName(myCommands[3]);
                allUsers.add(*myUser);
                return 3;
            }
            // ADD PLAYLIST
            else if(myCommands[1] == "-p"){
                myUser = allUsers.findByID(myCommands[2]);
                myPlaylist = myUser->findByID(myCommands[3]);
                
                if(myUser == NULL){
                    return -396;
                }
                else if(myPlaylist != NULL){
                    return -395;
                }

                myUser->newPlaylist(myCommands[3]);
                return 4;
            }
            // ADD PLAYLIST TRACK
            else if(myCommands[1] == "-l"){
                myUser = allUsers.findByID(myCommands[2]);
                myPlaylist = myUser->findByID(myCommands[3]);
                myTrack = allTracks.findByID(stoi(myCommands[4]));
                int checkMyPlaylistTrack = myPlaylist->checkPlaylistTrack(stoi(myCommands[4]));
        
                if(myUser == NULL){
                    return -396;
                }
                else if(myPlaylist == NULL){
                    return -394;
                }
                else if(myTrack == NULL){
                    return -393;
                }
                else if(checkMyPlaylistTrack == 1){
                    return -389;
                }

                myUser->addTrackToPlaylist(*myPlaylist, stoi(myCommands[4]));
                return 5;
            }
        }
        else if(myCommands[0] == "delete"){
            // DELETE A SONG
            if(myCommands[1] == "-s"){
                mySong = allSongs.findByID(stoi(myCommands[2]));
                myTrack = allTracks.findBySongID(stoi(myCommands[2]));
                
                if(mySong == NULL){
                    return -401;
                }
                if(myTrack != NULL){
					allUsers.deleteUserPlaylistTracks(myTrack->getID());
					allTracks.remove(*myTrack);
                }
                allSongs.remove(*mySong);
                return 10; 
            }
            // DELETE RECORDING
            else if(myCommands[1] == "-r"){
                myRecording = allRecordings.findByID(stoi(myCommands[2]));
                
                if(myRecording == NULL){
                    return -402;
                }

                allRecordings.remove(*myRecording);
                return 13;
            }
            // DELETE FROM PLAYLIST AND TRACKS - GLOBAL
            else if(myCommands[1] == "-u" && myCommands[3] == "-p" && myCommands[5] == "-t" && myCommands[7] == "-GLOBAL"){
                myUser = allUsers.findByID(myCommands[2]);
                myPlaylist = myUser->findByID(myCommands[4]);
                myTrack = allTracks.findByID(stoi(myCommands[6]));

                if(myUser == NULL && myPlaylist == NULL && myTrack == NULL){
                    return -391;
                }
                else if(myUser == NULL){
                    return -392;
                }
                else if(myPlaylist == NULL){
                    return -394;
                }
                else if(myTrack == NULL){
                    return -393;
                }

                myPlaylist->removePlaylistTrack(stoi(myCommands[6]));
                allUsers.deleteUserPlaylistTracks(stoi(myCommands[6]));
                allTracks.remove(*myTrack);
                mySong = allSongs.findByID(myTrack->getSongID());
                allSongs.remove(*mySong);
                return 12;
            }
            // DELETE USER PLAYLIST TRACK
            else if(!myCommands[1].compare("-u") && !myCommands[3].compare("-p") && !myCommands[5].compare("-t")){
                myUser = allUsers.findByID(myCommands[2]);
                myPlaylist = myUser->findByID(myCommands[4]);
                
                if(myUser == NULL && myPlaylist == NULL){
                    return -391;
                }
                else if(myUser == NULL){
                    return -392;
                }
                else if(myPlaylist == NULL){
                    return -394;
                }
                else if(myPlaylist->checkPlaylistTrack(stoi(myCommands[6])) == 0 ){
                    return -388;
                }

                myPlaylist->removePlaylistTrack(stoi(myCommands[6]));
                return 17;
            }
            // DELETE USER PLAYLIST
            else if(!myCommands[1].compare("-u") && !myCommands[3].compare("-p")){
                myUser = allUsers.findByID(myCommands[2]);
                myPlaylist = myUser->findByID(myCommands[4]);

                if(myUser == NULL && myPlaylist == NULL){
                    return -391;
                }
                else if(myUser == NULL){
                    return -392;
                }
                else if(myPlaylist == NULL){
                    return -394;
                }

                myUser->remove(*myPlaylist);
                return 15;
            }
            // DELETE USER
            else if(!myCommands[1].compare("-u")){
                myUser = allUsers.findByID(myCommands[2]);

                if(myUser == NULL){
                    return -392;
                }

                for (unsigned int i = 0; i < myUser->numberOfPlaylist(); i++){
                    myPlaylist = myUser->returnByOrder();
                    myUser->remove(*myPlaylist);
                }
                
                allUsers.remove(*myUser);
                return 14;
            }
            // DELETE TRACK
            else if(myCommands[1] == "-t"){
                myTrack = allTracks.findByID(stoi(myCommands[2]));

                if(myTrack == NULL){
                    return -393;
                }
				allUsers.deleteUserPlaylistTracks(stoi(myCommands[2]));
                allTracks.remove(*myTrack);
                return 16;
            }
        }
        else if(myCommands[0] == "show"){
            // SHOW SINGLE SONG
            if(myCommands[1] == "songs" && myCommands[2] == "-s"){
                mySong = new Song;
                mySong = allSongs.findByID(stoi(myCommands[3]));
                
                if(mySong == NULL){
                    return -401;
                }

                view.print("SONG:");
                view.print(mySong->toString());
                return 27; // show single song
            }
            // SHOW SONGS
            else if(myCommands[1] == "songs"){
                allSongs.printOn(cout);
                return 20;
            }
            // SHOW SINGLE USER
            else if(myCommands[1] == "users" && myCommands[2] == "-u"){
                allUsers.printOnSingleUser(myCommands[3]);
                return 22; // show single user
            }
            // SHOW USERS
            else if(myCommands[1] == "users"){
                allUsers.printOn(cout);
                return 21;
            }
            // SHOW SINGLE RECORDING
            else if(myCommands[1] == "recordings" && myCommands[2] == "-r"){
                myRecording = allRecordings.findByID(stoi(myCommands[3]));
                if(myRecording == NULL){
                    return -402;
                }
                allRecordings.singlePrintOn(*myRecording);
                return 26;
            }
            // SHOW RECORDINGS
            else if(myCommands[1] == "recordings"){
                allRecordings.printOn(cout);
                return 24;
            }
            // SHOW SINGLE TRACK
            else if(myCommands[1] == "tracks" && myCommands[2] == "-t"){
                myTrack = allTracks.findByID(stoi(myCommands[3]));
                if(myTrack == NULL){
                    return -393;
                }
                view.print("TRACK:");
                view.print(myTrack->toString());
                return 28;
            }
            // SHOW TRACKS
            else if(myCommands[1] == "tracks"){
                allTracks.printOn(cout);
                return 25;
            }
        }
        // QUIT
        else if(myCommands[0] == ".quit"){
            return -1;
        }
        // READ
        else if(myCommands[0] == ".read"){
            return 30;
        }
    
        else if(myCommands[0] == ".log"){
            if(myCommands[1] == "clear"){
                return 40; // clear the logs
            }
            else if(myCommands[1] == "start"){
                return 41; // begin logging commands only
            }
            else if(myCommands[1] == "start_output"){
                return 42; // begin logging output only
            }
            else if(myCommands[1] == "start_both"){
                return 43; // begin logging commands and output
            }
            else if(myCommands[1] == "stop"){
                return 44; // stop logging
            }
            else if(myCommands[1] == "save"){
                return 45; // save log to filename
            }
            else if(myCommands[1] == "show"){
                return 46; // display current log contents on console
            }
        }
        else if(myCommands[0] == ".help"){
            return 50; // show help menu
        }
    
        else if(checkFirstLetter(myCommands[0], "//")){
            return 60; // comments
        }
        // any error
        return -404;
    }
    return -2;
}

// this functions converts string to title case and also reorder if there is any "The"
string MediaPlayer::toTitleCase (string userInput){
    // defining variables
    string modifiedString;
    string str = userInput;
    bool capitalize = true;
    string remainingStr;
    
    // reference: http://www.cplusplus.com/forum/beginner/62826/

    for (unsigned i = 0; i<str.length(); i++){
    // Checking that is character alphetical character or not.
    // Also checking is it capital or not.
        if (isalpha(str[i]) && capitalize == true){
		str[i] = toupper(str[i]);
		capitalize = false;
        }
        else{
    // Checking if there is space and making capitalize true
            if(isspace(str[i])){
                capitalize = true;
            }
        }
    }

// Finding the "The" position. In this case our position should be 0
// because we are looking for which sentence starts with "The"
    size_t position = str.find("The ");

// If we finds a "The" in the our sentece we are just changing the order
    if(position == 0){
		remainingStr = str.substr(position+4);
		str = remainingStr + ", The";
	
    }

// Lastly, adding our new string to our returning string and returning it.
    modifiedString.append(str);
    return modifiedString;
}

// this function checks first letter starts with given value or not.
bool MediaPlayer::checkFirstLetter(string userInput, string findingValue){
    size_t found;
    found = userInput.find(findingValue);
    if (found == 0){
        return true;
    }    
    return false;
}
