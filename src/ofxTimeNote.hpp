//
//  ofxTimeNote.hpp
//  AbletonTest
//
//  Created by kezzardrix2 on 2017/02/17.
//
//

#ifndef ofxTimeNote_hpp
#define ofxTimeNote_hpp

#include "ofMain.h"

class ofxTimeNote{
public:
    
    ofxTimeNote():mCurrentNote(0),mCurrentTime(0){
        
    }
    
    struct Note{
        int key;
        float time;
    };
    
    int update();
    int updateByExternalTime(float time);
    
    void push(int key, float time);
    
    float getCurrentTime();
    int getCurrentKey();
    void next();
    void reset();
    void seek(float time);
    
    void setTrackName(string name){mTrackName = name;};
    string getTrackName(){return mTrackName;};
    
private:
    
    vector<Note>mNotes;
    int mCurrentNote;
    float mCurrentTime;
    
    string mTrackName;
    
};


#endif /* ofxTimeNote_hpp */
