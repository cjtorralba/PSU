#include "email.h"



class node
{
	public:
		//node constructors and destrucot
		node();		~node();
		node(const node & toAdd);	//copy constructos


		//functions to add learning classes to our memebers
		void addVideo(video& toAdd);
		void addStream(liveStream& toAdd);
		void addEmail(email& toAdd);
		void addEssay(essay& toAdd);

		//display the contents of a node
		bool displayNode();

		//these are used to recursivly add to the end a linked list of nodes
		//returns the next pointer
		node *& returnNext();
		node *& goNext();
		//recursivly adds to the end of a linear linked list of nodes
		void addToEnd(node* source, node *& head);

		int getType(); 	//returns the type in integer
		// this is going to be used for our table in order to add
		// nodes correctly to the array




	protected:
		//our members 
		//each node will only contain one of these, and when we are
		//done using said node
		//in main, we will destroy the node
		video* myVideo;
		liveStream* myStream;
		email* myEmail;
		essay* myEssay;

		//next pointer for the linear linked list
		node* next;

		//each node has a type, the type tells us which one of the objects above it
		//contains
		int type;	
		//for types:
		//0 = video
		//1 = livestream
		//2 = email
		//3 = essay
};



class table
{
	public:
		//constructor and destructor
		table();	
		~table();

		//addd a node to the array of nodes
		bool addNode(node* toAdd);

		//displays the contents of the entire array
		void displayAll();

		//displays all of a certain type of object
		//making use of the getType() function in the node class
		void displayVid();
		void displayEmails();
		void displayEssays();
		void displayStreams();

	protected:
		node** nodeTable;	//array of node pointers, this is 
					//what contains the linear linked list;
					//
		int size;		//size of the array, I set mine to 4 since we are only using 
					//four different objects
};
