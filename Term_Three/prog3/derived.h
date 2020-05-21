#include "base.h"

//header file with derived classes and their fucntions



//webstie class
class website : public base
{
	public:
		//constructoprs and destructors
		website();	~website();
		website(char priority, char* subject, char* link);
		website(const website& toCopy);

		void display();	//displays infromation

		void writeToFile();	//writes to fiel


	private:
		char* link;	//one data members which is the link to the website
};

//zoom meeting class
class zoom : public base
{
	public:
		//constructors and destrcutctos
		zoom();		~zoom();
		zoom(char priority, char* subject, char* teacher, char* time, char* id);
		zoom(const zoom& toCopy);

		void display();	//displays information


		void writeToFile();	//writes information tot he file
	private:
		//data members which include the teacher leading the lecture, the time the meeting starts, and the meeting id
		char* teacher;
		char* time;
		char* id;
};

//book class
class book : public base
{
	public:
		//constructors and destructos
		book();		~book();
		book(char priority, char* subject, char* pages, char* author, char* title);
		book(const book& toCopy);


		void display();	//displays information
		void writeToFile();	//writes to file

	private:
		//data members
		char* pages;
		char* author;
		char* title;
};




