#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>
								// Le Duc Cam-1952588
using namespace std;

const int MADBEAR = 1;
const int BANDIT = 2;
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
	const char* file_name = "input.txt";
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


int calLevelO(int i){
	int levelO;
	int b=i%10;
	if (i>6){
		if(b>5){
			levelO=b;
		}
		else{
			levelO=5;
		}
	}
	else{
		levelO=b;
	}
return levelO;
}

int calDamage(int theEvent,int levelO){
	int damage;
	switch(theEvent){
		case 1:{
			damage= (1*levelO*10);
			break;
		}
		case 2:{
			damage= (1.5*levelO*10);
			break;
		}
		case 3:{
			damage= (4.5*levelO*10);
			break;
		}
		case 4:{
			damage= (6.5*levelO*10);
			break;
		}
		case 5:{
			damage= (8.5*levelO*10);
			break;
		}
	}
return damage;
}

int case12(int n){   // fibonacy
	int fb1=0,fb2=1,fb;
	do{
		fb=fb1+fb2;
		fb1=fb2;
		fb2=fb;
	}
	while (fb<=n);
	n=fb;
return n;
}

bool isPrimeNumber(int n) { //primenum function
	if (n==1){
		return false;
	}
	else {
		for (int i=2;i<=sqrt(n);i++){
			if ((n % i)==0){
				return false;
			}
		}
	}
return true;
} 

bool DK(int n){				// n=x+y+z; x*x+y*y=z*z
	for(int j=1;j<=n-2;j++){
		for(int i=1;i<=n-j-1;i++){
			for(int k=1;k<=n-i-j;k++){
				if( (i*i+j*j==k*k||i*i+k*k==j*j||k*k+j*j==i*i ) && i+j+k ==n){
					return true;
				}
			}	
		}
	}
return false;
}

