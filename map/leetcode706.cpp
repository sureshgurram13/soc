#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:

    map<int,int> temp ;
    vector<int> x ;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if(value == 0){x.push_back(key);}
        temp[key] = value;
    }
    
    int get(int key) {

        if(temp[key] == -1){
            return -1;
        }else if(temp[key] == 0){
            for(int i=0;i<x.size();i++){
                if(x[i] == key){
                    return 0;
                }
            }
            return -1;
        }

        return temp[key];
    }
    
    void remove(int key) {

        for(int i=0;i<x.size();i++){
            if(x[i] == key){
                x[i] = x[x.size()-1];
                x.pop_back();
            }
        }   
             
        temp[key] = -1 ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */