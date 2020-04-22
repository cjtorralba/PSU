#include "email.h"



//============================Email constructos and functions =======================
email::email() : title(), subject(NULL), body(NULL), sender(NULL), recipiant(NULL), timeSent(0) {}

email::email(const email & toCopy) : title(toCopy.name, toCopy.date), body(toCopy.body), sender(toCopy.sender), recipiant(toCopy.recipiant), timeSent(toCopy.timeSent) {}

email::email(char* name, char* date, char* subject, char* body, char* sender, char* recipiant, double timeSent) 
	: title(name, date)
{
	this->subject = new char[strlen(subject) + 1];
	this->body = new char[strlen(body) + 1];
	this->sender = new char[strlen(sender) + 1];
	this->recipiant = new char[strlen(recipiant) + 1];

	strcpy(this->subject, subject);
	strcpy(this->body, bode);
	strcpy(this->sender, sender);
	strcpy(this->recipiant, recipiant);
}

void email::display()
{
	title::display();
	cout << "Sender: " << sender << endl
		<< "Recipiant: " << recipiant << endl
		<< "Time sent: " << timeSent << endl
		<< "Subject: " << subject << endl
		<< "Body: " << body << endl;
}







//===============Essay constructors and functions=================

essay::essay() : title(), body(NULL), dueDate(NULL), wordLength(0) { }


essay::essay(char* name, char* date, char* body, char* dueDate, int wordLength) 
	: title(name, date)
{
	this->body = new char[strlen(body) + 1];
	this->dueDate = new char[strlen(dueDate) + 1];

	strcpy(this->body, body);
	strcpy(this->dueDate, dueDate);
}

essay::essay(const essay & toCopy) : title(toCopy.name, toCopy.date), body(toCopy.body), dueDate(toCopy.dueDate), wordLength(toCopy.wordLength) {}


void essay::display()
{
	title::display();
	cout << "Due date: " << dueDate << endl
		<< "Length: " << wordLength << " words" << endl
		<< "Body: " << body << endl;
}
