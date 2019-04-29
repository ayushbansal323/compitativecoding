#include<iostream>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
/*void swapf(float *xp, float *yp) 
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}*/
int main()
{
    int t;
    cin>>t;
    for (size_t z = 0; z < t; z++)
    {
        int n;
        cin>>n;
        int s[n],e[n],l[n];
        //float r[n];
        for (size_t i = 0; i < n; i++)
        {
            cin>>s[i]>>e[i]>>l[i];
            //r[i]=float(s[i])/float(l[i]);
            //cout<<r[i]<<"\t";
        }
        //cout<<endl;
 

        bool swapped; 
        for (size_t i = 0; i < n-1; i++) 
        { 
            swapped = false; 
            for (size_t j = 0; j < n-i-1; j++) 
            { 
                if (l[j] < l[j+1]) 
                { 
                //swapf(&r[j], &r[j+1]); 
                swap(&s[j], &s[j+1]);
                swap(&e[j], &e[j+1]);
                swap(&l[j], &l[j+1]);
                swapped = true; 
                } 
            } 
        
            // IF no two elements were swapped by inner loop, then break 
            if (swapped == false) 
                break; 
        }
       
        /*for (size_t i = 0; i < n; i++)
        {
            cout<<s[i]<<" "<<e[i]<<" "<<l[i]<<"\n";
        }*/
        int times=0;
        int te=0;
        for (size_t i = 0; i < n; i++)
        {
            te=te-(times* l[i]);
            te=te+e[i];
            times=times+s[i];
            
        }
        
         cout<<"Case #"<<z+1<<": "<<te<<endl;
    }
    
    return 0;
}