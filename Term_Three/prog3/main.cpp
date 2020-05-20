#include "tree.h"


int main()
{
	tree BST;
	node toAdd;

	book* myBook;
	website* myWeb;
	zoom* myZoom;

	base* myBase;

	myWeb = new website('3', "bubject", "www.google.com");
	myWeb->display();

	cout << endl << endl;

//	myWeb->writeToFile();

//	myBook = new book('1', "first book", 200, "christian torralba", "like a bitch");
//	myBook->writeToFile();

	BST.getFromFile();



//book(int priority, char* subject, int pages, char* author, char* title) 
/*
//

	toAdd.addBook(*myBook);


//	toAdd.display();

	BST.addNode(toAdd);
	

	BST.display();
*/	

	return 0;
}
