#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

void palindrome(char ch[]){
    char cha[50];
    for(int i=0;i<strlen(ch);i++){
        cha[i]=ch[i];
    }
    int i=0,j=strlen(ch)-1;
    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
    int flag = 0;
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]!=cha[i]){
            flag =1;
            break;
        }
    }
    if (flag==0) cout << "palindrome";
    else cout << "not palindrome";
}
 
bool usingTwoPtr(char ch[]){
    int i=0;
    int j=strlen(ch)-1;
    while (i<=j)
    {
        if(ch[i]!=ch[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}
int main(){
    char ch[50];
    cin.getline(ch,50);
    // palindrome(ch);
    cout << usingTwoPtr(ch);
    return 0;
}