#include <bits/stdc++.h> 
using namespace std;

class DICTIONARY
{
    private:
        map<int,set<string>>mc;

     public:

     void buildDict(vector<string> words)
     {
        for(auto i : words) mc[i.length()].insert(i);  
     }

     void addWordToDict(string word)
     {
        mc[word.length()].insert(word);
     } 

     bool search(string target)
     {
         for(auto i: mc[target.length()])
         { 
             if(i==target)   return true;    
         }
         return false;
     } 

     set<string> getWordsAfterReplace(string target)
     {
         set<string>s;
         for(auto i : mc[target.length()])
            {   
             int count=0;
             for(int j=0;j<target.length();j++)
             {
                 if(target[j]!=i[j]) count++;
             }
             if(count==1) s.insert(i);

             if(search(target)) s.insert(target);
           }

         return s;
     }  
  

     set<string> getWordsAfterSwap(string target)
     {
         set<string>s;  auto i=mc[target.length()].begin();
         
         for(i;i!=mc[target.length()].end();i++)
         {    
             string temp=*i;
             for(int j=0;j<(target.length())-1;j++)
             {
                 swap(temp[j],temp[j+1]);
                 if(temp==target) s.insert(*i);
                 temp=*i;
             } 
         } 
         return s;
     } 

     int maxChangeableWord()
     {
        int final_max=0;

        for(auto i:mc)
        {
            for(auto j:i.second)
            {
                int x = getWordsAfterReplace(j).size();

                if(final_max<x) final_max=x;
            }
        }

        return final_max-1;
     }  

     int maxSwappableWord()
     {
        int final_max=0;

        for(auto i:mc)
        {
            for(auto j:i.second)
            {
                int x = getWordsAfterSwap(j).size();

                if(final_max<x) final_max=x;
            }
        }

        return final_max;
     }

};


int main()
{
    int N; cin>>N;
    DICTIONARY D;

    vector<string>words(N);  
    for(int i=0;i<N;i++)
    {
        cin>>words[i];
    }
    D.buildDict(words);

    int Q; cin>>Q;
    int n; string w;
    for(int i=0;i<Q;i++)
    {
       cin>>n; 
       
       if(n==1) 
       {  cin>>w;
           D.addWordToDict(w);      
       }
       else if(n==2)   
       { 
          cin>>w; 
          if(D.search(w)==1) cout<<"true"<<endl;
          else cout<<"false"<<endl;
       }
                else if(n==3)  
                {
                    cin>>w;
                    set<string>s1=D.getWordsAfterReplace(w);
                                if(s1.size()==0) cout<<-1<<endl;
                                else 
                                {
                                    for(auto i : s1) cout<<i<<" ";
                                    cout<<endl;
                                }
                }
                     else if(n==4) 
                     {
                         cin>>w;
                            set<string>s1=D.getWordsAfterSwap(w);
                        if(s1.size()==0) cout<<-1<<endl;
                        else 
                        {
                            for(auto i : s1) cout<<i<<" ";
                            cout<<endl;
                        } 
                     }
                           else if(n==5) cout<<D.maxChangeableWord()<<endl;
                                 else if(n==6)  cout<<D.maxSwappableWord()<<endl;

       
    }
}