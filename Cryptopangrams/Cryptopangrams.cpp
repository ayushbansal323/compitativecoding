#include<iostream>
using namespace std;

int zpos;
int prime26[26];


void insertprime(int n)
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

int leftfind(int *pt,int *ct,int i,int z,int zprime)
{
	for (int j = z; j >=i; --j)
	{
		pt[j-1] = ct[j]/pt[j];
		//cout<<pt[j-1]<<endl;
		insertprime(pt[j-1]);
	}
	return 0;
}

int rightfind(int *pt,int *ct,int i,int z,int zprime)
{
	for (int j = i; j <z; ++j)
	{
		pt[j] = ct[j]/pt[j-1];
		//cout<<"we ewe :"<<pt[j]<<endl;
	}
}

int checkPrime(int i,int *ct,int l)
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
bool isPrime(int n) 
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
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
  
// Function to print primes 
void printPrime(int n,int *ct,int l) 
{ 
    for (int i = n; i >= 2; i--) { 
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
        int n=0;
        int l=0;
        cin>>n;
        cin>>l;
        int ct[l+1];
        int pt[l+2]={0};
        for(size_t i = 1; i <= l; i++)
        {
            cin>>ct[i];
        }
        
        printPrime(n,ct,l);
        cout<<prime26[0]<<" "<<zpos<<endl;
        pt[zpos]=prime26[0];
        leftfind(pt,ct,1,zpos,prime26[0]);
        rightfind(pt,ct,zpos,l+1,prime26[0]);
        //cout<<ct[zpos]/pt[zpos]<<endl;
        for (int i = 0; i < l+1; ++i)
        {
        	cout<<"cipher :"<<pt[i]<<endl;
        }

    }
    
}