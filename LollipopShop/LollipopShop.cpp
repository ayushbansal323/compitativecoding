#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (size_t z = 0; z < t; z++)
    {
        int n;
        cin>>n;
        if(n==-1)
        {
            return -1;
        }
        float flavorl[n],countl[n];
        float probl[n];
        for (size_t i = 0; i < n; i++)
        {
            flavorl[i]=1;
            probl[i]=0;
            countl[i]=0;
        }
        
        for (size_t i = 0; i < n; i++)
        {
            int d;
            cin>>d;
            if(d==-1)
            {
                return -2;
            }
            int like[d];
            float min=1000000;
            int minf=-1;
            for (int j = 0; j < d; j++)
            {
                
                cin>>like[j];
                if(like[j]==-1)
                {
                return -3;
                }
                //cout<<" before:"<<countl[like[j]];

                countl[like[j]]++;
                probl[like[j]]=(countl[like[j]]/(i+1));
               //cout<<"\t"<<like[j]<<" count :"<<countl[like[j]]<<" "<<probl[like[j]]<<"\t";
                if(probl[like[j]]<min && flavorl[like[j]]!=0)
                {
                    min=probl[like[j]];
                    minf=like[j];
                }
                
            }
            if(minf==-1)
            {
                cout<<"-1"<<endl;
                continue; 
            }
            else
            {
                flavorl[minf]=0;
                cout<<minf<<endl;    
            }
            //cout<<endl;
            

        }
        
    }
    
    return 0;
}