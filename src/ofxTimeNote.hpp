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
    
    struct Note{
        int key;
        float time;
    };
    
    ofxTimeNote():mCurrentNote(0),
                  mCurrentTime(0),
                  mIsStart(false){
        
    }
    
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
    
    void setToFirstNote();
    void setStart(bool start);
    
private:
    
    vector<Note>mNotes;
    int mCurrentNote;
    float mCurrentTime;
    
    string mTrackName;
    
    bool mIsStart;
    
};


#endif /* ofxTimeNote_hpp */
