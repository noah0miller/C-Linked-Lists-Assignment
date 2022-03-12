#include "phoneList.h"

//Implementation file
//Noah Miller
//Implements constructor, destructor, PhoneList class functions

PhoneList::PhoneList(string newTitle)
{
	title = newTitle;
	numDirectories = 0;
	firstPtr = NULL;
}

void PhoneList::addDirectory(string newName, int newArea, int newPhone)
{
	newName = newName.empty() ? "No Name" : newName;
	newArea = newArea < 100 || newArea > 999 ? 999 : newArea;
	newPhone = newPhone < 1000000 || newPhone > 9999999 ? 9999999 : newPhone;

	Directory* stalker = NULL;
	Directory * walker = firstPtr;

	while (walker != NULL)
	{
		if (walker->name >= newName)
			break;
		stalker = walker;
		walker = walker->link;
	}
	if (walker != NULL && walker->name == newName)
	{
		cout << "The directory for " << newName << " already exists." << endl << endl;
	}
	else
	{
		Directory* builder = new Directory;
		assert(builder);
		builder->name = newName;
		builder->areaCode = newArea;
		builder->phoneNo = newPhone;
		builder->link = walker;
		if (walker == firstPtr)
			firstPtr = builder;
		else
			stalker->link = builder;
		numDirectories++;
	}
}

void PhoneList::showList(ostream& out) const
{
	if (firstPtr == NULL)
		out << "There are no directories." << endl;
	else
	{
		out << title << endl;
		out << setw(15) << left << "Name" << setw(15) << "Area Code" << setw(15) << right << "Phone Number" << endl << endl;

		Directory* walker = firstPtr;
		while (walker != NULL)
		{
			string phoneNumber = to_string(walker->phoneNo);

			out << setw(15) << left << walker->name << setw(15) << walker->areaCode << setw(15) << right << phoneNumber.insert(3, "-") << endl;
			walker = walker->link;
		}
		out << endl << "Number of directories: " << numDirectories << endl << endl;
	}
}

void PhoneList::removeDirectory(string passedName)
{
	Directory* walker = firstPtr;
	Directory* stalker = NULL;

	while (walker != NULL)
	{
		if (walker->name == passedName)
			break;

		stalker = walker;
		walker = walker->link;
	}

	if (walker == NULL)
		cout << "The " << passedName << " directory does not exist." << endl;
	else if (stalker == NULL)
	{
		firstPtr = walker->link;
		delete walker;
		cout << "The " << passedName << " directory has been removed." << endl;
		numDirectories--;
	}
	else
	{
		stalker->link = walker->link;
		delete walker;
		cout << "The " << passedName << " directory has been removed." << endl;
		numDirectories--;
	}
}

PhoneList::~PhoneList()
{
	Directory* walker = firstPtr;
	while (walker != NULL)
	{
		firstPtr = walker->link;
		delete walker;
		walker = firstPtr;
	}
}