using namespace ci;
using namespace ci::app;
using namespace std;

class Metronome {
public:
    float mTempo;
    long long mMillis;
    
    void setUp(int);
    bool bang();
};

void Metronome::setUp(int speed){
    mMillis=ci::app::getElapsedSeconds()*1000;
    mTempo=speed;
}

bool Metronome::bang(){
    bool mTrigger=false;
    if (fabs(ci::app::getElapsedSeconds()*1000 - mMillis) >= mTempo){
        mTrigger=true;
        mMillis += mTempo ;
    } else {
        mTrigger=false;
    }
    return mTrigger;
}