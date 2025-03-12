#include "User.h"
#include "GlobalConstants.h"

User::User(size_t userId, char* name, double balance)
{

}

void User::setUserId(size_t userId)
{
	if (userId < 0)
	{
		std::cout << "Invalid user id";
		this->userId = 0;
	}

	this->userId = userId;
}

void User::setName(char* name)
{
	if (!name)
	{
		std::cout << "Invalid name";
		strcpy_s(this->name, sizeof(GlobalConstants::UNKNOWN_USER), GlobalConstants::UNKNOWN_USER);
		return;
	}

	strcpy_s(this->name, sizeof(name), name);
}
