#include<bits/stdc++.h>
using namespace std;

class base
{  
    public:
        int optimal_value;
        int n;
        base()
        {
            cin>>n;
        }

        virtual int optimal_profit(int W, int revenue[], int weights[])
        {
            return 0;
        }
};

class derived : public base
{
    public:

        int optimal_profit(int W, int revenue[],int weights[])
        {
            int K[W+1];   //K[i] stores the max revenue when the bag capacity weight is i
            K[0]=0;

            for(int w=1;w<=W;w++)
            {
                int max_profit=K[w-1];
                for(int i=0;i<n;i++) 
                {
                    int temp;
                    if(weights[i]<=w) temp=K[w-weights[i]]+revenue[i];
                    else temp=K[w-1];
                    if(max_profit<temp) max_profit=temp;  
                }
                K[w]=max_profit;
                //    cout<<K[w]<<" "<<w<<endl;
            }
            optimal_value=K[W];
            return optimal_value;
        }
};

int main()
{
    int W; cin>>W; //total capacity of the bag
    // int n; cin>>n; //no of items

    derived obj1;

    int n=obj1.n;

    int revenue[n];  //revenue i.e profit of each item

    for(int i=0;i<n;i++) cin>>revenue[i];

    int weights[n];   //weight of each item

    for(int i=0;i<n;i++) cin>>weights[i];

    cout<<obj1.optimal_profit(W,revenue,weights)<<endl;


}