#include "list.h"



void help()
{
	cout << "You have three activities to add, "
		<< "working, hiking, and swiming" << endl;

	cout << "Please see the following for adding: " << endl
		<< "1: Add a new working activity" << endl
		<< "2: Add a new hiking activity" << endl
		<< "3: Add a new swimming activity" << endl
		<< "4: Remove an activity by name" << endl
		<< "5: Add a lunch to a work activity by name" << endl
		<< "6: Plan a work out for a swim activity by name" << endl
		<< "7: Pack climbing shoes for a hike by name" << endl
		<< "D: Display all activities" << endl
		<< "0: To exit program" << endl
		<< "H: To see this prompt again" << endl;
}

int main()
{
	list myList;
	base* toFind;

	char input;
	char locateActivity[50];


	//base class memebers 
	char name[40];
	char location[50];
	int priority;
	int activityLength;
	bool isGroupActivity;


	//swim pointer and all it's needed members
	swim* mySwim;
	char swimSuit[40];
	bool member;
	bool hasHotTub;

	//hike pointer and all it's needed members
	hike* myHike;
	bool overNight;
	char season[20];;
	char weather[20];


	//work pointer and all it's needed members
	work* myWork;
	char position[40];;
	double pay;
	bool partTime;



	//how we will be deciding what to do based on user input





	help();

	do
	{
		cin >> input;	cin.ignore(100, '\n');

		switch(input)
		{
			case '1':

				cout << "Please enter name: ";
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Enter location: ";
				cin.get(location, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Enter priority <1-10> 1 being you want to do it immediatly: ";
				cin >> priority;	cin.ignore(100, '\n');		cout << endl;

				cout << "Enter activity length, in hours, round to the nearest hour: ";
				cin >> activityLength;	cin.ignore(100, '\n');		cout << endl;

				cout << "Is this a group activity? <y,n>: ";
				cin >> input;		cin.ignore(100, '\n');		cout << endl;

				if(input == 'y')
					isGroupActivity = true;
				else
					isGroupActivity = false;

				cout << "Please enter your position in the work place: ";	
				cin.get(position, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Please enter your pay per hour: ";
				cin >> pay;	cin.ignore(100, '\n');			cout << endl;

				cout << "Is this a part time or full time job <p,f>: ";
				cin >> input;	cin.ignore(100, '\n');			cout << endl;
				if(input == 'p')
					partTime = true;
				else
					partTime = false;

				myWork = new work(activityLength, priority, isGroupActivity, name, location, position, pay, partTime);

				cout << "Adding work object" << endl;

				myList.addWork(myWork);

				cout << "Added work object" << endl;

				delete myWork;
				myWork = NULL;

				break;


			case '2':

				cout << "Please enter name: ";
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Enter location: ";
				cin.get(location, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Enter priority <1-10> 1 being you want to do it immediatly: ";
				cin >> priority;	cin.ignore(100, '\n');		cout << endl;

				cout << "Enter activity length, in hours, round to the nearest hour: ";
				cin >> activityLength;	cin.ignore(100, '\n');		cout << endl;

				cout << "Is this a group activity? <y,n>: ";
				cin >> input;		cin.ignore(100, '\n');		cout << endl;

				if(input == 'y')
					isGroupActivity = true;
				else
					isGroupActivity = false;

				cout << "Will this hike be overnight? <y,n>: ";
				cin >> overNight;	cin.ignore(100, '\n');	cout << endl;

				cout << "Current Season: ";
				cin.get(season, 20, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Predicted weather?: ";
				cin.get(weather, 20, '\n');	cin.ignore(100, '\n');	cout << endl;
			
				myHike = new hike(activityLength, priority, isGroupActivity, name, location, overNight, season, weather);

				myList.addHike(myHike);

				delete myHike;
				myHike = NULL;


				break;


			case '3':
				cout << "Please enter name: ";
				cin.get(name, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Enter location: ";
				cin.get(location, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Enter priority <1-10> 1 being you want to do it immediatly: ";
				cin >> priority;	cin.ignore(100, '\n');		cout << endl;

				cout << "Enter activity length, in hours, round to the nearest hour: ";
				cin >> activityLength;	cin.ignore(100, '\n');		cout << endl;

				cout << "Is this a group activity? <y,n>: ";
				cin >> input;		cin.ignore(100, '\n');		cout << endl;

				if(input == 'y')
					isGroupActivity = true;
				else
					isGroupActivity = false;


				cout << "What kind of swimsuit will you wear: ";
				cin.get(swimSuit, 100, '\n');	cin.ignore(100, '\n');	cout << endl;

				cout << "Are you a member? <y,n>: ";
				cin >> input;			cin.ignore(100, '\n');	cout << endl;
				if(input == 'y')
					member = true;
				else
					member = false;

				cout << "Does this pool have a hot tub? <y,n>: ";
				cin >> input;			cin.ignore(100, '\n');	cout << endl;
				if(input == 'y')
					hasHotTub = true;
				else
					hasHotTub = false;

				mySwim = new swim(activityLength, priority, isGroupActivity, name, location, swimSuit, member, hasHotTub);

				myList.addSwim(mySwim);
				cout << "swimSuit: " << swimSuit << endl;

				delete mySwim;
				mySwim = NULL;

				break;

			case '4':
				cout << "Please enter the name of the activity you would like to delete: ";
				cin.get(locateActivity, 40, '\n');	cin.ignore(100, '\n');	cout << endl;

				toFind = myList.getNodeByName(locateActivity);


				if(!toFind)
					cout << "There was no match" << endl;
				else
				{
					cout << "Located and deleted this activity" << endl << endl;
					toFind->display();
				}
				
				myList.deleteBase(locateActivity);
				toFind = NULL;

				break;

			case '5':

				cout << "Enter the work activity you would like to plan a lunch for: ";
				cin.get(locateActivity, 40, '\n');	cin.ignore(100, '\n');	cout << endl;

				toFind = myList.getNodeByName(locateActivity);

				myWork = dynamic_cast<work*>(toFind);

				myWork->display();
				
				if(myWork)
				{
					try
					{
						myWork->planLunch();
					}catch(int e) {}
				}
				else
					cout << "Sorry, couldn't add a lunch to this activity..." << endl;
				myWork = NULL;
				toFind = NULL;

				break;

			case '6':
				cout << "Please enter the swimming activity you would like to work out on: ";
				cin.get(locateActivity, 40, '\n');	cin.ignore(100, '\n');	cout << endl;

				toFind = myList.getNodeByName(locateActivity);

				mySwim = dynamic_cast<swim*>(toFind);

				if(mySwim)
				{
					try
					{
						mySwim->startExercise();
					} catch(int e) {}
				}
				else
					cout << "Sorry, couldn't plan a work out for this activity..." << endl;

				mySwim = NULL;
				toFind = NULL;

				break;

			case '7':
				cout << "Please enter the hike you would like to pack climbing shoes on: ";
				cin.get(locateActivity, 40, '\n');	cin.ignore(100, '\n');	cout << endl;

				toFind = myList.getNodeByName(locateActivity);

				myHike = dynamic_cast<hike*>(toFind);

				if(myHike)
				{
					try
					{
						myHike->rockClimb();
					}catch(int e) {}
				}
				else
					cout << "Sorry, couldn't pack climbing shoes for this activity..." << endl;

				myHike = NULL;
				toFind = NULL;

				break;

			case 'D':
				myList.display();
				break;
			case 'd':
				myList.display();
				break;

			case '0':
				break;

			case 'H':
				help();
				break;
			case 'h':
				help();
				break;

			default:
				cout << "Please enter something valid..." << endl;
				break;
		}

	} while(input != '0');
	cout << "Exiting Program..." << endl;


	return 0;

}
