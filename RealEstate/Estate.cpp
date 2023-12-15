#include "Estate.h"
#include <iostream>

void Estate::mainMenu() {
    int menu=0;
    do
    {
        system("cls");
        std::cout << "1 - Add new property" << std::endl;
        std::cout << "2 - Remove property" << std::endl;
        std::cout << "3 - Show all" << std::endl;
        std::cout << "4 - Show everything sent by user" << std::endl;
        std::cout << "5 - Search by parameter" << std::endl;
        std::cout << "6 - Exit and go to main menu" << std::endl;
        std::cout << "Choice: ";
        std::cin >> menu;

        switch (menu)
        {
        case 1: {
            if (Estate::postNewProperty())
                std::cout << "Property added\n";
            else
                std::cout << "Propery not added\n";
        }break;
        case 2: {
            Estate::removeProperty();
        }break;
        case 3: {
            Estate::printAllProperties();
            system("pause");

        }break;
        case 4: {
            Estate::printUserProperties();
            system("pause");

        }break;
        case 5: {
            Estate::searchProperties();
            system("pause");
        }break;
        default:
            break;
        }
    } while (menu!=6);
}

Estate::Estate() {
    addresses.push_back(Address("Kyiv", "Sadova"));
    addresses.push_back(Address("Kyiv", "Maya"));
    addresses.push_back(Address("Kyiv", "Agregatna"));
    addresses.push_back(Address("Dnipro", "Avtoparkova"));
    addresses.push_back(Address("Dnipro", "Agrarna"));
}

bool Estate::loginUser() {
    system("cls");
    std::string password;
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    User user;
    bool t = 0;
    for (const auto& u : users) {
        if (u.getUsername() == username && u.getPassword() == password) {
            currentUser = u;
            return true;
        }
    }
    return false;
}

void Estate::createUser()
{
    bool usernameValidate = true;
    std::string number = "";
    std::string username = "";
    std::string password = "";
    bool isBroker;

    do
    {
        system("cls");
        std::cout << "Enter username: ";
        std::cin >> username;

        int t = 0;
        for (const auto& user : users)
        {
            if (user.getUsername() == username)
            {
                std::cout << "Enter another username" << std::endl;
                usernameValidate = false;
                t++;
            }
        }

        if (t == 0)
            usernameValidate = true;

        system("pause");

    } while (!usernameValidate);

    bool passwordValidate = true;
    do
    {
        system("cls");
        std::cout << "Enter password: ";
        std::cin >> password;

        if (password.find_first_of("0123456789") != std::string::npos && password.find_first_of("_%$") != std::string::npos)
            passwordValidate = true;
        else
        {
            passwordValidate = false;
            std::cout << "The password is not strong" << std::endl;
        }

        system("pause");

    } while (!passwordValidate);

    bool phoneValidate = true;
    do
    {
        system("cls");
        std::cout << "Enter phone number(05xxxxxxxx): ";
        std::cin >> number;

        if (number.length() ==10 && number.substr(0, 2) == "05")
        {
            phoneValidate = true;
        }
        else
        {
            phoneValidate = false;
            std::cout << "Enter another number" << std::endl;
        }

        system("pause");

    } while (!phoneValidate);

    bool validateBroker = true;
    do
    {
        system("cls");
        std::cout << "Is broker(y/n): ";
        std::string broker;
        std::cin >> broker;

        if (broker == "y")
        {
            isBroker = true;
        }
        else if (broker == "n")
            isBroker = false;
        else
        {
            validateBroker = false;
        }

    } while (!validateBroker);

    int limit = 3;
    if (isBroker)
        limit = 10;

    User user(username, password, number, isBroker,limit);
    users.push_back(user);
    std::cout << "User created!" << std::endl;
}

