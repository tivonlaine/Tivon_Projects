/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 3
Description: Getting stock info
Input: Prices
Output: Stock changes
*/
#include "stocksPortfolio.h"
stocksPortfolio::stocksPortfolio() : invTypeObj() {
    priceOne=0;
    priceTwo=0;
    priceThree=0;
    stockValue=0;
}
stocksPortfolio::stocksPortfolio(double pOne, double pTwo, double pThree, investorType invTemp): invTypeObj(invTemp){
    priceOne=pOne;
    priceTwo=pTwo;
    priceThree=pThree;
}
void stocksPortfolio::setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp){
        priceOne=pOne;
        priceTwo=pTwo;
        priceThree=pThree;
        investorType invTypeObj =invTemp;
    }
void stocksPortfolio::printPriceChanges(ostream &output) const{
    output<<priceOne<<"  "
    <<priceTwo<<"   "<<priceThree<<endl;
}
void stocksPortfolio::calculateStockValue(investorType invTemp, ostream &output){
    double stockValue=invTemp.getStockPrice()*invTemp.getStockCount();
    string dashes;
    output<<endl;
    dashes.append(50, '_');
    double stockValue1=invTemp.getStockCount()*priceOne;
    double stockValue2=invTemp.getStockCount()*priceTwo;
    double stockValue3=invTemp.getStockCount()*priceThree;
    double s3=stockValue3-stockValue;
    if(!invTypeObj.checkInvestorID(invTemp.getID())||invTemp.getStockPrice()<0||invTemp.getStockCount()<0){
        stockValue1=0;
        stockValue2=0;
        stockValue3=0;
        s3=0;
        stockValue=0;
    }
    output<<"Stock Value with investor Price: "<<stockValue<<endl;
    output<<"Stock Value with a priceOne change: "<<stockValue1<<endl;
    output<<"Stock Value with a priceTwo change: "<<stockValue2<<endl;
    output<<"Stock Value with a priceThree change: "<<stockValue3<<endl;
    if(stockValue3>stockValue){
        output<<"Final stock value: "<<stockValue3<<endl;
        output<<"Profit on an investment: "<<s3<<endl;
    }else if(stockValue3<stockValue){
        output<<"Final stock value: "<<s3<<endl;
        output<<"Loss on an investment: "<<s3*-1<<endl;
    }else{
        output<<"Final stock value: 0.00"<<endl;
        output<<"profit on an investment: 0.00"<<endl;
    }
    string stars;
    stars.append(65, '*');
   
    output<<"price changes:  ";
    printPriceChanges(output);
    output<<endl;
    output<<stars<<endl;
}
void stocksPortfolio::writePriceChangesToFile(ostream &output) const{
  output<<priceOne<<setw(10)<<priceTwo<<setw(10)<<priceThree<<endl;
}
double stocksPortfolio::getInvestorPrice() const{
    return invTypeObj.getStockPrice();
}
double stocksPortfolio::getPriceOne() const{
    return priceOne; 
}
double stocksPortfolio::getPriceTwo() const{
    return priceTwo;
}
double stocksPortfolio::getPriceThree() const{
    return priceThree;
}
double stocksPortfolio::getStockValue() const{
    return stockValue;
}
