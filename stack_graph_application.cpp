#include<iostream>
using namespace std;

class Node{
    public:
           int val;
           Node* next=NULL;
};

Node* newnode(int x)
{
    Node* ptr=new Node;
    ptr->val=x;
    ptr->next=NULL;
    return ptr;
}

class Stack
{
    private:
             Node* head=NULL;

    public:

    void Push(int x)
    {
        Node* ptr=newnode(x);
        if(head==NULL) head=ptr;
        else
        {
          ptr->next=head;
          head=ptr;
        }

    }

    int Pop()
    {
        Node* ptr=head;
        if(head==NULL) return -1;
        else {
            int value=ptr->val;
            head=ptr->next;
            delete ptr;
            return value;
        }

        return -1;
    } 

    int Top()
    {
        if(head==NULL) return -1;
        else return head->val;
    }   

    bool isEmpty()
    {
        if(head==NULL)  return 1;
        else return 0;
    }             

              
};

class Graph
{
    private:
            int V; //no of vertices of the 
            int **adjmat;       //adj_mat initialization;
            int *visited;     //keeping track of whether the vertices are visited or not

    public:
           Graph(int n)
           {
               V=n;
               
               adjmat=new int*[n];
               for(int i=0;i<n;i++)
               {
                   adjmat[i]=new int[n];
               }
               for(int i=0;i<n;i++)
               {
                for(int j=0;j<n;j++)
                  adjmat[i][j]=0; 
               }
                visited=new int[n];
                for(int i=0;i<n;i++)
                   visited[i]=0;              //initializing all the vertics to be not visited
           } 


    void operator+=(pair<int,int> &p)
    {
          adjmat[p.first][p.second]=1;
          adjmat[p.second][p.first]=1;
    }

    void operator-=(pair<int,int> &p)
    {
           adjmat[p.first][p.second]=0;
           adjmat[p.second][p.first]=0;
    }


     bool DFS(int i, int parent)
    {
        visited[i]=1;
        
        for(int j=0;j<V;j++)
        {
            //for the adjacent vertices of i that are not visited doing DFS

            if(adjmat[i][j]==1)  //that is adjacent vertex
            {
                if(visited[j]==0)
                {
                    if(DFS(j,i)==1)
                      return true;
                }

                else if(j!=parent)  return true;
            }
        } 
        return false;  
    }             
           
    bool  detectCycle()
    {
        for(int i=0;i<V;i++)      //initializing all the vertices to be non-visited
                   visited[i]=0;   
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
               if(DFS(i,-1)==1)
                 return true;
        }
        return false;
    } 

    bool reach(int source, int destinition)
    {
        for(int i=0;i<V;i++)      //initializing all the vertices to be non-visited
                   visited[i]=0;

         Stack s;
         s.Push(source); 

         while(s.isEmpty()==0)
         {
             int t=s.Pop();

             if(visited[t]==0)
             {
                 visited[t]=1;
                 if(t==destinition)  return true;
             }

             for(int j=0;j<V;j++)
             {
                 if(adjmat[t][j]==1)
                 {
                     if(visited[j]==0)
                       s.Push(j);
                 }
             }
         }

         return false;         
    }

friend ostream& operator << (ostream& s,Graph& g);


};

ostream& operator<< (ostream &os,Graph& g ) {

    for (int i = 0; i <g.V; i++)
    {
        for (int j = 0; j <g.V; j++)
        {
            os << g.adjmat[i][j]<<" ";
        }
        os << endl;
    }
    return os;
}

int main()
{
    int Q;   cin>>Q; //no of  operators to be performed on the Stack

    Stack st;

    for(int i=0;i<Q;i++)
    {
        string s;
        cin>>s;

        if(s=="push")
        {
            int temp; cin>>temp;
            st.Push(temp);    
        }
        else if(s=="pop")
        {
            cout<<st.Pop()<<endl;
        }
        else if(s=="top")
        {
            cout<<st.Top()<<endl;
        }
        else if(s=="empty")
        {
            cout<<st.isEmpty()<<endl;
        }

    }

    int n; //no of vetices in the graph;
    cin>>n;
    Graph G(n);

    int m; cin>>m;

    for(int i=0;i<m;i++)
    {
        string s1; cin>>s1;

        if(s1=="add")
        {
           int u , v;   cin>> u>> v;
            pair<int,int>p(u,v);
            G+=p;
            
        }
        else if(s1=="del")
        {
            int u, v;    cin>> u>> v;
            pair<int,int>p(u,v);
            G-=p;
        }
        else if(s1=="cycle")
        {
            cout<<G.detectCycle()<<endl;
        }
        else if(s1=="print")
        {
              cout<<G; 
        }
        else if(s1=="reach")
        {
            int u, v; cin>> u>> v;
            cout<<G.reach(u,v)<<endl;
        }

    }

}