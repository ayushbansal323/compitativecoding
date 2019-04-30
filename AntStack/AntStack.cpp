#include<iostream>
using namespace std;
long long int inf=10000000000000;
long long int minweight(long long int *w,long long int x)
{
    long long int min = inf;
    for (size_t i = 0; i < x; i++)
    {
        if(w[i]<min)
        {
            min=w[i];
        }
    }
    return min;
}

long long int g(long long int x,int y,long long int * w,long long int ** found)
{
    //cout<<x<<" "<<y<<endl;
    if(x<y || x < 0)
    {
        //cout<<x<<endl;
        return inf;
    }
    if(found[x][y])
    {
        return found[x][y];
    }
    if(y==1 || y==0)
    {
        //cout<<x<<endl;
        
        return (found[x][y]=minweight(w,x));
    }
    //cout<<x<<"\t"<<endl;
    //cout<<x<<endl;
    long long int ret = g( x - (long long int)1, y -(long long int)1,w,found);
    //return ret;
     if(ret <= (6*w[x-1]))
     {
         return (found[x][y]=(g(x - (long long int)1, y -(long long int)1,w,found)+w[x-1]));
     }
    
    
    
    //cout<<" g: "<<temp<<" "<<found[x][y]<<"\t";
    return (found[x][y] = g(x-1,y,w, found ));
}

int main()
{
    int t;
    cin>>t;
    for (size_t z = 0; z < t; z++)
    {
        //cout<<"level";
        long long int n;
        cin>>n;
        long long int w[n];
        long long int **found;
        found=new long long int*[n+1];
        for (size_t i = 0; i < n; i++)
        {
            cin>>w[i];
            found[i]=new long long int[142];
        }
        found[n]=new long long int[142];
        int i = 0;
        //cout<<i<<endl;
        for (i = 0; i < 140; i++)
        {
            
            if(g(n,i,w,found)>=inf)
            {
                break;
            }
        }
        cout<<"Case #"<<z+1<<": "<<i-1<<endl;
        
        }
    
    
    
    return 0;
}