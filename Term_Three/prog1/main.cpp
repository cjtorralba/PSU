#include "node.h"




int main()
{



	cout << "TESTING LEARNING OBJECTS" << endl;
/*
	title first("christian", "7/26/2001");
	first.display();

	cout << endl << endl << "=======================" << endl << endl;
*/

	video second("jorge", "12/23/1963", "this is a description", 12.32);
	second.display();
	

	cout << endl << endl << "=======================" << endl << endl;


	liveStream third("lindsay", "12/13/1963", "this is the second description", 526.123, "karla fant", "computer science");
	third.display();


	cout << endl << endl << "=======================" << endl << endl;

	email firstEmail("lizzie", "8/24/1998", "subject isdasdlfkjasdl;fk", "poopy body", "Christian torralba", "lizzie torralba", 9.40);
	firstEmail.display();


	cout << endl << endl << "=======================" << endl << endl;

	essay firstEssay("karen", "3/14/2001", "essay body", "Due tommorow", 739);
	firstEssay.display();



	cout << endl << endl << "=======================" << endl << endl;
	cout << endl << endl << "=======================" << endl << endl;
/*
	cout << "NODE TESTING" << endl << endl;
	
		nodeAdd.displayNode();


	cout << endl << endl << "=======================" << endl << endl;
	cout << endl << endl << "=======================" << endl << endl;

	*/



	node* nodeAdd;
	table LLL;


	cout << "==================table testing===================" << endl;

	nodeAdd = new node();
	nodeAdd->addVideo(second);


	LLL.addNode(*nodeAdd);



	delete nodeAdd;
	nodeAdd = new node();
	nodeAdd->addEssay(firstEssay);	

	LLL.addNode(*nodeAdd);


	LLL.displayAll();








	return 0;
}
