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

// This class interacts with user. It takes input from user and
// shows output from program. Log command also keep track logs inside
// the this class

#ifndef VIEW
#define VIEW

#include <sstream>
#include <string>
#include <iostream>
#include "Model.h"
#include "CliLogging.h"

using namespace std;

class View {

    public:
        View(Model*);
        void display();
        void getInput(string&);
        void print(const string&);
        void printOthers(const string&);
        
    private:
        
};
#endif