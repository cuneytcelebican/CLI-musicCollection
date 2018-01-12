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

#include "Model.h"


Model::Model() {

}

void Model::update(const int command, vector<string> myCommands){
    // clearing result and error vectors, if there is any other entry will remove.
    result.clear();
    error.clear();
    string textCommand = "EXECUTING:";
    for(unsigned int i = 0; i < myCommands.size(); i++){
        textCommand += " ";
        textCommand += myCommands[i];
        
    }
    // Swicht statmeent, it will be pair one of our command.
    switch(command){
        case -404:{
            result.push_back("ERROR: UNRECOGNIZED COMMAND");
            break;
        }
            

        case -403:{
            result.push_back("ERROR: recordingID and songID do not match with Recordings and Songs");
            break;
        }
            
        
        case -402:{
            result.push_back("ERROR: recordingID does not match with Recordings");
            break;
        }
            
        case -401:{
            result.push_back("ERROR: songID does not match with Songs");
            break;
        }

        case -400:{
            result.push_back("ERROR: This recording ID already exist in the recordings. Please type '?' for albumID if you want to add in the empty spot");
            break;
        }

        case -399:{
            result.push_back("ERROR: This song ID already exist in the songs. Please type '?' for songID if you want to add in the empty spot");
            break;
        }

        case -398:{
            result.push_back("ERROR: This track ID already exist in the tracks. Please type '?' for trackID if you want to add in the empty spot");
            break;
        }

        case -397:{
            result.push_back("ERROR: Ops, this userID already exist in users. Please input another userID");
            break;
        }

        case -396:{
            result.push_back("ERROR: Ops, UserID does not match in Users. Please check your userID");
            break;
        }

        case -395:{
            result.push_back("ERROR: Ops, this playlist name already exist for this user. Please input different playlist name");
            break;
        }

        case -394:{
            result.push_back("ERROR: Ops, playlist name does not match. Please check your playlistName for particular user");
            break;
        }
        case -393:{
            result.push_back("ERROR: Ops, TrackID does not match in Tracks. Please check your trackID");
            break;
        }

        case -392:{
            result.push_back("ERROR: userID does not match with Users");
            break;
        }

        case -391:{
            result.push_back("ERROR: userID, trackID and playlistName do not match. Please check againg");
            break;
        }

        case -390:{
            result.push_back("ERROR: songID and trackID do not match. Please check againg");
            break;
        }
        case -389:{
            result.push_back("ERROR: Ops, this user's playlist (given by you) has same track. You cannot add twice");
            break;
        }

        case -388:{
            result.push_back("ERROR: Ops, this user does not has this track");
            break;
        }
            
        // Add command cases
        // add recording
        case 0:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // add songs
        case 1:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        //add tracks
        case 2:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // add users
        case 3:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // add playlists
        case 4:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // add playlist tracks
        case 5:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }

        // Delete command cases
        // delete song
        case 10:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // delete songs from playlist
        case 11:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // delete songs from playlist and global
        case 12:{
            result.push_back(textCommand);
            break;
        }
        // delete recording
        case 13:{
            result.push_back(textCommand);
            break;
        }
        // delete users
        case 14:{
            result.push_back(textCommand);
            break;
        }
        // delete user playlist
        case 15:{
            result.push_back(textCommand);
            break;
        }
        // delete track
        case 16:{
            result.push_back(textCommand);
            break;
        }
        // delete track from user playlist
        case 17:{
            result.push_back(textCommand);
            break;
        }


        // Show command cases    
        // show songs
        case 20:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show users
        case 21:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show playlists
        case 22:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show songs, userid and playlist
        case 23:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show recordings
        case 24:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show tracks
        case 25:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show single recording
        case 26:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show single song
        case 27:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // show single track
        case 28:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }

        // Read command case
        case 30:{



            fileToInput.clear();
            string fileNameX = myCommands[1];
            fileProcess.loadFile(myCommands[1]);
            vector<string> file = fileProcess.getFile();
            for(unsigned i = 0; i < file.size(); i++){
                //cout << file[i] << endl;
                fileToInput.push_back(file[i]);
            }
            error = fileProcess.getFileErrorMessage();
            break;
        }

        // Log command case
        // clear the logs
        case 40:{
            // clearing all logs
            aLog.clearLog();
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // begin logging commands only
        case 41:{
            // sending a notification to log object to start command only object enable
            aLog.setLogStatus(true);
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // begin logging output only
        case 42:{
            // sending log object to make log option enable
            aLog.setOutputLogStatus(true);
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // begin logging commands and output
        case 43:{

            // set all logs status true that means start logging
            aLog.setLogStatus(true);
            aLog.setOutputLogStatus(true);
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // stop logging
        case 44:{
            // set log status false that means stop logging
            aLog.setLogStatus(false);
            // set log output status false that means stop logging
            aLog.setOutputLogStatus(false);
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // save log to filename
        case 45:{
            // taking filename.
            string fileName = myCommands[2];
            // clearing our vector if there is any other command from before sessions.
            fileToInput.clear();
            // copying all log to our vector to send it.
            fileToInput = aLog.getLog();
            // sending our vector and file name to create a file.
            fileProcess.writeFile(fileName, fileToInput);
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
        // display current log contents on console
        case 46:{
            // clearing our vector if there is any before entry.
            fileToInput.clear();
            // putting all logs to our return variable
            fileToInput = aLog.getLog();
            // returning message that means: I understand the command
            result.push_back(textCommand);
            result.push_back("Logs//////////////////////////////////");
            for (unsigned int i = 0; i < fileToInput.size(); i++){
                result.push_back(fileToInput[i]);
            }
            result.push_back("/////////////////////////////////////");

            break;
        }


        // Help command case
        case 50:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            // notifing object for openning help.txt file
            fileProcess.loadFile("prototype_help.txt");
            // copying readed file to our return vector.
            helpInput.clear();
            helpInput = fileProcess.getFile();
            for (unsigned int i = 0; i < helpInput.size(); i++){
                result.push_back(helpInput[i]);
            }
            break;
        }

        // Comment command case
        case 60:{
            // returning message that means: I understand the command
            result.push_back(textCommand);
            break;
        }
            

    }
}
// returns result
const vector<string>& Model::getResult() { return result; }

// returns inputs from read file
const vector<string>& Model::getInputResult() { return fileToInput; }

// returns entered logs
const vector<string>& Model::getLogResult() { return fileToInput; }

// retruns error message
const string Model::getErrorMessage() {return error;}
