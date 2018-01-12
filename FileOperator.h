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

// This class incharge for file operations. When ever you try to open a file or save a
// file this class starts to work. There are only two operations for this class which
// are read file and write file.


#ifndef FILEOPERATOR
#define FILEOPERATOR

#include <fstream>
#include <vector>


using namespace std;

class FileOperator {
    // Creating public and privates
    public:
        FileOperator();
        // loadFile = loads file and sets to vector.
        void loadFile(const string);
        void writeFile(const string, vector<string>);

        // writeFile = writes file

        // getFile = returns loaded file
        const vector<string>& getFile();
        const string getFileErrorMessage();


    private:
        string line;
        // fileContext stores all lines from deserved file.
        vector<string> fileContext;
        string errorMessage;
        
};

#endif