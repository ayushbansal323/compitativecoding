#include<iostream>
#include <iomanip>
#include <bits/stdc++.h> 
#include<cmath>
//sort decreasing order
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
using namespace std;
int compare_function(const void *a,const void *b) {
long long int *x = (long long int *) a;
long long int *y = (long long int *) b;
return *y - *x;
}


// Defining comp for max_element 
bool comp(long long int a, long long int b) 
{ 
    return (a < b); 
} 


struct BitParty
{
    long long int MaxBits,Scantime,Packtime;
};

long long int maxFind(BitParty *bp,long long int Cashers,int type)
{
    long long int max=0;
    for (size_t i = 0; i < Cashers; i++)
    {
         if(type==1)
         {
             if(max<bp[i].Scantime)
             {
                 max=bp[i].Scantime;
             }
         }
         if(type==2)
         {
             if(max<bp[i].Packtime)
             {
                 max=bp[i].Packtime;
             } 
         }
    }
    return max;
}

int check(long long int T,long long int Rob,long long int Bits,long long int Cashers,BitParty *bp)
{
    long long int Capacity[Cashers];

    for (size_t i = 0; i < Cashers; i++)
    {
        Capacity[i]=max(0,min(bp[i].MaxBits,floor(((T-bp[i].Packtime))/bp[i].Scantime)));
        //cout<<Capacity[i]<<"\t";
    }
    //qsort(<arrayname>,<size>,sizeof(<elementsize>),compare_function);
    qsort (Capacity, sizeof(Capacity)/sizeof(*Capacity), sizeof(*Capacity), compare_function);
    long long int bcount=0;
    long long int rcount=0;
    for (size_t i = 0; i < Cashers; i++)
    {
        bcount=bcount+Capacity[i];
        if(i==Rob-1 || bcount>=Bits)
        {
            if(bcount>=Bits)
            {
                //cout<<"\n"<<Bits<<"\t"<<Rob<<endl;
                return 1;
            }
            else
            {
                return 0; 
            }
            
        }
        //cout<<Capacity[i]<<"\t";
    }
    //cout<<"\n"<<Bits<<"\t"<<Rob<<endl;
    return 0;
}

long long int findt(long long int start,long long int stop,long long int Rob,long long int Bits,long long int Cashers,BitParty *bp)
{
        if (stop >= start) { 
        long long int mid = start + ((stop - start) / 2); 
  
        // If the element is present at the middle 
        // itself 
        if (check( mid, Rob, Bits, Cashers, bp) == false)
        { 
            if(check( mid+1, Rob, Bits, Cashers, bp) == true)
            {
                return mid+1;
            }
            return findt(mid+1,stop, Rob, Bits, Cashers, bp);
        } 
        // Else the element can only be present 
        // in right subarray
        
        return findt(start,mid-1, Rob, Bits, Cashers, bp); 
    } 
  
    // We reach here when element is not 
    // present in array
    /*if(check( stop+1, Rob, Bits, Cashers, bp) == true)
    {
                return stop+1;
    } */
    return stop; 
}


int main(int argc, char const *argv[])
{
    long long int t;
    cin>>t;
    for (size_t z = 0; z < t; z++)
    {
        long long int Rob,Bits,Cashers;
        cin>>Rob>>Bits>>Cashers;
        BitParty bp[Cashers];
        for (size_t i = 0; i < Cashers; i++)
        {
            cin>>bp[i].MaxBits>>bp[i].Scantime>>bp[i].Packtime;
            //cout<<bp[i].MaxBits<<bp[i].Scantime<<bp[i].Packtime<<endl;
        }
        //max(S) × B + max(P)
        long long int maxST=maxFind(bp,Cashers,1);
        long long int maxPT=maxFind(bp,Cashers,2);
        long long int maxT=(maxST*Bits)+maxPT;
        long long int ans=0;
        ans=findt(0,maxT, Rob, Bits, Cashers, bp);
        //cout<<check( 7, Rob, Bits, Cashers, bp);
        cout<<"Case #"<<z+1<<": "<<ans<<endl;
    }
    
    return 0;
}
