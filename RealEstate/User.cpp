#include "User.h"

User::User(std::string username, std::string password, std::string numberOfPhone, bool isBroker,int limit)
    : username(username), password(password), numberOfPhone(numberOfPhone), isBroker(isBroker), limit(limit){}
User::User(){}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

std::string User::getNumberOfPhone() const {
    return numberOfPhone;
}

bool User::getIsBroker() const {
    return isBroker;
}

int User::getLimit()const {
    return limit;
}
void User::setLimit(int newLimit) {
    limit = newLimit;
}
