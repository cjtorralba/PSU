/* Code by christian torralba...assignment number 3 for CS162
 * purpose of this program is toask the user to input questions they want to store later to practice
 * this mainly uses structures and functions to display the structures, creating them locally from the text file
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
	char subject[SUBSIZE]; // this is the subject of our question, loops, stucts, files, etc...
	char questionText[QUESTSIZE];// this is the acutal question itself
	char date[11]; //dates are usually a set size already..
};


//------Prototypes--------
//functions explained where they are written 
//prototypes are pretty stright forward
void writeToFile(Question & question);
void createStruct(Question &list);
void displayQuestion(char subject[]);
void getQuestionStruct(char subject[]);
void displayStruct(Question & question);
void displayStructQuestion(Question & question);//for testing only...
//--------Fuctions---------
int main()
{
	int numOfQuestions;//numbers of questions the user wants to input, required for our for loop
	Question list[numOfQuestions];//our array of questions, 
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
		createStruct(list[i]);
		writeToFile(list[i]);
	}
	//---------------------------------------------------------------

	//--------This is the loop where the user is asked what questions they want to see---
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

//this function is called in our for loop and edits the desired struct at the current index
void createStruct(Question & list)
{

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


//This displays the quetion by passing in the current struct that contains a question
void displayStruct(Question & question)
{
	if(question.date[0] != '\0')
	{
		//cout << strlen(question.date) << endl;
		cout << "\nDate: " << question.date
			<< "\nSubject: " << question.subject
			<< "\nQuestion: " << question.questionText << endl;
	}
}

//this just displays question text for testing purposes
void displayStructQuestion(Question & question)
{
	cout << question.questionText << endl << endl;
}



//Much more improved way of getting the question from text file,
//done by creating a struct of the question on that line, then displaying it if 
//it matches a set criteria
void getQuestionStruct(char subject[])
{
	Question question;// the local struct we will be using to display the questions
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
		if(strcmp(subject, question.subject) == 0 || strcmp(subject, question.date) == 0 
				|| strcmp(subject, "all") == 0)
			displayStruct(question);
	}



}

//This is our function that writes our desired question to our test file
//does it in the order of        "| Date | Subject | Body of question | \n"
void writeToFile(Question & question)
{
	ofstream out;

	out.open("question.txt", ios::app);
	if(out)
	{
		//cout << "Connected to file... " << endl;
		//cout << "Order will be | Date | Subject | Body of question | " << endl;		
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







//Don't even look at this it's not worth your time...

/*      VERY LOW IQ VERSION OF GETTING SHIT FROM THE FILE...... works like 35% of the time
 *      this was a horrible way and it should never be used -_-
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






















