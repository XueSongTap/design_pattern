#pragma once
#include <map>
#include <string>
using namespace std;

class Country;

// 抽象的中介机构
class MediatorOrg
{
public:
    void addMember(Country* country);
    virtual void declare(string msg, Country* country, string name = string()) = 0;
    virtual ~MediatorOrg() {}
protected:
    map<string, Country*> m_countryMap;
};

class WorldGovt : public MediatorOrg{
public:
    void declare(string msg, Country* country, string name = string()) override;
};

// 革命军
class GeMingArmy : public MediatorOrg
{
public:
    void declare(string msg, Country* country, string name = string()) override;
};
