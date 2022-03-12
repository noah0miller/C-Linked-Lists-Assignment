#include "phoneList.h"

//Client code
//Noah Miller
//Friend function implementation. Creates PhoneList object and adds directories to it for testing.

ostream& operator << (ostream& output, const PhoneList& outPhone)
{
	output << outPhone.title << " has " << outPhone.numDirectories << " directory listings." << endl;
	return output;
}

int main()
{
	PhoneList* newPhone = new PhoneList("My Black Book");
	assert(newPhone);
	cout << "The title of the phone list is: " << newPhone->getTitle() << endl;
	cout << "The current number of directories is: " << newPhone->getNoDirectories() << endl << endl;

	newPhone->addDirectory("SLC", 111, 2222222);
	newPhone->addDirectory("Apple", 765, 7567562);
	newPhone->addDirectory("Noah Miller", 432, 1231232);
	newPhone->addDirectory("Microsoft", 1213, 45676803);
	newPhone->addDirectory("Apple", 123, 8686885);
	newPhone->addDirectory("Blackboard", 1234, 5454535);

	newPhone->showList(cout);

	newPhone->removeDirectory("SLC");
	newPhone->removeDirectory("Apple");
	newPhone->removeDirectory("Microsoft");
	newPhone->removeDirectory("Apple");
	newPhone->removeDirectory("CPA");
	cout << endl;

	newPhone->showList(cout);

	cout << *newPhone;
	cout << endl;
	delete newPhone;

	system("pause");
}