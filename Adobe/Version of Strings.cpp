#include <bits/stdc++.h>
using namespace std;

int main () {
    string a,b;
    cin >>a>>b;
    
    int n1 = a.length(), n2 = b.length();


    int i = 0, j = 0;
    while (i < n1 || j < n2) {
        int num1 = 0, num2 = 0;
        while (i < n1 && a[i] != '.'){
            num1 = num1*10 + a[i]-'0';
            i++;
        }    
        while (j < n2 && b[j] != '.'){
            num2 = num2*10 + b[j]-'0';
            j++;
        }    

        if (num1 > num2) {
            cout << a << "\n";
            break;
        }
        else if (num2 > num1) {
            cout << b << "\n";
            break;
        }
        i ++; j ++;
    }

    return 0;
}