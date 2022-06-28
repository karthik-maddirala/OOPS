#include<bits/stdc++.h>
using namespace std;

string LCS( string s1, string s2, int m, int n )
{
    string L[m+1][n+1];
      int i, j;
 
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = "";
    
        else if (s1[i-1] == s2[j-1])
            L[i][j] = L[i-1][j-1] + s1[i-1];
    
        else if(L[i-1][j].size()>L[i][j-1].size())
                L[i][j] = L[i-1][j];
                else L[i][j]=L[i][j-1];
        }
    }   
    return L[m][n];
}

vector<string> closest_with_high_lcs(string s1, vector<string>temp_stings)
{
    string max_len_str=LCS(s1,temp_stings[0],s1.size(),temp_stings[0].size());
    vector<string>temp_vector;  temp_vector.push_back(temp_stings[0]);
    for(int i=1;i<temp_stings.size();i++)
    {
        string lcs_string=LCS(s1,temp_stings[i],s1.size(),temp_stings[i].size());
        if(max_len_str.size()<lcs_string.size())
        {
            max_len_str=lcs_string;
            temp_vector.clear();
            temp_vector.push_back(temp_stings[i]);
        }
        else if(max_len_str.size()==lcs_string.size())
        {
            temp_vector.push_back(temp_stings[i]);
        }

    }
    return temp_vector;
}

int min(int x, int y, int z)
{
    return min(min(x,y),z);
}

int editdistance(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                   dp[i][j]=dp[i-1][j-1];
                   else 
                    dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    int N; cin>>N; //no of words in the sentence
    vector<string>sentence;
    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s; sentence.push_back(s);
    }

    int D; cin>>D; //no of words in the dictionary

    vector<string>Dictionary;
    for(int i=0;i<D;i++)
    {
        cin>>s; Dictionary.push_back(s);
    }

    for(int i=0;i<sentence.size();i++)  //i represents the words from the sentence
    {
        vector<string>temp_strings;     //used to store the closest strings in the Dictionary corresponding to string sentence[i]
        int min_edits=editdistance(sentence[i],Dictionary[0],sentence[i].size(),Dictionary[0].size());
        temp_strings.push_back(Dictionary[0]);
        for(int j=1;j<Dictionary.size();j++)  //j represents the words from the dictionary
        {
            int no_of_edits=editdistance(sentence[i],Dictionary[j],sentence[i].size(),Dictionary[j].size());
            if(min_edits>no_of_edits)
            {
                min_edits=no_of_edits;
                temp_strings.clear();
                temp_strings.push_back(Dictionary[j]);
            }
            else if(min_edits==no_of_edits)
            {
                temp_strings.push_back(Dictionary[j]);
            }

        }    
            //upto we will get closest strings corresponding to word sentence[i] which are stored in the vector temp_stings
            if(temp_strings.size()==1) //that is the closest words are only 1
            {
             cout<<sentence[i]<<endl;
             cout<<temp_strings[0]<<endl;

             string lcs_string=LCS(sentence[i],temp_strings[0],sentence[i].size(),temp_strings[0].size());
             if(lcs_string.size()==0) cout<<"EMPTY"<<endl;
             else  cout<<lcs_string<<endl;

             cout<<min_edits<<endl;
             temp_strings.clear();
            }
            else if(temp_strings.size()>1)
            { //that is we have more than one closest words

               vector<string>words_with_high_Lcs=closest_with_high_lcs(sentence[i],temp_strings); //this function gives the words from dict with high lcs

               for(int k=0;k<words_with_high_Lcs.size();k++)
               {
                   cout<<sentence[i]<<endl;
                   cout<<words_with_high_Lcs[k]<<endl;

                   string lcs_string=LCS(sentence[i],words_with_high_Lcs[k],sentence[i].size(),words_with_high_Lcs[k].size());
                     if(lcs_string.size()==0) cout<<"EMPTY"<<endl;
                     else  cout<<lcs_string<<endl;

                     cout<<min_edits<<endl;
               }
               temp_strings.clear();
            }
        temp_strings.clear();
    }

}