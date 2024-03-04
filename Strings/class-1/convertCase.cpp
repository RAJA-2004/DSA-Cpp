#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

void convert(char ch[]){
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]>='a' && ch[i]<='z'){
            ch[i]-=32;
        }else{
            ch[i]+=32;
        }
    }
    cout << ch << endl;
}
int main(){
    char ch[50];
    cin.getline(ch,50);
    convert(ch);
    return 0;
}