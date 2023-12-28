/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 2
Description: To define all functions used in implementation file
Input: User inputs mulitplicand, bits, multiplier
Output: Number in bits and binary
*/

#include "multiplication.h"
#include <fstream>
#include <cmath>
#include <iostream>

Multiplication::Multiplication()
{
    int multiplicand = 0;
    int multiplier = 0;
    int manMcand = 0;
    int manMplier = 0;
    int bits = 0;
    int result = 0;
}
void Multiplication::setMultiplicand(int mcand)
{
    multiplicand = mcand;
}
void Multiplication::setMultiplier(int mplier)
{
    multiplier = mplier;
}
int Multiplication::getMultiplicand() const
{
    return multiplicand;
}
int Multiplication::getMultiplier() const
{
    return multiplier;
}

Multiplication::Multiplication(int mc, int ml, int b)
{
    multiplicand = mc;
    multiplier = ml;
    bits = b;
    result = 0;
}

void Multiplication::writeOutputToFile(std::ofstream &outputFile) const
{
    if (outputFile)
    {
        performBoothAlgorithm(outputFile);
    }
    else
    {
        cout << "Problem occured" << endl;
    }
}

void Multiplication::performBoothAlgorithm(std::ostream &output) const
{
    int acc[10];
    int mulr[10];
    int mulc[10];
    int tempArray[10]={0};
    int lsb = 0;
    int n;
    tempArray[bits-1]=1;
    output << endl;
    output << "Multiplicand in decimal: " << multiplicand << endl;
    output << "Multiplicand in binary: ";
    if (multiplicand > 0)
    {
        output << "0";
    }
    printBinary(multiplicand, bits, output);
    output << endl;
    output << "\nMultiplier in decimal: " << multiplier << endl;
    output << "Multiplier in binary: ";
    if (multiplier > 0)
    {
        output << "0";
    }
    printBinary(multiplier, bits, output);
    output << endl;
    output<<"step\t\tqn\nq[n+1]\t\t\taction\t\t\t\tmultiplicandProduct";
    output << endl;
    output << "\t\t\t\tinitial\t\t\t";
    printBinary(multiplicand, bits, output);
    output << "\t\t0000 ";
    printBinary(multiplier, bits, output);
    output << endl;
    //  output<<endl;
    

    for (int i = 0; i < bits; i++)
    {
        acc[i] = mulr[i] = mulc[i] = tempArray[i] = {0};
    }
    decimalToBinary(multiplicand, mulc, bits);
    decimalToBinary(multiplier, mulr, bits);
		int bb = 0;
		lsb = mulr[bits-1];
	
    for (int i = 0; i < bits; i++)
    {
        output << i + 1 << '\t';

        if ((lsb == 1) && (bb == 1))
        {
            //lsb = mulr[bits - 1];
            output << "1\t1\t    a:11->no operation;shiftRight";
            arithShiftRight(acc, mulr, bb, bits, output);
						
        }
        else if ((lsb == 0) && (bb == 0))
        {
           
            output << "0\t0\t    a:00->no operation;shiftRight";
            arithShiftRight(acc, mulr, bb, bits, output);
        }
        else if ((lsb == 0) && (bb == 1))
        {
            for(int i = 0 ; i<bits ; i++){
                tempArray[i]=mulc[i];
            }
            add(acc, mulc, bits);
            output << "0\t1\t    a:01->prod=ls/prod+Mcand";
            printBinary(multiplicand, bits, output);

            output<< "\t\t\t\tb:shift right product";
            arithShiftRight(acc, mulr, bb, bits, output);
        }
        else if ((lsb == 1) && (bb == 0))
        {
            output << "1\t0\t\ta:10->prod=ls/prod-Mcand\t";
            printBinary(multiplicand, bits, output);
            output<<"\t";
            arithShiftRight(acc, mulr, bb, bits, output);
            output<<endl;
            output<<"\t\t\t\tb:shift right product";
            complement(mulc, bits);
            add(acc, mulc, bits);
            complement(mulc, bits);
			display(acc, mulr, bits, output);
            
					
            arithShiftRight(acc, mulr, bb, bits, output);
        }
			lsb = mulr[bits-1];
			output << "\t";
            printBinary(multiplicand, bits, output);
            output<<"\t\t";
			display(acc, mulr, bits, output);
			output << endl;
    
    }
}

