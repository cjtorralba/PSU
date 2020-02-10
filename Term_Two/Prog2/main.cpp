#include "header.h"


int main()
{

	travel circ1;
	travel circ2;


	return_trip stack1;
	return_trip stack2;

	trip_section trip;

	char name[100];
	char traffic[100];
	char notes[100];
	char landmarks[100];
	int length;

	bool exit = false;
	char input;
	int route;


	cout << "Welcome to the trip planner..." << endl
		<< "Please enter your first route, to do so, you will enter the name, \n"
		<< "traffic status, any notes about the road, any landmarks, and the length (miles)" << endl;
	do{

		cout << "Enter the road name: " << endl;
		cin.get(name, 100, '\n');       cin.ignore(100, '\n');

		cout << "Enter traffic condition: " << endl;
		cin.get(traffic, 100, '\n');    cin.ignore(100, '\n');

		cout << "Enter notes: " << endl;
		cin.get(notes, 100, '\n');      cin.ignore(100, '\n');

		cout << "Enter any landmarks: " << endl;
		cin.get(landmarks, 100, '\n');  cin.ignore(100, '\n');

		cout << "Enter length: " << endl;
		cin >> length;  cin.ignore(100, '\n');

		trip.set_trip(name, traffic, notes, landmarks, length);


		circ1.enqueue(&trip);
		stack1.push(&trip);

		cout << "Would you like to add another? <y,n>: ";
		cin >> input;   cin.ignore(100, '\n');



		if(input == 'n')
			exit = true;
	}while(!exit);

	circ1.display();

	cout << "Please enter the information for the second trip" << endl;

	exit = false;
	input = '\0';

	do{

		cout << "Enter the road name: " << endl;
		cin.get(name, 100, '\n');       cin.ignore(100, '\n');

		cout << "Enter traffic condition: " << endl;
		cin.get(traffic, 100, '\n');    cin.ignore(100, '\n');

		cout << "Enter notes: " << endl;
		cin.get(notes, 100, '\n');      cin.ignore(100, '\n');

		cout << "Enter any landmarks: " << endl;
		cin.get(landmarks, 100, '\n');  cin.ignore(100, '\n');

		cout << "Enter length: " << endl;
		cin >> length;  cin.ignore(100, '\n');

		trip.set_trip(name, traffic, notes, landmarks, length);

		circ2.enqueue(&trip);
		stack2.push(&trip);

		cout << "Would you like to add another? <y,n>: ";
		cin >> input;   cin.ignore(100, '\n');

		if(input == 'n')
			exit = true;
	}while(!exit);

	circ2.display();

	cout << "This is the trip to your destination via route 1:" << endl;
	circ1.display();

	cout << "Hit enter to see the trip via route 2:" << endl;
	cin; cin.ignore(100, '\n');
	circ2.display();

	cout << "Hit enter to see the trip back home via route 1:" << endl;
	cin; cin.ignore(100, '\n');
	stack1.display();

	cout << "Hit enter to see the trip back home via route 2:" << endl;   cin; cin.ignore(100, '\n');
	stack2.display();

	cout << "Please choose a route <1,2>: ";
	cin >> route;   cin.ignore(100, '\n');

	if(route == 1)
	{




	}
	else if(route == 2)
	{
//		circ1.~travel();
//		stack1.~return_trip();

	}
	cout << "At end of program" << endl;



	return 0;
}

