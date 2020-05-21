#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;


//base class holding information that is necessary for all the children
class base
{
	public:
		base();		~base();	// constructors and destructors
		base(char* subject, char priority);
		base(const base& toCopy);

		void display();	//display function

		char getPriority(){ return priority; }	//returns the priority which is a charaxcter

		void writeToFile(ofstream& out);	//writes to file, taking a ofstream object as an argument, I dont know why but it works for some reason

	private:
		char* subject;	//subjcet of the object
		char priority;	//priority from 0-9 0 being most important
};
