#include <iostream>
#include <fstream>
using namespace std;

class Question
{
	public:
		Question();
//		~Question();
		void initQuestion();
		void write();	
		void display();
	private:
	
		char* subject;
		char* body;
		char* date;


};
class List
{
	public:
		List(int length);
		//~List();
		void read();
		int lines;
	private:
		Question* fileList;
		Question* question;

};
