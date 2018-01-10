//
//  ofxTimeNote.cpp
//  AbletonTest
//
//  Created by kezzardrix2 on 2017/02/17.
//
//

#include "ofxTimeNote.hpp"

int ofxTimeNote::update(){
    
    if(mIsStart)mCurrentTime += ofGetLastFrameTime() * mPitch;
    
    int value = -1;
    if(mHasFinished == true)return -1;
    
    if(mIsStart){
        if(mCurrentTime + mTimeOffset > getCurrentEventTime()){
            value = getCurrentKey();
            next();
        }
    }
    
    return value;
}

int ofxTimeNote::updateByExternalTime(float time){
    
    mCurrentTime = time;
    
    int value = -1;
    if(mHasFinished == true)return -1;
    
    if(mCurrentTime > getCurrentEventTime()){
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
    return mCurrentTime;
}

float ofxTimeNote::getCurrentEventTime(){
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
        if(mCurrentNote == mNotes.size()){
            mHasFinished = true;
            mCurrentNote = mNotes.size() - 1;
        }
     //   mCurrentNote = ofClamp(mCurrentNote, 0, mNotes.size() - 1);
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
    if(mIsStart){
        mHasFinished = false;
        mFinishedCounter = 0;
    }
};

void ofxTimeNote::dump(){
    
    for(auto &v:mNotes){
        cout << "key: " << v.key << endl;
        cout << "note: "<< v.time << endl;
    }
}
