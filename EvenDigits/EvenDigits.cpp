/*c++11*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<bits/stdc++.h> 
using namespace std;


bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 
  
// Function for finding difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n2-1; i>=0; i--) 
    { 
        // Do school mathematics, compute difference of 
        // current digits and carry 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of str1[] 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) // remove preceding 0's 
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 












int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t ; i++ )
    {
        string str;
        cin>>str;
        string strn1 = str;
        //cout<<strn<<endl;
        int flag=0;
        for (int j = 0; j < strn1.length(); ++j)
        {

            if((strn1[j]-48)%2 == 1 && flag == 0)
            {
                strn1[j]=strn1[j]-1;
                flag=1;
            }
            else if(flag == 1)
            {
                strn1[j]='8';
            }
            //cout<<(strn1[j]-48);
        } 
        int x = atoi(strn1.c_str());
        //cout<<"\n"<<x<<endl;

        string strn2 = str;
        flag=0;
        for (int j = 0; j < strn2.length(); ++j)
        {

            if((strn2[j]-48)%2 == 1 && flag == 0)
            {
                if(strn2[j]=='9')
                {
                    strn2[j]='0';
                    int k=j-1;
                    for(k=j-1;k>=0;k--)
                    {
                        if((strn2[k]-48) % 2 == 1 )
                        {
                            strn2[k]=strn2[k]+1;
                            break;
                        }
                        else if(strn2[k] == '8')
                        {
                            strn2[k]='0';
                        }
                        else
                        {
                            strn2[k]=strn2[k]+2;
                            break;
                        }
                        
                    }
                    if(k<0)
                    {
                        strn2.insert(0, "2");
                    }
                    flag=1;
                }
                else
                {
                strn2[j]=strn2[j]+1;
                flag=1;
                }
            }
            else if(flag == 1)
            {
                strn2[j]='0';
            }
            //cout<<(strn2[j]-48);
        } 
        int y = atoi(strn2.c_str());
        //cout<<"\n"<<y<<endl;
        if(str.length()<6)
        {

        int n = atoi(str.c_str());
        if((n-x)<(y-n))
        {
            cout<<"Case #"<<i+1<<": "<<(n-x)<<endl;
        }
        else
        {
            cout<<"Case #"<<i+1<<": "<<(y-n)<<endl;
        }
        }
        else
        {
            string strc1=findDiff(str,strn1);
            //cout<<strc1<<endl;
            string strc2=findDiff(strn2,str);
            //cout<<strc2<<endl;
            if(isSmaller(strc1,strc2))
            {
                cout<<"Case #"<<i+1<<": "<<strc1<<endl;
            }
            else
            {
                cout<<"Case #"<<i+1<<": "<<strc2<<endl;
            }
        }
        
        
    }
}