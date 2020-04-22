#include "node.h"




//node constructors
node::node() : myVideo(NULL), myStream(NULL), myEmail(NULL), myEssay(NULL), next(NULL), type(-1) { cout << "Called default constructor" << endl; }

node::node(const node & toAdd) 	
{
	cout << "Node copy constructor called" << endl;
	next = NULL;


	if(toAdd.myVideo)
	{
		myVideo = new video(*toAdd.myVideo);
		myStream = NULL;
		myEmail = NULL;
		myEssay = NULL;
	}

	else if(toAdd.myStream)
	{
		myStream = new liveStream(*toAdd.myStream);
		myVideo = NULL;
		myEmail = NULL;
		myEssay = NULL;
	}

	else if(toAdd.myEmail)
	{
		myEmail = new email(*toAdd.myEmail);
		myVideo = NULL;
		myStream = NULL;
		myEssay = NULL;
	}

	else if(toAdd.myEssay)
	{
		myEssay = new essay(*toAdd.myEssay);
		myVideo = NULL;
		myEmail = NULL;
		myStream = NULL;
	}
}


node::~node()
{
	cout << "called node destructor" << endl;
	delete next;

	if(myVideo)
		delete myVideo;
	else if(myStream)
		delete myStream;
	else if(myEmail)
		delete myEmail;
	else if(myEssay)
		delete myEssay;

	myVideo  = NULL;
	myStream = NULL;
	myEmail  = NULL;
	myEssay  = NULL;
	next = NULL;
}

//returns type, this is necessary for 
//adding nodes to the node array in the table class
int node::getType()
{
	return type;
}



//for traversing through the linear linked list
node* node::returnNext()
{
	return next;
}


/*
 * =========Adding our learning method objects to the nodes=======
 * 0 = video
 * 1 = liveStream
 * 2 = email
 * 3 = essay
 */



void node::addVideo(video& toAdd)
{
	myVideo = new video(toAdd);	
	type = 0;
}

void node::addStream(liveStream& toAdd)   
{
	myStream = new liveStream(toAdd);
	type = 1;
}

void node::addEmail(email& toAdd)  
{
	myEmail = new email(toAdd);
	type = 2;
}	

void node::addEssay(essay& toAdd)   
{
	myEssay = new essay(toAdd);
	type = 3;
}




//out display function making use of the type integer
bool node::displayNode()
{
	int tempType = getType();
	bool displayed = false;

	/*
	 * using switch case on our type member
	 * 0 = video
	 * 1 = liveStream
	 * 2 = email
	 * 3 = essay
	 */

	switch(tempType)
	{
		case 0:
			myVideo->display();
			displayed = true;
			break;
		case 1:
			myStream->display();
			displayed = true;
			break;
		case 2:
			myEmail->display();
			displayed = true;
			break;
		case 3: 
			myEssay->display();
			displayed = true;
			break;

		case -1:
			break;

		default:
			break;
	}
	return displayed;
}


//===============================================================


void node::test()
{
	cout << "Node information: " << endl
		<< "Type: " << getType() << endl		 
		<< "Displaying: " << endl
		<< displayNode() << endl;
}












//=====================Table constructor and functions ====================A



table::table()	
{
	int i;
	size = 4;	//setting our table to size four since we only have four classes we're dealing with

	nodeTable = new node*[size];	//allocating new array of node of size N

	for(i = 0; i < size; ++i)
		nodeTable[i] = NULL;	//setting them all to NULL
}

table::~table()
{
	cout << "Called table destructor" << endl;
	int i;
	for(i = 0; i < size; ++i)
	{
		if(nodeTable[i])
		{
			delete nodeTable[i];
			nodeTable[i] = NULL;
		}
	}
	delete [] nodeTable;
	nodeTable = NULL;
	cout << "finished destroying table" << endl;
}

bool table::addNode(node& toAdd)
{
	int position = toAdd.getType();	//position in array


	if(position == -1)	
		return false;	//this means the node has nothing in it so we are not going to add it
	else	
	{
		//since the position is not -1, the node we want to add must exist


		if(nodeTable[position] == NULL)	//our position in the node table is empty
		{
			nodeTable[position] = new node(toAdd);
			return true;	//our node has succefully been added
		}

		else	//our position in the node table is not empty so we need to add to the  linear linked list
		{
			node* cur;

			for(cur = nodeTable[position]; cur != NULL; cur = cur->returnNext());	//traversing to the end of the list

			cur = new node(toAdd);

			return true;
		}
	}
	return false;	//if it did not enter any of the blocks, it did not add the node succefully, therefore returning false
}


void table::displayAll()
{
	int i;
	node* cur;	//temp node for traversing throuh the list

	for(i = 0; i < size; ++i)
	{
		/*
		 * 0 = video
		 * 1 = liveStream
		 * 2 = email
		 * 3 = essay
		 */	

		if(nodeTable[i])	//if we have nodes in this element
		{			
			switch(i)	//our i counter corresponds to what type of object we are dealing with
			{
				case 0:
					cout << "Videos: " << endl;
					break;
				case 1:
					cout << "LiveStreams: " << endl;
					break;
				case 2:
					cout << "Essay: " << endl;
					break;
				case 3:
					cout << "Emails: " << endl;
					break;
			}	

			for(cur = nodeTable[i]; cur != NULL; cur = cur->returnNext())
				cout << cur->getType();

		}
		cout << endl << endl << "I: " << i << endl;
	}
}













