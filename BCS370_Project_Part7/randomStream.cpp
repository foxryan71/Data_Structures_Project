#include "randomStream.h"
using namespace std;



void randomStream::setFile(string file) {

	fileName = file;




}

void randomStream::setLines(int lines) {

	numOfLines = lines;

}

int randomStream::getNumOfLines() {
	return numOfLines;
}

string randomStream::getFileName() {

	return fileName;

}

randomStream::randomStream() {

	fileName = "default.txt";
	numOfLines = 0;

}

randomStream::randomStream(string file, int fileLength) {
	fileName = file;
	numOfLines = fileLength;

}

void randomStream::setUpRandomStream() {



	ofstream outFile;
	ifstream infile;
	string words[1001];
	string word;
	int count = 1;
	
	outFile.open(fileName);

	infile.open("1-1000.txt");
	//store in array
	while (getline(infile,word)) {

		words[count] = word;
		
		count++;
		}//end while

	infile.close();

	cout << "Generating file, please hold." << endl;
	cout << endl;
	for (int i = 0; i < numOfLines; i++) {


		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 2);
		int randomNum = dis(gen);

		if (randomNum == 0) {

			int word_count = 1;
			string word;
			uniform_int_distribution<> dis(1, 1000);
			int randomNum2 = dis(gen);
		

			outFile << "A " << words[randomNum2] << " " << randomNum2 << endl;

		}

		if (randomNum == 1) {
			int word_count = 1;
			string word;
			uniform_int_distribution<> dis(1, 1000);
			int randomNum2 = dis(gen);


		
			outFile << "D " << words[randomNum2] << endl;


		}
		if (randomNum == 2) {
			int word_count = 1;
			string word;
			uniform_int_distribution<> dis(1, 1000);
			int randomNum2 = dis(gen);
		

			outFile << "P " << words[randomNum2] << endl;

		}
	
	}
	
	outFile.close();
	

}


