#ifndef VOTER_H
#define VOTER_H

#include "user.h"

class Voter: public User {
private:

protected:
    Voter();

    void showMenu() override;

};

#endif