

#include <iostream>

using namespace std;

class CokeSystem{
public:
    void immitCoke(){
        cout << "狮吼炮原料<可乐>已经注入完毕..." << endl;
    }
};

class EnergySystem {
public:
    void energyConvert(){
        cout << "已经将所有的可乐转换为了能量..." << endl;
    }
};


class AimLockSystem{
public:
    void aimLock() {
        cout << "已经瞄准并且锁定了目标..." << endl;
    }
};

class Cannon{
public:
    void cannonFire(){
        cout << "狮吼炮正在向目标开火..." << endl;
    }
};


class WindCannon{
public:
    void WindCannonFire(){
        cout << "发射风来炮抵消后坐力稳定船身..." << endl;
    }
};

class LionCannon{
public:
    LionCannon(){
        m_coke = new CokeSystem;
        m_energy = new EnergySystem;
        m_aimLock = new AimLockSystem;
        m_cannon = new Cannon;
        m_windCannon = new WindCannon;
    }

    ~LionCannon(){
        delete m_coke;
        delete m_energy;
        delete m_cannon;
        delete m_windCannon;
    }

    void aimAndLock(){
        m_coke -> immitCoke();
        m_energy -> energyConvert();
        m_aimLock -> aimLock();
    }

    void fire(){
        m_cannon-> cannonFire();
        m_windCannon -> WindCannonFire();
    }
private:
    CokeSystem* m_coke = nullptr;
    EnergySystem* m_energy = nullptr;
    AimLockSystem* m_aimLock = nullptr;
    Cannon* m_cannon = nullptr;
    WindCannon* m_windCannon = nullptr;
};

int main() {
    LionCannon* lion = new LionCannon;
    lion -> aimAndLock();
    lion -> fire();

    delete lion;

    return 0;

}