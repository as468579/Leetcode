
const int ALPHABET_SIZE = 26;

struct TrieNode{
public:
    bool isWord;
    TrieNode *next[ALPHABET_SIZE];

    // Constructor
    TrieNode(): isWord(false){
        for(int i=0; i<ALPHABET_SIZE; ++i){
            next[i] = nullptr;
        }
    }

    // Destructor
    ~TrieNode(){
    }
};

class Trie{
public:
    // Default Constructor
    Trie(){
        m_root = new TrieNode(); 
    }
    
    // Constructor with provied m_root
    Trie(TrieNode *tn){
        m_root = new TrieNode();
        copyHelper(m_root, tn);
    }

    // Copy Constructor
    Trie(Trie &t2){
        m_root = new TrieNode();
        copyHelper(m_root, t2.m_root);
    }
    
    // Helper function for copy constructor
    void copyHelper(TrieNode *t1, TrieNode *t2){
        if(!t2){ return; }
        for(int i=0; i<ALPHABET_SIZE; ++i){
            if(t2->next[i]){
                t1->next[i] = new TrieNode();
                t1->next[i]->isWord = t2->next[i]->isWord;
                copyHelper(t1->next[i], t2->next[i]);
            }            
        }
    }   
    
    void insert(string word){
        TrieNode *curr = m_root;
        int index;
        for(int i=0; i<word.length(); ++i){
            index = convert_index(word[i]);
            if(!(curr->next[index])){
                curr->next[index] = new TrieNode();
            }
            curr = curr->next[index];
        }
        curr->isWord = true;
    }
    
    bool search(TreeNode *tn=nullptr, string word){
        TrieNode *curr = tn ? tn : m_root;
        int index;
        for(int i=0; i<word.length(); ++i){
            if(word[i] == '.'){

                string n_word = "";
                for(int j=i+1; j<word.length(); ++j){
                    n_word += word[j];
                }
                
                bool res = false;
                for(int j=0; j<ALPHABET_SIZE; ++j){
                    if(curr->next[j]){
                        if((n_word == "") && (curr->next[j]->isWord)){ return true; }
                        if(n_trie.search(curr->next[j], n_word)){ return true; }
                    }
                }
               return false;
            }
            else{

                index = convert_index(word[i]);
                if(!(curr->next[index])){
                    return false;
                }
                curr = curr->next[index];
            }
        }
        return (curr->isWord);
    }
    
    void deleteHelper(TrieNode* curr){
        // cout << "deleteHelper" << endl;
        for(int i=0; i<ALPHABET_SIZE; ++i){
            if(curr->next[i]){
                deleteHelper(curr->next[i]);
            }
        }
        delete curr;
    }
    
    ~Trie(){
        // cout << "destructor" << endl;
        deleteHelper(m_root);
    }
private:

    int convert_index(char c){
        return c - 'a';
    }
    
private: 
    TrieNode *m_root;
};



class WordDictionary {
public:
    WordDictionary(): m_trie(){
        
    }
    
    void addWord(string word) {
        m_trie.insert(word);
    }
    
    bool search(string word) {
        return m_trie.search(word);
    }
private:
    Trie m_trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */