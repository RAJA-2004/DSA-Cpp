#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;
int main(){
    char ch[20];
    char arr[20];
    // cin >> arr; // do not read after space 
    cin.getline(ch,50);
    cout << ch << endl;
    int count = 0;
    for(int i=0;ch[i]!='\0';i++){
        count++;
    }
    cout << count << endl;
    cout << "strlen : " << strlen(ch) << endl;
    return 0;
}