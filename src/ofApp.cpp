#include "ofApp.h"
using namespace std;

ofPlanePrimitive plane;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	buton.addListener(this, &ofApp::buttonPressed);
	slider.addListener(this, &ofApp::sliderChanged);
	gui.setup();
	gui.add(screenSize.setup("screen size", ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight())));
	//gui.add(ofParExample.set("nameIWantToRetrieve", false));
	gui.add(slider.setup("select X", 5, 2,ofGetWidth()));
	gui.add(buton.setup("boton pintar"));
	//ofAddListener(groupParam.parameterChangedE(), this, &ofApp::nameExtractionParam);
	
	plane.set(350, 350);   ///dimensions for width and height in pixels
	plane.setPosition(500,350, 0); /// position in x y z
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255, 255);
	plane.draw();
	gui.draw();
	ofSetColor(0,0, 0, 255);
	line.draw();
	ofSetColor(0, 255, 0, 255);
	lineInter.draw();
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
		lineInter.clear();
	limpialinea = false;
	}
	ofPoint pt;
	ofPoint ptF;
	pt.set(x, 1);
	line.addVertex(pt);
	//agrgar nodos visibles
	//defino los rangos de X y Y
	int inX = plane.getX()-(plane.getWidth()/2);
	int fiX = plane.getX()+(plane.getWidth()/2);
	if (x>inX && x<fiX) {
		ofPoint ptDen1;
		ofPoint ptDen2;
		cout << "entre\n";
		
		ptDen1.set(x,plane.getY()-(plane.getHeight()/2));
		ptDen2.set(x, plane.getY()+(plane.getHeight() / 2));
		lineInter.addVertex(ptDen1);
		lineInter.addVertex(ptDen2);
		
	}
	ptF.set(x, 900);
	cout << "inicio"<< inX << "\n";
	cout << "fin"<< fiX << "\n";

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