bool Estate::postNewProperty() {
    if (currentUser.getLimit() == 0) {
        std::cout << "You have reached the limit for posting new properties." << std::endl;
        return false;
    }

    std::cout << "Cities in the system:" << std::endl;
    std::list<std::string> uniqueCities;
    for (const auto& address : addresses) {
        if (std::find(uniqueCities.begin(), uniqueCities.end(), address.getCity()) == uniqueCities.end()) {
            uniqueCities.push_back(address.getCity());
            std::cout << address.getCity() << std::endl;
        }
    }

    std::string chosenCity;
    std::cout << "Enter the name of the city: ";
    std::cin >> chosenCity;

    auto cityIt = std::find(uniqueCities.begin(), uniqueCities.end(), chosenCity);
    if (cityIt == uniqueCities.end()) {
        std::cout << "Invalid city name. Please try again." << std::endl;
        return false;
    }

    std::cout << "Streets in " << chosenCity << ":" << std::endl;
    for (const auto& address : addresses) {
        if (address.getCity() == chosenCity) {
            std::cout << address.getStreet() << std::endl;
        }
    }

    std::string chosenStreet;
    std::cout << "Enter the name of the street: ";
    std::cin >> chosenStreet;

    bool streetValid = false;
    for (const auto& address : addresses) {
        if (address.getCity() == chosenCity && address.getStreet() == chosenStreet) {
            streetValid = true;
            break;
        }
    }

    if (!streetValid) {
        std::cout << "Invalid street name. Please try again." << std::endl;
        return false;
    }

    int propertyType;
    std::cout << "Enter the type of property (1 - Apartment, 2 - Penthouse, 3 - House): ";
    std::cin >> propertyType;

    int floor = 0;
    if (propertyType == 1) {
        std::cout << "Enter the floor number: ";
        std::cin >> floor;
    }

    int numberOfRooms;
    std::cout << "Enter the number of rooms: ";
    std::cin >> numberOfRooms;

    int price;
    std::cout << "Enter the price: ";
    std::cin >> price;

    bool isRented;
    std::cout << "Is the property for rent? (1 - Yes, 0 - No): ";
    std::cin >> isRented;

    Property newProperty(Address(chosenCity, chosenStreet), numberOfRooms, price,
        (propertyType == 1) ? "Apartment" : (propertyType == 2) ? "Penthouse" : "House",
        isRented, floor, &currentUser);
    properties.push_back(newProperty);
    std::cout << "Property posted successfully!" << std::endl;
    currentUser.setLimit(currentUser.getLimit() - 1);

    return true;

}
void Estate::removeProperty() {
    if (currentUser.getLimit() == 3) {
        std::cout << "You haven't published any properties yet." << std::endl;
        return;
    }

    int index = 1;
    std::cout << "Properties published by you:" << std::endl;
    for (const auto& property : properties) {
        if (property.getOwner() == &currentUser) {
            std::cout << index << ". " << "Type: " << property.getType() << ", Address: "
                << property.getAddress().getCity() << ", " << property.getAddress().getStreet() << std::endl;
            index++;
        }
    }

    int choice;
    std::cout << "Enter the number of the property you want to remove: ";
    std::cin >> choice;

    index = 1;
    for (auto it = properties.begin(); it != properties.end(); ++it) {
        if (it->getOwner() == &currentUser) {
            if (index == choice) {
                properties.erase(it);
                std::cout << "Property removed successfully." << std::endl;
                currentUser.setLimit(currentUser.getLimit() + 1);
                return;
            }
            index++;
        }
    }

    std::cout << "Invalid property number. Removal failed." << std::endl;
}

void Estate::printAllProperties() const {
    std::cout << "All properties in the system:" << std::endl;
    for (const auto& property : properties) {
        std::cout << property.toString();
    }
}

void Estate::printUserProperties() const {
    std::cout << "Your properties:" << std::endl;
    for (const auto& property : properties) {
        if (property.getOwner() == &currentUser) {
            std::cout << property.toString();
        }
    }
}
void Estate::searchProperties() const {
    std::string saleOrRent;
    int propertyType, numberOfRooms, minPrice, maxPrice;

    std::cout << "Rent or Sale? (1 - Rent, 2 - Sale, 999 - doesn't matter): ";
    std::cin >> saleOrRent;

    std::cout << "Type? (1 - Apartment, 2 - Penthouse, 3 - House, 999 -  doesn't matter): ";
    std::cin >> propertyType;

    std::cout << "Rooms? (999 - doesn't matter): ";
    std::cin >> numberOfRooms;

    std::cout << "Price (min and max)? (999 - doesn't matter): ";
    std::cin >> minPrice >> maxPrice;

    std::cout << "\nResult:\n";
    for (const auto& property : properties) {
        bool match = true;

        if (saleOrRent != "999" && (property.getIsRented() != (saleOrRent == "1"))) {
            match = false;
        }

        if (propertyType != 999 && (propertyType != 1 && propertyType != 2 && propertyType != 3)) {
            match = false;
        }

        if (numberOfRooms != 999 && property.getRooms() != numberOfRooms) {
            match = false;
        }

        if ((minPrice != 999 && property.getPrice() < minPrice) || (maxPrice != 999 && property.getPrice() > maxPrice)) {
            match = false;
        }

        if (match) {
            std::cout << property.toString();
        }
    }
}