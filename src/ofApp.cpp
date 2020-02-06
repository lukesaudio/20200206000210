#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	iterations = 10;
	length = 10;
	currentPoint.set(0, ofRandom(ofGetHeight()));
	ofSetFrameRate(framerate);
	ofBackground(ofColor::black);
	ofSetColor(ofColor::white);

	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();

	//ofSetFullscreen(true);

	ofSetVerticalSync(true);
	camera.setDistance(800);	

	

	circleStart.set(0, 0);


	
	
	
	

}

//--------------------------------------------------------------
void ofApp::update()
{
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	camera.begin();
	
	if (decider == true)
	{
		for (int i = 0; i < iterations; i++)
		{

			for (int i = 0; i < iterations; i++)
			{

				ofPushMatrix();

				int rotation = ofRandom(-180, 180);
				ofRotate(rotation);
				ofSetColor(0, 0, 0, ofRandom(0, 100));

				ofDrawLine(currentPoint.x, currentPoint.y, currentPoint.x + length, currentPoint.y);
				nextPoint.set(currentPoint.x, currentPoint.y + length);

				ofPopMatrix();

				currentPoint.set(nextPoint);



			}


			currentPoint.set(0, ofRandom(ofGetHeight()));
			length = ofRandom(0, 100);

		}

		for (int i = 0; i < iterations; i++)
		{


			for (int i = 0; i < iterations; i++)
			{

				ofPushMatrix();

				int rotation = ofRandom(-180, 180);
				ofRotate(rotation);
				ofSetColor(0, 0, 0, ofRandom(0, 100));

				ofDrawLine(currentPoint.x, currentPoint.y, currentPoint.x + length, currentPoint.y);
				//ofDrawRectangle(circleStart.x + 40, circleStart.y + ofRandom(1, 30), 15, 15);
				nextPoint.set(currentPoint.x, currentPoint.y + length);

				ofPopMatrix();

				currentPoint.set(nextPoint);



			}


			currentPoint.set(0, ofRandom(ofGetHeight()));
			length = ofRandom(0, 100);
		}


		for (int i = 0; i < iterations; i++)
		{


			for (int i = 0; i < iterations; i++)
			{

				ofPushMatrix();


				ofRotate(ofRandom(0, 10));
				ofSetColor(ofRandom(200, 255), ofRandom(175, 255), ofRandom(0, 255), ofRandom(0, 100));
				
				

				ofDrawLine(currentPoint.x, currentPoint.y, currentPoint.x, currentPoint.y + length);

				nextPoint.set(currentPoint.x, currentPoint.y + length);

				circleStart.x += 10;

				if (circleStart.x > ofGetWidth())
				{
					circleStart.x = 0;
				}
				
				ofDrawCircle(circleStart, circleSize);

				ofPopMatrix();
				ofRotate(paigeRotato);
				currentPoint.set(nextPoint);



			}

			circleStart.y += 1;

			if (circleStart.y < ofGetHeight())
			{
				circleStart.y = ofGetHeight() * circleMultiplier;
			}


			currentPoint.set(0, ofRandom(ofGetHeight()));
			length = ofRandom(0, 100);

		}


	}

	camera.end();
		

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == '=')
	{
		ofSetFrameRate(framerate++);
	}

	if (key == '-')
	{
		ofSetFrameRate(framerate--);
		if (framerate < 0)
		{
			framerate = 0;
		}
	}

	if (key == ' ')
	{
		ofClear(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
		randCol.set(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));

	}

	if (key == 'q')
	{
		paigeRotato++;
	}

	if (key == 'w')
	{
		paigeRotato--;
	}

	if(key == 'r')
	{
		circleSize += 10;
	}

	if (key == 't')
	{
		circleSize -= 10;
	}

	if (key == 'y')
	{
		circleMultiplier += 0.1;
	}
	if (key == 'u')
	{
		circleMultiplier -= 0.1;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
