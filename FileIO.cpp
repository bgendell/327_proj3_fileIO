/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	fstream fileIn;
	fileIn.open(filename.c_str(),ios_base::in);
	if(fileIn.is_open()){
		std::string temp;
		while(!fileIn.eof()){
			getline(fileIn,temp);
			contents.append(temp);
		}
		fileIn.close();
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE_TO_READ;
}

//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	fstream fileOut;
	fileOut.open(filename.c_str(),ios_base::out);
	if(fileOut.is_open()){
		for(int i = 0; i < myEntryVector.size(); i++){
			fileOut << myEntryVector[i];
			fileOut << "\n";
		}
		fileOut.close();
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE_TO_WRITE;
}


