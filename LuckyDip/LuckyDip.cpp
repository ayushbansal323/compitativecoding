#include<iostream>
#include <iomanip>
using namespace std;
//quicksort stdlib
//max
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
int compare_function(const void *a,const void *b) {
double *x = (double *) a;
double *y = (double *) b;
return *x - *y;
}

int binarySearch(double arr[], int l, int r, double x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return r; 
} 

int main()
{
    int t=0;
    cin>>t;

    for(size_t i = 0; i < t; i++)
    {
        int n =0 , k = 0 ;

        cin>>n>>k;

        double v[n];
        double e[k+1]={0};
        for(int j=0;j<n;j++)
        {
            cin>>v[j];
        }
        cout <<setprecision(6) << fixed;
        //qsort(<arrayname>,<size>,sizeof(<elementsize>),compare_function);
        qsort (v, sizeof(v)/sizeof(*v), sizeof(*v), compare_function);
        /*for(int j=0;j<n;j++)
        {
            cout<<v[j]<<endl;
        }*/
        //E[0] = Σ Vi / N
        for(size_t j = 0; j < n; j++)
        {
                e[0]=e[0]+(v[j]/n);
        }
       
        for(size_t j = 1; j <= k; j++)
        {
            /*for(size_t k = 0; k < n; k++)
            {
                //E[k] = Σ max(Vi, E[k-1]) / N
                e[j]=e[j]+((max(v[k],e[j-1]))/n);
            }*/
            
            int index = binarySearch(v, 0, n-1 , e[j-1]);
            
            // E[k] = xk * E[k - 1] / N + Σi>xk Vi / N
            e[j]=((index)*e[j-1])/n;
            //cout<<"v["<<index<<"]"<<v[index]<<"e["<<j-1<<"]"<<e[j-1]<<endl;
            for(size_t k = index; k < n; k++)
            {
                // E[k] = xk * E[k - 1] / N + Σi>xk Vi / N
                e[j]=e[j]+((max(v[k],e[j-1]))/n);
            }    
        }   
        
        cout<<"Case #"<<i+1<<": "<<e[k]<<endl;
    }
    
    return 0;
}