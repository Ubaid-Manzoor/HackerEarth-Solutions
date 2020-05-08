#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printVector(const vector<int> &vec){
    for(const int v: vec){
        cout<<v<<" ";
    }
    cout<<endl;
}

/*
    Slower Version But It was a good idea
*/

int main()
{
    int testcases;
    cin>>testcases;

    for(int i = 0 ; i < testcases; i++){
        int N,K,Pth;
        unordered_set<int> toThrow;
        cin>>N>>K>>Pth;
        for(int j = 0 ; j < K; j++){
            int valueToThrow;
            cin>>valueToThrow;
            toThrow.insert(valueToThrow);
        }
        if(Pth > N-K){cout<<"-1"<<endl;}
        for(int i = 1,j=1; i <= N; i++){
            if(Pth == 0){
                cout<<i - 1<<endl;
                break;
            }
            if(toThrow.find(i) == toThrow.end()){
                Pth--;
            }
        }
    }

    return 0;
}

