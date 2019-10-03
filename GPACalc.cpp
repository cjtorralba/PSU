#include <iostream>
using namespace std;


/*
 * code written by christian torralba for the 3rd time cause I keep deleting it accidentally
 * first PSU assignment for Comp Sci 162, job is to calculate avg GPA
 */


double charToDouble(char c)
{
        double returnVal; // value of the character

        tolower(c);

        switch(c) {
                case 'a': returnVal = 4.0;
                break;

                case 'b': returnVal = 3.0;
                break;

		case 'c': returnVal = 2.0;
		break;

		case 'd': returnVal = 1.0;
		break;

		case 'f': returnVal = 0.0;
		break;

		default: break;
                }

	return returnVal;

}


int main()
{

	int totalClasses; // Total number of classes the user is taking

	char letterGrade, plusOrMinus; // the users letter grade for specified class, and if the got a +/-

	double totalGradePoints; // total amount of grade points, ex: a = 4.0, b- = 2.67

	double avgGpa; // calculated by dividing totalGradePoints by totalClasses

	cout << "How many classes are you taking?" << endl;

	cin >> totalClasses;


	for(int i = 1; i <= totalClasses; i++)
		{
				
			cin.ignore(2, '\n');  // clearing the input stream so it doesnt mess up the loop

			
			cout << "What was the letter grade for class number "
			<< i << endl;

			cin >> letterGrade;

			plusOrMinus = cin.peek();

//			cout << letterGrade << plusOrMinus;

			totalGradePoints += charToDouble(letterGrade);
		}

		
	avgGpa = totalGradePoints / totalClasses;

	cout << "Average GPA is: ";
	cout.precision(3);
	cout << avgGpa;

}
