#include <iostream>
#include <string>
using namespace std;
bool search(string str[],string s,int length)
{
    for (size_t i = 0; i < length; i++)
    {
        if(str[i]==s)
        {
            return true;
        }
    }
    return false;
    
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    int length=0;
    for (size_t z = 0; z < t; z++)
    {
        int n;
        cin>>n;
        string str[100000];
        for (size_t i = 0; i < n; i++)
        {
            string s;
            cin>>s;
            
            if(!search(str,s,length))
            {
                str[length]=s;
                length++;
                int first=length-1;
                for (int j = length-1; j >= 0; j--)
                {
                    //cout<<j<<" ";
                    if(str[first]<str[j])
                    {
                        string temp=str[first];
                        str[first]=str[j];
                        str[j]=temp;
                        first=j;
                    }
                }
            }
        }

        for (size_t j = 0; j < length; j++)
            {
                if(str[j]!="")
                {
                    cout<<str[j]<<endl;
                }   
            }

        
    }
    
    return 0;
}