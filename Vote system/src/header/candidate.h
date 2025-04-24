#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "user.h"
#include <fstream>
#include <string>

class Candidate : public User {
private:
    std::fstream candLog;
    bool validate_cand();

public:
    std::string party;
    
    Candidate(std::string a, std::string b);
    ~Candidate();
    
    void showMenu() override;
};

#endif 