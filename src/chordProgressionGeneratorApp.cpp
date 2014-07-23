#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "progression_database.h"
#include "chordMidi.h"
#include "upperStructures.h"
#include "metro.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/CinderMath.h"
#include <CoreGraphics/CGRemoteOperation.h>
#include "Population.h"
#include "modes.h"
#include "musicMain.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class chordProgressionGeneratorApp : public AppNative {
  public:
	void setup();
    void prepareSettings( Settings * settings );
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    Database database;
    Midiplay midi;
    int chordCounter;
    UpperStructure us;
    Metronome metro;
    Modes modes;
    Music music;
    
    vector<int> chord;
    int rootNote,bassNote;
    int velCounter;
    int vel;
    bool mD;
    bool go;
    gl::Texture myImage;
    gl::Texture knob;
    gl::Texture glow;
    gl::Texture depressedButton;
    bool button1,button2,button3;
    bool rotateKnob1,rotateKnob2,rotateKnob3;
    int mRot1,mRot2,mRot3;
    float high;
    Vec2i mMouseLoc,pMouseLoc,oMouseLoc;
    int counter=0;
    int darkness=0;
    int arpeggio=0;
    int direction=1;
};

void chordProgressionGeneratorApp::prepareSettings( Settings * settings ){
    settings->setWindowSize(960, 640);
    settings->setFrameRate(60.f);
    settings->setBorderless( true );
}

void chordProgressionGeneratorApp::setup()
{
    srand (time(NULL));
    midi.setup();
    database.read();
    music.setUp(8, 38, 62, 38);
    chordCounter=0;
    metro.setUp(250);
    rootNote=0;
    bassNote=rootNote;
    velCounter=0;
    vel=90;
    mD=false;
    myImage = gl::Texture( loadImage( loadResource( "chordGeneratorBackGround.jpg" ) ) );
    knob=gl::Texture( loadImage( loadResource("knob.png")));
    glow=gl::Texture( loadImage( loadResource("buttonGlow.png")));
    depressedButton=gl::Texture( loadImage( loadResource("depressedbutton.png")));
    button1=false;
    button2=false;
    button3=false;
    rotateKnob1=false;
    mRot1=mRot2=0;
    mRot3=190;
    go=false;
}

void chordProgressionGeneratorApp::mouseMove( MouseEvent event ) {
    mMouseLoc = event.getPos();
}

void chordProgressionGeneratorApp::mouseDrag( MouseEvent event ) {
    mouseMove( event );
    
    if (rotateKnob1) {
        bool up;
        bool down;
        
        if (mMouseLoc.y>pMouseLoc.y) {
            up=false;
            down=true;
            
        }
        if (mMouseLoc.y<pMouseLoc.y) {
            down=false;
            up=true;
            
        }
        if (up) {
            mRot1=constrain(float(mRot1+7),0.f,273.f);
        }
        if (down) {
            mRot1=constrain(float(mRot1-7),0.f,273.f);
        }
        
    }
    
    if (rotateKnob2) {
        bool up;
        bool down;
        
        if (mMouseLoc.y>pMouseLoc.y) {
            up=false;
            down=true;
            
        }
        if (mMouseLoc.y<pMouseLoc.y) {
            down=false;
            up=true;
            
        }
        if (up) {
            mRot2=constrain(float(mRot2+7),0.f,273.f);
        }
        if (down) {
            mRot2=constrain(float(mRot2-7),0.f,273.f);
        }
        
        if (mRot2>20) {
            darkness=0;
        }
        if (mRot2>19 && mRot2<40) {
            darkness=1;
        }
        if (mRot2>39 && mRot2<60) {
            darkness=2;
        }
        if (mRot2>59 && mRot2<80) {
            darkness=3;
        }
        if (mRot2>79 && mRot2<100) {
            darkness=4;
        }
        if (mRot2>99 && mRot2<120) {
            darkness=5;
        }
        if (mRot2>119 && mRot2<140) {
            darkness=6;
        }
        if (mRot2>139 && mRot2<160) {
            darkness=7;
        }
        if (mRot2>139 && mRot2<180) {
            darkness=8;
        }
        if (mRot2>179 && mRot2<200) {
            darkness=9;
        }
        if (mRot2>199 && mRot2<220) {
            darkness=10;
        }
        if (mRot2>219 && mRot2<240) {
            darkness=11;
        }
        if (mRot2>239 && mRot2<260) {
            darkness=12;
        }
        if (mRot2>259 && mRot2<274) {
            darkness=11;
        }
    }

    if (rotateKnob3) {
        bool up;
        bool down;
        
        if (mMouseLoc.y>pMouseLoc.y) {
            up=false;
            down=true;
            
        }
        if (mMouseLoc.y<pMouseLoc.y) {
            down=false;
            up=true;
            
        }
        if (up) {
            mRot3=constrain(float(mRot3+7),0.f,273.f);
        }
        if (down) {
            mRot3=constrain(float(mRot3-7),0.f,273.f);
        }
        
    }

    
    pMouseLoc=mMouseLoc;
    
    
}



