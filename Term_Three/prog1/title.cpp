#include "title.h"

//====================Title functions and contructors================================

title::title() : name(NULL), date(NULL)	{} 	//constructor with no data given to us so we will set it to NUL


//constructor when we are given the information via arguments
title::title(char* name, char* date)
{
	this->name = new char[strlen(name) + 1];
	this->date = new char[strlen(date) + 1];

	strcpy(this->name, name);
	strcpy(this->date, date);
} //constructor when we are given the data we need to work with

title::title(const title & toCopy) 	//copy constructor
{
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


//title destructor destroys dynamic memebersj
title::~title()
{
	delete [] name;
	delete [] date;

	name = NULL;
	date = NULL;
}

//display functions displays the name and date
void title::display()
{
	if(name)
		cout << "Name: " << name << endl;		
	if(date)
		cout << "Date: " << date << endl;
}

//a change title function 
//I will probably not include this in main

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



//default constructor
video::video() : description(NULL) {}

//constructor when we are given the information via arguments
video::video(char* name, char* date, char* description, double length) : title(name, date), length(length) 
{
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

//copy constructor calls title copy contructor as well using
//initialization list
video::video(const video & toCopy) : title(toCopy)
{
	description = new char[strlen(toCopy.description) + 1];
	strcpy(description, toCopy.description);

	length = toCopy.length;
}	

//video destructor
video::~video()
{
	delete [] description;
	description = NULL;
}


//display function calls title display function and 
//also displays description and length
void video::display()
{
	title::display();
	cout << "Description: " << this->description << endl << 
		"Length: " << this->length << endl;
}


//====================Live stream functions and constructors==============================

//default constructor
liveStream::liveStream() : video(), instructor(NULL), topic(NULL) { }

//copy contructor calls parent copy constructor for parent members
liveStream::liveStream(const liveStream& toCopy) : video(toCopy)
{
	this->instructor = new char[strlen(toCopy.instructor) + 1];
	this->topic = new char[strlen(toCopy.topic) + 1];

	strcpy(this->instructor, toCopy.instructor);
	strcpy(this->topic, toCopy.topic);
}


//constructor when we are given the information
liveStream::liveStream(char* name, char* date, char* description, double length, char* instructor, char* topic) 
	: video(name, date, description, length)
{
	this->instructor = new char[strlen(instructor) + 1];
	this->topic = new char[strlen(topic) + 1];

	strcpy(this->instructor, instructor);
	strcpy(this->topic, topic);
}

//destructor
liveStream::~liveStream()
{
	delete [] instructor;
	delete [] topic;

	instructor = NULL;
	topic = NULL;
}


//display function where we call parents display which in turn calls
//the title display function as well
void liveStream::display()
{
	video::display();

	cout << "Instructor: " << this->instructor << endl
		<< "Topic: " << this->topic << endl;

	cout << "Done displaying stream" << endl;
}


