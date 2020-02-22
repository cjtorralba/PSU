#include "header.h"

int main()
{
	table myTable;

	meal first;
	first.mealName = new char[100];
	first.name = new char[100];
	first.review = new char[100];

	for(int i = 0; i < 2; ++i)
	{
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

		first.type = true;



		myTable.add(first.mealName, &first);
	}
	myTable.displayAll();

	return 0;
}