int main(int argc, char** argv)
{
    // if (argc < 2) return 1;
    const char* filename = argv[1];;

   struct knight theKnight;
   int nEvent; //number of events
   int* arrEvent = new int[EVENT_SIZE]; // array of events
   int* nOut;                           // final result
   int i;

	readFile(filename, theKnight, nEvent, arrEvent);
	//cout << theKnight.HP << ' ' << theKnight.level << ' ' << theKnight.remedy << ' ' << theKnight.maidenkiss << ' ' << theKnight.phoenixdown << endl;
	int frog=0,tiny=0,excalibursword=0,myamor=0,excalipoorsword=0,odin=0,arthur=0,lancelot=0,paladin=0,dk=0,countfrog=0,counttiny=0;
	int levelO,prelevel,fresult;
	int maxHP=theKnight.HP;
	
	if(theKnight.HP==999){
		arthur=1;
	}
	else if(theKnight.HP==888){
		lancelot=1;
	}
	else if(isPrimeNumber(theKnight.HP)==1){
		paladin=1;
	}
	else {
		if( DK(theKnight.HP)==1 ){
			dk=1;
		}
	}
	
	for (i = 0; i < nEvent; i++){
		int theEvent = arrEvent[i];
		//cout << theEvent << endl;
		levelO=calLevelO(i+1);
		
		switch (theEvent){
			case 0:{
				goto case21;
				break;
			}
			case BANDIT:	//deal with Bandit here
			case MADBEAR:   //deal with MadBear here
			case 3:
			case 4:
			case 5:{
				if(odin==1 || dk==2 || arthur==1 || (lancelot==1 && (theKnight.level%2)==1 ) || paladin==1){
					if(theKnight.level<10){
						theKnight.level+=1;
					}
					break;
				}
				if(excalipoorsword==1){
					goto lose0;
				}
				if(excalibursword==1){
					theKnight.level+=1;
					break;
				}
				if (theKnight.level>levelO){
					if(theKnight.level<10){
						theKnight.level+=1;
					}
				}
				else if(theKnight.level==levelO){
					break;
				}
				else{
					lose0:
					if(myamor==1){
						break;
					}
					theKnight.HP-=calDamage(theEvent,levelO);
					if(theKnight.HP<0){
						if(theKnight.phoenixdown>0){
							frog=0;
							tiny=0;
							counttiny=0;
							countfrog=0;
							theKnight.HP=maxHP;
							theKnight.phoenixdown-=1;
							break;
						}
						else{
							cout<<-1;
							return 0;
						}
					}
				}
				break;
			}
			//case6 :Shaman
			case 6:{
				if(tiny==1||frog==1){
					break;
				}
				if(odin==1 || dk==2 || arthur==1 || (lancelot==1 && (theKnight.level%2)==1 ) || paladin==1){
					theKnight.level+=2;
					if(theKnight.level>10){
						theKnight.level=10;
					}
					break;
				}
				if(excalipoorsword==1){
					goto lose1;
				}
				if (theKnight.level>levelO){
					theKnight.level+=2;
					if(theKnight.level>10){
						theKnight.level=10;
					}
				}
				else if(theKnight.level==levelO){
					break;
				}
				else{	
					lose1:
					tiny=1;
					if(myamor==1){
						break;
					}
					theKnight.HP/=5;
					if(theKnight.remedy>0){
						theKnight.HP*=5;
						theKnight.remedy-=1;
						tiny=0;
						counttiny=0;
					}
					if(theKnight.HP<5){
						theKnight.HP=1;	
					}	
				}
				break;
			}
			//case 7 :Vajsh
			case 7:{
				if(tiny==1||frog==1){
					break;
				}
				if(odin==1 || dk==2 || arthur==1 || (lancelot==1 && (theKnight.level%2)==1) || paladin==1 ){
					theKnight.level+=2;
					if(theKnight.level>10){
						theKnight.level=10;
					}
					break;
				}
				if(excalipoorsword==1){
					goto lose2;
				}
				if (theKnight.level>levelO){
					theKnight.level+=2;
					if(theKnight.level>10){
						theKnight.level=10;
					}			
				}
				else if(theKnight.level==levelO){
					break;
				}
				else{
					lose2:
					frog=1;
					prelevel=theKnight.level;
					theKnight.level=1;
					if(theKnight.maidenkiss>0){
						theKnight.level=prelevel;
						theKnight.maidenkiss-=1;
						frog=0;
						countfrog=0;
					}
				}
				break;
			}
			case 8:{		
				if(dk==2){
					break;
				}	
				excalibursword=1;
				excalipoorsword=0;
				break;
			}
			case 9:{
				myamor=1;
				break;
			}
			case 10:{ // fake sword
				if(odin==1 || arthur==1 || (lancelot==1 && (theKnight.level%2)==1 ) || paladin==1 || dk==1 ||dk==2){
					excalipoorsword=0;
					break;
				}
				if(theKnight.level>=5){
					break;
				}
				else{
					excalipoorsword=1;
					excalibursword=0;
				}
				break;
			}
			case 11:{
				theKnight.HP+=50;
				if(theKnight.HP>maxHP){
					theKnight.HP=maxHP;
				}
				break;
			}
			case 12:{	// mushFibo
				theKnight.HP=case12(theKnight.HP);
				if(theKnight.HP>maxHP){
					theKnight.HP=maxHP;
				}
				break;
			}
			case 13:{	//mushGhost
				if(odin==1 || paladin==1 || dk==2 || myamor==1){
					break;
				}
				if(theKnight.HP<51){
					theKnight.HP=1;
				}
				else{
					theKnight.HP-=50;
				}
				break;
			}
			case 14:{	//mushKnight
				maxHP+=50;
				if(maxHP>999){
					maxHP=999;
				}
				theKnight.HP=maxHP;
				break;
			}
			case 15:{ //remedy-tiny
				theKnight.remedy+=1;
				if(theKnight.remedy>99){
					theKnight.remedy=99;
				}
				if(tiny==1){
					tiny=0;
					counttiny=0;
					theKnight.HP*=5;
					if(theKnight.HP>maxHP){
						theKnight.HP=maxHP;
					}
					theKnight.remedy-=1;
				}
				break;
			}
			case 16:{	//maidenkiss-frog
				theKnight.maidenkiss+=1;
				if(theKnight.maidenkiss>99){
					theKnight.maidenkiss=99;
				}
				if(frog==1){
					frog=0;
					countfrog=0;
					theKnight.level=prelevel;
					theKnight.maidenkiss-=1;
				}
				break;
			}
			case 17:{  //phoenixdown
				theKnight.phoenixdown+=1;
				if(theKnight.phoenixdown>99){
					theKnight.phoenixdown=99;
				}
				break;
			}
			case 18:{  // Merlin the Wizard
				if(tiny==1){
					tiny=0;
					counttiny=0;
					theKnight.HP*=5;
					if(theKnight.HP>maxHP){
						theKnight.HP=maxHP;
					}	
				}
				if(frog==1){
					frog=0;
					countfrog=0;
					theKnight.level=prelevel;
				}
				theKnight.level+=1;
				if(theKnight.level>10){
					theKnight.level=10;
				}
				theKnight.HP=maxHP;
				break;
			}
			case 19:{		//  Abyss
				if(theKnight.level>=7 || odin==1){
					break;
				}
				else{
					cout<<-1;
					return 0;
				}
				break;
			}
			case 20:{  // go back in reversed order-undone
				nEvent=2*i+1;
				int k=i-1;
				for(int j=i+1;j<nEvent;j++){
					arrEvent[j]=arrEvent[k];
					k--;
				}
				break;
			}
			case 21:{	//wings of lightning 
				for (int a=0;a<i;a++){
					if(arrEvent[a]==20){
						goto case21;
					}
				}
				if(odin==1){
					odin+=1;
				}
				if(nEvent-i-1<3){
					goto case21;
				}
				if(arrEvent[i+1]==0||arrEvent[i+1]==20||arrEvent[i+2]==0||arrEvent[i+2]==20||arrEvent[i+3]==0||arrEvent[i+3]==20){
					goto case21;
				}
				i+=3;
				break;
			}
			case 22:{ // Odin
				odin+=1;				
				break;
			}
			case 23:{	//dragon sword
				if(dk==1){
					dk=2;
				}
				else{
					break;
				}
				break;
			}
			case 99:{  //bowser
				if(arthur==1 || lancelot==1 || (paladin==1 && theKnight.level>=8 ) || (theKnight.level==10 && excalipoorsword==0) || dk==2|| odin==1){
					theKnight.level=10;
					break;
				}
				else{
					cout<<-1;
					return 0;
				}
				break;
			}
		}
		
			if(tiny==1){	// case 6 (after being tiny for 3 events)
				counttiny+=1;
				if(counttiny==4){	
					tiny=0;		
					counttiny=0;
					theKnight.HP*=5;
					if(theKnight.HP>maxHP){
						theKnight.HP=maxHP;
					}
				}
			}
			
			if(frog==1){	// case 7 (after being frog for 3 events)
				countfrog+=1;
				if(countfrog==4){	
					frog=0;		
					countfrog=0;
					theKnight.level=prelevel;
				}
			}
			
			
			if( arrEvent[i-3]==22){    //odin assit
				odin+=1;
			}
			
			
	}
	//
case21:
	
	fresult=theKnight.HP+theKnight.level+theKnight.maidenkiss+theKnight.phoenixdown+theKnight.remedy;
	nOut=&fresult;
    display(nOut);
return 0;
}

