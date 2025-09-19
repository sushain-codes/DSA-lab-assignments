#include<iostream>
#include<string>
using namespace std;
void reverseString(string &s){
    int st = 0;
    int end = s.length() - 1;
    while(st<end){
        swap(s[st], s[end]);
        st++;
        end--;
    }
}
int main(){
    string s;
    cout<<"enter string: "<<endl;
    getline(cin, s);
    reverseString(s);
    cout << "Reversed string: " << s << endl;

    return 0;
}
