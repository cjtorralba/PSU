#include "node.h"




//node constructors
node::node() : myVideo(NULL), myStream(NULL), myEmail(NULL), myEssay(NULL), next(NULL), type(-1) { }

node::node(const node & toAdd) : myVideo(toAdd.myVideo), myStream(toAdd.myStream), myEmail(toAdd.myEmail), next(NULL){}	//not setting the next pointer to anything because we might have to work with it



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


			break;
		case 1:


			break;
		case 2:


			break;
		case 3: 



			break;

		case -1:
			break;

		default:
			break;






	}






}


//=========Adding our learning method objects to the nodes=======

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

void node::addEssay(essay& toAdd)   
{
	myEssay = new essay(toAdd);
	type = 2;
}

void node::addEmail(email& toAdd)  
{
	myEmail = new email(toAdd);
	type = 3;
}	

//===============================================================



table::table(int size = 4)	//setting our table to size four since we only have four classes we're dealing with
{
	int i;

	nodeTable = new node*[size];	//allocating new array of node of size N

	for(i = 0; i < size; ++i)
		nodeTable[i] = NULL;	//setting them all to NULL
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
















