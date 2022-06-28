#include<iostream>
using namespace std;

template<class datatype>
class node
{
    public:
    node<datatype>* left;
    datatype data;
    node<datatype>*right;
};

template<class datatype>
node<datatype>* newnode(datatype val)
{
    node<datatype>* ptr=new node<datatype>;
    ptr->left=NULL;
    ptr->data=val;
    ptr->right=NULL;

    return ptr;
}

template<class datatype>
class Queue
{
    private:
           node<datatype>* head=NULL;
           node<datatype>* tail=NULL;

    public:  
           void enqueue(datatype k)   //inserts an element at the end of the queue
           {
              node<datatype>* ptr= newnode(k);
              if(head==NULL)            //base case
              {
                  head=ptr;
                  tail=ptr;
              }
              else{
                  tail->right=ptr;
                  ptr->left=tail;
                  tail=ptr;
              }

           }

           datatype dequeue()
           {
               datatype k;
             if(head==tail)      //if both points to the same node 
               {   k=head->data;
                   node<datatype>* ptr=head;
                   head=NULL;
                   tail=NULL;
                   delete ptr;
                   
               }
               else 
               {
                   k=head->data;
                   node<datatype>* ptr1=head;
                   node<datatype>* ptr2=head->right;
                   ptr1->right=NULL;
                   ptr2->left=NULL;
                   head=ptr2;
                   delete ptr1;
                   
               }
               return k;
           } 

           int size()
           {   int count=0;
               node<datatype>* ptr=head;
               if(head==NULL) return 0;
               else {
                   while(ptr!=NULL)
                   {
                       count++;
                       ptr=ptr->right;
                   }
               }
               return count;
           }

           bool isEmpty()
           {
               if(head==NULL)return true;
               else return false;
           }

           void print_queue()
           {
               node<datatype>* ptr=head;
               while(ptr!=NULL)
               {
                   cout<<ptr->data<<" ";
                   ptr=ptr->right;
               }
               cout<<endl;
           } 
};

template<class T>
class printer
{
    private:
     Queue<T>q; 
     int cap;
     int ink_value;

    public:
    class InsufficientInk{
        public:
              string message1;
              InsufficientInk(string insi){
                  message1=insi;
              }
    };
    class PrinterBusy{
        public:
              string message2;
              PrinterBusy(string prb){
                  message2=prb;
              }
    };

    class NoDocument{
        public:
              string message3;
              NoDocument(string nodoc)
              {
                  message3=nodoc;
              }
    };
     printer(int capacity,int ink)
     {
         cap=capacity;
         ink_value=ink;
     } 

     void addDocument(T document)
     {   
         if(q.size()==cap)        throw PrinterBusy("PRINTER_BUSY") ;
         q.enqueue(document);
     } 

     T printDocument()
     {
        if(q.size()==0)         throw   NoDocument("NO_DOCUMENT");
         if(ink_value==0) throw InsufficientInk("INSUFFICIENT_INK");
         T temp=q.dequeue();
         ink_value=ink_value-1;
         return temp;
     }

     void fillInk(int ink)
     {
         ink_value=ink;
     }
};

template<class T>
void encription(int M, int N)
{
    printer<T>p(M,N);
    int Q; cin>>Q; //no of commmands 
    for(int i=0;i<Q;i++)
    {
       int n;  cin>>n;
        switch(n)
        {
            case 1:
                  T document;
                  cin>>document;
                  try{
                  p.addDocument(document);
                  }
                  catch(typename printer<T>::PrinterBusy pb)
                  {
                      cout<<pb.message2<<endl;
                  }
                  break;

            case 2:
                  try
                  {
                    cout<<p.printDocument()<<endl;
                  }
                  catch(typename printer<T>::InsufficientInk iik)
                  {
                      cout<<iik.message1<<endl;
                  }

                  catch(typename printer<T>::NoDocument nd)
                  {
                      cout<<nd.message3<<endl;
                  }
                  break;

            case 3:
                  int ink;
                  cin>>ink;
                  p.fillInk(ink);
                  break;

        }

    }
}

int main()
{
    int M,N;    //M=capacity  , N=ink
    char T;
    cin>>M >>N >>T;
    
    if(T=='I')
    {
        encription<int>(M,N);
    }
    else if(T=='C')
    {
        encription<char>(M,N);
    }
    else if(T=='F')
    {
        encription<float>(M,N);
    }

}