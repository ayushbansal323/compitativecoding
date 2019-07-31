#include <iostream>
#include <string.h>
using namespace std;

struct charactor{
    int count;
    char c;
};
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    for (size_t z = 0; z < t; z++)
    {

        string p;
        cin>>p;
        charactor cp[26];
        for (size_t j = 0; j < p.length(); j++)
        {
            cp[j].c=p[j];
            cp[j].count=0;
        }
        
        string s;
        cin>>s;
        for (size_t i = 0; i < s.length(); i++)
        {
            for (size_t j = 0; j < 26; j++)
            {
                if(s[i]==cp[j].c)
                {
                    cp[j].count++;
                }
            }
        }
        for (size_t j = 0; j < 26; j++)
        {
            for (size_t i = 0; i < cp[j].count; i++)
            {
                cout<<cp[j].c;
            }
        }
        cout<<endl;
    }
    

    return 0;
}
