#include<iostream>
#include <math.h>
#include <limits>
#include <cstddef>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

double findmax(int t,double *r,double * h,double *mrad,double *mssa)
{
    double max=0;
    for (size_t i = 0; i <= t; i++)
    {
        // π × R02 + 2 × π * R0 × H0 
        double area=double((double)M_PI*(double)r[i]*(double)r[i])+(double)(2*(double)M_PI*(double)r[i]*(double)h[i]);
        if(area>max)
        {
            *mrad=r[i];
            *mssa=double(2*M_PI*(double)r[i]*(double)h[i]);
            max=area;
            
        }
    }
    
    //cout<<"max :"<<std::setprecision(9)<<max<<endl;
    return max;
}
double findmaxarea(int t,int k,double *r,double * h,int n,double *mrad,double *mssa)
{
    if(k==1)
    {
        return findmax(t,r,h,mrad,mssa);
    }
    if(t<=k)
    {
        *mssa=0;
        findmaxarea(t-1,k-1,r,h,n,mrad,mssa);
        *mssa=(*mssa)+(2*M_PI*r[t]*h[t]);
        if(*mrad>r[t])
        {

            return (M_PI*(*mrad)*(*mrad))+(*mssa);
        }
        else
        {
            return (M_PI*r[t]*r[t])+(*mssa);
        }
        
    }
    else
    {
        double ans1;
        *mssa=0;
        findmaxarea(t-1,k-1,r,h,n,mrad,mssa);
        *mssa=(*mssa)+(2*M_PI*r[t]*h[t]);
        if(*mrad>r[t])
        {

            ans1=(M_PI*(*mrad)*(*mrad))+(*mssa);
        }
        else
        {
            ans1=(M_PI*r[t]*r[t])+(*mssa);
        }
        *mssa=0;
        double ans2=findmaxarea(t-1,k,r,h,n,mrad,mssa);

        if(ans1>ans2)
        {
            return ans1;
        }
        else
        {
            return ans2;
        }
        
    }
    

}
int main()
{
    std::cout << std::fixed<<std::setprecision(9);
    int t;
    cin>>t;
    for (size_t z = 0; z < t; z++)
    {
        double *mrad=new double;
        double *mssa=new double;
        int n,k;
        cin>>n>>k;
        double r[n],h[n];
        for (size_t i = 0; i < n; i++)
        {
            cin>>r[i]>>h[i];
            //cout<<r[i]<<" "<<h[i]<<endl;
        }
        

        double ans=findmaxarea(n-1,k,r,h,n,mrad,mssa);

        cout<<"Case #"<<z+1<<": "<<ans<<endl;
    }
    
}