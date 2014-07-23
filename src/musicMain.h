#ifndef chordProgressionGenerator_intialize_h
#define chordProgressionGenerator_intialize_h

using namespace ci;
using namespace ci::app;
using namespace std;

class Music {
public:
    
    
    void setUp(int length, int low, int high, int root);
    
    int progressionLength;
    void setProgressionLength(int);
    
    int setBassStyle();
    int chooseMode();
    int choosePedalNote();
    int transposeNote(int);
    int lowRange, highRange, base;
    
};

void Music::setUp(int length, int low, int high,int root){
    progressionLength=length;
    lowRange=low;
    highRange=high;
    base=root;
}

int Music::transposeNote(int transpose){
    transpose=transpose+base;
    if (transpose>highRange) {
        transpose=transpose-12;
    }
    if (transpose<lowRange) {
        transpose=transpose+12;
    }
    if (transpose==51) { //Eb
        transpose=39;
    }
    if (transpose==57) { //A
        transpose=45;
    }
    if (transpose==60) { //C
        transpose=48;
    }
    if (transpose==61) { //C#
        transpose=49;
    }
    if (transpose==40) { //E
        transpose=52;
    }
    if (transpose==41) { //F
        transpose=53;
    }
    if (transpose==42) { //F#
        transpose=54;
    }
    if (transpose==43) { //G
        transpose=55;
    }
    if (transpose==44) { //G#
        transpose=56;
    }
    if (transpose==46) { //A#
        transpose=58;
    }
    if (transpose==50) { //D
        transpose=62;
    }
    int transposed=transpose;
    return transposed;
}


#endif
