using namespace ci;
using namespace ci::app;
using namespace std;

#include "cinder/Utilities.h"
#include <fstream>

struct Chord {
    string root;
    string type;
    vector<int> notes;
    Chord() {}
};

struct Progression {
    vector<Chord> unitChord;
    Progression() {}
};




class Database {
public:
	void read();
    void save(string input);
    void progression();
    vector<int> playChord(int,int);
    int progSize(int);
    vector<Progression> unitProgression;
    
    
private:
    string noteName(string num, bool oct);
    string mNotes="C C#D D#E F F#G G#A A#B ";
};

void Database::read(){
    fstream chords;
    chords.open ("../../chords.tsv");
    string line;
    int count=0;
    while ( chords.good() )
    {
        getline ( chords, line);
        unitProgression.push_back(Progression());
        vector<string> progression= split(line,'\t');
        
        string space=" ";
        for (int i=0;i<progression.size();i++){
            unitProgression[count].unitChord.push_back(Chord());
            vector<string> chord = split(progression[i],' ');
            for (int j=0;j<chord.size();j++){
                if (j==0) {
                    unitProgression[count].unitChord[i].root=chord[j];
                }else if (j==1) {
                    unitProgression[count].unitChord[i].type=chord[j];
                } else {
                    unitProgression[count].unitChord[i].notes.push_back(stoi(chord[j]));
                }
            }
            cout<<noteName(unitProgression[count].unitChord[i].root, false)<<unitProgression[count].unitChord[i].type<<" notes:";
            for (int j=0; j<unitProgression[count].unitChord[i].notes.size(); j++) {
                cout<<noteName(to_string(unitProgression[count].unitChord[i].notes[j]),true)<<" ";
            }
            cout<<endl;
            
        }
        
        cout<<"**end chord progression** "<<count<<endl<<endl;
        count++;
    }
    
    chords.close();
}

void Database::save(string input){
    fstream chords;
    chords.open ("../../chords.tsv", fstream::in | fstream::out | fstream::app);
    chords<<input;
    chords.close();
}

string Database::noteName(string num, bool oct) {
    int number=stoi(num);
    int start = number%12 * 2;
    int octave=number/12-1;
    string note=mNotes.substr(start,2);
    std::string::iterator end_pos = std::remove(note.begin(), note.end(), ' ');
    note.erase(end_pos, note.end());
    if (oct) {
        note=note+to_string(octave);
    }
    return note;
}

vector<int> Database::playChord(int prog, int chord) {
    return unitProgression[prog].unitChord[chord].notes;
}

int Database::progSize(int num){
    return unitProgression[num].unitChord.size();
}


