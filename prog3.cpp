/* Code by christian torralba...assignment number 3 for CS162
 * purpose of this program is toask the user to input questions they want to store later to practice
 */


#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;
//------------Constants-----------
const int SUBSIZE = 21; // size for array of characters thta holds subject, e.g., loops, arrays, structs
const int QUESTSIZE = 140; // Constant for size of question
//--------Structs------
struct Question{
	char subject[SUBSIZE]; //
	char questionText[QUESTSIZE];
	char date[11]; //dates are usually a set size already..
};


//------Prototypes--------
void writeToFile(Question & question);
void createStruct(int questionNumber, Question &list);
void displayQuestion(char subject[]);
void getQuestionStruct(char subject[]);
void displayStruct(Question & question);
void displayStructQuestion(Question & question);
//--------Fuctions---------
int main()
{
	int numOfQuestions;
	char nameOfQuestion[31];	
	Question list[10];
	bool endProg = true;
	//------Getting how many questions the user wants to enter-------
	cout << "How many questions would your like to input?" << endl;
	cin >> numOfQuestions;
	cin.ignore(100, '\n');
	while(numOfQuestions > 10)
	{
		cout << "Please put in a number that is 10 or less..." << endl;
		cin >> numOfQuestions;
		cin.ignore(100, '\n');
	}

	for(int i = 1; i <= numOfQuestions; ++i)
	{
		cout << "Creating problem " << i << endl;
		createStruct(i, list[i]);
		writeToFile(list[i]);
	}
	//---------------------------------------------------------------
	while(endProg)
	{

		cout << "Which questions do you want to see? \nEnter a date, subject, or \"all\"" << endl;
		char subject[30];
		cin.get(subject, 30, '\n');
		getQuestionStruct(subject);
		cout << "Do you want to see more questions? <y/n>" << endl;
		char input;
		cin >> input;
		cin.ignore(100, '\n');
		if(input == 'n')
			endProg = false;
	}
	cout << "Thanks for using the program!" << endl;
	return 0;
}
void createStruct(int questionNumber, Question & list)
{
	list.questionNumber = questionNumber;

	cout << "What is the subject: ";
	cin.get(list.subject, SUBSIZE, '\n');
	cin.ignore(100, '\n');

	cout << "What is the date you are writing this: ";
	cin.get(list.date, 11, '\n');
	cin.ignore(100,'\n');

	cout << "Please enter the question now: " << endl;
	cin.get(list.questionText, QUESTSIZE, '\n');
	cin.ignore(QUESTSIZE, '\n');
}
void displayStruct(Question & question)
{
	cout << "Date: " << question.date
		<< "\nSubject: " << question.subject
		<< "\nQUestion: " << question.questionText << endl;

}
void displayStructQuestion(Question & question)
{
	cout << question.questionText << endl << endl;
}




// VERY high iq qay of getting shit from the file
void getQuestionStruct(char subject[])
{
	Question question;
	ifstream infile;
	infile.open("question.txt");
	if(infile)
		infile.peek();
	else
		cerr << "Couldn't open file..." << endl;
	while(!infile.eof())
	{
		infile.get(question.date, 11, '|');
		infile.ignore(1000, '|');

		infile.get(question.subject, 100, '|');
		infile.ignore(1000, '|');

		infile.get(question.questionText, QUESTSIZE, '|');
		infile.ignore(1000, '\n');
		if(strcmp(subject, question.subject) == 0 || strcmp(subject, question.date) == 0 || strcmp(subject, "all") == 0)
			displayStructQuestion(question);
	}



}










/*      VERY LOW IQ VERSION OF GETTING SHIT FROM THE FILE...... works like 35% of the time
	void displayQuestion(char subject[])
	{	
	char date[11];
	char compare[30];
	char question[QUESTSIZE];
	ifstream infile;
	infile.open("question.txt");
	if(infile)
	{
	infile.peek();
//cout << "Date:" << date << endl;
//infile.ignore(100, '|');
}
else
cerr << "Trouble reading from file..." << endl;
//int count = 0;
while(!infile.eof())
{
//cout << count << endl;
infile.get(compare, 31, '|');
infile.ignore(100, '|');
cout << "Our compare string: " << compare << endl;
//cout << "What we want our compare to be: " << subject << endl;
if(strcmp(subject, compare) == 0)
{
cout << "Key: " << subject << endl << "Compare: " << compare << endl;
//infile.ignore(100, '|');
infile.get(question, QUESTSIZE, '|');	
infile.ignore(100, '|');
cout << "Our question: " << question << endl;
}
//++count;
}

}
*/
void writeToFile(Question & question)
{
	ofstream out;

	out.open("question.txt", ios::app);
	if(out)
	{
		cout << "Connected to file... " << endl;
		cout << "Oreder will be | Date | Subject | Body of question | " << endl;		
		out 
			<< question.date << "|"
			<< question.subject << "|"
			<< question.questionText << "|\n";
	}
	else
		cerr << "Error writing to file..." << endl;
	out.close();
	out.clear();
}
