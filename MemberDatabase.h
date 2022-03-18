//
//  MemberDataBase.hpp
//  MemberDataBase
//
//  Created by Nick Johnson on 3/15/22.
//

#ifndef MemberDataBase_hpp
#define MemberDataBase_hpp
#include <stdio.h>
#include <iostream>
#include "provided.h"
#include "PersonProfile.h"
#include <vector>
class MemberDatabase
{
public:
    
MemberDatabase();

~MemberDatabase();

    bool LoadDatabase(std::string filename);
    
std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    
const PersonProfile* GetMemberByEmail(std::string email) const;
    
private:
    RadixTree<std::vector<std::string>> rs;
    RadixTree<PersonProfile*> rp;
    std::vector<std::string> emails;
    
    
};
#endif /* MemberDataBase_hpp */
