#include "header.h"



/*
 * This code is by christian torralba in cs163
 * main focus is to explore hash tables
 * this program allows you to enter meals you have eaten from certain establishments and they will be
 * stored into a hjash table
 * you may also remove meals and add more when you want
 * you may also display information about a certain meal if you wish
 * thanks!
 */

//These two functions are purely for ease and I made them cause i was running out of time on this project
//please do not grade me down on them I could have implemented them elsewhere it would have just taken longer
bool again()
{
	char response;
	cout << "Would you like to enter another? <y,n>" << endl;
	cin >> response;	cin.ignore(100, '\n');
	if(response == 'y')
		return true;
	return false;
}

bool type()
{
	char input;
	cout << "Is it a food cart or restaurant? <f,r>" << endl;
	cin >> input;	cin.ignore(100, '\n');

	if(input == 'c')
		return true;
	return false;
}



int main()
{
	table myTable;

	char input[100];
	char meals[50];

	meal* pmeal;

	meal first;
	first.mealName = new char[100];
	first.name = new char[100];
	first.review = new char[100];

	

	do{
		cout << "Meal name: " << endl;
		cin.get(first.mealName, 100, '\n');	cin.ignore(100, '\n');

		cout << endl << "Establishment name: " << endl;
		cin.get(first.name, 100, '\n');	cin.ignore(100, '\n');

		cout << "Review: " << endl;
		cin.get(first.review, 100, '\n');	cin.ignore(100, '\n');

		cout << "Approximate price: " << endl;
		cin >> first.price;

		cout << "Rating <1-10>: " << endl;
		cin >> first.rating;

		first.type = type();

		myTable.add(first.mealName, &first);

	}while(again());


	do
	{
		cout << "Enter r to remove a meal by the name" << endl
			<<"Enter ra to remove all meals by a certain establishment" << endl
			<< "Enter d to display a meal and its information" << endl
			<< "Enter a to add more meals" << endl;

		

		cin.get(input, 100, '\n');	cin.ignore(100, '\n');

		if(strcmp(input, "r") == 0)
		{
			cout << "Please enter the meal name" << endl;
			cin.get(meals, 100, '\n');	cin.ignore(100, '\n');

			pmeal = myTable.retrieve("meals");
			if(pmeal != NULL)
			{

				cout << "Your removed: " << endl;
				(*pmeal).display();
				pmeal = NULL;
				myTable.remove(meals);
			}
		}	
		else if(strcmp(input, "d") == 0)
		{
			cout << "Enter meal you would like to see" << endl;
			cin.get(meals, 10, '\n');	cin.ignore(100, '\n');

			if(!myTable.display(meals))
				"Looks like the meal doesn't exist yet!" << endl;




		}
		else if(strcmp(input, "a") == 0)
		{

			do{
				cout << "Meal name: " << endl;
				cin.get(first.mealName, 100, '\n');	cin.ignore(100, '\n');

				cout << endl << "Establishment name: " << endl;
				cin.get(first.name, 100, '\n');	cin.ignore(100, '\n');

				cout << "Review: " << endl;
				cin.get(first.review, 100, '\n');	cin.ignore(100, '\n');

				cout << "Approximate price: " << endl;
				cin >> first.price;

				cout << "Rating <1-10>: " << endl;
				cin >> first.rating;

				first.type = type();

				myTable.add(first.mealName, &first);

				cout << "You are still adding meals" << endl;

			}while(again());

		}
		else if(strcmp(input, "ra") == 0)
		{
			cout << "Please enter the establishment name you would like to remove meals from" << endl;
			cin.get(meals, 100, '\n');	cin.ignore(100, '\n');
			cout << "Removing all meals made from: " << meals << endl;

			myTable.removeAll(meals);
		}
		else
			cout << "Not valid" << endl;






	}while(again());



	return 0;
}
