#include "node.h"




//node constructors
node::node() : myVideo(NULL), myStream(NULL), myEmail(NULL), myEssay(NULL), next(NULL), type(-1) { }



//copy contrusctor for the node class
node::node(const node & toAdd) 	
{
	next = NULL;


	//have to set the type or else we will seg fault
	if(toAdd.myVideo)
	{
		myVideo = new video(*toAdd.myVideo);
		myStream = NULL;
		myEmail = NULL;
		myEssay = NULL;
		type = toAdd.type;

	}
	else if(toAdd.myStream)
	{
		myStream = new liveStream(*toAdd.myStream);
		myVideo = NULL;
		myEmail = NULL;
		myEssay = NULL;
		type = toAdd.type;
	}
	else if(toAdd.myEmail)
	{
		myEmail = new email(*toAdd.myEmail);
		myVideo = NULL;
		myStream = NULL;
		myEssay = NULL;
		type = toAdd.type;
	}
	else if(toAdd.myEssay)
	{
		myEssay = new essay(*toAdd.myEssay);
		myVideo = NULL;
		myEmail = NULL;
		myStream = NULL;
		type = toAdd.type;
	}
}




//recursive destructor
node::~node()
{
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



//recursive function to add to the end of 
void node::addToEnd(node* source, node*& head)
{
	if(!head)
	{
		head = new node(*source);
		return;
	}
	addToEnd(source, head->goNext());
}


//returns the node->next of current node
node *& node::goNext()
{
	return this->next;
}



//returns type, this is necessary for 
//adding nodes to the node array in the table class
int node::getType()
{
	return type;
}



//for traversing through the linear linked list
node *& node::returnNext()
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


//setting our class members to a new objects using the copy constructors of each class
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



//our display function
//this uses our type member of the node class to see if the array is NULL
bool node::displayNode()
{
	
	bool displayed = false;

	/*
	 * using switch case on our type member
	 * 0 = video
	 * 1 = liveStream
	 * 2 = email
	 * 3 = essay
	 */



	switch(type)	//using the type of object to call corresponding functions
	{
		case 0:
			myVideo->display();
			displayed = true;
			break;
		case 1:
			myStream->display();
			displayed = true;
			cout << "done " << endl;
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






//=====================Table constructor and functions ====================A


//table constructor
table::table()	
{
	int i;
	size = 4;	//setting our table to size four since we only have four classes we're dealing with

	nodeTable = new node*[size];	//allocating new array of node of size N

	for(i = 0; i < size; ++i)
		nodeTable[i] = NULL;	//setting them all to NULL
}


//table destructor calls node destructor on each element
table::~table()
{
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
}


//adds a node to the nodeTable array
//if the position is null we just set the first
//if it is not null we call the recursive addToEnd() function for the node
bool table::addNode(node* toAdd)
{
	int position = toAdd->getType();	//position in array


	if(position == -1)	
		return false;	//this means the node has nothing in it so we are not going to add it
	else	
	{
		//since the position is not -1, the node we want to add must exist


		if(nodeTable[position] == NULL)	//our position in the node table is empty
		{
			nodeTable[position] = new node(*toAdd);
			return true;	//our node has succefully been added
		}

		else	//our position in the node table is not empty so we need to add to the  linear linked list
		{
			nodeTable[position]->addToEnd(toAdd, nodeTable[position]);	//calling recursive function to add to the end of our linear linked list
			return true;
		}
	}
	return false;	//if it did not enter any of the blocks, it did not add the node succefully, therefore returning false
}



//These following display functions are for displaying all of any given 
//objects using their type
//
/*	for reference
 * 0 = video
 * 1 = liveStream
 * 2 = email
 * 3 = essay
 */	


void table::displayVid()
{
	node* cur;
	if(nodeTable[0])
		for(cur = nodeTable[0]; cur != NULL; cur = cur->returnNext())
		{
			cout << endl;
			cur->displayNode();
		}
}
void table::displayEmails()
{
	node* cur;
	if(nodeTable[2])
		for(cur = nodeTable[2]; cur != NULL; cur = cur->returnNext())
		{
			cout << endl;
			cur->displayNode();
		}
}
void table::displayEssays()
{
	node* cur;
	if(nodeTable[3])
		for(cur = nodeTable[3]; cur != NULL; cur = cur->returnNext())
		{
			cout << endl;
			cur->displayNode();
		}
}
void table::displayStreams()	//displaying all streams(type id = 3);
{
	node* cur;
	if(nodeTable[1])
		for(cur = nodeTable[1]; cur != NULL; cur = cur->returnNext())
		{
			cout << endl;
			cur->displayNode();
		}
}




//displays all objects and in all elements of the array
void table::displayAll()
{
	int i;
	node* cur;	//temp node for traversing throuh the list

	for(i = 0; i < size; ++i)
	{
		/*	for reference
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
					cout << "Emails: " << endl;
					break;
				case 3:
					cout << "Essays: " << endl;
					break;
			}	

			for(cur = nodeTable[i]; cur != NULL; cur = cur->returnNext())
			{
				cur->displayNode();	
				cout << endl;
			}

		}
	}
}
