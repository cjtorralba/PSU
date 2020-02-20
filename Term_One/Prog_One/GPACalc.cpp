
#include <iostream>
using namespace std;


/*
 * code written by christian torralba for the 3rd time cause I keep deleting it accidentally
 * first PSU assignment for Comp Sci 162, job is to calculate avg GPA
 */



double charToDouble(char c, char plus_Or_Minus); // The job of this function is to convert grade such as b- to gradePoints

int main()
{

	int totalClasses; // Total number of classes the user is taking

	char letterGrade, plusOrMinus; // the users letter grade for specified class, and if they got a +/-

	double totalGradePoints; // total amount of grade points, ex: a = 4.0, b- = 2.67

	double avgGpa; // calculated by dividing totalGradePoints by totalClasses

	char recalculate = 'y'; // setting recalculate to be 'y' at first





//      Beggining of while to ask user for grades and calculate gpa
	while(recalculate == 'y')
	{

		cout << "How many classes are you taking?" << endl;

		cin >> totalClasses;
		
		int loopCounter = totalClasses; // this is for the for() loop, in case we change the value of totalClasses
		for(int i = 1; i <= loopCounter; i++)
			{
	
				cin.ignore(100, '\n');
			
				cout << "What was the letter grade for class number "
				<< i << endl;
				cout << "Enter P if pass and F is failed for pass/fail classes" << endl;

				cin >> letterGrade;
				if(letterGrade == 'p' || letterGrade == 'f'){ --totalClasses; } // if pass or fail, wont effect gpa
				
				plusOrMinus = cin.peek();
				totalGradePoints += charToDouble(letterGrade, plusOrMinus);
								
			}

		
		avgGpa = totalGradePoints / totalClasses;

		cout << "Average GPA is: ";
		cout.precision(3);
		cout << avgGpa << endl;


		cout << "Would you like to re-calculate? <y/n>" << endl;


	//got to make sure buffer is clear before asking if user wants to retry		
		cin.ignore(100, '\n');	

		recalculate = cin.get();



	//setting all my variables back to zero in case user wants to recalculate
		avgGpa = 0.0;		
		totalClasses = 0;		
		totalGradePoints = 0.0;
		
		cin.clear();
		cin.ignore(100, '\n');

	}
return 0;
}



double charToDouble(char c, char plus_Or_Minus)
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

                default: 
			break;
                }

        switch(plus_Or_Minus)
                {
                        case '+': returnVal += 0.33;
                                break;
                        case '-': returnVal -= 0.33;
                                break;
                        default:
                                break;
                }
        return returnVal;
}
