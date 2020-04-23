#include "node.h"


/*
 * program one by christian torralba for cs202 at PSU
 * this program is to experiment with the use of classes and inheritance, 
 * we have developed classes to represent different types of learning, whether it be a video, livestream, or essay
 *
 * to store these classes we have made use of an array of linear linked lists to try to make it more efficent, each 
 * element in the array contains a pointer to a list of like objects
 */


//just a simple function to check if the user want to continue
bool again()
{
	char input;
	cout << "Again? <y,n>:";
	cin >> input;
	cout << endl;
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

		cin >> input;	cin.ignore(100, '\n');

		switch(input)
		{
			/*
			 * when adding to our table, we allocated a new object of requested type and call the copy constructor on it to copy its contents into 
			 * the array
			 *
			 * when the contents have been copied, we de allocate it and set it to null so we can re use the pointer
			 */


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

				cout << endl << "Recipiant: ";
				cin.get(recipiant, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Subject: ";
				cin.get(subject, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Body: ";
				cin.get(body, 800, '\n');	cin.ignore(800, '\n');

				cout << endl << "Time sent: ";
				cin >> timeSent;		cin.ignore(100, '\n');

				toAdd = new node();

				myEmail = new email(name, date, recipiant, subject, body, timeSent);
				
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

				cout << endl << "Due Date: ";
				cin.get(dueDate, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Body: ";
				cin.get(paper, 1200, '\n');	cin.ignore(1200, '\n');

				cout << endl << "Word Length: ";
				cin >> wordLength;		cin.ignore(100, '\n');

				myEssay = new essay(name, date, paper, dueDate, wordLength);

				toAdd =  new node();

				toAdd->addEssay(*myEssay);

				LLL.addNode(toAdd);

				delete toAdd;
				delete myEmail;

				toAdd = NULL;
				myEmail = NULL;

				break;


			 // switch cases for displaying certain sets of objects

			 case 5:
				LLL.displayVid();
				break;
			 case 6:
				LLL.displayStreams();
				break;
			 case 7:
				LLL.displayEmails();
				break;
			 case 8:
				LLL.displayEssays();
				break;

			
			//9 displays the entire list with all its contents
			 case 9:
				LLL.displayAll();

			 default:
				break;
		}
	}while(again());

	return 0;
}


