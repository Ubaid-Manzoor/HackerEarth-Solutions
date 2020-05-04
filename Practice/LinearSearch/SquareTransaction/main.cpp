#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> vec){
    for(const int v:vec){
        cout<<v<<" ";
    }
    cout<<endl;
}

int stop = 0;

int binarySearch(vector<int> &array, int start, int end, int valueToFind){
    if(end < start){ return -1;}
    int middle = (end - 1) / 2 + start;
//    cout<<middle<<endl;
    cout<<start<<"->"<<end<<endl;
//    stop += 1;
//    if(stop >= 5){
//        return 0;
//    }
    if(array[middle] == valueToFind){
        return middle;
    }else if(valueToFind > array[middle]){
        binarySearch(array, middle+1, end, valueToFind);
    }else{
        binarySearch(array, start, middle-1, valueToFind);
    }

    return -1;
}

void SquareTransaction(vector<int> trans, vector<int> Queries){
//    sort(Queries.begin(),Queries.end());


    vector<int> transSum(trans.size());
    int currentSum=0;
    for(int i = 0 ; i < trans.size() ; i++){
        currentSum += trans[i];
        transSum[i] = currentSum;
    }

    for(int query: Queries){

    }
    printVector(transSum);
}


int main()
{
    int nOfTrac;
    cin>>nOfTrac;

    vector<int> trans(nOfTrac);
    for(int i = 0 ; i < nOfTrac; ++i){
        int currentTrans;
        cin>> currentTrans;
        trans[i] = currentTrans;
    }

    int nOfQueries;
    cin>> nOfQueries;

    vector<int> Queries(nOfQueries);
    for(int i = 0 ; i < nOfQueries ; i++){
        int currentQuerie;
        cin>>currentQuerie;
        Queries[i] = currentQuerie;
    }
    sort(Queries.begin(),Queries.end());
    printVector(Queries);
    cout<<binarySearch(Queries,0,Queries.size() - 1,3)<<endl;
//    SquareTransaction(trans, Queries);
    return 0;
}
