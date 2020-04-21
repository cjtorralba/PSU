#include "title.h"

//====================Title functions and contructors================================

title::title() : name(NULL), date(NULL)	{} 	//constructor with no data given to us so we will set it to NUL

title::title(char* name, char* date) : name(name), date(date) {} //constructor when we are given the data we need to work with

title::title(const title & toCopy) : name(toCopy.name), date(toCopy.date) {}

int title::sumCharName()
{
	int sum;
	int length = strlen(this->name);
	for(int i = 0; i < length; ++i)
		sum += this->name[i];
	return sum;
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


video::video(char* name, char* date, char* description, double length) : title(name, date), description(description), length(length) {}

video::video(const video & toCopy) : title(toCopy), description(toCopy.description), length(toCopy.length) {}



void video::display()
{
	title::display();
	cout << "Description: " << this->description << endl << 
		"Length: " << this->length << endl;
}


//====================Live stream functions and constructors==============================


liveStream::liveStream() : video(), instructor(NULL), topic(NULL) { }

liveStream::liveStream(char* name, char* date, char* description, double length, char* instructor, char* topic) :
	video(name, date, description, length), instructor(instructor), topic(topic) {}	



void liveStream::display()
{
	video::display();

	cout << "Instructor: " << this->instructor << endl
		<< "Topic: " << this->topic << endl;
}


//liveStream::liveStream(const title & title, const video & video, char* instructor, char* topic) :
//	title(title), video(video), instructor(instructor), topic(topic) {}






