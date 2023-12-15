#pragma once
#include "Address.h"
#include "User.h"
class Property
{
private:
	Address address;
	int rooms;
	int price;
	std::string type;
	bool isRented;
	int floor;
	User* owner;

public:
	Property(Address address, int numberOfRooms, int price, std::string type, bool isRented, int floor, User* owner);
	Address getAddress() const;
	int getRooms()const;
	int getPrice() const;
	std::string getType() const;
	bool getIsRented() const;
	int getFloor() const;
	User* getOwner() const;
	std::string toString() const;
	
};

