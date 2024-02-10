#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(log n)

vector<pair<int,string>>mp = {
    {1000000000,"Billion"},{1000000,"Million"},{1000,"Thousand"},{100,"Hundred"},
    {90,"Ninety"},{80,"Eighty"},{70,"Seventy"},{60,"Sixty"},{50,"Fifty"},{40,"Forty"},
    {30,"Thirty"},{20,"Twenty"},{19,"Nineteen"},{18,"Eighteen"},{17,"Seventeen"},{16,"Sixteen"},
    {15,"Fifteen"},{14,"Fourteen"},{13,"Thirteen"},{12,"Twelve"},{11,"Eleven"},{10,"Ten"},
    {9,"Nine"},{8,"Eight"},{7,"Seven"},{6,"Six"},{5,"Five"},{4,"Four"},{3,"Three"},{2,"Two"},{1,"One"}
};

string solve(int n){
    if(n==0){
        return "zero";
    }
    for(auto it : mp){
        if(n >= it.first){
            string a = "";
            if(n >= 100){
                // it will give starting number like how many times 200 so 2 times
                a = solve(n / it.first) + " ";
            }
            // it will assign the value like 200 so hundred
            string b = it.second;
            string c = "";
            if(n % it.first != 0){
                c = " " + solve(n % it.first);
            }
            return a + b + c;
        }
    }
    return "";
}

int main(){
    int n = 999999999;
    string st = solve(n);
    cout << st << endl;
    return 0;
}