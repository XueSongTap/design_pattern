#include <iostream>
#include "Sanji.h"
#include <vector>
#include "State.h"

using namespace std;

void ForenoonState::working(Sanji* sanji) {
    int time = sanji -> getClock();
    if (time < 8){
        cout << "当前时间<" << time << ">点, 准备早餐, 布鲁克得多喝点牛奶..." << endl;
    } else if (time > 8 && time < 11){
        cout << "当前时间<" << time << ">点, 去船头钓鱼, 储备食材..." << endl;
    }else {
        sanji -> setState(new NoonState);
        sanji -> working();
    }
}

void NoonState::working(Sanji* sanji) {
    int time = sanji -> getClock();
    if (time < 13){
        cout << "当前时间<" << time << ">点, 去厨房做午饭, 给路飞多做点肉..." << endl;
    }else {
        sanji -> setState(new AfternoonState);
        sanji -> working();
    }
}
void AfternoonState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 15)
    {
        cout << "当前时间<" << time << ">点, 准备下午茶, 给罗宾和娜美制作爱心甜点..." << endl;
    }
    else if (time > 15 && time < 18)
    {
        cout << "当前时间<" << time << ">点, 和乔巴去船尾钓鱼, 储备食材..." << endl;
    }
    else
    {
        sanji->setState(new EveningState);
        sanji->working();
    }
}


void EveningState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 19)
    {
        cout << "当前时间<" << time << ">点, 去厨房做晚饭, 让索隆多喝点汤..." << endl;
    }
    else
    {
        cout << "当前时间<" << time << ">点, 今天过得很高兴, 累了睡觉了..." << endl;
    }
}



int main() {
    Sanji * sanji = new Sanji;

    vector<int> data{7, 10, 12, 14, 16, 18, 22};
    for (const auto& item : data) {
        sanji -> setClock(item);
        sanji -> working();
    }

    delete sanji;
    return 0;
}
