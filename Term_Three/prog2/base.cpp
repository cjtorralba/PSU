#include "base.h"

//default constructor with no arguments using initialization list
base::base() : activityLength(-1), priority(-1), group(false), name(NULL), location(NULL) {}

//copy constructor, copying any dynamically allocated memoery
base::base(const base & toCopy) : activityLength(toCopy.activityLength), priority(toCopy.priority), group(toCopy.group)
{
	this->name = new char[strlen(toCopy.name) + 1];
	strcpy(this->name, toCopy.name);

	this->location = new char[strlen(toCopy.location) + 1];
	strcpy(this->location, toCopy.location);
}


//constructor when given the data members as arguments
base::base(int length, int priority, bool group, char* name, char* location) : activityLength(length), priority(priority), group(group)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->location = new char[strlen(location) + 1];
	strcpy(this->location, location);
}

//destructor deleteing any dynamic memoery
base::~base()
{
	if(this->location && this->name)
	{
	delete [] this->location;
	delete [] this->name;
	}

	this->name = NULL;
	this->location = NULL;
}



//display function
void base::display()
{
	cout << "Name: " << name << endl
		<< "Location: " << location << endl
		<< "Length: " << activityLength << " hours" << endl
		<< "Priority: " << priority << endl;
	if(group)
		cout << "Group Activity" << endl;
	else
		cout << "Not a group activity" << endl;
}

//returns prioprity
int base::getPriority()
{
	return priority;
}
