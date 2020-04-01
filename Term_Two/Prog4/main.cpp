#include "header.h"


bool again()
{
	char input;
	cout << "Again? <y,n>: ";
	cin >> input;	cin.ignore(100, '\n');
	cout << endl;

	if(input == 'y')
		return true;
	return false;
}	

int main()
{

	tree BST;

	meal myMeal;

	char name[100];
	char review[100];
	char storeName[100];
	int rating;
	int price;
	bool type;


	while(again())
	{
		cout << "Name: " << endl;
		cin.get(name, 100, '\n');	cin.ignore(100, '\n');

		cout << "Store: " << endl;
		cin.get(storeName, 100, '\n');	cin.ignore(100, '\n');

		cout << "Review: " << endl;
		cin.get(review, 100, '\n');	cin.ignore(100, '\n');


		cout << "Rating: " << endl;
		cin >> rating;	cin.ignore(100, '\n');

		cout << "Price: " << endl;
		cin >> price; 	cin.ignore(100, '\n');

		bool type = true;

		myMeal.name = name;
		myMeal.review = review;
		myMeal.storeName = storeName;
		myMeal.rating = rating;
		myMeal.price = price;
		myMeal.type = type;

		BST.add(&myMeal);

	}



	BST.display();


	BST.remove("a", "a");

	BST.display();



	return 0;
}
