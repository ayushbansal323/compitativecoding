#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n],arr1[n],small,big;
    int a,b,c;
    for (int z = 0; z < n; z++)
    {
        int val;
        cin>>val;
        a=val%10;
        val=val/10;
        b=val%10;
        val=val/10;
        c=val;
        //cout<<" c b a "<<c<<" "<<b<<" "<<" "<<a;
        if(a<=b)
        {
            if(b<=c)
            {
                big=c;
                small=a;

            }
            else
            {
                big=b;
                if(a<=c)
                {
                    small=a;
                }
                else
                {
                    small=c;
                }
                
            }
        }
        else if(b<=a)
        {
            if(a<=c)
            {
                big=c;
                small=b;
            }
            else
            {
                big=a;
                if(b<=c)
                {
                    small=b;
                }
                else
                {
                    small=c;
                }
                
            }
            
        }
        else if(c<=a)
        {
            if(a<=b)
            {
                big=b;
            }
            else
            {
                big=a;
                if(c<=b)
                {
                    small=c;
                }
                else
                {
                    small=c;
                }
            }
            small=c;
        }
        //cout<<" Small : "<<small<<"Big :"<<big<<endl;
        arr1[z]=(((big*11)+(small*7))%100);
        arr[z]=arr1[z]/10;
        //cout<<" "<<arr[z];

    }
    
    int arrc[10];
    int hash[100];
    //for even

    int count=0;
    for (int i = 0; i < 100; i++)
    {
        hash[i]=0;
    }
    
    for (int i = 0; i < 10; i++)
    {
        arrc[i]=-1;
    }
    
    for (int i = 0; i < n; i=i+2)
    {
        if(hash[arr1[i]]<2)
        {
            arrc[arr[i]]++;
            hash[arr1[i]]++;
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        if(arrc[i]>=0)
        {
            count=count+arrc[i];
        }
    }


    //for odd
    for (int i = 0; i < 100; i++)
    {
        hash[i]=0;
    }

    for (int i = 0; i < 10; i++)
    {
        arrc[i]=-1;
    }
    
    for (int i = 1; i < n; i=i+2)
    {
        if(hash[arr1[i]]<2)
        {
            arrc[arr[i]]++;
            hash[arr1[i]]++;

        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        if(arrc[i]>=0)
        {
            count=count+arrc[i];
        }
    }
    cout<<count;
    return 0;
}
