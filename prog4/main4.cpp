/* Code by christian Torralba
 * program assignment number 4 for cs162
 * this program is an object oriented version of program number 3
 * purpose is to get practice questions you may want to use in the future
 * and store them into a file, then you may request specific questions
 */







#include "prog4.h"
using namespace std;

int  main()
{

	char input[21]; //our inputfor questions the user wants to get
	int count;  //what we will be initializing the array of questions to
	char viewFile, exitVal; //if they want to view questions in the file or not, and an exit statement for main loop
	bool exit; //our exit boolean for main loop
	List list; // our list object


	cout << "How many questions do you want to enter: " << endl;
	cin >> count;
	cin.ignore(100, '\n');
	list.init(count); //Initializing list to count size
	for(int i = 0; i < count; ++i)	
	{
		list.initQuestion(i);
		list.write(i);
	}

	cout << "Would you like to access the questions in the file too? <y/n>" << endl;
	cin >> viewFile;
	cin.ignore(100, '\n');
	if(viewFile == 'y')
		list.initFileList();


	exit = list.hasQuestions();//checking to see if either list even has questions

	if(!list.hasQuestions())
		cout << "No quetions to display! Please run again and enter some..." << endl;


	while(exit)
	{
		cout << "What question do you want to see, enter a date, subject, or \"all\" to display all questions. " << endl;
		cin.get(input, 21, '\n');
		cin.ignore(1000, '\n');
		list.compare(input);
		cout << "\nWould you like to see more questions? <y/n>" << endl;
		cin >> exitVal;
		cin.ignore(100, '\n');
		if(exitVal == 'n')
			exit = false;	
	}
	//	delete list;	

	cout << "\nThank you for running the program..." << endl;

	return 0;
}
