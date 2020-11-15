//
// Created by jpalexander1706 on 2020-11-14.
//

#ifndef TRIES_TRY_H
#define TRIES_TRY_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

class Trie {
public:
    Trie* letters[256];
    bool isLeaf = false;
    vector<pair<long,long> > data;

    Trie() {
        for(int i=0; i<256; i++){
            letters[i] = nullptr;
        }
    }

    void insert(string word, long begin, long end) {
        Trie* current = this;
        for(auto a : word){
            if(!current->letters[a]){
                current->letters[a] = new Trie();
            }
            current = current->letters[a];
        }
        current->isLeaf = true;
        current->data.push_back(make_pair(begin,end));
    }

    void search(string word) {
        vector<pair<int,int>> ans;
        Trie* current = this;
        for(auto a : word){
            if(!current->letters[a]) return;
            current = current->letters[a];
        }
        if(current->isLeaf){
            fstream file("index.txt",ios::in |ios::out );
            string data;
            for(auto a : current->data){
                file.seekg(a.first);
                getline(file,data);
                cout << data << '\n';
            }
            return;
        }else{
            return;
        }
    }

};

#endif //TRIES_TRY_H
