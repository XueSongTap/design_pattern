#include <iostream>
#include <new>
#include <string>
#include "Country.h"
#include "Mediator.h"
using namespace std;
// 基类的成员添加函数
void MediatorOrg::addMember(Country* country)
{
    m_countryMap.insert(make_pair(country->getName(), country));
}

// 在子类中重写发表声明的函数 
void WorldGovt::declare(string msg, Country* country, string name)
{
    if (m_countryMap.find(name) != m_countryMap.end())
    {
        string str = msg + "【来自: " + country->getName() + "】";
        m_countryMap[name]->setMessage(str);
    }
}

void MediatorOrg::declare(string msg, Country *country, string name) {
    string str = msg + "【来自: " + country->getName() + "】";
    for (const auto& item : m_countryMap) {
        if (item.second == country) {
            continue;
        }
        item.second -> setMessage(str);
    }
}
// 在子类中重写发表声明的函数 
void GeMingArmy::declare(string msg, Country* country, string name)
{
    string str = msg + "【来自: " + country->getName() + "】";
    for (const auto& item : m_countryMap)
    {
        if (item.second == country)
        {
            continue;
        }
        item.second->setMessage(str);
    }
}


int main() {
    WorldGovt* world = new WorldGovt;
    Alabasta* alaba = new Alabasta(world);
    Dressrosa* dresa = new Dressrosa(world);

    world -> addMember(alaba);
    world -> addMember(dresa);

    alaba->declare("德雷斯罗萨倒卖军火, 搞得我国连年打仗, 必须给个说法!!!", dresa->getName());
    dresa->declare("天龙人都和我多弗朗明哥做生意, 你算老几, 呸!!!", alaba->getName());
    cout << "======================================" << endl;

    GeMingArmy* geming = new GeMingArmy;
    Lulusia* lulu = new Lulusia(geming);
    Kamabaka* kama = new Kamabaka(geming);

    geming -> addMember(lulu);
    geming -> addMember(kama);
    lulu->declare("我草, 我的国家被伊姆毁灭了!!!", lulu->getName());


    delete world;
    delete alaba;
    delete dresa;
    delete geming;
    delete lulu;
    delete kama;
    return 0;
}