#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <GLUT/glut.h>

#include <Ogre/OgreRoot.h>
#include <Ogre/OgreCamera.h>
#include <Ogre/OgreSceneManager.h>
#include <Ogre/OgreRenderWindow.h>

using namespace std;

int main(int argc, char* argv[]){
    cout << "Test Ogre Program blaha" << endl;

    //Relative to where its executed from, not binary location
    Ogre::Root *mRoot = new Ogre::Root("configs/plugins.cfg","configs/config.cfg","logs/main.log");
    
    Ogre::RenderSystem* rs = mRoot->getRenderSystemByName("OpenGL Rendering Subsystem");
    rs->setConfigOption("Full Screen", "No");
    rs->setConfigOption("VSync", "No");
    rs->setConfigOption("Video Mode", "800 x 600 @ 32-bit");

    mRoot->setRenderSystem(rs);

    Ogre::RenderWindow *mWindow = mRoot->initialise(true, "LowLevelOgre Render Window");

    bool continueRunning = true;
    while(continueRunning){
        mRoot->renderOneFrame();
        if(mWindow->isClosed()){
            continueRunning = false;
        }

    }
    
    
    delete mRoot;
}
