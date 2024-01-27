#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
int main(){
    string str;
    getline(cin,str);
    cout << "   .length()   : " << str.length() << endl;
    cout << "    .empty()   : " << str.empty() << endl;
    cout << ".push_back()   : ";
    str.push_back('@');
    cout << str << endl;
    cout << " .pop_back()   : ";
    str.pop_back();
    cout << str << endl;
    cout << "   .substr()   : " << str.substr(1,5) << endl;

    string a = "raja";
    string b = "singh";
    cout << "  .compare()   : " << a.compare(b) << endl;

    string c = "my name is raja";
    cout << "     .find()   : " << c.find("raja") << endl;

    cout << "  .replace()   : " << c.replace(2,3,"home") << endl;

    cout << "    .erase()   : " << c.erase(5,3) << endl;
    return 0;
}