void Multiplication::decimalToBinary(int num, int binary[], int length)
    const
{
    int zeros[10] = {0};
    //zeros[length - 1] = 1;

    int org = num;
    for (int i = length - 1; i >= 0; i--)
    {
        binary[i] = abs(num) % 2;
        num = abs(num) / 2;
    }

    if (org < 0)
    {
        complement(binary, length);
        add(binary, zeros, length);
    }
}

void Multiplication::printBinary(int num, int bits, std::ostream &output)
    const
{
    int bi[bits];
    decimalToBinary(num, bi, bits);
    for (int i = 0; i < bits; i++)
    {
        output << bi[i];
    }
}

void Multiplication::add(int accumulator[], int mcnadBinary[],
                         int mplierLength) const
{
    int total;
    int add = 0;
		for(int i = 0; i < mplierLength; i++)
			{
				//cout << accumulator[i];
			}
	//cout << endl << "mcnad: ";
			for(int i = 0; i < mplierLength; i++)
			{
				//cout << mcnadBinary[i];
			}
					
    for (int i = mplierLength - 1; i >= 0; i--)
    {
        total = (accumulator[i] + mcnadBinary[i] + add);
        add = total / 2;
        total = total % 2;
        accumulator[i] = total;
    }
		
}

void Multiplication::complement(int binary[], int n) const
{
    int one[10]{0};
	one[n-1]=1;
	
    for (int i = 0; i < n; i++)
    {
        if (binary[i] == 1)
        {
            binary[i] = 0;
        }
        else if (binary[i] == 0)
        {
            binary[i] = 1;
        }
    }

	add(binary, one, n);
}

void Multiplication::arithShiftRight(int accumulator[],
int mplierBinary[], int &mplierLSB,
 int mplierLength, std::ostream &output) const
{
    mplierLSB = mplierBinary[mplierLength-1];
    for (int i = mplierLength - 1; i > 0; i--)
    {
        mplierBinary[i] = mplierBinary[i - 1];
    }
    mplierBinary[0] = accumulator[mplierLength - 1];
    for (int i = mplierLength - 1; i > 0; i--)
    {
        accumulator[i] = accumulator[i - 1];
    }
    accumulator[0] = accumulator[1];
}

void Multiplication::display(int accumulator[], int mplierBinary[],
                        int mplierLength, std::ostream &output) const
{
    //output << "|";
        for (int i = 0; i < mplierLength; i++)
        {
            output << accumulator[i];
        }
	output << " ";
        for (int i = 0; i < mplierLength; i++)
        {
            output << mplierBinary[i];
        }
	//output << "|";
}

void Multiplication::performBoothAlgorithmUserInput()
{
    int b1;
    int b2;
    int d1;
    int d2;
    cout << "Number of mulitplicand bits=";
    cin >> b1;
    cout << "Enter the multiplicand in decimal=";
    cin >> d1;
    cout << "Multiplicand in binary:";

    cout << "Number of multiplier bits=" << endl;
    cout << "Enter the number in decimal=" << endl;
    cout << "Multiplier in binary:" << endl;
}

void Multiplication::binaryToDecimal(int accumulator[],
                                     int mplierBinary[],
                                     int mplierLength, std::ostream &output) const
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < mplierLength; i++)
    {
        x += accumulator[i] * pow(2, mplierLength - i);
    }
    for (int i = 0; i < mplierLength; i++)
    {
        y += mplierBinary[i] * pow(2, mplierLength - i);
    }
    output << x << "   " << y;
}