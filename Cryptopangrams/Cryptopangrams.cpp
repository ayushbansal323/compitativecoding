#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

long long int zpos;
long long int prime26[26];

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
int compare_function(const void *a,const void *b) {
long long int *x = (long long int *) a;
long long int *y = (long long int *) b;
return *x - *y;
}

long long int binarySearch(long long int arr[], long long int l, long long int r,long long int x) 
{ 
    if (r >= l) { 
        long long int mid = l + (r - l) / 2; 
  
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
    return -1; 
} 

void insertprime(long long int n)
{
	for (int i = 0; i < 26; ++i)
	{
		if(prime26[i] == 0)
		{
			prime26[i] = n;
			break;
		}
		else if(prime26[i] == n)
		{
			break;
		}
	}
}

long long int leftfind(long long int *pt,long long int *ct,long long int i,long long int z,long long int zprime)
{
	if(z == 1)
	{
		pt[0]=pt[1];
		pt[1] = ct[1]/pt[1];
	}
	else
	{
		for (long long int j = z; j >=i; --j)
		{
			pt[j-1] = ct[j]/pt[j];
			//cout<<pt[j-1]<<endl;
			insertprime(pt[j-1]);
		}
	}
	return 0;
}

long long int rightfind(long long int *pt,long long int *ct,long long int i,long long int z,long long int zprime)
{
	for (long long int j = i; j <z; ++j)
	{
		pt[j] = ct[j]/pt[j-1];
		//cout<<"we ewe :"<<pt[j]<<endl;
		insertprime(pt[j]);
	}
}

long long int checkPrime(long long int i,long long int *ct,long long int l)
{
    for(size_t j = 1; j <= l; j++)
    {
        if(ct[j]%i == 0)
        {
            prime26[0]=i;
            zpos=j;
            return 1;
        }
    }
    return 0;
}
bool isPrime(long long n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (long long int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
  
// Function to print primes 
void printPrime(long long int n,long long int *ct,long long int l) 
{ 
    for (long long int i = n; i >= 2; i--) { 
        if (isPrime(i))
        {
            
            //cout << i << " "; 
            if(checkPrime(i,ct,l) == 1)
            {
                break;
            } 
        }
    } 
} 

int main()
{
    int t;
    cin>>t;
    for(size_t z = 1; z <= t; z++)
    {
        long long int n=0;
        long long int l=0;
        cin>>n;
        cin>>l;
        long long int ct[l+1];
        long long int pt[l+2]={0};
        for(size_t i = 1; i <= l; i++)
        {
            cin>>ct[i];
        }
        
        printPrime(n,ct,l);
        //cout<<prime26[0]<<" "<<zpos<<endl;
        pt[zpos]=prime26[0];
        leftfind(pt,ct,1,zpos,prime26[0]);
        /*for (int i = 0; i < l+1; ++i)
        {
        	cout<<i<<" cipher :"<<pt[i]<<endl;
        }*/
        rightfind(pt,ct,zpos,l+1,prime26[0]);
        //cout<<ct[zpos]/pt[zpos]<<endl;
        /*for (int i = 0; i < l+1; ++i)
        {
        	cout<<i<<" cipher :"<<pt[i]<<endl;
        }*/
        /*for (int i = 0; i < 26; ++i)
        {
        	cout<<"cipher :"<<prime26[i]<<endl;
        }*/	
        qsort (prime26, sizeof(prime26)/sizeof(*prime26), sizeof(*prime26), compare_function);
        /*for (int i = 0; i < 26; ++i)
        {
        	cout<<"cipher :"<<prime26[i]<<endl;
        }*/
        cout<<"Case #"<<z<<": ";
	for (long long int i = 0; i < l+1; ++i)
        {
        	cout<<char(binarySearch(prime26,0,26,pt[i])+65);
        }
        cout<<endl;
        for (int i = 0; i < 26; ++i)
        {
        	prime26[i]=0;
        }
        zpos=0;
        //cout<<"cf[0] :"<<pt[0]<<endl;
    }
    
}
