//
//  ofxTimeNote.cpp
//  AbletonTest
//
//  Created by kezzardrix2 on 2017/02/17.
//
//

#include "ofxTimeNote.hpp"

int ofxTimeNote::update(){
    
    mCurrentTime += ofGetLastFrameTime();
    
    int value = -1;
    
    if(mCurrentTime > getCurrentTime()){
        value = getCurrentKey();
        next();
    }
    
    return value;
}

int ofxTimeNote::updateByExternalTime(float time){
    
    mCurrentTime = time;
    
    int value = -1;
    
    if(mCurrentTime > getCurrentTime()){
        value = getCurrentKey();
        next();
    }
    
    return value;
}

void ofxTimeNote::push(int key, float time){
    Note n;
    n.key = key;
    n.time = time;
    mNotes.push_back(n);
};

float ofxTimeNote::getCurrentTime(){
    return mNotes[mCurrentNote].time;
}

int ofxTimeNote::getCurrentKey(){
    return mNotes[mCurrentNote].key;
}

void ofxTimeNote::next(){
    
    if(mCurrentNote < mNotes.size()){
        mCurrentNote++;
        mCurrentNote = ofClamp(mCurrentNote, 0, mNotes.size() - 1);
    }
    
}

void ofxTimeNote::reset(){
    mCurrentNote = 0;
    mCurrentTime = 0;
}

void ofxTimeNote::seek(float time){
    for(int i = 0; i < mNotes.size(); i++){
        if(time > mNotes[i].time){
            mCurrentTime = mNotes[i].time;
            mCurrentNote = i;
        }
    }
}