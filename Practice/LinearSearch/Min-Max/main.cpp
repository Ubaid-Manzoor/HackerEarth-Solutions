#include <iostream>
#include <vector>
#include <limits>

using namespace std;

pair<int,int> Min_Max(vector<int> array){
    int Min=numeric_limits<int>::max(),Max=0;

    int arraySum=0;
    for(int num:array){
        arraySum += num;
        if(num > Max){
            Max = num;
        }
        if(num < Min){
            Min = num;
        }
    }

    return make_pair(arraySum-Max, arraySum-Min);
}

int main()
{
    int N;
    cin>>N;

    vector<int> array(N);
    for(int i = 0 ; i < N ; i++){
        int number;
        cin>>number;
        array[i] = number;
    }

    pair<int,int> min_max = Min_Max(array);
    cout<<min_max.first<<" "<<min_max.second<<endl;
    return 0;
}