void chordProgressionGeneratorApp::mouseDown( MouseEvent event )
{
    
    pMouseLoc = oMouseLoc= event.getPos();
    if (Area(mMouseLoc,mMouseLoc).intersects(Area(108,124,234,250))) {
        rotateKnob1=true;
         hideCursor();
    }
    if (Area(mMouseLoc,mMouseLoc).intersects(Area(413,122,539,248))) {
        rotateKnob2=true;
        hideCursor();
    }
    if (Area(mMouseLoc,mMouseLoc).intersects(Area(707,124,833,250))) {
        rotateKnob3=true;
        hideCursor();
    }
    
    //database.save("\n52 min 52 55 59");
    //database.read();
    
    //cout<<us.sus2(1)<<endl;
    
    //middle C is 60
    int progNum=2;
    //vector<int> chord=database.playChord(progNum,chordCounter);
    
    //0 as note is middle c
    if (pow((mMouseLoc.x - 112),2) + pow((mMouseLoc.y - 461),2) < pow(30,2)) {
        button1=true;
        go=true;
    
        int inv=rand()%3+1;
//        int switcher=rand()%2;
    //    if (switcher==0) {
    //        bassNote=switcher;
    //    } else{
    //        bassNote=4;
    //    }
        
        int struc=rand()%6+1;
        mD=true;
        switch (struc) {
            case 1:
                chord=us.sus2(rootNote,inv);
                break;
                
            case 2:
                chord=us.min(rootNote,inv);
                break;
                
            case 3:
                chord=us.maj(rootNote,inv);
                break;
                
            case 4:
                chord=us.sixFive(rootNote,inv);
                break;
                
            case 5:
                chord=us.fiveSix(rootNote,inv);
                break;
                
//            case 6:
//                chord=us.aug(rootNote,inv);
//                break;
                
            case 6:
                chord=us.threeFour(rootNote,inv);
                break;
                
            default:
                break;
        }
    }
    if (pow((mMouseLoc.x - 220),2) + pow((mMouseLoc.y - 461),2) < pow(30,2)) {
        button2=true;
        go=!go;
    }
    if (pow((mMouseLoc.x - 331),2) + pow((mMouseLoc.y - 462),2) < pow(30,2)) {
        button3=true;
        
        vector<int> notes;
        switch (darkness) {
            case 0:
                notes=modes.lyd_aug();
                break;
                
            case 1:
                notes=modes.lyd();
                break;
                
            case 2:
                notes=modes.ion();
                break;
                
            case 3:
                notes=modes.mix_SharpFour();
                break;
                
            case 4:
                notes=modes.mix();
                break;
                
            case 5:
                notes=modes.mix_FlatSix();
                break;
                
            case 6:
                notes=modes.mel_Min();
                break;
                
            case 7:
                notes=modes.dor();
                break;
                
            case 8:
                notes=modes.aeo();
                break;
                
            case 9:
                notes=modes.aeo_FlatFive();
                break;
                
            case 10:
                notes=modes.phr_NaturalSix();
                break;
                
            case 11:
                notes=modes.phr();
                break;
                
            case 12:
                notes=modes.loc();
                break;
                
            case 13:
                notes=modes.loc_FlatFour();
                break;
                
                
                
            default:
                break;
        }
        
        midi.noteOut(62+notes[counter], 90);
        counter=(counter+1)%7;
    }
    
    
    chordCounter=(chordCounter+1)%database.progSize(progNum);
}

