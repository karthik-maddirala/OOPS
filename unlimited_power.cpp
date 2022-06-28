#include<bits/stdc++.h>
using namespace std;

int total_max_power(int arr[],int N)
{    
    int temp[N + 2]; temp[0] = 1;   temp[N + 1] = 1;
 
    for (int i = 1; i <= N; i++)   temp[i] = arr[i - 1];

    int dp[N + 2][N + 2];
    memset(dp, 0, sizeof(dp));

    for (int size = 1; size < N + 1; size++)
    {
        for (int left = 1; left < N - size + 2; left++)
        {
            int right = left + size - 1;

            for (int last = left; last < right + 1; last++)
            {
                dp[left][right] = max(dp[left][right],   dp[left][last - 1] + 
                                temp[left - 1] * temp[last] * temp[right + 1] +  dp[last + 1][right]);
            }
        }
    }
    return dp[1][N];
}

int main()
{
    int N; cin>>N;  //no of stones

    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    int P; cin>>P; //power of thanos

    int max_power=total_max_power(arr,N);

    cout<<max_power<<endl;

    if(max_power>=P) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}