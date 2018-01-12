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

#include <iostream>
#include <string>
using namespace std;
#include "Recording.h"

Recording::Recording(){
    id      = -1;
    year    = -1;
}
Recording::~Recording(){
	cout << "~Recording(void) "  << this << endl;
}

int Recording::getID(){return id;}

string Recording::toString()const {
	return to_string(id) + " " + title + " " + artist + " " + to_string(year) + " " + producer;
}

ostream & operator<<(ostream & out, const Recording & aRecording){
	out << aRecording.toString() << endl;
	return out;
}
