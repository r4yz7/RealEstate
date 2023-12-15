#pragma once
#include "User.h"
#include <string>
#include <list>
#include "Address.h"
#include "Property.h"

class Estate
{
private:
    std::list<User> users;
    User currentUser;
    std::list<Address> addresses;
    std::list<Property> properties;

public:
    Estate();
    void createUser();
    bool loginUser();
    void mainMenu();
    bool postNewProperty();
    void removeProperty();
    void printAllProperties() const;
    void printUserProperties() const;
    void searchProperties() const;
};
