#include "title.h"

class email : public title
{
	public:
		//contructors and destructor
		email();	~email();
		email(const email & toCopy);
		email(char* name, char* date, char* subject, char* body, char* recipiant, double timeSent);

		//display function
		void display();

	protected:
		char*    subject;	//subject of an email
		char* 	    body;	//actual message the email will hold
		char*  recipiant;	//who is recieving this email
		double  timeSent;	//the time the email was sent
};


class essay : public title
{
	public:
		//constructors and destructor
		essay();	~essay();
		essay(char* name, char* date, char* body, char* dueDate, int wordLength);
		essay(const essay & toCopy);

		//display functions
		void display();

	protected:
		char*     body;	//actual paper
		char*  dueDate;	//due date
		int wordLength;	//length of paper 





};



