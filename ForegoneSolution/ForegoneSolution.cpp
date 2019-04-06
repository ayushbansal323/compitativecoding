#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    for(size_t z = 1; z <= t; z++)
    {
        string a,b,n;
        int r=0;
        cin>>n;
        //cout<<n<<endl;
        for(int i = 0; i < n.length() ; i++)
        {
            if(n[i]=='4')
            {
                a=a+'3';
                b=b+'1';
            }
            else
            {
                a=a+n[i];
                b=b+'0';
            }
            
        }
        
        
        /*
        while(n!=0)
        {
            a=a*10;
            b=b*10;
            r=n%10;
            if(r!=4)
            {
                a=a+r;
                b=b;
            }
            else
            {
                a=a+r-1;
                b=b+1;
            }
            cout<<"n :"<<n<<"\tr :"<<r<<"\ta :"<<a<<"\t b:"<<b<<endl;
            n=n/10;
        }*/
        a.erase(0, a.find_first_not_of('0'));
        b.erase(0, b.find_first_not_of('0'));

        cout<<"Case #"<<z<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}
