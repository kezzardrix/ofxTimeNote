//
//  ofxTimeNote.cpp
//  AbletonTest
//
//  Created by kezzardrix2 on 2017/02/17.
//
//

#include "ofxTimeNote.hpp"

int ofxTimeNote::update(){
    
    
    if(mIsStart)mCurrentTime += ofGetLastFrameTime();
    
    int value = -1;
    
    if(mIsStart){
        if(mCurrentTime > getCurrentTime()){
            value = getCurrentKey();
            next();
        }
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
    assert(mNotes.empty() == false);
    return mNotes.at(mCurrentNote).time;
}

int ofxTimeNote::getCurrentKey(){
    assert(mNotes.empty() == false);
    return mNotes.at(mCurrentNote).key;
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

void ofxTimeNote::setToFirstNote(){
    mCurrentNote = 0;
    mCurrentTime = mNotes.at(0).time;
};

void ofxTimeNote::setStart(bool start){
    mIsStart = start;
};