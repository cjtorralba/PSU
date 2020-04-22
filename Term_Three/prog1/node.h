#include "email.h"



class node
{
	public:
		node();		~node();
		node(const node & toAdd);	//copy constructos

		void addVideo(video& toAdd);
		void addStream(liveStream& toAdd);
		void addEmail(email& toAdd);
		void addEssay(essay& toAdd);

		bool displayNode();

		node* returnNext();

		void test();

		video* myVideo;
		int getType(); 	//returns the type in integer
		// this is going to be used for our table in order to add
		// nodes correctly to the array




	protected:

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
		table();	
		~table();
		bool addNode(node& toAdd);
		void displayAll();

		

	protected:
		node** nodeTable;
		int size;



};
