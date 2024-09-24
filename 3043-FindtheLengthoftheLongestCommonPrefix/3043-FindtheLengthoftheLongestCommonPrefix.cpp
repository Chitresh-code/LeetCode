struct Node {
    Node* c[26];
    bool end = false;

    bool contains(char a){
        return c[a-'0'] != NULL;
    }

    void put(char a, Node* newNode){
        c[a-'0'] = newNode;
    }

    Node* get(char a){
        return c[a-'0'];
    }

    void setEnd(){
        end = true;
    }

    bool isEnd(){
        return end;
    }
};
class Trie{
    public:
    Node* root;
    int ch = 0;

    Trie(){
        root = new Node();
    }

    void insert(string c){
        Node* node = root;
        for(auto a: c){
            if(!node->contains(a)){
                node->put(a, new Node());
            }
            node = node->get(a);
        }
        node->setEnd();
    }

    void find(string c){
        Node* node = root;
        int t = 0;
        for(auto a: c){
            if(node->contains(a)){
                t++;
                ch = max(ch, t);
                node = node->get(a);
            }else break;
        }
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        Trie trie;
        for(auto a: arr1){
            trie.insert(to_string(a));
        }
        for(auto a: arr2){
            trie.find(to_string(a));
        }
        return trie.ch;
    }
};