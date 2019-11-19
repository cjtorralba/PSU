#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;







class Question
{

	public:
		Question(); //Contructor
		void writeToFile(); // writes question to file...
		void initQuestion(char Date[], char Subject[], char Body[]); // initilaizes question without user input
		void initQuestion(); // initiliazes question WITH user input
		void display();// Displays question date, subject, and body
		void compare(char word[]);// compares question to input, either a date, subject, or "all"
	private:
		char subject[21]; // Our subject, ex: loops, files, linked lists...
		char questionBody[140];// question itself..
		char date[11];//the date of the question
};



class List
{
	public:
		List(int length); //Constructor, taking in an int as an argument to create dynamic array
		~List();//destructor
		void initQuestion(int index);//initiliazes question at x index, using the Question initQuestion();
		void initList(); //initiliazes list that the user will enter questions to
		void initFileList(); //initializes list of questions from external file should they want to view them
		void write(int index); // writes question at index x to external file
		void compare(char word[]);//compares using, the compare in the Question class


	private:
		Question* list; // pointer to list for questions the user will enter
		Question* fileList;// pointer to list for the questions from the external file
		int arrayLength; // length of list for input from user
		int fileLength;// amount of lines in the file, necessary for making the fileList of questions from file
};



