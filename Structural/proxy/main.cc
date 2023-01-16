#include <iostream>

using namespace std;

class Communication{
public:
    virtual void communicate() = 0;
    virtual ~Communication() {}
};

class Speaker : public Communication{
public:
    void communicate() override{
        cout << "开始说话..." << endl;
        cout << "通话时发生了一些列的表情变化..." << endl;
    }
};

class DenDenMushi: public Communication{
public:
    DenDenMushi(){
        m_isStart = true;
        m_speaker = new Speaker;
    }
    ~DenDenMushi(){
        if (m_speaker != nullptr){
            delete m_speaker;
        }
    }
    bool isStart(){
        return m_isStart;
    }

    void communicate() override{
        if (isStart()){
            cout << "电话虫开始实时模仿通话者的语言和表情..." << endl;
            m_speaker -> communicate();
        }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};

int main(){
    Communication* comm = new Speaker;
    comm -> communicate();
    delete comm;
    cout << "===================================" << endl;
    
    comm = new DenDenMushi;
    comm -> communicate();
    delete comm;

    return 0;
}