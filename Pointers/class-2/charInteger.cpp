#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int main(){

    char arr[10] = "rajadigvi";
    int ar[10] = {1,2,3,4,5,6,7,8,9,10};

    char* ch = arr;
    int * a = ar;

    cout << ar << endl;
    cout << a << endl;
    cout << &ar << endl; 

    // special case
    char c = 'k';
    char* cc = &c;
    cout << c << endl;
    cout << cc << endl;
    cout << *cc << endl;

    // special declaration 
    char r[10] = "raja";
    char* f = "raja";
    cout << r << endl;
    cout << f << endl;

    char s[10] = "sherbano";
    char* p = &s[0];

    cout << s << endl;
    cout << p << endl;
    cout << &s << endl;
    cout << &p << endl;
    cout << *(s+3) << endl;
    cout << *(p+3) << endl;
    cout << s+3 << endl; // 3 index se end tak everything will be printed
    cout << p+3 << endl; // 3 index se end tak everything will be printed
    cout << p+6 << endl; // 6 index se end tak everything will be printed

    cout << "arr : " << arr << endl;
    cout << "ch  : " << ch << endl;
    cout << "&arr : " << &arr << endl;
    cout << "&ch : " << &ch << endl;
    cout << "*ch : " << *ch << endl;
    cout << "arr[0] : " << arr[0] << endl;

    // if int pointer hota tho address would have been printed
    // reason : implementation of cout is different for char and int
    cout << "char pointer display value : " << ch << endl;
    cout << "int pointer display address : " << a << endl;

    cout << arr << " " << endl;
    
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }

    return 0;
}