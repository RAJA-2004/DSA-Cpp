#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    char ch[100];
    ch[0]='r';
    ch[1]='a';
    ch[2]='\0';
    ch[3]='j';
    ch[4]='a';
    ch[5]='\0';
    str[0]='r';
    str[1]='a';
    str[2]='\0';
    str[3]='j';
    str[4]='a';
    str[5]='\0';

    cout << "char ch[] : " << ch << endl;
    cout << "string str : " << str << endl;
    return 0;
}