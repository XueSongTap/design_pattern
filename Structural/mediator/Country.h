#pragma once
#include <string>
#include <iostream>
#include "Mediator.h"
using namespace std;

// 抽象国家类
class Country
{
public:
    Country(MediatorOrg* mediator) : m_mediator(mediator) {}
    // 发表声明
    virtual void declare(string msg, string country) = 0;
    virtual void setMessage(string msg) = 0;
    virtual string getName() = 0;
    virtual ~Country() {}
protected:
    MediatorOrg* m_mediator = nullptr;
};

// 阿拉巴斯坦
class Alabasta : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "阿拉巴斯坦得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "阿拉巴斯坦";
    }
};

// 德雷斯罗萨
class Dressrosa : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "德雷斯罗萨得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "德雷斯罗萨";
    }
};

// 露露西亚王国
class Lulusia : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "露露西亚得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "露露西亚";
    }
};

// 卡玛巴卡王国
class Kamabaka : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "卡玛巴卡得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "卡玛巴卡";
    }
};
