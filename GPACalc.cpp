#include <iostream>
using namespace std;


/*
 * code written by christian torralba for the 3rd time cause I keep deleting it accidentally
 * first PSU assignment for Comp Sci 162, job is to calculate avg GPA
 */


int main()
{

	int totalClasses; // Total number of classes the user is taking
	char letterGrade, plusOrMinus; // the users letter grade for specified class, and if the got a +/-


	cout << "How many classes are you taking?" << endl;

	cin >> totalClasses;


	for(int i = 1; i <= totalClasses; i++)
		{
			
			cout << "What was the letter grade for class number "
			<< totalClasses << endl;

			cin >> letterGrade;
			plusOrMinus = cin.peek();


			cout << "You got a "
			<< letterGrade
			<< plusOrMinus
			<< "in class number "
			<< i << endl;




		}






}
