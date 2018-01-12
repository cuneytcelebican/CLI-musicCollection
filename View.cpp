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

#include "View.h"
Model* model;

View::View(Model* m){
    model = m;
}

// PRINTS AN OUTPUT TO SHOW PROGRAM READY
void View::display(){
    cout << "CMD or .quit:";
}

// TAKES INPUT FROM USER AND IF LOG IS ON KEEP TRACKS LOG
void View::getInput(string& output){
    cout << " ";
    getline(cin, output);
    
    if(model->aLog.getLogStatus() == 1){
        model->aLog.loadLog(output);
    }
}

// PRINTS TO SCREEN AND IF LOG IS ON KEEP TRACKS LOG
void View::print(const string& toPrint){
    cout << toPrint << endl;
    if(model->aLog.getOutputLogStatus() == 1){
        model->aLog.loadLog(toPrint);
    }
}

// PRINTS WITHOUT LOG // SECONDARY PRINT
void View::printOthers(const string& toPrint){
    cout << toPrint << endl;
}