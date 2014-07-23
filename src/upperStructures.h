using namespace ci;
using namespace ci::app;
using namespace std;



class UpperStructure {
public:
    vector<int>         sus2(int, int);
    vector<int>         min(int, int);
    vector<int>         maj(int, int);
    vector<int>         sixFive(int, int);
    vector<int>         fiveSix(int, int);
    vector<int>         aug(int, int);
    vector<int>         threeFour(int, int);
    int                 transposeNotes(int);
};

vector<int> UpperStructure::sus2(int note, int rootPlacement) {

    vector<int> notes;
    int a;
    int b;
    int c;
    
    switch (rootPlacement) {
        case 1:
            a=0;
            b=2;
            c=7;
            break;
        case 2:
            a=0;
            b=5;
            c=7;
            break;
        case 3:
            a=0;
            b=5;
            c=10;
            break;
    }
    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);
    return notes;
}

vector<int> UpperStructure::min(int note, int rootPlacement) {

    vector<int> notes;
    int a;
    int b;
    int c;
    
    switch (rootPlacement) {
        case 1:
            a=0;
            b=3;
            c=7;
            break;
        case 2:
            a=0;
            b=4;
            c=9;
            break;
        case 3:
            a=0;
            b=5;
            c=8;
            break;
    }
    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);
    return notes;
}

vector<int> UpperStructure::maj(int note, int rootPlacement) {
    
    vector<int> notes;
    int a;
    int b;
    int c;
    
    switch (rootPlacement) {
        case 1:
            a=0;
            b=4;
            c=7;
            break;
        case 2:
            a=0;
            b=3;
            c=8;
            break;
        case 3:
            a=0;
            b=5;
            c=9;
            break;
    }
    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);
    return notes;
}

vector<int> UpperStructure::sixFive(int note, int rootPlacement) {
    
    vector<int> notes;
    int a;
    int b;
    int c;
    
    switch (rootPlacement) {
        case 1:
            a=0;
            b=6;
            c=11;
            break;
        case 2:
            a=0;
            b=5;
            c=6;
            break;
        case 3:
            a=0;
            b=1;
            c=6;
            break;
    }
    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);
    return notes;
}

vector<int> UpperStructure::fiveSix(int note, int rootPlacement) {
    
    vector<int> notes;
    int a;
    int b;
    int c;
    
    switch (rootPlacement) {
        case 1:
            a=0;
            b=5;
            c=11;
            break;
        case 2:
            a=0;
            b=6;
            c=7;
            break;
        case 3:
            a=0;
            b=1;
            c=6;
            break;
    }
    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);
    return notes;
}

vector<int> UpperStructure::aug(int note, int rootPlacement) {
    
    vector<int> notes;
    int a;
    int b;
    int c;
    
    switch (rootPlacement) {
        case 1:
            a=0;
            b=4;
            c=8;
            break;
        case 2:
            a=0;
            b=4;
            c=8;
            break;
        case 3:
            a=0;
            b=4;
            c=8;
            break;
    }
    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);
    return notes;
}

vector<int> UpperStructure::threeFour(int note, int rootPlacement) {
    
    vector<int> notes;
    int a;
    int b;
    int c;
    
    switch (rootPlacement) {
        case 1:
            a=0;
            b=4;
            c=5;
            break;
        case 2:
            a=0;
            b=1;
            c=8;
            break;
        case 3:
            a=0;
            b=7;
            c=11;
            break;
    }
    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);
    return notes;
}


