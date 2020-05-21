#include "tree.h"
bool again()
{
	char input;
	cout << "Would you like to go again? <y,n>: ";
	cin >> input;	cin.ignore(100, '\n');	cout << endl;
	return input == 'y';
}

void help()
{
	cout << "Here are your options" << endl
		<< "1: Add a book" << endl
		<< "2: Add a zoom meeting" << endl
		<< "3: Add a website" << endl
		<< "4: Display all" << endl
		<< "5: See these options again" << endl;


}

int main()
{
	char input;

	tree BST;
	node* toAdd;

	book* myBook;
	website* myWeb;
	zoom* myZoom;
	
	
	char subject[100];
	char priority;

	char link[100]; // all the members for the website class

	//all the members for the book class
	char pages[100];
	char author[100];
	char title[100];

	//all the members for the zoom class
	char teacher[100];
	char time[100];
	char id[100];



	//start by populating the tree with information from the external file if there is one
	BST.getFromFile();

	help();

	do
	{
		cin >> input;	cin.ignore(100, '\n');
		switch(input)
		{
			case '1':
				cout << "Please enter the title of the book: ";
				cin.get(title, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Please enter the author of the book: ";
				cin.get(author, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Please enter the length in pages: ";
				cin.get(pages, 100, '\n');	cin.ignore(100, '\n'); 	cout << endl;

				cout << "Please enter the priority from <0-9> 0 being most important: ";
				cin >> priority;	cin.ignore(100, '\n');		cout << endl;

				cout << "Please enter the subject of this book: ";
				cin.get(subject, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				myBook = new book(priority, subject, pages, author, title);
				toAdd = new node();
				toAdd->addBook(*myBook);

				myBook->writeToFile();

				BST.addNode(*toAdd);

				delete myBook;
				delete toAdd;

				myBook = NULL;
				toAdd = NULL;

				break;

			case '2':
				cout << "Please enter the teacher for this zoom meeting: ";
				cin.get(teacher, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Please enter the time: ";
				cin.get(time, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "please enter the zoom meeting id: ";
				cin.get(id, 100, '\n');		cin.ignore(100, '\n');	cout << endl;

				cout << "Please enter the priority from <0-9> 0 being most important: ";
				cin >> priority;	cin.ignore(100, '\n');		cout << endl;

				cout << "Please enter the subject of this book: ";
				cin.get(subject, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				myZoom = new zoom(priority, subject, teacher, time, id);
				toAdd = new node();

				toAdd->addZoom(*myZoom);

				myZoom->writeToFile();

				BST.addNode(*toAdd);

				delete myZoom;
				delete toAdd;

				myZoom = NULL;
				toAdd = NULL;

				break;
			case '3':

				cout << "Please enter the link to this website: ";
				cin.get(link, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Please enter the priority from <0-9> 0 being most important: ";
				cin >> priority;	cin.ignore(100, '\n');		cout << endl;

				cout << "Please enter the subject of this book: ";
				cin.get(subject, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				myWeb = new website(priority, subject, link);
				toAdd = new node();

				toAdd->addWeb(*myWeb);

				myWeb->writeToFile();

				BST.addNode(*toAdd);

				delete myWeb;
				delete toAdd;

				toAdd = NULL;
				myWeb = NULL;

				break;
			case '4':
				BST.display();
				break;
			case '5':
				help();
				break;







		}	





	}while(again());





	BST.getFromFile();

	BST.display();


	/*
	   base* myBase;

	   myWeb = new website('3', "bubject", "www.google.com");

	   myWeb->writeToFile();	



	//	myWeb->writeToFile();

	//	myBook = new book('1', "first book", 200, "christian torralba", "like a bitch");
	//	myBook->writeToFile();

	BST.getFromFile();


	BST.display();




	//book(int priority, char* subject, int pages, char* author, char* title) 
	//

	toAdd.addBook(*myBook);


	//	toAdd.display();

	BST.addNode(toAdd);


	BST.display();
	*/	

	return 0;
}
