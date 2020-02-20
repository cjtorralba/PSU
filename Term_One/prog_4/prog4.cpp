#include "prog4.h"
Question::Question()
{
	subject[0] = '\0';
	date[0] = '\0';
	body[0] = '\0';
}
void Question::display()
{
	cout 
		<< "Date: " << date
		<< "\nSubject: " << subject
		<< "\nQuestion: " << body << endl;
}


void Question::write()
{
	ofstream out;
	out.open("question.txt", ios::app);
	if(out)
	{
		out 
			<< date << "|" 
			<< subject << "|"
			<< body << "|\n";
	}
}



void Question::initQuestion()
{
	cout << "Date: ";
	cin.get(date, 11, '\n');
	cin.ignore(100, '\n');

	cout << "\nSubject: ";
	cin.get(subject, 21, '\n');
	cin.ignore(100, '\n');

	cout << "\nQuestion: ";
	cin.get(body, 140, '\n');
	cin.ignore(1000, '\n');
}

List::List(int length)
{
	question = new Question[length];
	fileList = NULL;
	lines = 0;
	char temp[300];
	ifstream in;
	in.open("question.txt");
	if(in)
		in.peek();
	else
		cerr << "Couldn't open file..." << endl;
	while(getline(in, temp))
		++lines;
	fileList = new question[lines];
		for(int i = 0; !in.eof(); ++i)
		{
			in.get(fileList[i].date, 11, '|');
			in.ignore(100, '|');

			in.get(fileList[i].subject, 21, '|');
			in.ignore(100, '|');

			in.get(fileList[i].body, 140, '|');
			in.ignore(140, '\n');

		}	
	fileList[0].display();	
}















