#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;




class title
{
	public:
		//copy constructor and defauly, as well as descturcot
		title(char* name, char* date);
		title(const title & title);
		title();	~title();	
		
	//display function
		void display();

	//get/setters
		void changeTitle(char* name, char* date);
		void changeTitle(const title & toChange);
		void setTitleName(char* name);
		void setTitleDate(char* date);
		
	protected:
		char* name;	//name of title
		char* date;	//date of title
};





class video : public title	//video is a title so it conatins its member functions
{

	public:
		//constructors and destructor
		video();	~video();	
		video(char* name, char* date, char* description, double length);
		video(const video & toCopy);

		//display function
		void display();


		//functions to change members of the class
		void changeVideo(double length, char* description);
		void changeVideo(const video & toChange);


	protected:
		char* description;	//description of video
		double length;		//length of video
};

class liveStream : public video
{
	public:
		//construcotrs and desturcots
		liveStream();	~liveStream();
		liveStream(char* name, char* date, char* description, double length, char* instructor, char* topic);
		liveStream(const liveStream & toCopy);

		//change stream and display fucntions
		void changeStream(const liveStream & toChange);
		void display();



	protected:
		char* instructor;	//instructor teaching the liveStream
		char* topic;		//topic of the liveStream

};

