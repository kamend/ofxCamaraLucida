#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxOpenNI.h"
#include "ofxCamaraLucida.h"
#include "cmlDepthmap_openni.h"
#include <GLUT/glut.h>

class testApp : public ofBaseApp 
{
    public:

        void setup();
        void update();
        void draw();
        void exit();

        void keyPressed(int key);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);

        ofxOpenNI openNI;

        cml::CamaraLucida *_cml;
        cml::Depthmap_openni *_depthmap;

        void render_texture(ofEventArgs &args);
        void render_3d(ofEventArgs &args);
        void render_2d(ofEventArgs &args);
};
