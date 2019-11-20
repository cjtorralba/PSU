
#include "prog4.h"
using namespace std;

int  main()
{

	int count;
	char viewFile, exitVal;
	bool exit = true;
	cout << "How many questions do you want to enter: " << endl;
	cin >> count;
	cin.ignore(100, '\n');
	List list(count);
	for(int i = 0; i < count; ++i)	
	{
		list.initQuestion(i);
		list.write(i);
	}

	cout << "Would you like to access the questions in the file? <y/n>" << endl;
	cin >> viewFile;
	cin.ignore(100, '\n');
	if(viewFile == 'y')
		list.initFileList();

	char input[21];
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

	cout << "\nThank you for running the program..." << endl;

	return 0;
}
