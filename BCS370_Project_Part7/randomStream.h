#ifndef H_randomStream
#define H_randomStream
#include<iostream>
#include<string>
#include<fstream>
#include<climits>
#include<random>





class randomStream {

private:
	int numOfLines;
	std::string fileName;

public:

	void setFile(std::string file);
	void setLines(int lines);
	int getNumOfLines();
	std::string getFileName();
	randomStream();
	randomStream(std::string file, int fileLength);
	void setUpRandomStream();

};
// end of randomStream.h
#endif