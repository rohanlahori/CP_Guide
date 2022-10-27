#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    int cnt=0;
	int end=0;
    bool containsKey(char ch)
    {
        if(links[ch-'a']!=NULL)
        {
            return 1;
        }
        return 0;
    }
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    void setCnt()
    {
        cnt++;
    }
    int count()
    {
        return cnt;
    }
    void reducecnt()
    {
        cnt--;
    }
	void increaseEnd()
	{
		end++;
	}
    int checkequal()
	{
		return end;
	}
	void reduceend()
	{
		end--;
	}
	bool isEnd() {
		return flag;
	}
};


class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root=new Node();
    }
    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->setCnt();
        }
		node->increaseEnd();
    }


	bool search(string word) 
	{
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}


	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containsKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}



    int countWordsEqualTo(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->checkequal();
    }

    int countWordsStartingWith(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
            
        }
        return node->count();
    }

    void erase(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            node=node->get(word[i]);
            node->reducecnt();
        }
		node->reduceend();
    }
};


int main() 
{
  Trie T;
//   T.insert("apple");
}
