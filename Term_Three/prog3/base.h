#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;



class base
{
	public:
		base();		~base();
		base(char* subject, char priority);
		base(const base& toCopy);

		void display();

		char getPriority(){ return priority; }

		void writeToFile(ofstream& out);

	private:
		char* subject;
		char priority;
};
