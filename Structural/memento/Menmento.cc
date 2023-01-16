#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



class History{
public:
    History(string msg) : m_msg(msg) {}
    string getHistory(){
        return m_msg;
    }
private:
    string m_msg;
};

class JiaoPenji{
public:
    void setState(string msg){
        m_msg = msg;
    }
    string getState(){
        return m_msg;
    }
    void beiDaddyDa()
    {
        cout << "脚盆鸡被兔子狠狠地揍了又揍, 终于承认了它们之前不承认的这些罪行: " << endl;
    }

    History* saveHistory(){
        return new History(m_msg);
    }

    void getStateFrontHistory(History* History){
        m_msg = History -> getHistory();
    }
private:
    string m_msg;
};

class Recorder{
public:
    void addHistory(int index, History* history){
        m_history.emplace(make_pair(index, history));
    }

    History* getHistory(int index){
        if (m_history.find(index) != m_history.end()){
            return m_history[index];
        }
        return nullptr;
    }
private:
    map<int, History*> m_history;
};

int main(){
    vector<string> msg{
        "不承认偷了中国的中医!!!",
        "不承认发动了侵华战争!!!",
        "不承认南京大屠杀!!!!",
        "不承认琉球群岛和钓鱼岛是中国的领土!!!",
        "不承认731部队的细菌和人体试验!!!",
        "不承认对我国妇女做出畜生行为!!!",
        "不承认从中国掠夺的数以亿计的资源和数以万计的文物!!!",
        "我干的龌龊事儿罄竹难书, 就是不承认......"
    };
    JiaoPenji* jiaopen = new JiaoPenji;
    Recorder* recorder = new Recorder;

    for (int i = 0; i < msg.size(); ++ i) {
        jiaopen -> setState(msg.at(i));
        recorder -> addHistory(i, jiaopen-> saveHistory());
    }
    jiaopen-> beiDaddyDa();
    for (int i = 0; i < msg.size(); i ++){
        jiaopen  -> getStateFrontHistory(recorder -> getHistory(i));
        cout << "  -- " << jiaopen->getState() << endl;
    }

    return 0;
}