class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for (int i = 0 ; i < 26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};


class Trie {
public:
 TrieNode* root;
    Trie() {
      root = new TrieNode('\0');
       
    }
    //insert
    void insertUtil(TrieNode* root , string word){
        if (root == NULL) return ;
        if(word.length()==0) {root->isTerminal = true; return;}
        TrieNode* child;
        int index = word[0] - 'a';

        // char is present as a node
        if(root->children[index]) child = root->children[index];

        // absent 
        else {
           child = new TrieNode(word[0]);
           root->children[index] = child;
        }
        // recursive call
        insertUtil(child , word.substr(1));
    }
    void insert(string word) {
        insertUtil(root , word);
    }
    
   
   //search 
   bool searchUtil(TrieNode* root , string word){
         if(root == NULL) return false;

         if(word.length() == 0 ) return root->isTerminal;

         int index = word[0] - 'a';
         TrieNode* child;

         //present
         if(root->children[index]) child = root->children[index];

         // absent 
         else return false;

         return searchUtil(child , word.substr(1)); 
    }
   
    bool search(string word) {
        return searchUtil(root , word);
    }
    
    
    
    
    //start with , checking prefix
    //this is similar to search except the base case 
    bool startsWithUtil(TrieNode* root ,  string prefix){
        if(root == NULL) return false;
         if(prefix.length() == 0) return true;  // prefix is found , we dont need last word to terminal like we needed in the search
         int index = prefix[0] - 'a';
         TrieNode* child ;
         //present 
         if(root-> children[index]) child = root->children[index];

         else return false;

         return startsWithUtil(child , prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root , prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */