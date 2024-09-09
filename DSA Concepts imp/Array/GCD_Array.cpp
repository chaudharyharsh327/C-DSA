//gcd(greateest common divisble)
//its just like hcf and two no. ko minus krne par change nhi hota
//18-24=18 18 and 24 ka gcd = 24 and 42 ka gcd
//////////////////////////////////////////////////////////
// 42%24=18
// 24%18=6
// 18%6=0 soo 6 is GCD OR HCF   
#include<iostream>
using namespace std;
int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;

}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}