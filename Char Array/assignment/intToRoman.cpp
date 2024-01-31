#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

string roman(int num){
    string romanValues[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    string ans = "";
    for(int i=0;i<13;i++){
        while(num>=values[i]){
            ans+=romanValues[i];
            num-=values[i];
        }
    }
    return ans;
}
int main(){
    int s = 999;
    string r = roman(s);
    cout << r << endl;
    return 0;
}