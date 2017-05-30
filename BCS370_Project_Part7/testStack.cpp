#include "testStack.h"
#include <map>
#include<utility>
#include "BST.h"
using namespace std;
using namespace farmingdale;
using farmingdale::SUCCESS;
using farmingdale::FAILURE;

void testStack::randomStream()
{
	testStack t1;
	int num = 0;
	int numOfLines;
	string fileName;


	while (num != 4)
	{
		cout << "Please choose an option" << endl;
		cout << endl;
		cout << "1)Generate test file" << endl;
		cout << endl;
		cout << "2)Test an exsisting file" << endl;
		cout << endl;
		cout << "3)Generate test file and run it" << endl;
		cout << endl;

		cout << "4)Exit" << endl;
		cin >> num;

		switch (num)
		{

		case 1:

			cout << "Please enter the file name:" << endl;
			cin >> fileName;

			t1.f1.setFile(fileName);
			cout << "Enter the number of lines for the file:" << endl;
			cin >> numOfLines;
			t1.f1.setLines(numOfLines);

			t1.f1.setUpRandomStream();

			break;

		case 2:

		{
			cout << "Enter in the name of the File you would like to test:";
			cin >> fileName;
			ifstream file;
			file.open(fileName);



			t1.testStream(file);

			break;

		}
		case 3: {

			cout << "Please enter the file name:" << endl;
			cin >> fileName;

			t1.f1.setFile(fileName);
			cout << "Enter the number of lines for the file:" << endl;
			cin >> numOfLines;
			t1.f1.setLines(numOfLines);

			t1.f1.setUpRandomStream();


			ifstream file;
			file.open(fileName);
			t1.testStream(file);

			break;
		}
		case 4:
			break;

		default:
			cout << "Wrong source of input" << endl;
			break;
		}


	}
}








int testStack::testStream(ifstream& fileName) {
	string  letterLine;
	string numLine;
	string word;
	int fileLine = 1;
	int error_count = 0;
	int pop_error = 0;
	int peek_error = 0;

	std::map<std::string, int> q1;
	farmingdale::bst q3;
	farmingdale::bst q2;
	cout << "Currently testing the file!" << endl;
	cout << endl;
	while (!fileName.eof())
	{


		fileName >> letterLine;

		fileLine++;




		// if letter from file = A
		if (letterLine == "A")
		{

			fileName >> word;

			//converts wordLine from string to int for std::map



			fileName >> numLine;
			int wordNum = atoi(numLine.c_str());




			farmingdale::statusCode s1 = enqueue(word, wordNum, q1);

			farmingdale::statusCode s2 = q2.enqueue(word, wordNum);
			//
			farmingdale::statusCode s3 = q3.enqueue(word, wordNum);


			if (s1 != s2 || s2 != s3) {


				cerr << "1 FAILURE:Error on file line: " << fileLine << endl;

				error_count++;
				return fileLine;
			}




		}


		if (letterLine == "P")
		{


			string num1 = " ";
			string num2 = " ";
			string num3 = " ";
			std::string word;
			fileName >> word;



			farmingdale::statusCode s1 = search(word, q1);
			farmingdale::statusCode s2 = q2.top(word);
			farmingdale::statusCode s3 = q3.top(word);



			if (s1 != s2 || s2 != s3)
			{

				cerr << "2 FAILURE:Error on file line: " << fileLine << endl;
				error_count++;
				return fileLine;

			}


			if (s1 == SUCCESS && (num1 != num2 || num2 != num3))
			{

				cerr << "3 FAILURE:Error on file line: " << fileLine << endl;
				error_count++;
				return fileLine;

			}


			if (s1 == FAILURE && (s2 == FAILURE && s3 == FAILURE)) {

				// this just keeps track of the amount of times the queue was tried being peeked while empty... this is not a fatal error though because queues match up that all are empty 
				peek_error++;

			}




		}


		if (letterLine == "D")
		{

			string num1 = " ";
			string num2 = " ";
			string num3 = " ";
			std::string word;

			fileName >> word;

			farmingdale::statusCode s1 = dequeue(word, q1);
			farmingdale::statusCode s2 = q2.dequeue(word);
			farmingdale::statusCode s3 = q3.dequeue(word);


			if (s1 != s2 || s2 != s3) {

				cerr << "4 FAILURE:Error on file line: " << fileLine << endl;
				error_count++;
				return fileLine;


			}




			if (s1 == SUCCESS && (num1 != num2 || num2 != num3)) {

				cerr << "5 FAILURE:Error on file line: " << fileLine << endl;


				error_count++;
				return fileLine;

			}
			if (s1 == FAILURE && (s2 == FAILURE && s3 == FAILURE)) {

				// this just keeps track of the amount of times the queue was tried being dequed while empty... this is not a fatal error though because queues match up that all are empty.
				pop_error++;

			}

		}
	}

	if (error_count == 0) {

		cout << "Passed the testStack test!" << endl;
		cout << "\n";
		cout << "Count of q2 BST:" << q2.getCount() << endl;
		cout << "\n";
		cout << "Count of q3 BST:" << q3.getCount() << endl;
		cout << "\n";
	}
	else {

		cout << "Please check errors above" << endl;
	}


	return 0;

}
testStack::testStack() {


}

farmingdale::statusCode testStack::enqueue(std::string &word, int word_num, std::map<std::string, int>&q1) {
	if (q1.find(word) == q1.end()) {
		q1[word] = word_num;
		return SUCCESS;
	}
	else {
		return FAILURE;
	}



}//end of enqueue






farmingdale::statusCode testStack::dequeue(std::string &word, std::map<std::string, int>& q1) {

	if (q1.count(word) > 0) {

		q1.erase(word);

		return SUCCESS;

	}
	else {

		return FAILURE;
	}


}

farmingdale::statusCode testStack::search(std::string &word, std::map<std::string, int>& q1) {

	if (q1.count(word) > 0) {

		return SUCCESS;
	}
	else {
		return FAILURE;
	}

}