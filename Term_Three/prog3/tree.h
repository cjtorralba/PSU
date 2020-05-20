#include "derived.h"



class node
{

	public:
		node();		~node();
		node(const node& toCopy);

		void addBook(book& toAdd);
		void addWeb(website& toAdd);
		void addZoom(zoom& toAdd);

		void addNode(node& toAdd, node* root);

		node*& goLeft(){ return left; }
		node*& goRight(){ return right; }

		int getPriority();

		void display();


	private:
		int id; //how we know which node holds what type of object 0 = book, 1 = website, 2 = zoom
		node* left;
		node* right;

		book* myBook;
		website* myWeb;
		zoom* myZoom;

};


class tree
{
	public:
		tree();		//~tree();

		void addNode(node& toAdd);
		void display();
		void getFromFile();

	private:
		node* root;

		void addNode(node& toAdd, node*& root);
		void display(node* root);

		void writeToFile();




};
