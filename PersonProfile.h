//
//  PersonProfile.hpp
//  PersonProfile
//
//  Created by Nick Johnson on 3/15/22.
//

#ifndef PersonProfile_hpp
#define PersonProfile_hpp

#include <stdio.h>
#include <set>
#include "provided.h"
#include "utility.h"
#include "RadixTree.h"

class PersonProfile
{
public:
    
PersonProfile(std::string name, std::string email);

~PersonProfile();
    
    std::string GetName() const;
    
    std::string GetEmail() const;

    void AddAttValPair(const AttValPair& attval);
    
    int GetNumAttValPairs() const;
    
    bool GetAttVal(int attribute_num, AttValPair& attval) const;
    
private:
    
    std::string m_email;
    std::string m_name;
    std::set<AttValPair> s1;
    
    //RadixTree<std::string> r;
    
    
};

#endif /* PersonProfile_hpp */
