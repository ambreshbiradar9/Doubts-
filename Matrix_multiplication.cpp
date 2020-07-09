#define rep(i,n) for(int i = 0; i < n; i++) 
#define rep1(i,n) for(int i = 1; i <= n; i++)
#include<vector>
typedef long long int ll;
using namespace std;
typedef vector<vector<ll>> Matrix;
typedef vector<ll> array;
#include<iostream>
ll mod=10E9+7;


void print(Matrix M)
{
    rep(i,M.size())
    {
        rep(j,M.size())
        {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

Matrix multiply(Matrix M1,Matrix M2)
{
    int d=M1.size();
    Matrix result(d,array(d));
   
    rep(i,d)
    {
        rep(j,d)
        {
        result[i][j]=0;
        rep(k,d)
        {
            result[i][j]=result[i][j]+(M1[i][k]*M2[k][j])%mod;
        }
        }
    }

    return result;
}

void Matrix_multiplication(Matrix M,int p)
{
    //cout<<"Successfulluy i am in the Matrix_multiplication function"
    Matrix res;
    
    rep(i,M.size())
    {
        array temp;
        rep(j,M.size())
        {
            int t;
            (i==j)?t=1:t=0;
            temp.push_back(t);
        }
        res.push_back(temp);
    }
    
   // rep1(i,p)
    //{
    //    res=multiply(res,M);
    //}
        while(p)
        {
            if(p%2) res=multiply(res,M);
            M=multiply(M,M);
            p=p/2;
        }

    print(res);
}

int main()
{
   
    int T;
    
    cin>>T;
    while(T--)
    {
    //cout<<"enter the dimension of the matrix"<<endl;
    int d;
    int p;
    Matrix M;
    cin>>d;
    cin>>p;
    //cout<<"enter the parameters"<<endl;
    rep(i,d)
    {
        array temp;
        rep(j,d)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        M.push_back(temp);
    }
    //cout<<"enter the power to be raised"<<endl;
    Matrix_multiplication(M,p);
    }
    return 0;
}