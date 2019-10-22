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


// ------------Functions--------------------
void phraseCondition(char* phrase); // this checks and makes sure the phrases have the correct conditions

void capSignature(char* signature); // this makes sure the signature is capitalized

int main()
{
	const int MAX_LENGTH = 130; // Max size of the arrays
	
	char phraseOne[MAX_LENGTH], phraseTwo[MAX_LENGTH], phraseThree[MAX_LENGTH], phraseFour[MAX_LENGTH], signature[MAX_LENGTH];// all of arr character arrays set to max length
	char exitInput;// when the user wants to stop entering phrases 

	cout << "Hi, the purpose of this program is to make life easier for you." << endl;
	cout << "Lets start by getting your signature please: " << endl;

	cin.get(signature, MAX_LENGTH, '\n');
	cin.ignore(150, '\n');	
//checking signature and making sure its lookin good
	capSignature(signature);
	cout << "Hello " << signature << " nice to meet you!" << endl;


//iterating through each of the phrases, i being equal to five is our exit condition

	for(int i = 1; i < 5; ++i)
	{
		
		cout << "Please enter phrase number " << i << endl;
		
		switch(i)
		{
			case 1:
			cin.get(phraseOne, MAX_LENGTH, '\n');
			cin.ignore(100, '\n');
			phraseCondition(phraseOne);
			break;

			case 2:
			cin.get(phraseTwo, MAX_LENGTH, '\n');
			cin.ignore(1000, '\n');
			phraseCondition(phraseTwo);
			break;
		
			case 3:
			cin.get(phraseThree, MAX_LENGTH, '\n');
			cin.ignore(1000, '\n');
			phraseCondition(phraseThree);
			break;

			case 4:
			cin.get(phraseFour, MAX_LENGTH, '\n');
			cin.ignore(1000, '\n');
			phraseCondition(phraseFour);
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



// function that checks the phrase and makes sure it's valid. Also capitalizes the first character
void phraseCondition(char* phrase)
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

void capSignature(char* signature)
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









