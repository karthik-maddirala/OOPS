#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Matrix
{
    private:
            int rows;
            int columns;
            int **mat;
    public:

    Matrix()
    {
        rows=0;
        columns=0;
        mat=NULL;
    }
    Matrix(int r, int c)
    {
        rows=r;
        columns=c;
        mat=new int*[r];
        for(int i=0;i<rows;i++)
        {
          mat[i]=new int[c];
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                mat[i][j]=0;
            }
        }
    }

    Matrix(int r, int c, int  **matrix)
    {
        rows=r;
        columns=c;

        mat=new int*[r];
        for(int i=0;i<rows;i++)
        {
          mat[i]=new int[c];
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                mat[i][j]=matrix[i][j];
            }
        }
        
    }

    void setValue(int row,int col,int val)
    {
        mat[row][col]=val;
    }
    int getValue(int row,int col)
    {
        return mat[row][col];
    }
    int getNoRows()
    {
        return rows;
    }
    
    int getNoColumns()
    {
        return columns;
    }

    void printSpiral();
    int trace();
    bool checkTriangular();
    bool isSpecialMatrix();

};

void Matrix:: printSpiral()
{
    int T=0;
    int B=rows-1;
    int L=0;
    int R=columns-1;
    int dir=0;

    while(T<=B && L<=R)
    {
        if(dir==0)
        {
            for(int i=L; i<=R; i++)
              {cout<<mat[T][i]<<" ";}
              T++;
              dir++;
        }
        else if(dir==1)
        {
            for(int i=T; i<=B ; i++)
               { cout<<mat[i][R]<<" ";}
                R--;
                dir++;   
        }
        else if(dir==2)
        {
            for(int i=R; i>=L; i--)
            { cout<<mat[B][i]<<" ";}
             B--;
             dir++;
        }
        else if(dir==3)
        {
            for(int i=B;i>=T;i--)
             {cout<<mat[i][L]<<" ";}
             L++;
             dir=0;
        }

    }
    cout<<endl;

}

int Matrix:: trace()
{
    if(rows!=columns) return -1;
    else
    {
        int trc=0;
        for(int i=0;i<columns;i++)
        {
            trc+=mat[i][i];
        }
        return trc;
    }
}

bool Matrix:: checkTriangular()
{
    int up_check=0;
    int down_check=0;

    if(rows!=columns) return false;
    if(rows==1 && columns==1) return true;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(j>i)
            {
                if(mat[i][j]!=0)
                {
                    up_check=-1;
                    break;
                }
                else 
                {
                    up_check=0;
                    continue;
                }
            }
        }
        if(up_check==-1) break;
        else continue;
    }

    for(int j=0;j<columns;j++)
    {
        for(int i=0;i<rows;i++)
        {
            if(i>j)
            {
                if(mat[i][j]!=0) 
                {
                    down_check=-1;
                    break;
                }
                else
                {
                    down_check=0;
                    continue;
                }
            }
        }
        if(down_check==-1) break;
        else continue;
    }

    if(up_check==0||down_check==0) return true;
    else return false;
    return false;
}

bool Matrix:: isSpecialMatrix()
{
    int x=0;
    int y=0;
    for(int j=0;j<columns;j++)  x +=mat[0][j];
    for(int i=0;i<rows;i++)  y +=mat[i][0];

    for(int i=1;i<rows;i++)
    {   int temp=0;
        for(int j=0; j<columns; j++)
        {
            temp +=mat[i][j];
        }
        if(temp!=x) return false;
        else continue;
    }

    for(int j=1;j<columns;j++)
    {
        int stemp=0;
        for(int i=0;i<rows;i++)
        {
            stemp +=mat[i][j];
        }
        if(stemp!=y) return false ;
        else continue;
    }
    if(x==y) return true;
    else return false;
}

int main()
{
    int N, M;
    cin>>N >>M;
    int m;
    Matrix t(N,M);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>m;
            t.setValue(i,j,m);
        }
    }

    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        int n; cin>>n;
        if(n==1) t.printSpiral();
        else if(n==2) cout<<t.trace()<<endl;
        else if(n==3)
               {
                   if(t.checkTriangular()==true) cout<<"true"<<endl;
                   else cout<<"false"<<endl;
               }
        else if(n==4)
              {
                  if(t.isSpecialMatrix()==true) cout<<"true"<<endl;
                  else cout<<"false"<<endl;
              }      

    
    }
    return 0;
} 

