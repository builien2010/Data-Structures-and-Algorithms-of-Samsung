#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool check(char x, char y){
    if( x == '(' && y == ')')
        return true;
    if( x == '[' && y == ']')
        return true;
    if( x == '{' && y == '}')
        return true;

    return false;
}

int parenthese(string a){
    stack<char> S;

    for (int i = 0; i < a.length(); i++){
        if(a[i] == '(' || a[i] == '[' || a[i] == '{')
            S.push(a[i]);
        else{
            if( S.empty())
                return 0;
            else{
                char c = S.top();
                S.pop();

                if(check(c, a[i]) == false)
                    return 0;

            }
        }

    }
    return S.empty();
}
int main(){

    int n;
    cin >> n;

    string a[1000];


    for ( int i = 0; i < n; i++){
        cin >> a[i];
    }

    for ( int i = 0; i < n; i++){
        if(parenthese(a[i]) == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
