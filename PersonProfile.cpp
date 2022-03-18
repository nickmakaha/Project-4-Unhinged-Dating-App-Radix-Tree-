//
//  PersonProfile.cpp
//  PersonProfile
//
//  Created by Nick Johnson on 3/15/22.
//

#include "PersonProfile.h"


PersonProfile::PersonProfile(std::string name, std::string email)
{
    m_name = name;
    m_email = email;
}

PersonProfile::~PersonProfile()
{
    
}

std::string PersonProfile::GetName() const
{
    return m_name;
}

std::string PersonProfile::GetEmail() const
{
    return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval)
{
    
    s1.insert(attval);
}

int PersonProfile::GetNumAttValPairs() const
{
    return s1.size();
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const
{
    if(attribute_num >= 0 && attribute_num < s1.size())
    {
    std::set<AttValPair>::iterator it;
        it = s1.begin();
    for(int i = 0; i < attribute_num; i++)
        it++;
        
        attval = (*it);
        return true;
    }
    return false;
}
