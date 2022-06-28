#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

template<class datatype>
 class node{
    public: 
    node<datatype>* left;
    datatype data;
    node<datatype>* right;
};

template<typename datatype>
node<datatype>* newnode(datatype x){
    node<datatype>* ptr=new node<datatype>;
    ptr->left=NULL;
    ptr->data=x;
    ptr->right=NULL;

    return ptr;
}

template<class datatype>class DLL{
    private:
          node<datatype>* head;
          node<datatype>* tail;
    public:
          DLL(){
              head=NULL; tail=NULL;
          }

          void push_front(datatype x){
              node<datatype>* ptr=newnode(x);
              if(NULL==head) { head=ptr; tail=ptr;}
              else {
                  ptr->right=head;
                  head->left=ptr;
                  head=ptr;
              }

          }

          void push_end(datatype x){
              node<datatype>* ptr=newnode(x);
              if(NULL==tail){tail=ptr; head=ptr;}
              else {
                  tail->right=ptr;
                  ptr->left=tail;
                  tail=ptr;
              }

          }

          datatype pop_front(){
              if(head==tail)
              {
                  node<datatype>* temp1=head;
                  datatype k=temp1->data;
                  delete temp1;
                  head=NULL; tail=NULL;
                  return k;
              }
              node<datatype>* temp1=head;  node<datatype>* temp2=head->right;
              temp2->left=NULL;
              temp1->right=NULL;
              head=temp2;
              datatype k=temp1->data;
              delete temp1;
              return k;
          }

          datatype pop_end(){
              if(head==tail)
              {
                  node<datatype>* temp1=head;
                  datatype k=temp1->data;
                  delete temp1;
                  head=NULL; tail=NULL;
                  return k;
              }
              node<datatype>* temp1=tail->left;  node<datatype>* temp2=tail;
              temp1->right=NULL;
              temp2->right=NULL;
              tail=temp1;
              datatype k=temp2->data;
              delete temp2;
              return k;
          }

          int size(){
              node<datatype>* temp=head;
              int count=0;
              while(temp!=NULL)
              {
                  count++;
                  temp=temp->right;
              }
              return count;
          }

}; 

template<class datatype>class Stack{
    private:
      DLL<datatype> list;  
    public:
    void push(datatype x){
        list.push_front(x);
    }

    datatype pop(){
      return  list.pop_front();
    }

    datatype return_top(){
        datatype k=list.pop_front();
        list.push_front(k);
        return k;
    }

    int return_size(){
        return list.size();
    }

    bool compare(datatype n){
        datatype k=list.pop_front();
        list.push_front(k);
        if(n>k) return true;
        else return false;
    }

    void print(){
        list.print();
    }

}; 

template<typename T>
void encription(int N)
{   
    Stack<T>s;
    T current ;
    T arr[N];
    for(int j=0;j<N;j++)
     cin>>arr[j]; 

    int i=0 ;
     current=arr[i];        int count=1;

    while(count!=N+1)
    {
        
         if(s.return_size()==0) 
        {
            s.push(current);
            i=i+1;
            current=arr[i];   count++;
        }
        else if(s.compare(current))
        {
            s.push(current);
            i=i+1;
            current=arr[i];  count++;
        }
        else 
        {  
            cout<<s.pop();
        }
    }
            while(s.return_size())
            cout<<s.pop();
    
}

int main()
{

    int N; char T;
    cin>>N >>T;
    
    if(T=='I')
    {
        encription<int>(N);
    }
    else if(T=='C')
    {
        encription<char>(N);
    }
    else if(T=='F')
    {
        encription<float>(N);
    } 

}
