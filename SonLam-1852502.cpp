#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;
// TODO

const int MADBEAR = 1;
const int BANDIT = 2;
const int LORDLUPIN = 3;
const int ELF = 4;
const int TROLL = 5;
const int SHARMAN = 6;
const int VAJSH = 7;
const int Excalibur = 8;
const int Mythril = 9;
const int Excalipoor = 10;
const int MushMario = 11;
const int MushFib = 12;
const int MushGosht = 13;
const int MushKnight = 14;
const int Remedy = 15;
const int Maidenkiss = 16;
const int Phoenixdown = 17;
const int WIZARD = 18;
const int FallAbyss = 19;
const int Guinevere = 20;
const int Lightwing = 21;
const int ODIN = 22;
const int DragonSword = 23;
const int Bowser = 99;

const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

struct knight
{
   int HP;
   int level;
   int remedy;
   int maidenkiss;
   int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0
int readFile(const char* filename, knight& theKnight, int& nEvent, int* arrEvent)
{
	const char* file_name = filename;
	FILE* f = 0;
	char* str = new char[MAX_CHARACTER_EACH_LINE];
	int num;

	f = fopen(file_name, "r");
	if (f == NULL)	//file not found || cannot read
		return 0;

	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	if (feof(f))
		return 0;

	int start = 0;
	int len = strlen(str);
	// read HP
	while (start < len && str[start] == ' ')
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.HP = num;
	if (theKnight.HP < 1 || theKnight.HP > 999)
		return 0;

	// read level
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.level = num;
	if (theKnight.level < 1 || theKnight.level > 10)
		return 0;

	// read remedy
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.remedy = num;
	if (theKnight.remedy < 0 || theKnight.remedy > 99)
		return 0;

	// read maidenkiss
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.maidenkiss = num;
	if (theKnight.maidenkiss < 0 || theKnight.maidenkiss > 99)
		return 0;

	// read phoenixdown
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.phoenixdown = num;
	if (theKnight.phoenixdown < 0 || theKnight.phoenixdown > 99)
		return 0;

	// read events
	nEvent = 0;
	while (1){
		if (feof(f))
			break;
		fgets(str, MAX_CHARACTER_EACH_LINE, f);
		if (str == NULL)
			break;
		start = 0;
		len = strlen(str);
    // cout << "\'" << str << "\'" << "\t" << len << endl;
		while (start < len){
			while (start < len && (str[start] > '9' || str[start] < '0'))
				start++;
			if (start >= len)
				break;
			arrEvent[nEvent] = 0;
			while (start < len && str[start] <= '9' && str[start] >= '0'){
				arrEvent[nEvent] = arrEvent[nEvent] * 10 + str[start] - '0';
				start++;
			}
			nEvent++;
		}
    delete[] str;
	}
	fclose(f);
	return 1;
}

void display(int* nOut)
{
  if (nOut)
    cout << *nOut;
  else
    cout << "Error!";
}

// TODO

int fibonacci(int n)
{
      int t1=0, t2=1, t;
	t = t1 + t2;
	while (t <= n)
	{
        t1=t2;
        t2 = t;
        t = t1+t2;
	}
    return t;
}


bool isprimenum(int n) {
bool result = true;
    if(n < 2)
        result = false;
    else
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n%i == 0)
            {
                result = false;
                break;
            }
        }
    }
    return result;
}

bool checkDragonKnight(int m)
{	
    bool result = false;
    int x,y,z;
    for ( x=1; x<(m-1); x++)
        for ( y=1; y< (m-x); y++){
        z=m -x -y;
        if (x*x+y*y == z*z)
		{
        result = true;
        goto thus;}
    }
    thus:
  if (result == true){
    return true;
  }
  else
  	return false;
    
if (m==888) return false;
}

