#include "base.h"



//this is the header file for all the derived classes of the base class



//swim class
class swim : public base
{
	public:
		//constructors and destructor
		swim();		~swim();
		swim(const swim & toCopy);
		swim(int length, int priority, bool group, char* name, char* location, char* swimsuit, bool member, bool hasHotTub);

		void display();	//display function

		void startExercise();	//user can se wether or not they want to work out on this trip





	private:
		char* swimSuit;	//type of swimsuit or color of swim suit, upto the user
		bool member;	//if they are a member of the pool club
		bool hasHotTub;	//if the pool has a hot tub
		bool exercise;	//true if they was to work out on this trip, false otherwise




};



//hiking class
class hike : public base
{
	public:
		//constructor and destructor
		hike();		~hike();
		hike(const hike & toCopy);
		hike(int length, int priority, bool group, char* name, char* location, bool overNight, char* season, char* weather);

		void display();	//display function

		bool rockClimb();	//prompts the user if they was to pack rock climbining shoes


	private:
		bool overNight;	//true if the hike is going to be overnight
		char* season;	//season
		char* weather;	//weather suny, rainy etc
		bool climbShoes;//true if they packed rock climbing shoes
		



};


//work class
class work : public base
{
	public:
		//work class constructor and destructor
		work();		~work();
		work(const work& toCopy);
		work(int length, int priority, bool group, char* name, char* location, char* position, int pay, bool partTime);

		void display();	//display functions

		void planLunch();	//prompts the user as to which luinch they want to pack



	private:
		char* position;	//position at work manager, floor staff etc
		double pay;	//pay per hour
		bool partTime;	//true if part time job, fals otherwise
		char* lunch;	//their lunch tehy packed


};
