#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Book
{
    public:
           string title;
           string author;
           int year;
           int price;

};

class Node{
    public: Book info;
            Node* next=NULL;
         
};

Node* newnode(Book b)
{
    Node* ptr=new Node;
    ptr->info=b;
    ptr->next=NULL;
    return ptr;
}

class Bookshelf
{
    public:
          Node* head=NULL;

   virtual void addBook(Book b);
   virtual void removeBook();
   virtual int checkEmpty();
   virtual void list();
   virtual void findCheap();
   virtual void reverseUnique();      
};

int Bookshelf::checkEmpty()
{
    if(head==NULL) return 0;
    else  return 1;
}  

class verticalBookshelf: public Bookshelf
{
    public:
      void addBook(Book b)
      {
         Node* ptr=newnode(b);

         if(head==NULL) head=ptr;
         else
         {
             ptr->next=head;
             head=ptr;
         }
      }

        void removeBook()
        {
            if(head==NULL)
            {
                cout<<"e"<<endl;
                return ;
            }

            else {
                Node* temp1=head;
                head=temp1->next;
                delete temp1;   
                return ;
            }
            return ;
        }

        void list()
        {
            if(head==NULL) {
                cout<<"e"<<endl;  
                return ;
            }
            else 
            {
                Node* temp2=head;
                while(temp2!=NULL)
                {
                    cout<<temp2->info.title<<","<<temp2->info.author<<",";
                    cout<<temp2->info.year<<","<<temp2->info.price<<endl;

                    temp2=temp2->next;
                }
            }
        }

        void findCheap()
        {
            if(head==NULL) cout<<"e";

            else {
                Node* temp3=head;
                int min=temp3->info.price;
                while(temp3!=NULL)
                {
                    int curr_price=temp3->info.price;
                    if(curr_price<=min)
                    {
                        cout<<"-1";
                        min=curr_price;
                    }
                    else{
                        cout<<min;
                    }
                    temp3=temp3->next;
                    if(temp3!=NULL) cout<<",";
                }
            }

            cout<<endl;
        }

        void reverseUnique()
        {
            Node* temp01;  Node* temp02;
              temp01=head;
              while(temp01!=NULL&&temp01->next!=NULL)
              {
                  temp02=temp01;
                  while(temp02->next!=NULL)
                  {
                      if(temp01->info.price==temp02->next->info.price)
                      {
                          Node* n=temp02->next;
                          temp02->next=temp02->next->next;
                          delete n;
                      }
                      else temp02=temp02->next;
                  }
                  temp01=temp01->next;
              }

              //reversing the list 
              Node* P=NULL; //previous pointer
              Node* C=head; //current pointer
              Node* N=C;    //Next pointer
              while(C!=NULL)
              {
                  N=C->next;
                  C->next=P;
                  P=C;
                  C=N;
              }
              head=P; 
        } 

    
};

class HorizontalBookshelf: public Bookshelf
{
    public:
         void addBook(Book b)
      {
         Node* ptr=newnode(b);

         if(head==NULL) head=ptr;
         else
         {
            Node* tmp=head;
            while(tmp->next!=NULL) tmp=tmp->next;

            tmp->next=ptr;
         }
      }

      void removeBook()
        {
            if(head==NULL)
            {
                cout<<"e"<<endl;
                return ;
            }

            else {
                Node* temp1=head;
                head=temp1->next;
                delete temp1;  
                return ; 
            }
            return;
        }

        void list()
        {
            if(head==NULL) {
                cout<<"e"<<endl;  
                return ;
            }
            else 
            {
                Node* temp2=head;
                while(temp2!=NULL)
                {
                    cout<<temp2->info.title<<","<<temp2->info.author<<",";
                    cout<<temp2->info.year<<","<<temp2->info.price<<endl;

                    temp2=temp2->next;
                }
            }
        }

        void findCheap()
        {
            if(head==NULL) cout<<"e";

            else {
                Node* temp3=head;
                int min=temp3->info.price;
                while(temp3!=NULL)
                {
                    int curr_price=temp3->info.price;
                    if(curr_price<=min)
                    {
                        cout<<"-1";
                        min=curr_price;
                    }
                    else{
                        cout<<min;
                    }
                    temp3=temp3->next;
                    if(temp3!=NULL) cout<<",";
                }
            }

            cout<<endl;
        }

        void reverseUnique()
        {
            Node* temp01;  Node* temp02;
              temp01=head;
              while(temp01!=NULL&&temp01->next!=NULL)
              {
                  temp02=temp01;
                  while(temp02->next!=NULL)
                  {
                      if(temp01->info.price==temp02->next->info.price)
                      {
                          Node* n=temp02->next;
                          temp02->next=temp02->next->next;
                          delete n;
                      }
                      else temp02=temp02->next;
                  }
                  temp01=temp01->next;
              }

              //reversing the list 
              Node* P=NULL; //previous pointer
              Node* C=head; //current pointer
              Node* N=C;    //Next pointer
              while(C!=NULL)
              {
                  N=C->next;
                  C->next=P;
                  P=C;
                  C=N;
              }
              head=P; 
        } 
   

};

int main()
{
    int Q; cin>>Q;
    verticalBookshelf v1;
    HorizontalBookshelf H1;
    for(int i=0;i<Q;i++)
    {
       
        string s;
        cin>>s;
        
        
            if(s=="ADD")
            {
                       Book b;  char x;  cin>>x;
                       cin>>b.title>>b.author>>b.year>>b.price;
                       if(x=='v'){
                           v1.addBook(b);
                       } else H1.addBook(b);
            }

            else if(s=="REMOVE")
            {
                          int n; char x;
                          cin>>n>>x;
                          for(int i=0;i<n;i++)
                          {
                              if(x=='v') v1.removeBook();
                              else H1.removeBook();
                          } 
            }

            else if(s=="LIST")
            {
                        char x; cin>>x;
                        if(x=='v') v1.list();
                        else H1.list(); 
             }

            else if(s=="FINDC")
            {
                         char x; cin>>x;
                         if(x=='v') v1.findCheap();
                         else H1.findCheap(); 
            }

            else if(s=="REVUNI")
            {
                          char x; cin>>x;
                          if(x=='v') v1.reverseUnique();
                          else H1.reverseUnique();
          }            
    } 

}
