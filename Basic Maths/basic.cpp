#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

bool isPrime(int a){
    if(a<=1){
        return false;
    }
    for(int i=2;i<a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

// enhanced approach for sieve 
void prime4(int a){
    if(a==0){
        cout << "not prime";
    }
    vector<int>prime(a-1,true); 
    prime[0]=prime[1]=false;
    int count=0;
    for(int i=2;i<a;i++){
        if(isPrime(i)){
            count++;

            // int j = i*2; we will not mark the values which have already been marked
            int j = i*i; // this will ensure that it starts from value which is not marked
            while(j<a){
                prime[j]=false;
                j+=i;
            }
        }
    }
    cout << "number of prime b/w 0 to " << a << " are : " << count << endl;
}

// time complexity : o(n*log(log n))
// sieve of eratosthenes
void prime3(int a){
    if(a==0){
        cout << "not prime";
    }
    vector<int>prime(a-1,true); 
    prime[0]=prime[1]=false;
    int count=0;
    for(int i=2;i<a;i++){
        if(isPrime(i)){
            count++;

            int j = i*2;
            while(j<a){
                prime[j]=false;
                j+=i;
            }
        }
    }
    cout << "number of prime b/w 0 to " << a << " are : " << count << endl;
}

// time complexity : O(root n)
// square root approach
void prime2(int a){
    int flag = 0;
    int sq = sqrt(a);
    for(int i=2;i<=sq;i++){
        if(a%i==0){
            flag = 1;
            cout << "not prime" << endl;
            break;
        }
    }
    if(flag == 0){
        cout << "prime" << endl;
    }

}


// time complexity : o(n)
// nive approach
void prime1(int a){
    if(a==1){
        cout << "number is 1 , prime start from 2" << endl;
    }
    int flag = 0;
    for(int i=2;i<a;i++){
        if(a%i==0){
            flag = 1;
            cout << "not prime" << endl;
            break;
        }
    }
    if(flag==0){
        cout << "prime" << endl;
    }
}
int main(){
    int a = 10;
    prime1(a);
    prime2(a);
    prime3(a);
    prime4(a);
    return 0;
}