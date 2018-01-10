//
//  ofxTimeNoteLoader.h
//  TimeNoteDev
//
//  Created by kezzardrix2 on 2017/09/22.
//

#ifndef ofxTimeNoteLoader_h
#define ofxTimeNoteLoader_h

#include "ofxXmlSettings.h"
#include "ofxTimeNote.hpp"

class ofxTimeNoteLoader{
public:
    static void load(string name, ofxTimeNote &timeNote){
        
        ofxXmlSettings xml;
        
        if(xml.load(name)){
            xml.pushTag("SCENE");
            int numTrackNum = xml.getNumTags("NAME");
            
            string name = xml.getValue("NAME", "none");

            timeNote.setTrackName(name);
            
            int numParamNum = xml.getNumTags("PARAM");
            
            for(int i = 0 ; i < numParamNum; i++){
                float time = xml.getValue("PARAM::TIME", 0.0, i);
                int key = xml.getValue("PARAM::KEY",0, i);

                timeNote.push(key, time);
            }
        }
    }
};
#endif /* ofxTimeNoteLoader_h */
