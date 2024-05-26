#include <iostream>
#include <iomanip>

using namespace std;

int main(){     
    int a,b;
    double valor,conta;
    //scanf(("%i %i"),&a,&b);//
    cin >> a >> b;
    if (a == 1)
    {
        valor = 4.00;
    }
    else if(a == 2){
        valor =4.50;
    }
    else if(a == 3){
        valor =5.00;
    }
    else if(a == 4){
        valor =2.00;
    }
    else if(a == 5){
        valor =1.50;
    }
    
    conta= valor * b;
    //printf("Total: R$ %0.2f\n",conta);//
    cout << "Total: R$ " << fixed << setprecision(2) << conta << endl;
    
    return 0;
}
