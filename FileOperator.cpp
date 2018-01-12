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

#include "FileOperator.h"

FileOperator::FileOperator(){

}

void FileOperator::writeFile(const string fileName, vector<string> myFileContext){
    errorMessage.clear();

    ofstream outFile(fileName);

    if(!outFile){
        errorMessage = "ERROR: The program coudn't create the file: " + fileName;
    }
    
    for(unsigned int i = 0; i < myFileContext.size(); i++){
        outFile << myFileContext[i] << endl;
    }
    

    outFile.close();
}

void FileOperator::loadFile(const string fileName){
    // Clearing fileContext from before context.
    fileContext.clear();
    errorMessage.clear();
    

    // Openning file
    ifstream myFile(fileName);

    if(!myFile){
        errorMessage = "ERROR: .read could not open file: " + fileName;
	}
    
    //Reading whole file
    while (getline(myFile, line)){
        fileContext.push_back(line);
    }

    // Closing file
    myFile.close();
}

const string FileOperator::getFileErrorMessage() { return errorMessage; }
const vector<string>& FileOperator::getFile() { return fileContext; }