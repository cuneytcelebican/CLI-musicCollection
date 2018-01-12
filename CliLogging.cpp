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

#include "CliLogging.h"

CliLogging::CliLogging(){

}

void CliLogging::loadLog(const string logText){
     logContext.push_back(logText);

}

void CliLogging::clearLog(){
    logContext.clear();
}

void CliLogging::setLogStatus(bool status){
    newStatus = status; 
}

void CliLogging::setOutputLogStatus(bool status){
    newOutputStatus = status; 
}

bool CliLogging::getLogStatus(){
    return newStatus;
}

bool CliLogging::getOutputLogStatus(){
    return newOutputStatus;
}

const vector<string>& CliLogging::getLog() { 
    return logContext; 

}

