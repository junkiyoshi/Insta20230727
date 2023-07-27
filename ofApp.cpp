#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto target = glm::vec3(
		ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.01), 0, 1, -600, 600),
		ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.01), 0, 1, -600, 600),
		-600);

	ofColor color;
	for (int i = 0; i < 200; i++) {

		auto x = ofRandom(-600, 600);
		auto y = ofRandom(-600, 600);
		auto z = (int)(ofRandom(1200) + ofGetFrameNum() * 60) % 1200 - 600;

		auto start = glm::vec3(x, y, 600);
		auto gap = target - start;
		auto location = start + (gap / 1200 * (z + 600));

		color.setHsb(ofRandom(120, 200), ofRandom(255), 255);
		ofSetColor(color);

		ofDrawLine(location, location - gap / 15);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}