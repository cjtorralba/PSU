#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;



class base
{
	public:
		base();		~base();	//constructors and destructors
		base(int actLength, int priority, bool group, char* name, char* location);
		base(const base& toCopy);

		virtual void display() = 0;	//virtual functions
		virtual char* getName() { return name; }	//returns the name for easier strcmp

		int getPriority();		//returns the priority

	private:
		int activityLength;	//lenght of the activity in hours`
		int priority; 		//priority of the activity from one to ten, one being you want to do it immediatly
		bool group;		//true = is a group activity		false = not a group activity 
		char* name;		//name of the activity
		char* location;		//location of the acticity

};
