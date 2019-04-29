#include<iostream>
#include<string>
using namespace std;
int main()
{
int t;
cin>>t;
for (size_t z = 0; z < t; z++)
{
    int block,ques,ans=0;
    cin>>block>>ques;

    string str;
    cin>>str;
    //cout<<str;
    
    for (size_t i = 0; i < ques; i++)
    {
        int hash[26]={0};
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        for (size_t j = l; j <= r; j++)
        {
            int temp=str[j]-65;
            if(hash[temp]==1)
            {
                hash[temp]--;
            }
            else
            {
                hash[temp]++;
            }
            
            //cout<<":"<<temp<<str[j]<<" :"<<hash[temp]<<"\t";
        }
        int onec=0;
        for (size_t j = 0; j < 26; j++)
        {
            if(hash[j]==1)
            {
                onec++;
            }
        }
        if(onec<=1)
        {
            ans++;
        }
       //cout<<endl; 
    }
    cout<<"Case #"<<z+1<<": "<<ans<<endl;
}   

}