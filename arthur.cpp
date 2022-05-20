/*****Version 1.1***********/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	char* file_name = "input.txt";
	ifstream in;
	in.open(file_name);
	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;
	in.close();
	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;
	in.close();
	return 1;

}
bool isPrimeNumber(int n) {
bool result=true;
    if(n<2)
        result=false;
    else
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                result=false;
                break;
            }
        }
    }
    return result;


}
void display(float fOut)
//display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		cout << s;
	}
}


int main(void)
{
	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	readFile(baseHP1,baseHP2,wp1,wp2,ground);
	int realHP1,realHP2;
	//write your code here
		if(baseHP1==999 && baseHP2==888)
			{fOut=1;}
		else if(baseHP1==999)
			{fOut=1;}
		else if(baseHP2==888)
			{fOut=0.00;}
			
	if(isPrimeNumber(baseHP1)==true && isPrimeNumber(baseHP2)==true)
		{if(baseHP1==baseHP2)
				{fOut=0.50;}
			else if(baseHP1>baseHP2)
				{fOut=0.99;}
			else 
				{fOut=0.01;}
			}
		else if(isPrimeNumber(baseHP1)==true && baseHP2==888)
				{fOut=0.00;}
		else if(isPrimeNumber(baseHP1)==true)
				{fOut=0.99;}
			
		else if(isPrimeNumber(baseHP2)==true && baseHP1==999)
				{fOut=1;}
		else if(isPrimeNumber(baseHP2)==true)
				{fOut=0.01;}
		
	//----------------------------------------------------------------
	if(wp1==0)
		realHP1=baseHP1/10.0;	
	if(wp2==0)	
		realHP2=baseHP2/10.0;
	if(wp1==1)
		realHP1=baseHP1;
	if(wp2==1)
		realHP2=baseHP2;
	if(ground==baseHP1){
		if(wp1==0){
		realHP1=baseHP1/10.0;
		realHP1*=1.1;
		if(realHP1>999)
		realHP1=999;}
		else if(wp1==1){
		realHP1=baseHP1;
		realHP1*=1.1;
		if(realHP1>999)
		realHP1=999;}}
	if(ground==baseHP2){
		if(wp2==0){
		realHP2=baseHP2/10.0;
		realHP2*=1.1;
		if(realHP2>999)
		realHP2=999;}
		else if(wp2==1){
		realHP2=baseHP2;
		realHP2*=1.1;
		if(realHP2>999)
		realHP2=999;}}
	if(wp1==2){
		realHP1=baseHP1;
		if(ground==baseHP1)
		{realHP1*=1.1;
		if(realHP1>999)
		realHP1=999;}
		if(wp2==1)
		{realHP2=baseHP2;
		if(baseHP2==ground)
		realHP2*=1.1;
		if(realHP2>999)
		realHP2=999;}
		if(realHP1<realHP2)
		fOut=0.50;}
	if(wp2==2){
		realHP2=baseHP2;
		if(ground==baseHP2){
		realHP2*=1.1;
		if(realHP2>999)
		realHP2=999;}
		if(wp1==1)
		{realHP1=baseHP1;
		if(baseHP1==ground)
		realHP1*=1.1;
		if(realHP1>999)
		realHP1=999;}}
		if(realHP1>realHP2)
		fOut=0.50;
	if(wp1==3){
		realHP1=baseHP1;
		if(ground==baseHP1){
		realHP1*=1.1;}
		realHP1*=2;
		if(realHP1>999)
		realHP1=999;
		if(wp2==1)
		realHP2=baseHP2;
		if(ground==baseHP2)
		realHP2*=1.1;
		if(realHP2>999)
		realHP2=999;
		if(wp2==2){
		realHP2=baseHP2;
		if(ground==baseHP2)
		realHP2*=1.1;
		if(realHP2>999)
		realHP2=999;}}
	if(wp2==3){
		realHP2=baseHP2;
		if(ground==baseHP2)
		{realHP2*=1.1;}
		if(realHP2>999)
		realHP2=999;
		if(wp1==1)
		{realHP1=baseHP1;
		if(baseHP1==ground)
		realHP1*=1.1;
		if(realHP1>999)
		realHP1=999;}}
	fOut=float(realHP1-realHP2+999)/2000;

	display(fOut);
	

	return 0;
}
