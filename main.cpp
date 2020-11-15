#include "radixTree.h"
#include "Try.h"
#include "TSearch.h"

using namespace std;

pair<string,string> getName(string s){
    int count = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == '/') break;
        count++;
    }
    return make_pair(s.substr(s.size()-count, s.size()), s.substr(0, s.size()-count));
}

int main() {

    /* TRY
    Trie trie = Trie();
    ifstream file("index.txt");
    if (file.is_open()) {
        string line;
        long prev = 0;
        while (std::getline(file, line)) {
            pair<string,string> path = getName(line);
            string name = path.first.substr(0, path.first.size()-4);
            long begin = prev;
            long size = path.first.size();
            long end = (long)file.tellg() - size;
            prev = (long) file.tellg();
            trie.insert(name,begin,end);
        }
        file.close();
    }
    trie.search("uml 2 toolkit");
     */




    /* MAIN RADIX TREE
    radixTree radix = radixTree();
    ifstream file("text.txt");
    if (file.is_open()) {
        string line;
        long prev = 0;
        while (std::getline(file, line)) {
            pair<string,string> path = getName(line);
            string name = path.first.substr(0, path.first.size()-4);
            long begin = prev;
            long size = path.first.size();
            long end = (long)file.tellg() - size;
            prev = (long) file.tellg();
            radix.insert(name,begin,end);
        }
        file.close();
    }
    radix.search("paper-100k");
     */



    /* TERNARY SEARCH TREE

    Ternary_Search_tree tree;
    Node* root2 = tree.get_root();
    tree.insert(&root2, "hola");
    tree.insert(&root2, "sin");
    tree.insert(&root2, "casa");
    tree.insert(&root2, "casas");

    cout<<"Following is traversal of ternary search tree\n";
    tree.traverseTST(root2);


    cout<<"\nFollowing are search results for cats, bu and cat respectively\n";
    tree.searchTST(root2, "casa")? cout<<"Found\n" : cout<<"Not Found\n";
    tree.searchTST(root2, "si")?   cout<<"Found\n": cout<<"Not Found\n";
    tree.searchTST(root2, "casas")?  cout<<"Found\n": cout<<"Not Found\n";

return 0;
    */


    return 0;
}
