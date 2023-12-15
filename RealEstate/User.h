#pragma once
#include <string>

class User
{
private:
    std::string username;
    std::string password;
    std::string numberOfPhone;
    bool isBroker;
    int limit;

public:
    User(std::string username, std::string password, std::string numberOfPhone, bool isBroker,int limit);
    User();
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getNumberOfPhone() const;
    bool getIsBroker() const;
    int getLimit()const;
    void setLimit(int newLimit);
};
