#include "base.h"


//constructors and destructors
base::base() : subject(NULL) { }

base::~base()
{
	if(subject)
		delete [] subject;
	subject = NULL;
}

base::base(const base& toCopy) : priority(toCopy.priority)
{
	this->subject = new char[strlen(toCopy.subject) + 1];
	strcpy(this->subject, toCopy.subject);
}

base::base(char* subject, char priority) : priority(priority)
{
	this->subject = new char[strlen(subject) + 1];
	strcpy(this->subject, subject);
}


//displays information in the base class
void base::display()
{
	if(subject)
		cout << "Subject: " << subject << endl;
	cout << "Priority: " << priority << endl;

}

//writes to the given ofstream file
void base::writeToFile(ofstream& out)
{
	if(out)
	{
		out 
			<< "|" << subject 
			<< "|"  << priority << "|\n";
	}
	else
		cerr << "Couldnt write to file" << endl;
}

