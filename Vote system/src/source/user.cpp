#include<string>
#include<iostream>
using namespace std;

class User {
protected:
    string username;
    string password;
public:
    User();
    User(const string& user, const string& pass);
    
    // Getters
    string getUsername() const;
    
    // Setters
    void setUsername(const string& user);
    void setPassword(const string& pass);
    
    // Authentication
    bool authenticate(const string& user, const string& pass) const;
    
    // Menu function
    virtual void showMenu() = 0;
};
