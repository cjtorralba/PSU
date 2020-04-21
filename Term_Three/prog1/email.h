#include "title.h"

class email : public title
{
	public:
		email();	//~email();
		email(const email & toCopy);
		

		email(char* name, char* date, char* subject, char* body, char* sender, char* recipiant, double timeSent);

		void display();



	protected:
		char*    subject;
		char* 	    body;
		char*     sender;
		char*  recipiant;
		double  timeSent;
};









class essay : public title
{
	public:
		essay();	//~essay();
		essay(char* name, char* date, char* body, char* dueDate, int wordLength);
		essay(const essay & toCopy);

		void display();



	protected:
		char*     body;
		char*  dueDate;
		int wordLength;





};



