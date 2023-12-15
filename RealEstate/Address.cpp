#include "Address.h"

Address::Address(std::string city, std::string street) :city(city), street(street){}
std::string Address::getCity() const {
	return city;
}

std::string Address::getStreet() const {
	return street;
}
