#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
       //private:
       //bool isEnd;
      // vector<Node*>next;
       public:
            bool isEnd;
            vector<Node*>next;
        
          Node()
          {
             isEnd=false;
             for(int i=0;i<26;i++)
             {
                 next.push_back(NULL);
             }
          }
};

class my_trie
{
    private:
        Node* head;

    public:
        my_trie()
        {
            head=new Node;
        }

        void insert(string s)
        {
            Node* temp=head;
            int n=s.size();
            for(int i=0;i<n;i++)
            { 
                int k=s[i]-97;
                if(temp->next[k]==NULL)
                {
                  Node* new_node=new Node;
                 temp->next[k]=new_node;
                 temp=new_node;
                }
                else 
                {
                    temp=temp->next[k];
                }
            }
            temp->isEnd=true;  
        }

        void search(string s)
        {
            
            string pre="";
            Node* ptr=head;

            int flag=0;
            //base case
            int j=s[0]-97;
            int n=s.size();
            int flag1=0;
            string small_pref;
            if(ptr->next[j]==NULL)  cout<<s<<" "; 
            else{
            for(int i=0;i<n;i++)
            {
                int k=s[i]-97;

                    if(ptr->next[k]==NULL)
                    {
                        if(ptr->isEnd==true)    //case-1 equal, equal
                        {
                          flag=1;
                          break;
                        }
                        else if(ptr->isEnd!=true) break;     //case-2 equal, false
                    }
                    else
                    {
                        if(ptr->isEnd==true)               //case-3 notequal, equal
                        {
                            flag1=1;
                            small_pref=pre;

                        }
                                                       //case-4  notequal, notequal
                            pre=pre+s[i];
                            ptr=ptr->next[k];
                        
                    } 

            }       
            
            if(flag==0)  
            {
                if(flag1==1)
                    cout<<small_pref<<" ";
                else
                    cout<<s<<" ";
            }
            else if(flag==1)   cout<<pre<<" ";
            }

        }


};

int main()
{
    int p;   cin>>p;  //no of prefix words

    my_trie T;

    string prefix[p];
    for(int i=0;i<p;i++) 
    {
         cin>>prefix[i];
         T.insert(prefix[i]);
    }

    int n; cin>>n; //no of words in the sentence

    string sentence[n];
    for(int i=0;i<n;i++)  
    {   
        cin>>sentence[i];
        T.search(sentence[i]);
    }
    
}