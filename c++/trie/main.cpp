#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct TrieNode{
	TrieNode *children[26];
	bool isEnd;
};

const int ALPHABET_SIZE = 26; 


struct TrieNode *getNode() 
{
	TrieNode *pNode =new TrieNode;
	pNode->isEnd=false;
	
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		pNode->children [i]=NULL;
	}
	
	return pNode;
}
void insert(struct TrieNode *root, string key) 
{
	TrieNode *pcrawl=root;
	
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!pcrawl->children [index])
		{
			pcrawl->children [index]=getNode();
		}
		pcrawl=pcrawl->children[index];
	}
	pcrawl->isEnd =true;
}

bool isLeafNode(struct TrieNode* root) 
{ 
    return root->isEnd != false; 
}
void display(struct TrieNode* root, char str[], int level) 
{
	if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
        cout << str << endl; 
    } 
  
    int i; 
    for (i = 0; i < ALPHABET_SIZE; i++)  
    { 
        // if NON NULL child is found 
        // add parent key to str and 
        // call the display function recursively 
        // for child node 
        if (root->children[i])  
        { 
            str[level] = i + 'a'; 
            display(root->children[i], str, level + 1); 
        } 
    }  
}
bool search(struct TrieNode *root, string key) 
{
	
	TrieNode *pcrawl=root;
	
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		
		if(pcrawl->children [index]==NULL)//if (!pCrawl->children[index]) 
		{
			return false;
		}
		pcrawl=pcrawl->children [index];
	}
	
	return (pcrawl != NULL && pcrawl->isEnd);
}
bool isEmpty(TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
} 
TrieNode* remove(TrieNode* root, string key, int depth = 0) 
{
	if(root==NULL)
	{
		return NULL;
	}
	
	if(depth==key.length())
	{
		if(root->isEnd==true)
		{
			root->isEnd=false;
		}
		
		if(isEmpty(root))
		{
			delete(root);
			root=NULL;
		}
		return root;
	}
	
	int index=key[depth]-'a';
	root->children[index]=remove(root->children[index], key, depth + 1);
	
	if(isEmpty(root)&&root->isEnd==false)
	{
		delete(root);
		root=NULL;
	}
	return root;
}
int main(int argc, char** argv) {
	// Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their", "hero", "heroplane" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    int level = 0; 
    char str[20]; 
  
    // Displaying content of Trie 
    cout << "Content of Trie: " << endl; 
    display(root, str, level); 
	  
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" :cout << "No\n";
	
	remove(root, "heroplane"); 
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
	 
    return 0; 
	
}
