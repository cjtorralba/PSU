#include "email.h"



class node
{
	public:
		node();		//~node();
		node(const node & toAdd);	//copy constructos

		void addVideo(video& toAdd);
		void addStream(liveStream& toAdd);
		void addEmail(email& toAdd);
		void addEssay(essay& toAdd);

		void displayNode();

		node* returnNext();

		int getType(); 	//returns the type in integer
		// this is going to be used for our table in order to add
		// nodes correctly to the array




	protected:

		video* myVideo;
		liveStream* myStream;
		email* myEmail;
		essay* myEssay;

		node* next;

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
		table(int size);	//~table();
		bool addNode(node& toAdd);

	protected:
		node** nodeTable;
		int size;



};
