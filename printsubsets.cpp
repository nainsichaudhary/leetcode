#include<iostream>
#include<vector>
using namespace std;
void printsubsets(vector<int>&arr,vector<int>&ans,int i){
    if(i>=arr.size()){
        for(auto it:ans){
            cout<<it<<" ";
        }
        if(ans.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    //include
    ans.push_back(arr[i]);
    printsubsets(arr,ans,i+1);
    //exclude
    ans.pop_back();
    printsubsets(arr,ans,i+1);
}
int main(){
    vector<int>arr={1,2,3};
    vector<int>ans;
    printsubsets(arr,ans,0);
    return 0;
}