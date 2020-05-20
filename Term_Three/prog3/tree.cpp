#include "tree.h"


node::node() : id(-1), left(NULL), right(NULL),  myBook(NULL), myWeb(NULL), myZoom(NULL) {}

node::node(const node& toCopy) : id(toCopy.id), left(NULL), right(NULL)
{
	switch(toCopy.id)
	{
		case 0:
			myBook = new book(*toCopy.myBook);
			break;
		case 1:
			myWeb = new website(*toCopy.myWeb);
			break;
		case 2:
			myZoom = new zoom(*toCopy.myZoom);
			break;
		default:
			break;
	}
}

node::~node()
{

	delete left;
	delete right;

	switch(id)
	{
		case 0:
			delete myBook;
			myBook = NULL;
			break;
		case 1:
			delete myWeb;
			myWeb = NULL;
			break;
		case 2:
			delete myZoom;
			myZoom = NULL;
			break;
		default:
			break;
	}
	left = NULL;
	right = NULL;
}

void node::display()
{
	switch(id)
	{
		case '0':
			myBook->display();
			break;
		case '1':
			myWeb->display();
			break;
		case '2':
			myZoom->display();
			break;
		default:
			break;
	}
}



int node::getPriority()
{
	char priority = '\0';
	switch(id)
	{
		case '0':
			priority = myBook->getPriority();
			break;
		case '1':
			priority = myWeb->getPriority();
			break;
		case '2':
			priority = myZoom->getPriority();
			break;
		default:
			break;
	}
	return priority;
}

	











//how we know which node holds what type of object 0 = book, 1 = website, 2 = zoom

void node::addBook(book& toAdd)
{
	myBook = new book(toAdd);
	id = 0;
}

void node::addWeb(website& toAdd)
{
	myWeb = new website(toAdd);
	id = 1;
}

void node::addZoom(zoom& toAdd)
{
	myZoom = new zoom(toAdd);
	id = 2;
}






tree::tree() : root(NULL) {}

void tree::addNode(node& toAdd, node*& root)
{
	if(!root)
	{
		root = new node(toAdd);
		return;
	}
	else
	{
		if(toAdd.getPriority() < root->getPriority())
			addNode(toAdd, root->goRight());
		else
			addNode(toAdd, root->goLeft());
	}



}

void tree::addNode(node& toAdd)
{
	addNode(toAdd, root);
}


void tree::display()
{
	display(root);
}


void tree::display(node* root)
{
	if(!root)
		return;

	else
	{
	root->display();
	display(root->goLeft());
	display(root->goRight());
	}

}

void tree::getFromFile()
{
	ifstream in;
	in.open("prog3.txt");

	char type;	// either w, b, z, how we find out which object we are going to be adding

	//members for our base class
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


	if(in)
		in.peek();
	else
		cerr << "Couldn't open file" << endl;

	while(!in.eof())
	{
		in.get(type);
		in.ignore(100, '|');

		switch(type)
		{
			case 'w':
				
				in.get(link, 100, '|');		in.ignore(100, '|');

				in.get(subject, 100, '|');	in.ignore(100, '|');

				in.get(priority);	in.ignore(100, '\n');

				root->addWeb(*(new website(priority, subject, link)));

				break;
			case 'b':
				break;
			case 'z':
				break;
			default:
				break;




		}
		/*

		in.get(word, 100, '|');
		in.ignore(100, '|');
		cout << word << endl;

		in.get(word, 100, '|');
		in.ignore(100, '|');
		cout << word << endl;

		in.get(word, 100, '|');
		in.ignore(100, '\n');
		cout << word << endl;

		in.get(type);
		cout << input << endl;
		*/



		break;





	}

	




}






