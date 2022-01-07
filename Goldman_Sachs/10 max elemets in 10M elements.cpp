#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=10, n = 10000000;
    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<k;i++)    pq.push(v[i]);

    for(int i=k;i<n;i++){
        if(v[i]> pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    }

    while(!pq.empty()){
        cout<<pq.top();
        pq.pop()
    }
    return 0;
}