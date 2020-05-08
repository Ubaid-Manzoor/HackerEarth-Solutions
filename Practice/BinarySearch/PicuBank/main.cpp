#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin>>testcases;

    for(int i = 0; i < testcases ; i++){
        long int initial_amount,A_Dollar,M_Month,B_Dollar,X_Dollar;
        cin>>initial_amount>>A_Dollar>>M_Month>>B_Dollar>>X_Dollar;
        X_Dollar -= initial_amount;

        long int total_month = ( X_Dollar / ( A_Dollar * M_Month + B_Dollar ) * (M_Month+1));

        X_Dollar = X_Dollar % ( (A_Dollar * M_Month) + B_Dollar );
        total_month += X_Dollar  / (A_Dollar);

        if((A_Dollar * (X_Dollar / A_Dollar)) != 0)
            X_Dollar = X_Dollar  % (A_Dollar * (X_Dollar / A_Dollar));
        total_month += X_Dollar  == 0 ? 0 : 1;
        cout<<total_month<<endl;
    }

    return 0;
}
