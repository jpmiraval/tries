//
// Created by jpalexander1706 on 2020-11-14.
//

#ifndef TRIES_RADIXTREE_H
#define TRIES_RADIXTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

class radixTree {
public:
    radixTree* letters[256];
    bool isLeaf = false;
    string almacenado = "";
    vector<pair<long,long>> data;

    radixTree(string word) {
        for(int i=0; i<256; i++){
            letters[i] = nullptr;
        }
        almacenado = word;
    }

    radixTree() {
        for(int i=0; i<256; i++){
            letters[i] = nullptr;
        }
    }

    void insert(string& word, long begin, long end, int& index, radixTree*& current){
        if(index == word.length()){
            return;
        }

        if(current->letters[word[index]-'0'] == nullptr){
            string temp = "";
            for(index; index < word.length(); index++){
                temp += word[index];
            }
            letters[word[index]-'0'] = new radixTree(temp);
        }
        current = current->letters[word[index]-'0'];

        //Iteramos por el dato guardado

        for(int i = 0; i < current->almacenado.length(); i++){
            if(current->almacenado[i] == word[index]){
                index++;
                if(index == word.length()){
                    return;
                }
            }else{
                string queda = "";
                string temp = "";
                string temp2 = "";
                for(index; index < word.length(); index++){
                    temp += word[index];
                }
                for(int l = i; l < almacenado.length(); l++){
                    temp2 += almacenado[l];
                }
                for(int p = 0; p < i; p++){
                    queda+= almacenado[p];
                }
                auto nodito = new radixTree(queda);
                nodito->letters[word[index]-'0'] = new radixTree(temp);
                nodito->letters[almacenado[i]-'0'] = new radixTree(temp2);
                for(int m=0; m<256; m++){
                    nodito->letters[almacenado[i]-'0']->letters[m] = current ->letters[m];
                }
                current->almacenado = nodito->almacenado;
                for(int m=0; m<256; m++){
                    current->letters[m] = nodito->letters[m];
                }
            }
        }
        insert(word, begin, end, index, current);
    }

    void insert(string word, long begin, long end) {
        radixTree* current = this;
        int index = 0;
        insert(word, begin, end, index, current);
        //Current debe ser el nodo hoja.
        current->isLeaf = true;
        current->data.push_back(make_pair(begin,end));
    }

    void search(string& word, int& index, radixTree*& current){
        if(index == word.length()-1){
            if(current->isLeaf){
                fstream file("index.txt",ios::in |ios::out );
                string data;
                for(auto a : current->data){
                    file.seekg(a.first);
                    getline(file,data);
                    cout << data << '\n';
                }
            }else{
                return;
            }
        }


        for(int i = 0; i < almacenado.length(); i++){
            if(almacenado[i] == word[index]){
                index++;
            }else{
                string temporal = "";
                for(int j = 0; j < i; j++){
                    temporal+= almacenado[j];
                }

            }
        }

        if(current->letters[word[index]-'0'] != nullptr)
            current = current->letters[word[index]-'0'];
        else
            return;

        search(word, index, current);
    }

    void search(string word) {
        vector<pair<int,int>> ans;
        int index = 0;
        radixTree* current = this;

        search(word, index, current);
    }

};

#endif //TRIES_RADIXTREE_H
