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
                  mIsStart(false),
                  mFinishedCounter(0),
                  mHasFinished(false),
				  mPitch(1.0){
        
    }
    
    void setup(string path);
    
    int update();
    int updateByExternalTime(float time);
    
    void push(int key, float time);
    
    float getCurrentTime();
    float getCurrentEventTime();
    int getCurrentKey();
    void next();
    void reset();
    void seek(float time);
    
    void setTrackName(string name){mTrackName = name;};
    string getTrackName(){return mTrackName;};
    
    void setToFirstNote();
    void setStart(bool start);
    
    bool isStart(){
        return mIsStart;
    }
    
    void dump();
	void setTimeOffset(float offset) { mTimeOffset = offset; }
	void setPitch(float pitch) { mPitch = pitch; }
    
private:
    
    vector<Note>mNotes;
    int mCurrentNote;
    float mCurrentTime;
    
    string mTrackName;
    
    bool mIsStart;
    bool mHasFinished;
    int mFinishedCounter;

	float mTimeOffset;

	float mPitch;
    
};


#endif /* ofxTimeNote_hpp */
