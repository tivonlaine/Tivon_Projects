#include <iostream>

using namespace std;

void decimalToBinary(int num, int binary[], int length)
 {
        int zeros[10] = {0};
        zeros[length-1] = 1;

       int org=num;
        for(int i=length-1;i>=0;i--){
            binary[i]=abs(num)%2;
            num=abs(num)/2;
        }

    //     if(org){
    //         complement(binary,length);
    //         add(binary, zeros, length);
    //     }
    // }
 }


int main(){
    
    int num = 2; 
    int binary[4];

    decimalToBinary(num, binary, 4);

    for(int i = 0; i < 4; i++){
        cout<<
    }


    return 0;
}