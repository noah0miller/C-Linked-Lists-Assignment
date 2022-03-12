#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>

using namespace std;

//Specification file
//Noah Miller
//Purpose: defines PhoneList class & Directory struct, as well as their members. Includes header for friend function

struct Directory
{
	string name;
	int areaCode;
	int phoneNo;
	Directory* link;
};

class PhoneList
{
public:
	PhoneList(string = NULL /*title*/);
	~PhoneList();
	void showList(ostream& /*out*/) const;
	void addDirectory(string /*name*/, int /*phoneNo*/, int /*areaCode*/);
	void removeDirectory(string /*name*/);
	int getNoDirectories() { return numDirectories; };
	string getTitle() { return title; };
private:
	int numDirectories;
	string title;
	Directory* firstPtr;

	friend ostream& operator << (ostream&, const PhoneList&);
};
