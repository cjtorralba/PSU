/* code by christian torralba
 * written for cs162 programming assignment number 2
 * goal is to get common phrases from user and a signature
 * the user then can decide what order they want the phrases output in
 * ended with the users signature
 * started writing 10/21/2019 at psu library
 * my name a jeff
 */

#include <iostream> 
#include <cstring>
#include <cctype> 
using namespace std;

const int MAX_SIZE = 130;


// ------------Functions--------------------
void phraseCondition(char phrase[]); // this checks and makes sure the phrases have the correct conditions

void capSignature(char signature[]); // this makes sure the signature is capitalized

int main()
{

// -----------Variables-------------------
	const int MAX_LENGTH = 130; // Max size of the arrays
	
	char phraseOne[MAX_LENGTH], phraseTwo[MAX_LENGTH], phraseThree[MAX_LENGTH], phraseFour[MAX_LENGTH], signature[MAX_LENGTH];// all of arr character arrays set to max length
	char exitInput;// when the user wants to stop entering phrases 
	
	int numOfPhrases = 0; // total number of phrases the user has input
	int order[4]; // keeps the order of phrases
	bool exit = false, finalExit = false; // our exit conditions for bot while loops
	int phraseCount = 1; // number phrases for the switch statemenit
	cout << "Hi, the purpose of this program is to make life easier for you." << endl;
	cout << "Lets start by getting your signature please: " << endl;

	cin.get(signature, MAX_LENGTH, '\n');
	cin.ignore(150, '\n');	
//checking signature and making sure its lookin good
	capSignature(signature);
	cout << "Hello " << signature << " nice to meet you!" << endl;


//iterating through each of the phrases
while(!finalExit){
	while(!exit)
	{
		
		cout << "Please enter phrase number " << phraseCount << endl;
		
		switch(phraseCount)
		{
			case 1:
			cin.get(phraseOne, MAX_LENGTH, '\n');
			cin.ignore(100, '\n');
			phraseCondition(phraseOne);
			++numOfPhrases;
			break;

			case 2:
			cin.get(phraseTwo, MAX_LENGTH, '\n');
			cin.ignore(1000, '\n');
			phraseCondition(phraseTwo);
			++numOfPhrases;
			break;
		
			case 3:
			cin.get(phraseThree, MAX_LENGTH, '\n');
			cin.ignore(1000, '\n');
			phraseCondition(phraseThree);
			++numOfPhrases;
			break;

			case 4:
			cin.get(phraseFour, MAX_LENGTH, '\n');
			cin.ignore(1000, '\n');
			phraseCondition(phraseFour);
			++numOfPhrases;
			break;
		}
		if(phraseCount < 4)
		{
			cout << "Would you like to enter another? <y/n>: " << endl;
			cin >> exitInput;
			cin.ignore(100, '\n');
		}
		//our exit condition
		if(phraseCount == 4 || exitInput == 'n') { exit = true; phraseCount = 0; }
		++phraseCount;

	}



	cout << "What order would you like your phrases in? " << endl
		<< "Please enter numbers one at a time, followed by a return: " << endl;

	for(int i = 0; i < numOfPhrases; ++i)
	{
		cin >> order[i];
		cin.ignore(100, '\n');
	}

	for(int i = 0; i < numOfPhrases; ++i)

		switch(order[i])
		{
			case 1:
				cout << phraseOne << " ";
				break;
			case 2: 
				cout << phraseTwo << " ";
				break;
			case 3: 
				cout << phraseThree << " ";
				break;
			case 4: 
				cout << phraseFour << " ";
				break;
			default:
				break;
		}

	cout << "\n\nFrom " << signature << endl; // Adding signature to end of phrase combination.


	cout << "\n\nWould you like to run this program again? <y/n>:" << endl;
	cin >> exitInput;
	cin.ignore(100,'\n');
	if(exitInput == 'n') { finalExit = true; }
	exit = false; // setting exit condition back so user can run program again
	numOfPhrases = 0;

}
	// ------------End Program------------
	cout << "\n\nThank you for using this program!";

	return 0;


	}




// function that checks the phrase and makes sure it's valid. Also capitalizes the first character
void phraseCondition(char phrase[])
{

	int size = strlen(phrase);
	//checking that last character of phrase ends in . ! or ?
	while(phrase[size-1] != '.' && phrase[size-1] != '!' && phrase[size-1] != '\?')
	{
		cout << "Your phrase doesn't end in a valid character, please try again." << endl;

		cin.get(phrase, 130, '\n');
		cin.ignore(100, '\n');
		size = strlen(phrase); //resetting size of array to new string
	}	


	//remove double spaces and capitalize first letter
	for(int i = 0; i < size; ++i)
	{
		phrase[0] = toupper(phrase[0]);
		if(isspace(phrase[i]) && isspace(phrase[i+1]))
			for(int j = i+1; j < MAX_SIZE; ++j)
				phrase[j] = phrase[j+1];
	}
}

// this function just capitalizes our users signature
void capSignature(char signature[])
{
	int size = strlen(signature);

// remove any extra white space and capitalize letters after white space
	for(int i = 0; i < size; ++i)
		{
			if(isspace(signature[i]) && isspace(signature[i+1]))
			{
				for(int j = i+1; j < size; ++j)
					signature[j] = signature[j+1];
			}
			if(isspace(signature[i]) && isalpha(signature[i+1]))
						signature[i+1] = toupper(signature[i+1]);
		}
//capitalize first letter
	signature[0] = toupper(signature[0]);
}









