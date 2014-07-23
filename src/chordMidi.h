using namespace ci;
using namespace ci::app;
using namespace std;

#include "MidiOut.h"


class Midiplay {
public:
    void setup();
    void noteOut(int note, int vel);
    midi::MidiOut       mMidiOut;
    int                 mPort;
    string              mPortName;
};

void Midiplay::setup() {
    mMidiOut.getPortList();
    mPort=0;
    mMidiOut.openPort(mPort);
    mPortName=mMidiOut.getName();
}

void Midiplay::noteOut(int note, int vel) {
    mMidiOut.sendNoteOn(1,note,vel);
}

