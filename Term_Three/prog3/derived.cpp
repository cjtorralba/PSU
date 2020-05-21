#include "derived.h"


//constructors and destructors
website::website() : link(NULL) {}

website::~website()
{
	if(link)
		delete [] link; link = NULL;
}


website::website(char priority, char* subject, char* link) : base(subject, priority)
{
	this->link = new char[strlen(link) + 1];
	strcpy(this->link, link);
}


website::website(const website& toCopy) : base(toCopy)
{
	if(toCopy.link)
	{
		this->link = new char[strlen(toCopy.link) + 1];
		strcpy(this->link, toCopy.link);
	}
}


//display functions displays all the data members and calls base class display function
void website::display()
{

	base::display();
	cout << "Link: " << link << endl;
	
}


//writes the information of the object to file then calls base class writeToFile()
void website::writeToFile()
{
	ofstream out;
	out.open("prog3.txt", ios::app);

	if(out)
	{
		out << "w|" << link;
		base::writeToFile(out);
	}
}


//zoom class constructors and destructors
zoom::zoom() : teacher(NULL), time(NULL), id(NULL) {}

zoom::~zoom()
{
	if(teacher)
		delete [] teacher;
	if(time)
		delete [] time;
	teacher = time = NULL;
}

zoom::zoom(char priority, char* subject, char* teacher, char* time, char* id) : base(subject, priority)
{
	this->teacher = new char[strlen(teacher) + 1];
	this->time = new char[strlen(time) + 1];
	this->id = new char[strlen(id) + 1];

	strcpy(this->teacher, teacher);
	strcpy(this->time, time);
	strcpy(this->id, id);
}

zoom::zoom(const zoom& toCopy) : base(toCopy), id(toCopy.id)
{
	if(toCopy.teacher)
	{
		this->teacher = new char[strlen(toCopy.teacher) + 1];
		strcpy(this->teacher, toCopy.teacher);
	}
	if(toCopy.time)
	{
		this->time = new char[strlen(toCopy.time) + 1];
		strcpy(this->time, toCopy.time);
	}
}



//writes the information of the object to file then calls base class writeToFile()
void zoom::writeToFile()
{

	ofstream out;
	out.open("prog3.txt", ios::app);

	if(out)
	{
		out
			<< "z|" << teacher
			<< "|" << time 
			<< "|" << id;
		base::writeToFile(out);
	}
}



//display functions displays all the data members and calls base class display function

void zoom::display()
{
	base::display();
	if(teacher && time)
		cout << "Teacher: " << teacher << endl << "Time: " << time << endl;
}


//book class construectors and destructors
book::book() : pages(NULL), author(NULL), title(NULL) {}

book::~book()
{
	if(author)
		delete [] author;
	if(title)
		delete [] title;
	if(pages)
		delete [] pages;
	title = author = pages = NULL;
}

book::book(const book& toCopy) : base(toCopy)
{
	if(toCopy.title)
	{
		this->title = new char[strlen(toCopy.title) + 1];
		strcpy(this->title, toCopy.title);
	}
	if(toCopy.author)
	{
		this->author = new char[strlen(toCopy.author) + 1];
		strcpy(this->author, toCopy.author);
	}
	if(toCopy.pages)
	{
		this->pages = new char[strlen(pages) + 1];
		strcpy(this->pages, toCopy.pages);
	}
}


book::book(char priority, char* subject, char* pages, char* author, char* title) : base(subject, priority)
{
	this->author = new char[strlen(author) + 1];
	this->title = new char[strlen(title) + 1];
	this->pages = new char[strlen(pages) + 1];

	strcpy(this->author, author);
	strcpy(this->title, title);
	strcpy(this->pages, pages);
}

//writes the information of the object to file then calls base class writeToFile()
void book::writeToFile()
{
	ofstream out;
	out.open("prog3.txt", ios::app);

	if(out)
	{
		out
			<< "b|" << pages 
			<< "|" << author 
			<< "|" << title;
		base::writeToFile(out);
	}
}




//display functions displays all the data members and calls base class display function
void book::display()
{
	base::display();
	if(author && title)
		cout << "Author: " << author << endl << "Title: " << title << endl << "Length: " << pages << " pages" << endl;

}







