#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[2];// 0 and 1
    bool containsKey(long long bit){ // to check if bit exist or not
        return links[bit]!=NULL; 
    }

     void put(long long bit,Node* node){

        links[bit] = node;
     }

     Node* get(long long bit){
        return links[bit];
     }

};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(long long num){
        Node* node = root;
        for(long long i = 31;i>= 0;i--){
            long long bit = (num >> i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
     long long getmax(long long x){
        // get maximum xor value when xor with x 

        Node* node = root;
        long long maxNum = 0;
        for(long long i = 31;i>=0;i--){
            long long bit = (x>>i)&1;
            if(node->containsKey(1 -bit)){
                maxNum |= (1 << i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
     }
};

// any xor problem with trie can be done using this
