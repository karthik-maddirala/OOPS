#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
    public:

        T key, val;
        Node* left=NULL ;  Node* right=NULL;
        Node* top=NULL ;   Node* bottom=NULL;
};

int coinToss()
{
	int num;
	// unsigned seed = time(0);
	// srand(seed);
	num = rand() % 2 ;
	return num;
}

template<class T>
class skip_list
{  
    private:
        Node<T>* head;            //used to store the address of starting memory
        int max_levels=10; 
        int size=0;


    public:

        skip_list()
        {
            Node<T>* start_ptr=new Node<T>;  //start_ptr->left=NULL;
            Node<T>* end_ptr=new Node<T>;    //end_ptr->right=NULL;
            start_ptr->right= end_ptr;    end_ptr->left=start_ptr;
            // start_ptr->top=NULL;          end_ptr->top=NULL;  
            head=start_ptr;
            
            int i=max_levels;
            for(i; i!=1; i--)
            {
                Node<T>* s_ptr=new Node<T>;    Node<T>* e_ptr=new Node<T>;
                s_ptr->right=e_ptr;      e_ptr->left=s_ptr;

                s_ptr->top=start_ptr;    e_ptr->top=end_ptr;
                start_ptr->bottom=s_ptr;  end_ptr->bottom=e_ptr;
                start_ptr=s_ptr;         end_ptr=e_ptr;
            }

            start_ptr->bottom=NULL;       end_ptr->bottom=NULL;
        }   

    Node<T>* search(T K)
    {
        Node<T>* ptr=head;
        while(ptr->bottom!=NULL)
        {
            ptr=ptr->bottom;

            if(ptr->right->right!=NULL)
            {
                while(K>=ptr->right->key)
                {
                    if(ptr->right->right!=NULL)
                       ptr=ptr->right;

                    else break;  
                }
            }

        }
        return ptr;
    }

    void insert(T  K, T V)
    {
        Node<T>* insert_node=new Node<T>;
        insert_node->key=K;   insert_node->val=V;  //insert_node indicates the newnode we are inserting

        Node<T>* temp=search(K);                 

        if(K==temp->key) return ;
        else 
        {
            size++;
            Node<T>* next_ptr=temp->right;            //btwn temp and next_ptr we have to insert insert_node
            temp->right=insert_node;
            next_ptr->left=insert_node;
            insert_node->left=temp;
            insert_node->right=next_ptr;

            int i=max_levels;

            for(i;i!=2&&(coinToss()%2!=0);i--)
            {
                Node<T>* new_node=new Node<T>;
                new_node->key=K;         new_node->val=V;
    
                    while(temp->top==NULL)
                    {
                        // if(temp->left->left!=NULL)
                        temp=temp->left;
                    }
               
                    temp=temp->top; //here we will be in the upper lever to where we have to insert
                    Node<T>* next_ptr=temp->right;            //btwn temp and next_ptr we have to insert insert_node
                    temp->right=new_node;
                    next_ptr->left=new_node;
                    new_node->left=temp;
                    new_node->right=next_ptr;

                    new_node->bottom=insert_node;   insert_node->top=new_node;
                    insert_node=new_node;

            } 

        }

    }

    void Delete(T K)
    {
        Node<T>* ptr=search(K);
        // cout<<ptr->key<<endl;
        if(ptr->left==NULL||ptr->right==NULL) return ;
        if(ptr->key!=K)  return ;
        else if(ptr->key==K)
        {
            // cout<<"key is there"<<endl;
            size--;
            while(ptr!=NULL)
            {
                Node<T>* ptr_left=ptr->left;      Node<T>* ptr_right=ptr->right;
                Node<T>* remove_ptr=ptr;
                ptr_left->right=ptr_right;         ptr_right->left=ptr_left;
                ptr->left=NULL;                    ptr->right=NULL;
                ptr=ptr->top;
                delete remove_ptr;
            }
        }

    }

    int return_size()
    {
        return size;
    }
}; 

template<class T>
class dictionary
{
    private:
        skip_list<T> S;

    public:

    void  empty()    //print true if dictionary is empty
    {
        if(S.return_size()==0) cout<<"True"<<endl;
        else  cout<<"False"<<endl;
    }

    void insert(T K, T V)
    {
        S.insert(K,V);
    } 

    void Delete(T K)
    { //remove from D an arbitary entry with key value  K
        S.Delete(K);
    } 

    void find(T K)
    { //if dictionary contains key equal to K then print its value else print "NOT FOUND"
        Node<T>* ptr=S.search(K);
        if(ptr->right==NULL||ptr->left==NULL) 
        {
            cout<<"NOT FOUND"<<endl;
            return;
        } 
        else if(ptr->key==K) cout<<ptr->val<<endl;
             else cout<<"NOT FOUND"<<endl;
        return;
    }  

    void size()     //no of keys stored in the dictionary
    {
          cout<<S.return_size()<<endl;
          return;
    }

};

template<class T>
void main_function()
{
    dictionary<T>D;

     int p; cin>>p;  //no of operations

    for(int i=0 ; i<p; i++)
    {
        string s; cin>>s;

        if(s=="ISEMPTY") D.empty();
        else if(s=="INSERT")
              {
                  T K; T V;
                  cin>>K>>V;
                  D.insert(K,V);
              }
             else if(s=="DELETE")
                    {
                        T K; cin>>K;
                        D.Delete(K);
                    }
                    else if(s=="FIND")
                    {
                        T K; cin>>K;
                        D.find(K);
                    }
                    else if(s=="SIZE")
                    {
                        D.size();
                    }
    }
}

int main()
{
    string s; cin>>s;

    if(s=="STRINGDICT") main_function<string>();
    else if(s=="INTEGERDICT")  main_function<int>();
}