#include "multiplication.h"
#include <fstream>
#include <cmath>
    Multiplication::Multiplication(){
        int multiplicand=0;
        int multiplier=0;
        int manMcand=0;
        int manMplier=0;
        int bits=0;
        int result=0;
    }
    void Multiplication::setMultiplicand(int mcand) {
        multiplicand=mcand;
    }
    void Multiplication::setMultiplier(int mplier) {
        multiplier=mplier;
    }
    int Multiplication::getMultiplicand() const {
        return multiplicand;
    }
    int Multiplication::getMultiplier() const {
        return multiplier;
    }
   
    Multiplication::Multiplication(int mc, int ml, int b){
        multiplicand=mc;
        multiplier=ml;
        bits=b;
        result=0;
    }

    
    //void Multiplication::writeOutputToFile(std::ostream &outputFile) const{}

    
    //void performBoothAlgorithm(std::ostream &output) const;

    
    void Multiplication::decimalToBinary(int num, int binary[], int length) const{
        for(int i=length-1;i>0;i--){
            binary[i]=num%2;
            num=num/2;
        }
    }

    void Multiplication::printBinary(int num, int bits, std::ostream &output) const{//COME BACK
        int bi[bits];                                                               //COME BACK
        decimalToBinary(num,bi,bits);                                               //COME BACK
        for(int i =0;i<bits;i++){                                                   //COME BACK
            output<<bi[i];                                                          //COME BACK
        }
    }

    
    void Multiplication::add(int accumulator[], int mcnadBinary[], int mplierLength) const{
        int total;
        int add=0;
        for(int i=mplierLength-1;i>0;i--){
            total=accumulator[i]+mcnadBinary[i]+add;
            add=total/2;
            total=total%2;
            accumulator[i]=total;
        }
    }

   void Multiplication::complement(int binary[], int n) const{    
        bool s;
        for(int i=0;i<n;i++){
            if(binary[i]=1){
                binary[i]=0;
            }else if(binary[i]=0){
            binary[i]=1;
        }
        }
     }

    
void Multiplication::arithShiftRight(int accumulator[],int mplierBinary[],
        int &mplierLSB, int mplierLength, std::ostream &output) const{
            for(int i=mplierLength-1;i>0;i--){
                mplierBinary[i]=mplierBinary[i-1];
            }mplierBinary[0]=accumulator[mplierLength-1];
            for(int i=mplierLength-1;i>0;i--){
                accumulator[i]=mplierBinary[i-1];
                }     accumulator[0]=accumulator[0]; }

    
void Multiplication::display(int accumulator[], int mplierBinary[], 
int mplierLength, std::ostream &output) const{
      if(output){
        for(int i=0;i<mplierLength;i++){
            output<<accumulator[i];
        }
        for(int i=0;i<mplierLength;i++){
            output<<mplierBinary[i];
        }
      }

   }

   
   // void performBoothAlgorithmUserInput();

    
void Mulitplication::binaryToDecimal(int accumulator[], int mplierBinary[], 
        int mplierLength, std::ostream &output) const{
            int x;
            int y;
            for(int i=0;i<mplierLength;i++){
                x+=accumul
            }
        }