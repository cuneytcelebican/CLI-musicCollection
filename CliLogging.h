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

// This is log class. The program keep starts to log when you input .log start...
// It takes all datas from view not from any other class.

#ifndef CLILOGGING
#define CLILOGGING

#include <vector>
#include <string>

using namespace std;

class CliLogging{
    public:
        CliLogging();
        void loadLog(const string);
        void clearLog();
        void setLogStatus(bool);
        bool getLogStatus();

        void setOutputLogStatus(bool);
        bool getOutputLogStatus();
        const vector<string>& getLog();
    private:
        string x;
        bool newStatus;
        bool newOutputStatus;
        vector<string> logContext;
};

#endif