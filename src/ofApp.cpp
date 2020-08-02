#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	iterations = 40; //how many times the loops should run each
	length = 100; //starting line length

	currentPoint.set(0, ofRandom(ofGetHeight())); //picks a random location height-wise to set the first point

	ofSetFrameRate(framerate); //this variable can be changed later on with = and -
	ofBackground(ofColor::black); //default background colour
	ofSetColor(ofColor::white); //default drawing colour

	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending(); //allows for opacity colours 

	//ofSetFullscreen(true); //enable for fullscreen

	ofSetVerticalSync(true); //allows all frames to be drawn periodically without screen tearing but at a slower rate
	camera.setDistance(800);	//sets the cameras distance from the canvas
	circleStart.set(0, 0); //sets the origin point for circle drawing


	
	
	
	

}

//--------------------------------------------------------------
void ofApp::update()
{
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	camera.begin(); //Starts the camera frame
	
	if (decider == true)
	{
		for (int i = 0; i < iterations; i++)
		{

			for (int i = 0; i < iterations; i++)
			{

				//freezes the current canvas so we can manipulate everything without losing the original state
				ofPushMatrix(); 

				//chooses a random rotation to rotate the canvas by
				int rotation = ofRandom(-180, 180); 
				ofRotate(rotation);

				//sets colour to white with a random alpha level
				ofSetColor(0, 0, 0, ofRandom(0, 100));

				ofDrawLine(currentPoint.x, currentPoint.y, currentPoint.x + length, currentPoint.y); //draws a line from the current point to a point (current.x + length) away
				nextPoint.set(currentPoint.x, currentPoint.y + length); 

				ofPopMatrix(); //applies changes to canvas before moving back to orignal state

				currentPoint.set(nextPoint); //move the current point to the location of the next point



			}


			currentPoint.set(0, ofRandom(ofGetHeight())); //moves the current point x back to 0 and picks a random distance away based on the height
			length = ofRandom(0, 100); //chooses a random length for the next line

		}

		//the code then repeats here

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

	camera.end(); //Ends the camera frame
		

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{

	if (key == '=')
	{
		//Increases the framerate of the window's playback
		ofSetFrameRate(framerate++);
	}

	if (key == '-')
	{
		//Decreases the framerate of the window's playback

		ofSetFrameRate(framerate--);
		if (framerate < 0)
		{
			framerate = 0; //if the framerate drops below zero, set it to 0
		}
	}

	if (key == ' ')
	{
		//Clears the screen and selects a random colour

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
		//Increases the size of the circles drawn

		circleSize += 10;
	}

	if (key == 't')
	{

		//Decreases the size of the circles drawn

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
