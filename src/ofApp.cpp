#include "ofApp.h"
using namespace std;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	buton.addListener(this, &ofApp::buttonPressed);
	slider.addListener(this, &ofApp::sliderChanged);
	gui.setup();
	gui.add(screenSize.setup("screen size", ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight())));
	//gui.add(ofParExample.set("nameIWantToRetrieve", false));
	gui.add(slider.setup("select X", 5, 2, 2000));
	gui.add(buton.setup("boton pintar"));
	//ofAddListener(groupParam.parameterChangedE(), this, &ofApp::nameExtractionParam);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawPlane(250, 150);
	gui.draw();
	line.draw();
}

//------------MIO-----------------------------------------------------
void ofApp::exit() {
	buton.removeListener(this, &ofApp::buttonPressed);
}

void ofApp::buttonPressed() {
	++i;
	cout << i << "\n";
	cout << x << "\n";
	if (limpialinea)
	{
		line.clear();
		limpialinea = false;
	}
	ofPoint pt;
	ofPoint ptF;
	//
	pt.set(x, 1);
	ptF.set(x, 900);
	line.addVertex(pt);
	line.addVertex(ptF);
	limpialinea = true;
	
}
void ofApp::sliderChanged(int &slider) {
	//ofSetslider(slider);
	x = slider;
	

}

/*
void ofApp::nameExtractionParam(ofAbstractParameter& parameter) {

	vector<string> hierarchy = parameter.getGroupHierarchyNames();
	auto escaped = parameter.getEscapedName();
	auto stringName = parameter.toString();
	// cut the hierarchy name here
	// and use it for something else

}
*/
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
