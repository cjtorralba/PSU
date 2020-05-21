#include "derived.h"
/*
 * this is oujr data structure, a tree of nodes, with each node holding an object
 * */


class node
{

	public:
		//cosntrucotr and destructor
		node();		~node();
		node(const node& toCopy);


		//adding objects to the node usign copy constructor
		void addBook(book& toAdd);
		void addWeb(website& toAdd);
		void addZoom(zoom& toAdd);

		void addNode(node& toAdd, node* root);	//add node to tree

		//to go left and rigtht in the tree
		node*& goLeft(){ return left; }
		node*& goRight(){ return right; }

		char getPriority();	//returns the priority of the specified object

		void display();		//displays node


	private:
		char id; //how we know which node holds what type of object 0 = book, 1 = website, 2 = zoom
		node* left;
		node* right;

		book* myBook;
		website* myWeb;
		zoom* myZoom;

};


class tree
{
	public:
		tree();		~tree();	//constructor

		void addNode(node& toAdd);	//add node to tree
		void display();			//display contents fo the tree
		void getFromFile();		//get information from the file

	private:
		node* root;			//root node

		void addNode(node& toAdd, node*& root);	//private recursive wrappers
		void display(node* root);

		void writeToFile();




};