void chordProgressionGeneratorApp::mouseUp( MouseEvent event )
{
    
    button1=button2=button3=rotateKnob1=rotateKnob2=rotateKnob3=false;
    showCursor();
    CGPoint pt;
    
    pt.x = oMouseLoc.x+getWindowPos().x;
    pt.y = oMouseLoc.y+getWindowPos().y;
    CGWarpMouseCursorPosition(pt);
    
    
}

void chordProgressionGeneratorApp::update()
{
    
    if (mD) {
        vel=100;
    }
    
    
    if (metro.bang()){
        if (go){
        //for (int i=0;i<chord.size();i++){
            midi.noteOut(music.transposeNote(chord[arpeggio]),vel);
        //}
        //midi.noteOut(62,vel);
        //midi.noteOut(bassNote+43,vel);
        int r=rand()%3+5;
        velCounter=(velCounter+1)%r;
        mD=false;
            
//            if (arpeggio==chord.size()-1) {
//                direction=-1;
//            }
//            if (arpeggio==0) {
//                direction=1;
//            }
//            arpeggio=arpeggio+direction;
            
            arpeggio=(arpeggio+1)%chord.size();
        }
    }
    if (!mD){
    if (velCounter==0) {
        vel=90;
    } else {
        vel=80;
    }
    }
    
    metro.mTempo=lmap(float(mRot3), 273.f, 0.f, 150.f, 600.f);
}

void chordProgressionGeneratorApp::draw()
{
    gl::enableAlphaBlending();
	gl::clear( Color( 0, 0, 0 ) );
    gl::draw( myImage, getWindowBounds() );
    
    
        
    glPushMatrix();
        gl::translate(Vec3f(171, 187, 0.0));
        gl::rotate(Vec3f(0.,0.,mRot1));
        glPushMatrix();
            gl::translate(Vec3f(-knob.getWidth()/2,-knob.getHeight()/2,0));
            gl::draw(knob);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        gl::translate(Vec3f(476, 185, 0.0));
        gl::rotate(Vec3f(0.,0.,mRot2));
        glPushMatrix();
            gl::translate(Vec3f(-knob.getWidth()/2,-knob.getHeight()/2,0));
            gl::draw(knob);
        glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
        gl::translate(Vec3f(770, 185, 0.0));
        gl::rotate(Vec3f(0.,0.,mRot3));
        glPushMatrix();
            gl::translate(Vec3f(-knob.getWidth()/2,-knob.getHeight()/2,0));
            gl::draw(knob);
        glPopMatrix();
    glPopMatrix();
    
//    gl::draw(knob,Area(413,122,539,248));
//    gl::draw(knob,Area(707,124,833,250));
    if (button1) {
        gl::color( 1,1,1,1);
    } else{
        gl::color( 1,1,1,0);
    }
    gl::draw(depressedButton,Area(87,434,136,483));
    gl::draw(glow,Area(99,446,124,472));
    
    gl::color(1, 1, 1,1);
    if (button2) {
        gl::color( 1,1,1,1);
    } else{
        gl::color( 1,1,1,0);
    }
    gl::draw(depressedButton,Area(196,434,245,483));
    gl::draw(glow,Area(207,446,232,472));
    gl::color(1, 1, 1,1);
    if (button3) {
        gl::color( 1,1,1,1);
    } else{
        gl::color( 1,1,1,0);
    }
    gl::draw(depressedButton,Area(306,436,355,483));
    gl::draw(glow,Area(318,447,343,473));
    gl::color(1, 1, 1,1);
}


CINDER_APP_NATIVE( chordProgressionGeneratorApp, RendererGl )
