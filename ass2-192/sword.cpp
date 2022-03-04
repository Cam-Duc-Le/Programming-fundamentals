#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif

int calLevelO(int i){ //checked
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

bool friendlyNum(int hp, int gil){ //checked
	float sumhp=0,sumgil=0;
	for (int a=1; a<=hp; a++){
		if ((hp%a)==0){
			sumhp+=a;
		}
	}
	for (int b=1; b<=gil; b++){
		if ((gil%b)==0){
			sumgil+=b;
		}
	}
	float m=sumhp/hp;
	float n=sumgil/gil;
	if (m==n){
		return true;
	}
	else{
		return false;
	}
}

bool isPrimeNumber(int n) { //primenum function checked
	if (n==1){
		return false;
	}
	else {
		for (int i=2;i<=n/2;i++){
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

void swap(castle& x, castle& y){
	castle t = x;
	x = y;
	y = t;
}
//base on heap permutation algorithym
void hoanvi(castle a[], int size, int nCastle, report*result[],knight tempknight[], int nPetal){
	static int k = 0;// let k exist through out the function
	if (size == 1){
		result[k] = walkthrough(tempknight[k], a, nCastle, 0, nPetal);
		k++;
		return;
	}

	for (int i = 0; i < size; i++){
		hoanvi(a, size - 1, nCastle,result,tempknight,nPetal);
		if (size % 2 == 1){
			swap(a[0], a[size - 1]);
		}else{
			swap(a[i], a[size - 1]);
		}
	}
}

report* mode2(knight& theKnight, castle arrCastle[], int nCastle, int nPetal){
	int soluong=1;
	for(int z=1;z<=nCastle;z++){ //so luong truong hop=z!
		soluong*=z;
	}

// initialize vaule of the clone-knigth like:  hp, level,gil,.. of  tempknight
	knight* tempknight = new knight[soluong];
	for (int m = 0;m < soluong;m++){
		tempknight[m] = theKnight;
	}
	//
	//
	
	report** result = new report*  [soluong];// pointer point to a array-  array result has soluong elements- each element contain nPetal,win,lose   - like 2 dimensional array
	hoanvi(arrCastle, nCastle, nCastle, result, tempknight, nPetal);
	// 
	//
	int max = 0;
	for (int i = 0;i < soluong;i++){
		if (result[i] == NULL){
			result[i]->nLose=0;
			result[i]->nWin=0;
			result[i]->nPetal=0;
		}
		// compare to find the max petal left
		if (max < result[i]->nPetal){
			max = result[i]->nPetal;
		}
	}
	
	//
	// check which case refer to the case we want to cout
	for (int i = 0; i < soluong;i++){
		if (max == result[i]->nPetal){
			theKnight = tempknight[i];
			return result[i];
		}
	}
}
// mode 0
report*  walkthrough (knight& theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{
  report* pReturn= new report;
  int bFlag;
  //
	int maxHP=theKnight.HP,levelO,countpoisoned=0,countlionheartsword=0,countodin=0,odinappear=0,ninaappear=0;
	bool door=false,poisoned=false,lionheartsword=false,odin=false,metodin=false,metnina=false,dk=false,excalibursword=false,defeatomega=false,myamor=false,deadodin=false,eternallove=false,spear=false,hair=false,authur=false,lancelot=false,guinevere=false,sh=false,paladin=false,shield=false;
  //
  //fighting for the existence of mankind here

if(theKnight.HP==999){ // check the character of knight
	authur=true;
}
else if(theKnight.HP==888){
	lancelot=true;
	spear=true;
}
else if(theKnight.HP==777){
	guinevere=true;
	hair=true;
}
else if(isPrimeNumber(theKnight.HP)==true){
	paladin=true;
	shield=true;
}
else if(DK(theKnight.HP)==true){
	dk=true;
}
else{};

pReturn->nLose=0;
pReturn->nWin=0;
pReturn->nPetal=nPetal;


	// mode 1
	int a=hash(95),b=hash(96),c=hash(97);
	//int a=2,b=1,c=3;
	//
	
	//mode 2
	 	if (mode == 2){
	  		return mode2(theKnight, arrCastle, nCastle, nPetal); //return a pointer point to a tempknight[i] in heap area
		}
	//

while(pReturn->nPetal>0 || authur==true){ // loop for start again
  for(int i=0;i<nCastle;i++){ // pass each castle
  	castle cc= arrCastle[i];
	for(int j=0;j<cc.nEvent;j++){// each event in castle
  		levelO=calLevelO(j+1);
  	
  		switch (cc.arrEvent[j]){
  			case 1:{	
  				if(theKnight.level>=levelO || lionheartsword==true || odin==true || authur==true || lancelot==true || paladin==true){
  					pReturn->nWin+=1;
  					theKnight.gil+=100;
  					if(theKnight.gil>999){
  						theKnight.gil=999;
					}
				}
				else{
					pReturn->nLose+=1;
					if(myamor==false){
						theKnight.HP-=10*levelO;
						if(theKnight.HP<=0){
							callPhoenix(theKnight,maxHP);
							poisoned=false;
							countpoisoned=0;
						}	
					}
				}
				
				if (poisoned==true && paladin==false && dk==false){
  					theKnight.HP-=10*levelO;
				}
				
				if(theKnight.HP<=0){
					callPhoenix(theKnight,maxHP);
					poisoned=false;
					countpoisoned=0;
				}	
				break;
			}
  			case 2:{ // moon bringer
  				if(theKnight.level>=levelO || lionheartsword==true || odin==true || authur==true || lancelot==true || paladin==true){
  					pReturn->nWin+=1;
  					theKnight.gil+=150;
  					if(theKnight.gil>999){
  						theKnight.gil=999;
					}
				}
				else{
					pReturn->nLose+=1;
					if(myamor==false && guinevere==false){
						theKnight.HP-=15*levelO;
						if(theKnight.HP<=0){
							callPhoenix(theKnight,maxHP);
							poisoned=false;
							countpoisoned=0;
						}
					}
				}
				
				if (poisoned==true && paladin==false && dk==false){
  					theKnight.HP-=15*levelO;
				}
				
				if(theKnight.HP<=0){
					callPhoenix(theKnight,maxHP);
					poisoned=false;
					countpoisoned=0;
				}	
				break;
			}
  			case 3:{	
  				if(theKnight.level>=levelO || lionheartsword==true || odin==true || authur==true || lancelot==true || paladin==true){
  					pReturn->nWin+=1;
  					theKnight.gil+=450;
  					if(theKnight.gil>999){
  						theKnight.gil=999;
					}
				}
				else{
					pReturn->nLose+=1;
					if(myamor==false){
						theKnight.HP-=45*levelO;
						if(theKnight.HP<=0){
							callPhoenix(theKnight,maxHP);
							poisoned=false;
							countpoisoned=0;
						}
					}
				}
				
				if (poisoned==true && paladin==false && dk==false){
  					theKnight.HP-=45*levelO;
				}
				
				if(theKnight.HP<=0){
					callPhoenix(theKnight,maxHP);
					poisoned=false;
					countpoisoned=0;
				}	
				break;
			}
  			case 4:{
  				if(theKnight.level>=levelO || lionheartsword==true || odin==true || authur==true || lancelot==true || paladin==true){
  					pReturn->nWin+=1;
  					theKnight.gil+=650;
  					if(theKnight.gil>999){
  						theKnight.gil=999;
					}
				}
				else{
					pReturn->nLose+=1;
					if(myamor==false){
						theKnight.HP-=65*levelO;
						if(theKnight.HP<=0){
							callPhoenix(theKnight,maxHP);
							poisoned=false;
							countpoisoned=0;
						}
					}
				}
				
				if (poisoned==true && paladin==false && dk==false){
  					theKnight.HP-=65*levelO;
				}
				
				if(theKnight.HP<=0){
					callPhoenix(theKnight,maxHP);
					poisoned=false;
					countpoisoned=0;
				}	
				break;
			}
  			case 5:{
  				if(theKnight.level>=levelO||lionheartsword==true || odin==true || authur==true || lancelot==true || paladin==true){
  					pReturn->nWin+=1;
  					theKnight.gil+=850;
  					if(theKnight.gil>999){
  						theKnight.gil=999;
					}
				}
				else{
					pReturn->nLose+=1;
					if(myamor==false){
						theKnight.HP-=85*levelO;
						if(theKnight.HP<=0){
							callPhoenix(theKnight,maxHP);
							poisoned=false;
							countpoisoned=0;
						}
					}
				}
				
				if (poisoned==true && paladin==false && dk==false){
  					theKnight.HP-=85*levelO;
				}
				
				if(theKnight.HP<=0){
					callPhoenix(theKnight,maxHP);
					poisoned=false;
					countpoisoned=0;
				}	
				break;
			}
			case 6:{ //tornbery
				if(poisoned==true){  //Tornbery will not fight a poisoned knight
					break;
				}
				
				if(theKnight.level>=levelO ||lionheartsword==true || odin==true || authur==true || lancelot==true){
  					pReturn->nWin+=1;
  					if(theKnight.level<10){
  						theKnight.level+=1;
  						maxHP+=100;
  						if(maxHP>999){
							maxHP=999;
						}
					}	
				}	
				else{
					pReturn->nLose+=1;
					poisoned=true;
					if(paladin==true || dk==true){
						poisoned=false;
						countpoisoned=0;
						break;
					}
					if(theKnight.antidote>=1){
						poisoned=false;
						countpoisoned=0;
						theKnight.antidote-=1;
					}
				}
				break;
			}
  			case 7:{//queen of cards
  				if(theKnight.level>=levelO || lionheartsword==true || odin==true || authur==true || lancelot==true){
  					pReturn->nWin+=1;
  					theKnight.gil*=2;
  					if(theKnight.gil>999){
  						theKnight.gil=999;
					}
				}
				else{
					pReturn->nLose+=1;
					if(sh==true || guinevere==true){
						break;
					}
					theKnight.gil/=2;
				}
				break;
			}
			case 8:{ // meet nina de ring
				if(metnina){
					ninaappear=0;
					break;
				} 
				metnina=true;
				if(friendlyNum(theKnight.HP,theKnight.gil)==true){
					poisoned=false;
					countpoisoned=0;
					theKnight.HP=maxHP;
					lionheartsword=true;
					break;
				}	
				
				if(sh==true || guinevere==true || paladin==true){
					poisoned=false;
					countpoisoned=0;
					theKnight.HP=maxHP;
					if(guinevere==true){
						theKnight.gil+=50;
						if(theKnight.gil>999){
							theKnight.gil=999;
						}
					}
					break;
				}
				
				if(theKnight.gil<50){
					break;
				}
				
				if(poisoned==true){
					poisoned==false;
					countpoisoned=0;
					theKnight.gil-=50;
				}
				
				while(theKnight.gil > 0 && theKnight.HP<maxHP ) {
					theKnight.gil-=1;
					theKnight.HP+=1;
				}
				break;
			}
			case 9:{ //durian garden
				poisoned=false;
				countpoisoned=0;	
				theKnight.HP=maxHP;
				pReturn->nPetal+=5;
				if(pReturn->nPetal>99 || sh==true ){
					pReturn->nPetal=99;
				}
				break;
			}
			case 10:{ //obtain antidote
				theKnight.antidote+=1;
				if(theKnight.antidote>99){
					theKnight.antidote=99;
				}
				
				if(countpoisoned==6 && poisoned==true){
					countpoisoned=0;
					poisoned=false;
					break;
				}
				
				if(poisoned==true){
					poisoned=false;
					countpoisoned=0;
					theKnight.antidote-=1;
				}
				break;
			}
			case 11:{ //meet odin
				if(deadodin==true ){ // odin no more appear
					odin=false;
					countodin=0;
					metodin=false;
					odinappear=0;
					break;
				}
				
				if(metodin==true){// already met odin
					odinappear=0;
					break;
				}
				else{// not yet
					metodin=true;
					odin=true;
				}
				break;
			}
			case 12:{ //meet merlin	
				if(poisoned==true){
					poisoned=false;
					countpoisoned=0;
				}
				if(theKnight.level<10){
					theKnight.level++;
					maxHP+=100;
					if(maxHP>999){
						maxHP=999;
					}
				}
				theKnight.HP=maxHP;
				break;
			}
			case 13:{ //meet omega
				if(defeatomega==true){
					break;
				}
				
				if((theKnight.level==10 && excalibursword==true) || (dk==true && lionheartsword==true)){
					pReturn->nWin+=1;
					theKnight.gil=999;
					maxHP+= 100*(10-theKnight.level);
					if(maxHP>999){
						maxHP=999;
					}
					theKnight.level=10;
					defeatomega=true;
				}
				else{
					pReturn->nLose+=1;
					if(myamor==true){
						break;
					}
					callPhoenix(theKnight,maxHP);
					poisoned=false;
					countpoisoned=0;
				}
				break;
			}
			case 14:{ // meet hades
				if(odin==true && dk==false){
					deadodin=true;
					odin=false;
					countodin=0;
				}
				
				if((spear==true&&hair==true&&excalibursword==false) || (authur==true&&hair==true) || (lancelot==true&&hair==true) || (guinevere==true&&spear==true)){
  					eternallove=true;	
				}
				
				if (theKnight.level>=levelO || eternallove==true || (dk==true && odin==true) || lionheartsword==true ){
					pReturn->nWin+=1;
					eternallove=false;
					myamor=true;
				}
				else{
					pReturn->nLose+=1;
					if(myamor==false){
						callPhoenix(theKnight,maxHP);
						poisoned=false;
						countpoisoned=0;
					}
				}
				break;
			}
			case 15:{ // obtain SH
				sh=true;
				break;
			}
			case 16:{ //  locked door 
				if((theKnight.level > ((j+1)%10)) || dk==true || lancelot==true  ){//pass
					break;
				}
				else{
					door=true;
				}
				break;
			}
			case 95:{ //shield
				if( mode==0 ){
					shield=true;
					break;
				}			
			
				if(mode==1){
				  	if(hair&&spear){ // hash 95 max
				  		shield=true;
				  	}
					else if(a<b && a<c){ // hash95 min
						shield=true;
					}
					else if( a>b&&a<c  ){ // hash 95 in the middle
						if(spear){
							shield=true;
						}
					}
					else if( a>c&&a<b ){
						if(hair){
							shield=true;
						}
					}else{}	;
				}
				
				break;
			}
			case 96:{ // spear
				if(mode==0){
					spear=true;
					break;
				}			
			
				if(mode==1){
					if(hair && shield){ // hash96 mmax
						spear=true;
					}
					else if(b<a&&b<c){ // hash96 min
						spear=true;
					}
					else if( b>a&&b<c  ){ // hash 96 in the middle
						if(shield){
							spear=true;
						}
					}
					else if( b>c&&b<a){ // 
						if(hair){
							spear=true;
						}
					}else{};		
				}
			
				break;
			}
			case 97:{ //hair
				if(mode==0){
					hair=true;
					break;
				}
				
				if(mode==1){
					if(spear&&shield){//hash97 max
						hair=true;
					}
					else if(c<a && c<b){ // hash97 min
						hair=true;
					}
					else if( c>b&&c<a  ){ // hash 97 in the middle
						if(spear){
							hair=true;
						}
					}
					else if(c>a&&c<b){
						if(shield){
							hair=true;
						}
					}else{};		
				}
			
				break;
			}
			case 98:{ //excalibursword	
				if( (spear==true && hair==true && shield==true) || authur==true){
					excalibursword=true;
				}
				break;
			}
			case 99:{ // fight with ultimecia
				if (excalibursword==true || lionheartsword==true){//win
					pReturn->nWin+=1;
					if(pReturn->nPetal>0){
						pReturn->nPetal-=1;
				    }
				    
					if (poisoned==true){
						if(theKnight.HP<3){
							theKnight.HP=1;
						}
						else{
							theKnight.HP/=3;
						}
					}
					return pReturn;
				}
				else{// lose ultimecia
					pReturn->nLose+=1;
					if(myamor==false && guinevere==false){
						if(theKnight.HP<3){
							theKnight.HP=1;
					 	}
						else{
							theKnight.HP/=3;
						}
					}
					
					if(poisoned==true && paladin==false && dk==false){
						if(theKnight.HP<3){
							theKnight.HP=1;
						}
						else{
							theKnight.HP/=3;
						}
					}	
				}
				break;
			}
		}//end of switch-case
		
		if(pReturn->nPetal > 0){
			pReturn->nPetal--;
		}
		if(pReturn->nPetal==0 && authur==false){
			return NULL;
		}
		
		
		if(poisoned==true){
			countpoisoned++;
			if(countpoisoned==6){
				countpoisoned=0;
				poisoned=false;
			}
		}
		
		
		if (lionheartsword==true && paladin==false){
			countlionheartsword++;
			if(countlionheartsword==6 && paladin==false){
				countlionheartsword=0;
				lionheartsword=false;
			}
		}
		
	
		if(odin==true ){ // how many time odin help
			countodin++;
			if(countodin==6){
				countodin=0;
				odin=false;
			}
		}
		
		if(metodin==true){ // how many times odin appear
			odinappear++;
			if(odinappear==6){
				odinappear=0;
				metodin=false;
			}
		}
		
		// m
		
		if( metnina==true){// how many times nina appear
			ninaappear++;
			if( ninaappear==6){
				metnina=false;
				ninaappear=0;
			}
		}
		
		
		//
		
		if(door==true){// for case 16 to skip current castle
			door=false;
			break;
		}
		
   }// end of fisrt for loop
   //after each castle: 
  
  
    if(pReturn->nPetal>0 || authur==true){
  		if(theKnight.level<10){
  			theKnight.level+=1;	
  			maxHP+=100;
  			if(maxHP>999){
  				maxHP=999;
			}
		}
	}
	
  }//end of second for loop
}// end of while loop


  // success or failure?	
// pReturn = (bFlag)? new report : NULL;
  return pReturn;
}
