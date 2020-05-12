#include "derived.h"


//Swim class constructors and destructor
swim::swim() : swimSuit(NULL), member(false), hasHotTub(NULL), exercise(false) {}


//copy constructor
swim::swim(const swim& toCopy) : base(toCopy), member(toCopy.member), hasHotTub(toCopy.hasHotTub), exercise(toCopy.exercise)
{
	if(toCopy.swimSuit)
	{
		cout << "Copying swimsuit string: " << toCopy.swimSuit << endl;
		swimSuit = new char[strlen(toCopy.swimSuit) + 1];
		strcpy(this->swimSuit, toCopy.swimSuit);
	}
}

//constructor when given all the members as arguments
swim::swim(int length, int priority, bool group, char* name, char* location, char* swimSuit, bool member, bool hasHotTub) : 
	base(length, priority, group, name, location), member(member), hasHotTub(hasHotTub), exercise(false)
{
	this->swimSuit = new char[strlen(swimSuit) + 1];
	strcpy(this->swimSuit, swimSuit);
}


//swim class destructor deleting only dynamically allocated array
swim::~swim() 
{
	delete [] this->swimSuit;
	this->swimSuit = NULL;
}


//swim class functions
void swim::display()
{
	base::display();

	cout << "Swimsuit: " << swimSuit << endl;

	if(hasHotTub)
		cout << "Has a hot tub" << endl;
	else
		cout << "Does not have a hot tub" << endl;
	if(member)
		cout << "Requires membership" << endl;
	else
		cout << "Does not require membership" << endl;
	if(exercise)
		cout << "You plan to exercise on this trip" << endl;
	else
		cout << "You do not plan to exercise on this trip" << endl;
}


//prompts the user if the want to plan an exercise on this trip
void swim::startExercise()
{
	char input;

	cout << "Would you like to exercise on this trip? <y,n>: " << endl;
	cin >> input;	cin.ignore(100, '\n');
	if(input == 'y')
		exercise = true;
	else
		exercise = false;
	cout << "You can change this at any time" << endl;
}




//hike class constructors and destructor
hike::hike() : overNight(false), season(NULL), weather(NULL), climbShoes(false) {}


//hike copy constructor
hike::hike(const hike & toCopy) : base(toCopy), overNight(toCopy.overNight), climbShoes(toCopy.climbShoes)
{
	if(toCopy.season && toCopy.weather)
	{
		this->season = new char[strlen(toCopy.season) + 1];
		this->weather = new char[strlen(toCopy.weather) + 1];

		strcpy(this->season, toCopy.season);
		strcpy(this->weather, toCopy.weather);
	}
}

//hike constructor when given all members as, arguments
	hike::hike(int length, int priority, bool group, char* name, char* location, bool overNight, char* season, char* weather)
: base(length, priority, group, name, location), overNight(overNight), climbShoes(false)
{
	this->season = new char[strlen(season) + 1];
	this->weather = new char[strlen(weather) + 1];

	strcpy(this->season, season);
	strcpy(this->weather, weather);
}

//hike destrucotr deleting all dynamically allocated memory
hike::~hike()
{
	delete [] this->season;
	delete [] this->weather;

	this->season = NULL;
	this->weather = NULL;
}



//hike class functions
//displayu funtiuons
void hike::display()
{
	base::display();
	if(overNight)
		cout << "Overnight" << endl;
	else
		cout << "Day hike" << endl;
	cout << "Season: " << season << endl
		<< "Weather: " << weather << endl;

}


//prompts the user if they want to pack rock climbing shoes
bool hike::rockClimb()
{
	char input;
	if(climbShoes)
		cout << "You have packed climbing shoes" << endl;
	else
	{
		cout << "YOu have not packed climbing shoes, would you like to? <y,n>: ";
		cin >> input;	cin.ignore(100, '\n'); cout << endl;
		if(input == 'y')
			climbShoes = true;
	}
}




//work class constructors and destructor
work::work() : position(NULL), pay(-1), partTime(false), lunch(NULL) {}


//work class constructor when given the information as arguments
	work::work(int length, int priority, bool group, char* name, char* location, char* position, int pay, bool partTime)
: base(length, priority, group, name, location), pay(pay), partTime(partTime), lunch(NULL)
{
	this->position = new char[strlen(position) + 1];
	strcpy(this->position, position);
}

//work class copy constructor
work::work(const work& toCopy) : base(toCopy), pay(toCopy.pay), partTime(toCopy.partTime)
{
	if(toCopy.position)
	{
		this->position = new char[strlen(toCopy.position) + 1];
		strcpy(this->position, toCopy.position);
	}

	if(toCopy.lunch)
	{
		this->lunch = new char[strlen(toCopy.lunch) + 1];
		strcpy(this->lunch, toCopy.lunch);
	}
}
//work class destructor
work::~work()
{
	delete [] this->position;
	this->position = NULL;
}


//work class functions
//usual display fucntion
void work::display()
{
	base::display();
	cout << "Position: " << position << endl
		<< "Pay: " << pay << endl;
	if(partTime)
		cout << "Part time job" << endl;
	else
		cout << "Full time job" << endl;
	if(lunch == NULL)
		cout << "No lunch planned" << endl;
	else
		cout << "Lunch: " << lunch << endl;
}

//prompts the user for which type of lunch they would like to pack
void work::planLunch()
{
	char input;
	char lunch[30];

	cout << endl << "Would you like to pack a lunch? <y,n>: ";
	cin >> input;	cin.ignore(100, '\n');	cout << endl;

	if(input == 'y')
	{
		cout << "What would you like to pack: ";
		cin.get(lunch, 100, '\n');	cin.ignore(100, '\n');	 cout << endl;

		if(this->lunch)
		{
			delete this->lunch;
			this->lunch = new char[strlen(lunch) + 1];
			strcpy(this->lunch, lunch);
		}
		else
		{
			this->lunch = new char[strlen(lunch) + 1];
			strcpy(this->lunch, lunch);	
		}
	}
}

