#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;



class base
{
	public:
		base();		~base();
		base(int actLength, int priority, bool group, char* name, char* location);
		base(const base& toCopy);

		virtual void display() = 0;
		virtual char* getName() { return name; }

		int getPriority();

	private:
		int activityLength;
		int priority;
		bool group;
		char* name;
		char* location;

};
