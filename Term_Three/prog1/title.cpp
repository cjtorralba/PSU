#include "title.h"

//====================Title functions and contructors================================

title::title() : name(NULL), date(NULL)	{} 	//constructor with no data given to us so we will set it to NUL

title::title(char* name, char* date)
{
	this->name = new char[strlen(name) + 1];
	this->date = new char[strlen(date) + 1];

	strcpy(this->name, name);
	strcpy(this->date, date);
} //constructor when we are given the data we need to work with

title::title(const title & toCopy) 	//copy constructor
{
	cout << "Title copy constructor called" << endl;
	if(toCopy.name)
	{
		name = new char[strlen(toCopy.name) + 1];
		strcpy(name, toCopy.name);
	}
	if(toCopy.date)
	{
		date = new char[strlen(toCopy.date) + 1];
		strcpy(date, toCopy.date);
	}
}

title::~title()
{
	cout << "Call title destructor" << endl;
	delete [] name;
	delete [] date;

	name = NULL;
	date = NULL;
}


void title::display()
{
	if(name)
		cout << "Name: " << name << endl;		
	if(date)
		cout << "Date: " << date << endl;
}

void title::changeTitle(char* name, char* date)
{
	if(this->name)	//checking to see if the name has already been set first
	{
		delete [] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	if(this->date)	//checking to see if the date has been set already
	{

		delete [] this->date;
		this->date = new char[strlen(date) + 1];
		strcpy(this->date, date);
	}
	else
	{
		this->date = new char[strlen(date) + 1];
		strcpy(this->date, date);
	}
}


void title::changeTitle(const title & toChange)
{
	if(this->name)	//checking to see if the name has already been set first
	{
		delete [] this->name;
		this->name = new char[strlen(toChange.name) + 1];
		strcpy(this->name, toChange.name);
	}
	else
	{
		this->name = new char[strlen(toChange.name) + 1];
		strcpy(this->name, toChange.name);
	}

	if(this->date)	//checking to see if the date has been set already
	{

		delete [] this->date;
		this->date = new char[strlen(toChange.date) + 1];
		strcpy(this->date, toChange.date);
	}
	else
	{
		this->date = new char[strlen(toChange.date) + 1];
		strcpy(this->date, toChange.date);
	}
}


void title::setTitleName(char* name)
{
	if(this->name && name)	//checking to see if the name has already been set first
	{
		delete [] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else if(!this->name && name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void title::setTitleDate(char* date)
{
	if(this->date)	//checking to see if the date has been set already
	{

		delete [] this->date;
		this->date = new char[strlen(date) + 1];
		strcpy(this->date, date);
	}
	else
	{
		this->date = new char[strlen(date) + 1];
		strcpy(this->date, date);
	}
}





//=================================Video function and constructors==================================


video::video() : description(NULL) {}


video::video(char* name, char* date, char* description, double length) : title(name, date), length(length) 
{
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

video::video(const video & toCopy) : title(toCopy)
{
	description = new char[strlen(toCopy.description) + 1];
	strcpy(description, toCopy.description);

	length = toCopy.length;
}	



video::~video()
{
	delete [] description;
	description = NULL;
}



void video::display()
{
	title::display();
	cout << "Description: " << this->description << endl << 
		"Length: " << this->length << endl;
}


//====================Live stream functions and constructors==============================


liveStream::liveStream() : video(), instructor(NULL), topic(NULL) { }

liveStream::liveStream(char* name, char* date, char* description, double length, char* instructor, char* topic) 
	: video(name, date, description, length)
{
	this->instructor = new char[strlen(instructor) + 1];
	this->topic = new char[strlen(topic) + 1];

	strcpy(this->instructor, instructor);
	strcpy(this->topic, topic);
}

liveStream::~liveStream()
{
	delete [] instructor;
	delete [] topic;

	instructor = NULL;
	topic = NULL;
}

void liveStream::display()
{
	video::display();

	cout << "Instructor: " << this->instructor << endl
		<< "Topic: " << this->topic << endl;
}


