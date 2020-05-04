#include <iostream>
#include <vector>
#include <limits>


/*
    This is not the best solution we have to use math to achieve best result.
*/

using namespace std;

int SpecialShop(int NofPots, int A, int B){
    int lowestPrice = numeric_limits<int>::max();
    int X = 0;
    int Y = NofPots;
    for(int i = 0 ; i <= NofPots ; i++){
        int price = (A * (X*X)) + (B * (Y*Y));
        if(price < lowestPrice){
            lowestPrice = price;
        }

        X++;Y--;
    }

    return lowestPrice;
}

int main()
{
    int NoOfCase;
    cin>>NoOfCase;

    for(int i = 0 ; i < NoOfCase ; i++){
        int N,A,B;
        cin>>N>>A>>B;
        cout<<SpecialShop(N, A, B)<<endl;
    }

    return 0;
}
