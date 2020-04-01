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

	char input;





	graph myGraph;

	myClass first;
	first.name = "cs161";

	myClass second;
	second.name = "cs162";

	myClass third;
	third.name = "cs163";

	myClass fourth;
	fourth.name = "cs202";

	myGraph.insertVertex(&first);
	myGraph.insertVertex(&second);
	myGraph.insertVertex(&third);
	myGraph.insertVertex(&fourth);

	myGraph.insertEdge("cs161", "cs162");
	myGraph.insertEdge("cs161", "cs202");
	myGraph.insertEdge("cs161", "cs163");
	
	myGraph.traverse("cs161");

	myGraph.test(0);
/*
	do
	{
		cout << "=======================" << endl;
		cout << "1: Add a class" << endl;
		cout << "2: Add a pre-req to this class" << endl;
		cout << "3: View what courses you can take after a current one" << endl;
		







	}while(again());
*/



	return 0;
}
