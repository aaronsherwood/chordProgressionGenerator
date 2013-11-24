#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class chordProgressionGeneratorApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void chordProgressionGeneratorApp::setup()
{
}

void chordProgressionGeneratorApp::mouseDown( MouseEvent event )
{
}

void chordProgressionGeneratorApp::update()
{
}

void chordProgressionGeneratorApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( chordProgressionGeneratorApp, RendererGl )
