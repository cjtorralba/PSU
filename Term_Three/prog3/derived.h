#include "base.h"


class website : public base
{
	public:
		website();	~website();
		website(char priority, char* subject, char* link);
		website(const website& toCopy);

		void display();

		void writeToFile();


	private:
		char* link;
};


class zoom : public base
{
	public:
		zoom();		~zoom();
		zoom(char priority, char* subject, char* teacher, char* time, char* id);
		zoom(const zoom& toCopy);

		void display();


		void writeToFile();
	private:
		char* teacher;
		char* time;
		char* id;
};


class book : public base
{
	public:
		book();		~book();
		book(char priority, char* subject, char* pages, char* author, char* title);
		book(const book& toCopy);


		void display();
		void writeToFile();

	private:
		char* pages;
		char* author;
		char* title;
};




