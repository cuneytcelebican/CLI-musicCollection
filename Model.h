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

// This class created in the first assignment as a generic model solution.
// Now, it helps to communicate with user to show some screen output if there is any
// error. It improves communication and also reduces time spent.
// Lastly log starts through model.

#ifndef MODEL
#define MODEL


#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include <sstream>
#include <vector>

#include "FileOperator.h"
#include "CliLogging.h"

using namespace std;

class Model{
    public:
        Model();
        void update(const int, vector<string>);
        const vector<string>& getResult();
        const vector<string>& getInputResult();
        const vector<string>& getLogResult();
        const string getErrorMessage();
        CliLogging aLog;

    private:
        FileOperator fileProcess;
        vector<string> result;
        vector<string> fileToInput;
        vector<string> fileToInput2;
        vector<string> helpInput;
        string error;
        

        string id, title, artist, year, producer;
};

#endif