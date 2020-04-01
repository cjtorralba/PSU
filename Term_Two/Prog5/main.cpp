#include "header.h"

bool again()
{
	char input;
	cout << "Would you like to enter again? <y,n> " << endl;
	cin >> input;	cin.ignore(100, '\n');

	return input == 'y';
}


int main()
{


	graph myGraph;	//graph object

	myClass toEnter;	//class object for entering things
	char name[100];		//user input

	char connect[100];	//user input

	char input;	//for the switch case

	do
	{
		cout << "=======================" << endl;
		cout << "1: Add a class" << endl;
		cout << "2: Add a pre-req to this class" << endl;
		cout << "3: View what courses you can take after a current one" << endl;
		
		cin >> input;	cin.ignore(100, '\n');

		switch(input)
		{
			case '1':
				cout << "Please enter the name of the class: " << endl;
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');
				toEnter.name = name;

				myGraph.insertVertex(&toEnter);
				break;

			case '2':
				cout << "Please enter the class before the pre req" << endl;
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');

				cout << "Now please enter the pre req" << endl;
				cin.get(connect, 100, '\n');	cin.ignore(100, '\n');

				myGraph.insertEdge(name, connect);
				break;

			case '3':
				cout << "Please enter the class you wish to see" << endl;
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');
				myGraph.traverse(name);

				break;


			default:
				break;



		}






	}while(again());



	return 0;
}
