#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int iterations;
		int length;
		ofPoint currentPoint;
		ofPoint nextPoint;

		int transparent = 0;
		int colour = 0;

		ofPoint circleStart;

		int framerate = 10;

		ofColor blueboi;
		int colourVal = 0;
		ofColor randCol;


		int paigeRotato = 0;

		bool decider = true;

		int circleSize = 1;
		int circleMultiplier = 0;
		ofEasyCam camera;


		
};
