//
//  MatchMaker.cpp
//  MatchMaker
//
//  Created by Nick Johnson on 3/15/22.
//

#include "MatchMaker.h"

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at)
: m_mb(mdb), m_at(at)
{
  
}

MatchMaker::~MatchMaker()
{
    
}

std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email,
                                              int threshold) const
{
   // m_mb.LoadDatabase("members.txt");
    //m_mb.LoadDatabase("members.txt");
    const PersonProfile* p = m_mb.GetMemberByEmail(email);
    std::vector<AttValPair> v;
    std::vector<AttValPair> comp;
    std::vector<AttValPair> iter;
    std::vector<std::string> str;
    std::vector<std::string> strt;
    std::map<std::string, int> map;
    int n = p->GetNumAttValPairs();
    for(int i = 0; i < n; i++)
    {
        AttValPair a;
        p->GetAttVal(i, a);
        v.push_back(a);
    }
    
    for(int k = 0; k < v.size(); k++)
    {
        iter = m_at.FindCompatibleAttValPairs(v[k]);
        std::vector<AttValPair>::iterator it = iter.begin();
        
        while(it != iter.end())
        {
            comp.push_back((*it));
            it++;
        }
        
    }
    for(int i = 0; i < comp.size(); i++)
    {
        str = m_mb.FindMatchingMembers(comp[i]);
        std::vector<std::string>::iterator it = str.begin();
        
        while(it != str.end())
        {
            strt.push_back((*it));
            it++;
        }
    }
    
    for(int j = 0; j < strt.size(); j++)
    {
        std::map<std::string, int>::iterator it = map.find(strt[j]);
        
        if(it == map.end())
            map.insert(std::pair(strt[j], 1));
        else
        {
             it->second++;
        }
    }
    
    
    std::vector<EmailCount> v1;
    
    
    std::map<std::string, int>::iterator it = map.begin();
    
    while(it != map.end())
    {
        if(it->second >= threshold)
        {
            EmailCount e(it->first, it->second);
            v1.push_back(e);
        }
        it++;
    }
    
    
    std::sort(v1.begin(), v1.end(), std::greater<EmailCount>());
    return v1;
}
