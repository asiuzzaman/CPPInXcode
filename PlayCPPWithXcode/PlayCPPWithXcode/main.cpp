#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define MX 26

 struct TrieNode {
     bool isEnd;
     int count;
     TrieNode * child[MX];

     TrieNode() {
         for(int i=0; i<MX; i++) {
             child[i] = NULL;
         }
         isEnd = false;
         count = 0;
     }
 };

 void insertKey(TrieNode * root, const string& key) {
     TrieNode * cur = root;

     for(auto ch: key) {
         int idx = ch - 'a';

         if(cur->child[idx] == NULL) {
             cur->child[idx] = new TrieNode();
         }
         cur = cur->child[idx];
         cur->count += 1;  // age or pore te kono problem hoy kina
     }
     cur->isEnd = true;
 }

 int findIndex(TrieNode * root, const string& key) {

     TrieNode * cur = root;

     int index = 0;

     for(auto ch: key) {

         int idx = ch - 'a';

         for(int i=0; i<idx; i++) {
             if (cur->child[i] != NULL) {
                 index += cur->child[i]->count;
             }
         }
         if (cur->child[idx] != NULL) {
             cur = cur->child[idx];
         } else {
             return -1; // word not found
         }
     }

     if (cur->isEnd) return index;

     return -1;
 }

int main() {

    TrieNode * root = new TrieNode();

    //insertKey(root, "asdb");
    vector<string> arr = {"aaa", "bcd", "aac", "sam", "ppy", "ppa", "pqs" ,"yound", "ggdks"};
     for(auto str: arr) {
         insertKey(root, str);
     }



    printf("the index is: %d\n", findIndex(root, "pqs"));

//    for(auto str: keys) {
//        cout<<"Key: "<<str<<"->";
//
//        if (searchKey(root, str)) {
//            cout<<"Present"<<endl;
//        }
//        else {
//            cout<<"Absent"<<endl;
//        }
//    }
}
