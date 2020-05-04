#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

void printVector(vector<int> vec){
    for(const int v:vec){
        cout<<v<<" ";
    }
    cout<<endl;
}

void printUMap(unordered_map<int,int> toPrint){
    for(auto pair: toPrint){
        cout<<pair.first<<"->"<<pair.second<<endl;
    }
}

int RepeatedKTimes(vector<int> numbers, int K){
    unordered_map<int,int> counter;

    for(int num: numbers){
        if(counter.find(num) == counter.end()){
            counter[num] = 1;
        }else{
            counter[num] += 1;
        }
    }

    int smallest = numeric_limits<int>::max();
    for(pair<int,int> p:counter){
        int num = p.first;
        int count = p.second;

        if(count == K){
            if(num < smallest){
                smallest=num;
            }
        }
    }
    return smallest;
}


int main()
{

    int N;
    cin>>N;

    vector<int> numbers(N);

    for(int i = 0 ; i < N ; i++){
        int num;
        cin>>num;
        numbers[i] = num;
    }


    int K;
    cin>>K;

    cout<<RepeatedKTimes(numbers, K)<<endl;
    return 0;
}
