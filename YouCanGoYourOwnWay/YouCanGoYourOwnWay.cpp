#include<iostream>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    for(size_t z = 1; z <= t; z++)
    {
        int n=0;
        cin>>n;
        string p,ans;
        cin>>p;
        ans=p;
        for(size_t i = 0; i < ans.length(); i++)
        {
            if(ans[i]=='S')
            {
                ans[i]='E';
            }
            else
            {
                ans[i]='S';
            }
            
        }
        
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
    
    return 0 ;
}