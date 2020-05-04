#include <iostream>
#include <vector>

using namespace std;


void printGrid(const vector<vector<char>> &grid){
    for(vector<char> row:grid){
        for(char c:row){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}

void printGrid(const vector<vector<int>> &grid){
    for(vector<int> row:grid){
        for(int c:row){
            cout<<c<<" ";
        }
        cout<<endl;
    }

}

void printVector(const vector<int> &vec){
    for(int v: vec){
        cout<<v<<" ";
    }
    cout<<endl;
}


int PolicemenAndThieves(vector<vector<int>> police, vector<vector<int>> thief, int K){
    /*
        TcolNo = Thief Column Number
        PcolNo = Police Column Number
    */

    int N = thief.size();

    int totalThifeCatch = 0;
    for(int row = 0 ; row < N; row++){
        vector<int> Theifrow = thief[row];
        vector<int> Policerow = police[row];

        for(int TcolNo=0,PcolNo=0 ;TcolNo < Theifrow.size() && PcolNo < Policerow.size() ;){
            if( abs( Theifrow[TcolNo] - Policerow[PcolNo] ) <= K ){
                cout<<Theifrow[TcolNo]<<"<-"<<Policerow[PcolNo]<<endl;
                totalThifeCatch++;
                TcolNo++;PcolNo++;
            }else if( Theifrow[TcolNo] < Policerow[PcolNo]){ // If police is in right of thief
                TcolNo++;
            }else{
                PcolNo++;
            }
        }
    }
    return totalThifeCatch;
}


int main()
{
    int testcases;
    cin>>testcases;
    for(int i = 0 ; i < testcases ; i++){
        int N,K;
        cin>>N>>K;


        vector<vector<char>> grid(N, vector<char>(N));
        vector<vector<int>> police(N),thief(N);
        for(int row = 0 ; row < N ; row++){
            for(int column = 0 ; column < N ; column++){
                char c;
                cin>>c;
                grid[row][column] = c;
                if(c == 'P'){
                    police[row].emplace_back(column);
                }else{
                    thief[row].emplace_back(column);
                }
            }
        }
        cout<<PolicemenAndThieves(police,thief,K)<<endl;
    }

    return 0;
}
