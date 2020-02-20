#include <iostream>
#include "prog4.h"
int main()
{
	int questions;
	cout << "How many questions would you like to enter?" << endl;
	cin >> questions;
	cin.ignore(100, '\n');

	List list(questions);
	for(int i = 0; i < questions; ++i)
	{
		list.question[i].initQuestion();
		list.question[i].display();
	}
	return 0;
}
