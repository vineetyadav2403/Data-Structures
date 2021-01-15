class Trie{
    public:
    bool isEndWord;
    Trie *child[26];
    Trie(){
        isEndWord = false;
        for(int i=0;i<26;i++){
            this->child[i] = NULL;
        }
    }
};
void insert(Trie *root,string word){
    Trie *temp = root;
    for(int i=0;i<word.length();i++){
        int index = word[i]-'a';
        if(!temp->child[index]){
            Trie *node = new Trie();
            temp->child[index] = node;
        }
        temp = temp->child[index];
    }
    temp->isEndWord = true;
    
}