int main(int argc, char** argv)
{
    if (argc < 2) return 1;
    const char* filename = argv[1];;

   struct knight theKnight;
   int nEvent; //number of events
   int* arrEvent = new int[EVENT_SIZE]; // array of events
   int* nOut;                           // final result
   int i;

	readFile(filename, theKnight, nEvent, arrEvent);
	
	// TODO

int maxHP = theKnight.HP;
	int maxlevel=theKnight.level;
	int *realHP;
   int *reallevel;
   int *realremedy;
   int *realmaidenkiss;
   int *realphoenixdown;
   int b,levelO;
   int  N, damage;
   float baseDamage;
   realHP = &theKnight.HP;
   reallevel = &theKnight.level;
   realremedy = &theKnight.remedy;
   realmaidenkiss = &theKnight.maidenkiss;
   realphoenixdown = &theKnight.phoenixdown;
	int extiny = -1;
	int exfrog = -1;

	int countmeet=300 ;
	bool hasExcalibur = false;
	bool hasMythril = false;
	bool hasExcalipoor = false;
	bool withOdin = false;
	bool Arthur =false;
	bool Lancelot=false;
	bool had_met = false;
	bool Lancelotability = false;
	bool Paladin = false;
	bool Dragonknight = false;
    bool meetPrincess = false;
    int arrGuinever[200];
    
    
    nOut=&N;
    
    
	if (theKnight.HP == 999) Arthur = true;
	if (theKnight.HP == 888) Lancelot = true;
	if (isprimenum(theKnight.HP) == true) Paladin = true;
		

	for (i = 0; i < nEvent; i++)
{
		int theEvent = arrEvent[i];
		
		
		if(meetPrincess== true)
		{
			theEvent=arrGuinever[i];	
		}	
		
		if (Lancelot == true)	
			{
            if (*reallevel % 2 == 0)
                Lancelotability = false;
            else
                Lancelotability = true;
			}

		
          

		// 0
		if ( theEvent == 0 ) {
            N = *realHP + *reallevel + *realremedy + *realmaidenkiss + *realphoenixdown  ;
            break;
		}
		// 1-99
			switch(theEvent)
	{
			
			case 1:
				baseDamage=1;
				b = (i+1)%10;
				levelO = (i+1)>6?( b>5? b:5 ):b;
					if (( *reallevel > levelO && hasExcalipoor == false)|| hasExcalibur == true || withOdin == true ||Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true )
					{
                	theKnight.level =(theKnight.level+1 >10)? 10 :(theKnight.level+1);
               		 continue;
            		}
            	
            		if (hasMythril == true)
					{
                    continue;
                	}
            		else if ( *reallevel < levelO || hasExcalipoor==true)
					{
					damage=baseDamage*levelO*10;
                    theKnight.HP =theKnight.HP-damage;
					}
				break;
			case 2:
				baseDamage=1.5;
				b = (i+1)%10;
				levelO = (i+1)>6?( b>5? b:5 ):b;
					if (( *reallevel > levelO && hasExcalipoor == false )|| hasExcalibur == true || withOdin == true ||Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true)
					{
                	theKnight.level =(theKnight.level+1 >10)? 10 :(theKnight.level+1);
               		 continue;
            		}
            	
            		if (hasMythril == true)
					{
                    continue;
                	}
            		else if ( *reallevel < levelO || hasExcalipoor==true)
					{
					damage=baseDamage*levelO*10;
                    theKnight.HP =theKnight.HP-damage;
					}
				break;
			
			case 3:
				baseDamage=4.5;
				b = (i+1)%10;
				levelO = (i+1)>6?( b>5? b:5 ):b;
					if (( *reallevel > levelO && hasExcalipoor == false )|| hasExcalibur == true || withOdin == true ||Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true )
					{
                	theKnight.level =(theKnight.level+1 >10)? 10 :(theKnight.level+1);
               		 continue;
            		}
            	
            		if (hasMythril == true)
					{
                    continue;
                	}
            		else if ( *reallevel < levelO || hasExcalipoor==true )
					{
					damage=baseDamage*levelO*10;
                    theKnight.HP =theKnight.HP-damage;
					}
				break;
				
            case 4:	
            	baseDamage=6.5;
				b = (i+1)%10;
				levelO = (i+1)>6?( b>5? b:5 ):b;
					if (( *reallevel > levelO && hasExcalipoor == false )|| hasExcalibur == true || withOdin == true ||Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true)
					{
                	theKnight.level =(theKnight.level+1 >10)? 10 :(theKnight.level+1);
               		 continue;
            		}
            	
            		if (hasMythril == true)
					{
                    continue;
                	}
            		else if ( *reallevel < levelO || hasExcalipoor==true )
					{
					damage=baseDamage*levelO*10;
                    theKnight.HP =theKnight.HP-damage;
					}
				break;
			case 5:
				baseDamage=8.5;
				b = (i+1)%10;
				levelO = (i+1)>6?( b>5? b:5 ):b;
					if (( *reallevel > levelO && hasExcalipoor == false )|| hasExcalibur == true || withOdin == true || Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true )
					{
                	theKnight.level =(theKnight.level+1 >10)? 10 :(theKnight.level+1);
               		 continue;
            		}
            	
            		if (hasMythril == true)
					{
                    continue;
                	}
            		else if ( *reallevel < levelO || hasExcalipoor==true)
					{
					damage=baseDamage*levelO*10;
                    theKnight.HP =theKnight.HP-damage;
					}
				break;
				
			case 6:	
				if (exfrog != -1) break;  
           		b = (i+1)%10;
				levelO = (i+1)>6?( b>5? b:5 ):b;
            
            	if ((*reallevel > levelO && hasExcalipoor == false) || Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true || withOdin == true)
				{
                theKnight.level =(theKnight.level+2 >10)? 10 :(theKnight.level+2);
                break;
            	}

            	if ( *reallevel < levelO || hasExcalipoor==true) 
				{
                	if (hasMythril == true) break;
                	if (*realHP < 5) theKnight.HP = 1;
                	else
                    theKnight.HP /= 5;
                	extiny = i+3;
                	if (*realremedy >= 1)
					{
                    	extiny = -1;
                    	theKnight.HP *= 5;
                    	theKnight.remedy--;
                	}
            	}
            	break;
            
            case 7:
            	if (extiny != -1) break;
		    	b = (i+1)%10;
				levelO = (i+1)>6?( b>5? b :5 ):b;

            	if ( (*reallevel > levelO && hasExcalipoor == false) || Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true|| withOdin == true )
				{
                theKnight.level =(theKnight.level+2 >10)? 10 :(theKnight.level+2);
                break;
            	}

            	if ( *reallevel < levelO || hasExcalipoor==true)
				 {
                    theKnight.level = 1;
                    exfrog = i+3;
                	if (*realmaidenkiss >= 1)
					{
                    exfrog = -1;
                    theKnight.level = maxlevel;
                    theKnight.maidenkiss--;
                	}
            		
				}
				break;
				
			case 8:
				if (Dragonknight == true) break;
		    	hasExcalipoor = false;
				hasExcalibur = true;
		    	break;
		    	
		    case 9:
				hasMythril = true;
            	break;	
            	
            case 10:
            	if (*reallevel>=5 || withOdin == true || Arthur == true || Lancelotability == true || Paladin == true || Dragonknight == true || checkDragonKnight (theKnight.HP) == true) break;
            	hasExcalibur = false;
            	hasExcalipoor = true;
                break;
            case 11:
            	theKnight.HP = (theKnight.HP+50 >maxHP)? maxHP :(theKnight.HP+50);
                break;
            case 12:
            	theKnight.HP=(fibonacci(theKnight.HP) >maxHP)? maxHP :(fibonacci(theKnight.HP));
            	break;
            case 13:
            	if (hasMythril == true || Paladin == true ||  withOdin == true|| Dragonknight == true ) break;
            	if(theKnight.HP <51) theKnight.HP=1;
            	theKnight.HP-=50;
                break;
            case 14:
            	maxHP=(maxHP+50 > 999)? 999 :(maxHP+50);
            	theKnight.HP=maxHP;
            	break;
            case 15:
            	theKnight.remedy=(theKnight.remedy+1 >99)? 99 :(theKnight.remedy+1);
            	if(extiny!=-1)
            	{
					extiny = -1;
                    theKnight.HP *= 5;
                    theKnight.remedy--;
                }
            	break;
            case 16:
            	theKnight.maidenkiss=(theKnight.maidenkiss+1 >99)? 99 :(theKnight.maidenkiss+1);
            	if(exfrog!=-1)
            	{
            		exfrog=-1;
            		theKnight.level=maxlevel;
            		theKnight.maidenkiss--;
				}
            	break;
            case 17:
            	theKnight.phoenixdown=(theKnight.phoenixdown+1 >99)? 99 :(theKnight.phoenixdown+1);
            	break;
            case 18:
            	if(extiny!= -1 || exfrog!= -1)
            	{
            		extiny=-1;
            		exfrog=-1;
				}
				theKnight.level=(theKnight.level+1 >10)? 10 :(theKnight.level+1);
				theKnight.HP=maxHP;
				break;
			case 19:
				if (*reallevel >= 7 || withOdin == true) break;
            	else 
                N =-1;
                display(nOut);
                return 0;
            
            case 20:
             {
            meetPrincess=true;
            int j=0;
            while(i-j>=0)
            {
            	arrGuinever[i+j]=arrEvent[i-j];
            	j++;
			}
			nEvent=i+j;
			break;
		}
		
			case 21:
				if((nEvent-1-i)<3 || arrEvent[i+1]==0 || arrEvent[i+2]==00 || arrEvent[i+3]==0 || arrEvent[i+1]==20 || arrEvent[i+2]==20 || arrEvent[i+3]==20 )
				{
					N = *realHP + *reallevel + *realremedy + *realmaidenkiss + *realphoenixdown ;
					display(nOut);
					return 0;
				}
				if (extiny != -1) extiny =extiny+3;
				if (exfrog != -1) exfrog =exfrog+ 3;
            	i=i+3;
            	break;
            case 22:
            	if (had_met == true) break;
                withOdin = true;
                had_met = true;
                countmeet = i+3;
                break;
            case 23:
            	if (checkDragonKnight(theKnight.HP) == true)
				{
                Dragonknight = true;
            	}
            	else break;
            case 99:
            	if (Arthur == true || Lancelot == true || (Paladin == true && *reallevel >=8) || (*reallevel == 10 && hasExcalipoor == false) || Dragonknight == true)
				{
                theKnight.level =10;
            	}
            	else 
            	{
            	N=-1;
            	display(nOut);
            	return 0;
                }
               break;

}            	
            if(i==extiny)
            {
            	theKnight.HP=(theKnight.HP*5 >maxHP)? maxHP :(theKnight.HP*5);
            	extiny=-1;
			}
			if(i==exfrog)
			{
				theKnight.level=maxlevel;
				exfrog=-1;
			}
			if(i>=countmeet)
			{
				withOdin=false;
			}
		
		
			
		if ( *realHP <= 0)
		{
			if ( *realphoenixdown == 0 )
			{
			N=-1;
			display(nOut);
			return 0;
			}
			if ( *realphoenixdown >= 1 )
			{
			theKnight.HP = maxHP;
			theKnight.phoenixdown--;
			}
		}


}
		N = *realHP + *reallevel + *realremedy + *realmaidenkiss + *realphoenixdown ;
	
    display(nOut);
	return 0;
}

