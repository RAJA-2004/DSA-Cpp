#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

void usingPTR(char ch[]){
    int i = 0;
    int n = strlen(ch);
    int j = n-1;
    cout << ch << endl;
    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
    cout << ch << endl;
}

void rep(char ch[]){
    for(int i=0;ch[i]!='\0';i++){
        if(ch[i] == ' '){
            ch[i]='@';
        }
    }
    cout << ch << endl;
}
int main(){
    char ch[50] = "raja digvijay ";
    rep(ch);
    return 0;
}