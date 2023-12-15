#pragma once
#include <string>
class Address
{
private:
	std::string city;
	std::string street;
public:
	Address(std::string city, std::string street);

	std::string getCity() const;
	std::string getStreet() const;
};

