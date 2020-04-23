#include "email.h"



//============================Email constructos and functions =======================
//
//defualt constructor
email::email() : title(), subject(NULL), body(NULL), recipiant(NULL) {}



//copy constructor, calls title copy constructor as well
email::email(const email & toCopy) : title(toCopy), timeSent(toCopy.timeSent)
{
	this->subject = new char[strlen(toCopy.subject) + 1];
	this->body = new char[strlen(toCopy.body) + 1];
	this->recipiant = new char[strlen(toCopy.recipiant) + 1];

	strcpy(this->subject, toCopy.subject);
	strcpy(this->body, toCopy.body);
	strcpy(this->recipiant, toCopy.recipiant);
}

//constructor when given information
	email::email(char* name, char* date, char* subject, char* body,  char* recipiant, double timeSent) 
: title(name, date), timeSent(timeSent)
{
	this->subject = new char[strlen(subject) + 1];
	this->body = new char[strlen(body) + 1];
	this->recipiant = new char[strlen(recipiant) + 1];

	strcpy(this->subject, subject);
	strcpy(this->body, body);
	strcpy(this->recipiant, recipiant);
}


//email destructor
email::~email()
{
	delete [] subject;
	delete [] body;
	delete [] recipiant;

	subject = body = recipiant = NULL;
}


//diaply  function to cout all the information
void email::display()
{
	title::display();
		cout << "Recipiant: " << recipiant << endl
		<< "Time sent: " << timeSent << endl
		<< "Subject: " << subject << endl
		<< "Body: " << body << endl;
}




//===============Essay constructors and functions=================


//default constructor for the essay class
essay::essay() : title(), body(NULL), dueDate(NULL), wordLength(0) { }

//constructor when given information
essay::essay(char* name, char* date, char* body, char* dueDate, int wordLength) 
: title(name, date), wordLength(wordLength)
{
	this->body = new char[strlen(body) + 1];
	this->dueDate = new char[strlen(dueDate) + 1];

	strcpy(this->body, body);
	strcpy(this->dueDate, dueDate);
}


//copy constructor
essay::essay(const essay & toCopy) : title(toCopy.name, toCopy.date), wordLength(toCopy.wordLength)
{
	body = new char[strlen(toCopy.body) + 1];
	dueDate = new char[strlen(toCopy.dueDate) + 1];

	strcpy(body, toCopy.body);
	strcpy(dueDate, toCopy.dueDate);
}

//essay class destructor
essay::~essay()
{
	delete [] body;
	delete [] dueDate;

	body = dueDate = NULL;
}


//essay display fucntion
void essay::display()
{
	title::display();
	cout << "Due date: " << dueDate << endl
		<< "Length: " << wordLength << " words" << endl
		<< "Body: " << body << endl;
}
