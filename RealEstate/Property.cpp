#include "Property.h"

Property::Property(Address address, int numberOfRooms, int price, std::string type, bool isRented, int floor, User* owner) :address(address), rooms(numberOfRooms),
price(price), type(type), isRented(isRented), floor(floor), owner(owner){}

Address Property::getAddress() const {
	return address;
}
int Property::getRooms()const {
	return rooms;
}
int Property::getPrice() const {
	return price;
}
std::string Property::getType() const {
	return type;
}
bool Property::getIsRented() const {
	return isRented;
}
int Property::getFloor() const {
	return floor;
}
User* Property::getOwner() const {
	return owner;
}
std::string Property::toString() const {
	std::string propertyTypeStr = type;
	std::string saleOrRent = isRented ? "Rent" : "Sale";

	std::string floorStr = (floor != 999) ? "Floor " + std::to_string(floor) + ". " : "";

	return propertyTypeStr + ": " + std::to_string(rooms) + " room. " + floorStr +
		"\nPrice: " + std::to_string(price) + " $." +
		"\nnumber: " + owner->getUsername() + " " + owner->getNumberOfPhone() +
		(owner->getIsBroker() ? " (broker)" : " (individual)") + "\n";
}