#include "title.h"


class email : title
{
	public:
		email();	//~email();
		email(const email & toCopy);
		email(char* name, char* date, char* subject, char* body, char* sender, char* recipiant, double timeSent, bool containsVideo, const video & attached);

		void changeEmail(const email & toChange);


		void display();



	protected:
		char* subject;
		char* 	body;
		char* sender;
		char*  recipiant;

		double timeSent;
		bool containsVideo;
		class video & attached;
};









class essay : title
{
	public:
		essay();	//~essay();
		essay(char* author, char* dateWritten, char* body, char* dueDate, int wordLength);
		essay(const essay & toCopy);

		void display();



	protected:
		char* body, dueDate;
		int wordLength;





};
