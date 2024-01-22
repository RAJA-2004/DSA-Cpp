// Quotient * Divisor + Rem = Dividend
// Quotient * Divisor <= Dividend

#include <iostream>
#include <vector>
using namespace std;
int divide(int dividend,int divisor){
    int ans = -1;
    int start = 0;
    int end = abs(dividend);
    int mid = start + (end-start)/2;
    while(start <= end){
        if(abs(mid*divisor) == abs(dividend)){
            ans = mid;
            break;
        }
        else if(abs(mid*divisor) < abs(dividend)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    if((dividend>=0 && divisor>=0) || (dividend<0 && divisor<0)){
        return ans;
    }else{
        return -ans;
    }
}
int main(){
    int divisor,dividend;
    cin >> dividend;
    cin >> divisor;
    int res = divide(dividend,divisor);
    cout << res << endl;

    // Decimal places
    int precision;
    cout << "enter precision : ";
    cin >> precision;
    double step = 0.1;
    double ans = res;
    for(int i=0;i<precision;i++){
        for(double j=ans;j*divisor<=dividend;j=j+step){
            ans = j;
        }
        step = step/10;
    }
    cout << ans << endl;
    return 0;
}