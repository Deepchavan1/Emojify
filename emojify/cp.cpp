#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool flg = true;

bool solve(int arr[],int st, int en, bool flg){

    if(en == 1 || en == 0) return flg;
    
    if(en % 2 == 0){
        for(int i=0; i<(en/2); i++){
            for(int j=en-1; j>=(en/2); j++){
                if((arr[i]&arr[j]) != 0) swap(arr[i],arr[j]);
                else{
                    flg = false;
                    return flg;
                }
            }
        }
    }
    else{
        for(int i=0; i<=(en/2); i++){
            for(int j=(en-1); j>=(en/2); j++){
                if((arr[i]&arr[j]) != 0) swap(arr[i],arr[j]);
                else{
                    flg = false;
                    return flg;
                }
            }
        }
    }

    return solve(arr, 0, (en/2), flg);
    return solve(arr, (en/2), en, flg);
}

vector<int> minSwaps(int arr[], int n){
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    vector<int> v;
 
    int ans = 0;
    int extra = 0;
    bool flg = true;
    for (int i = 0; i < n; i++){
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            v.push_back(j);
            j = arrPos[j].second;
            cycle_size++;
            if(flg) extra++;
        }
 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
        if(flg){
            extra = v.size();
            flg = false;
        }
    }
    v.push_back(v[extra-1]);
 
    return v;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        // vector<int> pos = minSwaps(arr, n);
        // bool flg = true;
        // for(int i=0; i<(pos.size()); i++){
        //     cout<<pos[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<(pos.size()-1); i++){
        //     if(((arr[pos[i]]&arr[pos[i+1]]) == 0) && pos[i] != pos[i+1]){
        //         flg = false;
        //         break;
        //     }
        //     else swap(arr[pos[i]],arr[pos[i+1]]);
        // }
        // if(flg) cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;
        // for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        // cout<<endl;
        cout<<solve(arr,0,n,flg)<<endl;
    }
    
    return 0;
}