/* code by christian torralba
 * written for cs162 programming assignment number 2
 * goal is to get common phrases from user and a signature
 * started writing 10/21/2019 at psu library
 * my name a jeff
 */









#include <iostream> 
#include <cstring>
#include <cctype> 
using namespace std;

const int MAX_SIZE = 130;

void phraseCondition(char (&phrase)[MAX_SIZE]);
int main()
{
	const int MAX_LENGTH = 130; // Max size of the arrays
	
	char phraseOne[MAX_LENGTH], phraseTwo[MAX_LENGTH], phraseThree[MAX_LENGTH], phraseFour[MAX_LENGTH], signature[MAX_LENGTH];// all of arr character arrays set to max length
	char exitInput;// when the user wants to stop entering phrases 

	cout << "Hi, the purpose of this program is to make life easier for you." << endl;
	cout << "Lets start by entering your name: " << endl;

	cin.get(signature, MAX_LENGTH, '\n');
	cin.ignore(150, '\n');	


	cout << "Hello " << signature << " nice to meet you!" << endl;


//iterating through each of the phrases, i being equal to five is our exit condition

	for(int i = 1; i < 5; ++i)
	{
		
		cout << "Please enter phrase number " << i << endl;
		
		switch(i)
		{
			case 1:
			cin.get(phraseOne, MAX_LENGTH, '\n');
			phraseCondition(phraseOne);
			break;

			case 2:
			cin.get(phraseTwo, MAX_LENGTH, '\n');
			break;
		
			case 3:
			cin.get(phraseThree, MAX_LENGTH, '\n');
			break;

			case 4:
			cin.get(phraseFour, MAX_LENGTH, '\n');
			break;
		}

		cout << "Would you like to enter another? <y/n>: " << endl;
		cin >> exitInput;
		cin.ignore(100, '\n');

		if(exitInput == 'n') { i = 5; }
	}

	cout << "Phrase one: " << endl;
	cout << endl << phraseOne << endl;

	return 0;


}




void phraseCondition(char (&phrase)[MAX_SIZE])
{
	for(int i = 0; i < 130; ++i)
	{
		phrase[0] = toupper(phrase[0]);

		if(isspace(phrase[i]) && isspace(phrase[i+1]))
			for(int j = i+1; j < MAX_SIZE; ++j)
			{
				phrase[j] = phrase[j+1];
			}	
	}	






}













































