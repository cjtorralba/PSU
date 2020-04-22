#include "node.h"


bool again()
{
	char input;
	cin >> input;
	return input == 'y';
}

int main()
{

	table LLL;	//our data structure;
	
	//variables for adding specific objects to nodes
	video* vid;
	email* myEmail;
	liveStream* stream;
	essay* myEssay;

	node* toAdd;	//node we will be using to add to the table;

	int input;	//user input

//variable for the title class
	char name[50];
	char date[50];

//variables for the video class
	char desc[100];
	double length;

//variables for the liveStream class
	char instructor[50];
	char topic[100];

//variables for the email class
	char subject[100];
	char body[800];
	char sender[50];
	char recipiant[50];
	double timeSent;

//variables for the essay class
	char paper[1200];
	char dueDate[20];
	int wordLength;



	do
	{
		cout << "Please enter corresponding to below: " << endl
			<< "1: Add a new video" << endl
			<< "2: Add a new livestream" << endl
			<< "3: Add a new Email" << endl
			<< "4: Add a new essay" << endl
			<< "5: Display all videos" << endl
			<< "6: Display all livestreams" << endl
			<< "7: Display all emails" << endl
			<< "8: Display all essays" << endl
			<< "9: Display everything" << endl
			<< "0: Exit" << endl;

		cin >> input;	cin.ignore(100, '\n');

		switch(input)
		{
			case 0:
				break;

			case 1: 
				cout << "Name: ";
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Date: ";
				cin.get(date, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Description of the video: ";
				cin.get(desc, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Length (minutes): ";
				cin >> length;			cin.ignore(100, '\n');

				vid = new video(name , date, desc, length);
				toAdd = new node();

				toAdd->addVideo(*vid);

				LLL.addNode(toAdd);

				delete vid;
				delete toAdd;

				vid = NULL;
				toAdd = NULL;

				break;
			case 2:
				
				cout << "Name: ";
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Date: ";
				cin.get(date, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Description of the video: ";
				cin.get(desc, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Length (minutes): ";
				cin >> length;			cin.ignore(100, '\n');

				cout << endl << "Instructor: ";
				cin.get(instructor, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Topic: ";
				cin.get(topic, 100, '\n');	cin.ignore(100, '\n');

				stream = new liveStream(name, date, desc, length, instructor, topic);

				toAdd = new node();

				toAdd->addStream(*stream);

				LLL.addNode(toAdd);

				delete stream;
				delete toAdd;

				stream = NULL;

				toAdd = NULL;

				break;


			case 3:
				cout << "Name: ";
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Date: ";
				cin.get(date, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Sender: ";
				cin.get(sender, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Recipiant: ";
				cin.get(recipiant, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Subject: ";
				cin.get(subject, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Body: ";
				cin.get(body, 800, '\n');	cin.ignore(800, '\n');

				cout << endl << "Time sent: ";
				cin >> timeSent;		cin.ignore(100, '\n');

				toAdd = new node();

				myEmail = new email(name, date, sender, recipiant, subject, body, timeSent);
				
				toAdd->addEmail(*myEmail);

				LLL.addNode(toAdd);

				delete myEmail;
				delete toAdd;

				myEmail = NULL;
				toAdd = NULL;

				break;

			case 4:
				cout << endl << "Name: ";
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Date: ";
				cin.get(date, 100, '\n');	cin.ignore(100, '\n');



				break;

			case 9:
				LLL.displayAll();

			default:
				break;



		}







	}while(again());

	return 0;

}


