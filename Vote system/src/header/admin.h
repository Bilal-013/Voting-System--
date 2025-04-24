#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <fstream>
#include <iostream>
#include <string>

class admin: public User {
private:
    fstream adminLog;
    fstream reg_user;
    fstream reg_cand;
    
    bool validate_admin();

public:
    admin(string usr_name, string pass);
    ~admin();
    
    void admin_options();
    void add_user();
    void remove_user();
    void add_cand();
    void remove_cand();
};

#endif // ADMIN_H