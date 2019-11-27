#include "prog4.h"		
//Question contructor, initializes all arrays to \0
Question::Question()
{
	subject[0] = '\0'; 
	questionBody[0] = '\0';
	date[0] = '\0';
}




//Compares and displays question if the date, or subject is equal to input
void Question::compare(char word[])
{
	if(strcmp(word, date) == 0 || strcmp(word, subject) == 0 || strcmp(word, "all") == 0)
		display();
}




//-----------This method uses user input to initilaize a question------------
void Question::initQuestion()
{
	cout << "Enter date please dd/mm/yyyy: ";
	cin.get(date, 11, '\n');
	cin.ignore(1000, '\n');

	cout << "Subject: ";
	cin.get(subject, 21, '\n');
	cin.ignore(1000, '\n');

	cout << "Please enter the question itself:\n";
	cin.get(questionBody, 140, '\n');
	cin.ignore(1000, '\n');
}
//----------------This method is specifically for when we are getting questions from the file-----------
void Question::initQuestion(char Date[], char Subject[], char Body[])
{
	strcpy(date, Date);
	strcpy(subject, Subject);
	strcpy(questionBody, Body);
}
//--------Displays date, subject, and quesion------------
void Question::display()
{
	cout 
		<< "\nDate: " << date
		<< "\nSubject: " << subject
		<< "\nQuestion: " << questionBody << endl;
}
//--------Writes question to file in order       date | subject | questionBody |\n 
void Question::writeToFile()
{
	ofstream out;
	out.open("question.txt", ios::app);
	if(out)
	{
		out
			<< date << "|"
			<< subject << "|"
			<< questionBody << "|\n";
	}
	else
		cerr << "Could not open or write to file..." << endl;
}
//-----Constructor--------
List::List()
{
	list = NULL;
	fileList = NULL;
	arrayLength = 0;
	fileLength = 0;
}


//---------Accesses question at sepcific index in the lis and runs the writeToFile method on it--------
void List::write(int index)
{
	list[index].writeToFile();
}

//Compares questions in both the regular list and fileList
void List::compare(char word[])
{
	if(fileList == NULL)
	{
		for(int i = 0; i < arrayLength; ++i)
			list[i].compare(word);
	}
	else
	{
		for(int i = 0; i < fileLength; ++i)
			fileList[i].compare(word);
	}
}


//---------Initializes the list, with a set length for how many questions the user wants to input---
void List::init(int length)
{
	if(length > 0)
		list = new Question[length];
	else
		list = NULL;
}
//List destructor
List::~List()
{
	delete [] list;
	delete [] fileList;
	list = NULL;
	fileList = NULL;
	arrayLength = 0;
	fileLength = 0;
}

//------------This initiliazes the list of the questions from the file, should they choose to---------
void List::initFileList()
{
	ifstream in;
	in.open("question.txt");
	if(in)
		in.peek();
	else
	{
		cerr << "Couldn't open file..." << endl;
		return;
}
	while(!in.eof())
	{

		char line[300];
		in.get(line, 300, '\n');
		in.ignore(300, '\n');

		if(line[0] != '\0')
			++fileLength;
	}
	//	cout << fileLength << " lines in the file..." << endl;
	fileList = new Question[fileLength];
	in.close();
	in.open("question.txt");
	for(int i = 0; i < fileLength; ++i)
	{
		char date[11];
		char subject[21];
		char body[140];

		in.get(date, 11, '|');
		in.ignore(100, '|');

		in.get(subject, 21, '|');
		in.ignore(100, '|');

		in.get(body, 140, '|');
		in.ignore(200, '\n');

		fileList[i].initQuestion(date, subject, body);
	}
}

//-----Initializes the question at whatever index you want, runs initQuestion on the question object....
void List::initQuestion(int index)
{
	list[index].initQuestion();
	++arrayLength;
}
bool List::hasQuestions()
{
	return !(fileList == NULL && list == NULL);
}


