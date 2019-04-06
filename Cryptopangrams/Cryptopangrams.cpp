#include<iostream>
using namespace std;

int zpos;
int prime26[26];


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
        for(size_t i = 1; i <= l; i++)
        {
            cin>>ct[i];
        }
        
        printPrime(n,ct,l);
        cout<<prime26[0]<<" "<<zpos<<endl;
    }
    
}