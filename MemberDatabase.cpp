//
//  MemberDataBase.cpp
//  MemberDataBase
//
//  Created by Nick Johnson on 3/15/22.
//
#include "MemberDatabase.h"
#include <fstream>
#include <sstream>

MemberDatabase::MemberDatabase()
{
    
}
MemberDatabase::~MemberDatabase()
{
    
}
bool MemberDatabase::LoadDatabase(std::string filename)
{
        std::ifstream infile(filename);
        if(!infile)
            return false;
        
        std::string line;
    int n = 0;

        std::string name;
        std::string email;
        //int pairs;
        std::string att1;
        std::string att2;
    std::vector<std::string> v1;
        while(getline(infile, line))
        {
          
            std::istringstream iss(line);
            
            if(!getline(iss, name))
                break;
            getline(infile, line);
                email = line;
         
            getline(infile, line);
            
            while(getline(infile, line))
            {
                std::istringstream iss(line);

                if(!getline(iss, att1, ','))
                {
                    //getline(infile, line);
                    break;
                }
                if(!getline(iss, att2, ','))
                {
                   // getline(infile, line);
                    break;
                }
                AttValPair a1(att1, att2);
                std::string pair = att1 + att2;
                if(rp.search(email) == nullptr)
                {
                    
                    PersonProfile* p = new PersonProfile(name, email);
                    p->AddAttValPair(a1);
                    rp.insert(email, p);
                    
                    
                }
                else
                {
                    (*rp.search(email))->AddAttValPair(a1);
                }
                
                if(rs.search(pair) == nullptr)
                {
                    rs.insert(pair, v1);
                    (*rs.search(pair)).push_back(email);
                }
                else if(rs.search(pair))
                {
                    (*rs.search(pair)).push_back(email);
                }

            }
            

       

            
        }
        
    return true;
}


std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const
{
    std::vector<std::string> empty;
    std::string s = input.attribute + input.value;
    if(rs.search(s) == nullptr)
        return empty;
    else
        return(*rs.search(s));
}

const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const
{
 
    if(rp.search(email) == nullptr)
        return nullptr;
    else
        return(*rp.search(email));
}
