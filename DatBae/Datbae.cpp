#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include<string>
using namespace std;

int findbroke(int *broke,int b,int index)
{
    for(size_t i = 0; i < b; i++)
    {
        if(broke[i]==index)
        {
            return index;
        }
    }
    return -1;
}
int check(string request,string response,int *broke,int n,int b)
{
    int j=0;
    for(size_t i = 0; i < n; i++)
    {
        if((findbroke(broke,b,i)==-1))
        {
            //cout<<i<<" = "<<request[i]<<"\t"<<j<<" = "<<response[j]<<endl;
            if(request[i]==response[j])
            {
                j++;
            }
            else
            {
                return -1;
            }
            
        }
    }
    return 0;
}
int findprebroke(int *prebroke,int b,int index)
{
    for(size_t i = 0; i < b; i++)
    {
        if(prebroke[i]==index)
        {
            return index;
        }
    }
    return -1;
}
void findbroke(int *broke,int *prebroke,string request,string response,int n,int b)
{
    int j =0,flag=0,bk=0;
    int last=b-1;
    for(size_t i = 0; i < n; i++)
    {
        //cout<<i<<" = "<<request[i]<<"\t"<<j<<" = "<<response[j]<<endl;
        if( (request[i]==response[j]) && (flag == 0))
        {
            if(findprebroke(prebroke,b,i)!= -1)
            {
                broke[bk]=i;
                bk++; 
            }
            else
            {
                j++;
                if(j==(n-b))
                {
                    flag=1;
                }
            }
        }
        else if(flag==1)
        {
            broke[bk]=i;
            bk++;
        }
        else if((request[i]!=response[j]))
        {
            broke[bk]=i;
            bk++;
        }

        if(bk==b && flag==0)
        {
            break;
        }
    }
    while((check(request,response,broke,n,b)!=0) && last>=0)
    {
        //cout<<"check failed"<<endl;
        broke[last]=prebroke[last];
        last--;
    }
    
}
int main()
{
    int t=0;
    cin>>t;
    for(size_t z = 0; z < t; z++)
    {
       // cerr<<"sadds";
        int n,b,f;
        cin>>n>>b>>f;
        string request(n,'0');
        string response(n-b,'0');
        int broke[b],prebroke[b];
        int gap=2;
        for(size_t j = 0; j < b; j++)
            {
                prebroke[j]=broke[j]=n;
               // cout<<prebroke[j];
            }
        //cout<<request;
        for(size_t i = 0; i < f; i++)
        {
            for(size_t j = 0; j < n; j++)
            {
                int temp=(rand()%2)+48;
                request[j]=temp;
            }
            cout<<request<<endl;
            cout.flush();
            cin>>response;
            for(size_t j = 0; j < b; j++)
            {
                prebroke[j]=broke[j];
                //cout<<prebroke[j];
            }
            //cout<<response<<endl;
            findbroke(broke,prebroke,request,response,n,b);

            //cout<<"broke \n";
            /*for(size_t j = 0; j < b; j++)
            {
                cout<<broke[j]<<endl;
            }*/
            
        }
        for(size_t j = 0; j < b; j++)
        {
                cout<<broke[j]<<" ";
        }
        cout<<endl;
        cout.flush();
        int verdic=0;
        cin>>verdic;
        if(verdic == -1)
        {
            return 0;
        }
        //cerr<<verdic;
    }
    
}