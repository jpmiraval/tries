//
// Created by jpalexander1706 on 2020-11-14.
//

#ifndef TRIES_TSEARCH_H
#define TRIES_TSEARCH_H

#include <iostream>
#include <cstdlib>
#define MAX 50
using namespace std;

class Node{
public:
    char data;
    bool isEndOfString = true;
    Node *left;
    Node *eq;
    Node *right;
};

class Ternary_Search_tree{
private:
    Node* root = nullptr;

public:
    Ternary_Search_tree() = default;

    Node* get_root(){
        return root;
    }

    Node* newNode(char data){
        Node* temp = (Node*) malloc(sizeof(Node));
        temp->data = data;
        temp->isEndOfString = 0;
        temp->left = temp->eq = temp->right = NULL;
        return temp;
    }

    void insert(Node** root, char *word) {
        if (!(*root))
            *root = newNode(*word);

        if ((*word) < (*root)->data)
            insert(&( (*root)->left ), word);

        else if ((*word) > (*root)->data)
            insert(&( (*root)->right ), word);

        else{
            if (*(word+1))
                insert(&( (*root)->eq ), word+1);
            else
                (*root)->isEndOfString = 1;
        }
    }

    void traverseTSTUtil(Node* root, char* buffer, int depth){
        if (root){
            traverseTSTUtil(root->left, buffer, depth);

            buffer[depth] = root->data;
            if (root->isEndOfString){
                buffer[depth+1] = '\0';
                cout << buffer <<'\n';
            }

            traverseTSTUtil(root->eq, buffer, depth + 1);

            traverseTSTUtil(root->right, buffer, depth);
        }

    }

    void traverseTST(Node* root){
        char buffer[MAX];
        traverseTSTUtil(root, buffer, 0);
    }

    int searchTST(Node *root, char *word){
        if (!root)
            return 0;

        if (*word < (root)->data)
            return searchTST(root->left, word);

        else if (*word > (root)->data)
            return searchTST(root->right, word);

        else{
            if (*(word+1) == '\0')
                return root->isEndOfString;

            return searchTST(root->eq, word+1);
        }
    }
};

#endif //TRIES_TSEARCH_H
