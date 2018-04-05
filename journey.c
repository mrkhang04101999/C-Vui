#include "defs.h"
#include <math.h>
int firstnum(int);
int gold(int);
int min(int, int);
int isprime(int);
int ktrangto(int);
int ucln(int,int);
int lastnum(int);
int midnum(int);
int checkFibo(int);
int Da(int,int,int);
int calculate(struct musketeer theMusketeer, int R, int N, int nEvent, int* arrEvent)
{
	int nOut=0,kq,i,t,p,b,x,h=0,solan,k=1,uc,j,td,ji;
	float a;
	int h1,h2,vd=0,my=0;
	theMusketeer.nRedDiamonds = 0;
	theMusketeer.nBlueDiamonds = 0;
	switch(theMusketeer.ID){
		case 1:
			theMusketeer.HP=999;
			theMusketeer.nHealthPoint = theMusketeer.HP; 
			break;
		case 2:
			theMusketeer.HP=900;
			theMusketeer.nHealthPoint = theMusketeer.HP;
			break;
		case 3:
			theMusketeer.HP=888;
			theMusketeer.nHealthPoint = theMusketeer.HP;
			break;
		case 4:
			theMusketeer.HP=777;
			theMusketeer.nHealthPoint = theMusketeer.HP;
			break;
	}
	

	for(i=1;i<=nEvent;i++){
		
		td =theMusketeer.nHealthPoint;
		
		if(firstnum(arrEvent[i]) == 2){
			theMusketeer.nRedDiamonds = theMusketeer.nRedDiamonds + 1;
			vd = vd + gold(arrEvent[i]);
		}
		
		if(firstnum(arrEvent[i]) == 1){
			theMusketeer.nBlueDiamonds = theMusketeer.nBlueDiamonds + 1;
			vd = vd + gold(arrEvent[i]);
			if(theMusketeer.ID == 3){
				theMusketeer.nBlueDiamonds = theMusketeer.nBlueDiamonds - 1;
				vd = vd - gold(arrEvent[i]);
				theMusketeer.nGoldCoin = theMusketeer.nGoldCoin + gold(arrEvent[i]);
			}
		}
		
		
		if(firstnum(arrEvent[i]) == 4){
			//td = theMusketeer.nHealthPoint;
			if(solan <= 3 && solan > 0){
				solan = solan - 1;
				continue;
			}
			if(theMusketeer.ID == 4 && (td - Da(my,R,gold(arrEvent[i]))) < 1)
				continue;
			for(ji=1;ji<=k;ji++){
				h1 = gold(arrEvent[i]) * R;
				h2 = (theMusketeer.nHealthPoint + h1) % (100 + R);
				if(theMusketeer.ID == 2){
					if(isprime(h2) == 1)
						if(h2 > R){
							if(my == 1){
								a = ((float)(R+1))/((float)pow(2,R)) ;
								b = round(gold(arrEvent[i]) * a);
								theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - b;
							}else theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - gold(arrEvent[i]);						
						}
				}else{
					if(theMusketeer.nHealthPoint >= h1){
						theMusketeer.nGoldCoin = min(theMusketeer.nGoldCoin + gold(arrEvent[i]),999);
						if(h2 == 0){
							if(my == 1){
								a = ((float)(R+1))/((float)pow(2,R)) ;
								b = round(gold(arrEvent[i]) * a);
								theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - b;
							}else theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - gold(arrEvent[i]);
						}
					}else if(my == 1){
							a = ((float)(R+1))/((float)pow(2,R)) ;
							b = round(gold(arrEvent[i]) * a);
							theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - b;
						}else theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - gold(arrEvent[i]); 
				
				}
			}
			/*if(theMusketeer.ID == 4)
				if(theMusketeer.nHealthPoint <= 0)
					theMusketeer.nHealthPoint = td;*/
			
		}
		
		if(firstnum(arrEvent[i]) == 3){
			if(theMusketeer.ID == 3){
				if(R < 3 || theMusketeer.nGoldCoin <=2) continue;
				p=gold(arrEvent[i])/ktrangto(R);
				theMusketeer.nHealthPoint = min(theMusketeer.nHealthPoint + p,theMusketeer.HP);
				theMusketeer.nGoldCoin = theMusketeer.nGoldCoin - p*ktrangto(R);
			}else{	
				theMusketeer.nHealthPoint = min(theMusketeer.nHealthPoint + gold(arrEvent[i]),theMusketeer.HP);
				theMusketeer.nGoldCoin = theMusketeer.nGoldCoin - gold(arrEvent[i]);
			}
		}
		
		if(firstnum(arrEvent[i]) == 5){
			if(x==1) continue;
			h1 = gold(arrEvent[i]) * R;
			h2 = (theMusketeer.nHealthPoint + h1) % (100 + R);
			if(theMusketeer.nHealthPoint >= h1){
				if(isprime(theMusketeer.nBlueDiamonds) && isprime(theMusketeer.nRedDiamonds)){
					my = my + 1;
				}else if(theMusketeer.ID == 3){
						theMusketeer.nRedDiamonds = theMusketeer.nRedDiamonds + 1;
						vd = vd + gold(arrEvent[i]);
					}else{
						theMusketeer.nBlueDiamonds = theMusketeer.nBlueDiamonds + 1;
						vd = vd + gold(arrEvent[i]);
					}	
				
			}
			if(theMusketeer.nHealthPoint < h1){
				theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - gold(arrEvent[i]);
				theMusketeer.nGoldCoin = theMusketeer.nGoldCoin / 2;
			}
			x=1;

		}
		
		
		if(firstnum(arrEvent[i]) == 6){
			if(theMusketeer.nBlueDiamonds >= theMusketeer.nRedDiamonds){
				theMusketeer.nHealthPoint = min(theMusketeer.nHealthPoint + gold(arrEvent[i]),theMusketeer.HP);
				k=1;
			}else k=2;
		}
		
		
		if(firstnum(arrEvent[i]) == 7){
			if(theMusketeer.ID == 3){
				solan = 3;
				continue;
			}
			if(theMusketeer.ID == 4 && (td - Da(my,R,arrEvent[i])) < 1) 
				continue;
			else{
				for(ji=1;ji<=k;ji++){	
					h1 = gold(arrEvent[i]) * R;
					h2 = (theMusketeer.nHealthPoint + h1) % (100 + R);
					if(theMusketeer.nHealthPoint >= h1){
						if(h2 == 0){
							if(my == 1){
								a = ((float)(R+1))/((float)pow(2,R)) ;
								b = round(arrEvent[i] * a);
								theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - b;
							}else theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - arrEvent[i];
						}
						h=h+1;
					}else if(my == 1){
						a = ((float)(R+1))/((float)pow(2,R)) ;
						b = round(arrEvent[i] * a);
						theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - b;
						}else theMusketeer.nHealthPoint = theMusketeer.nHealthPoint - arrEvent[i];
				}
			}
		}
		
		if(firstnum(arrEvent[i]) == 8){
			if(theMusketeer.ID == 1) return -1;
			if(theMusketeer.ID == 2) theMusketeer.nGoldCoin = 999;
			if(theMusketeer.nHealthPoint <= 700){
				if(theMusketeer.ID == 3){
					uc = ucln(midnum(arrEvent[i]),lastnum(arrEvent[i]));
					j=i;
					for(;j>0 && uc >0;){
						if(firstnum(arrEvent[j]) == 2){
							theMusketeer.nRedDiamonds = theMusketeer.nRedDiamonds - 1;
							vd = vd - gold(arrEvent[j]);
							uc = uc -1;
						}
						j=j-1;
					}
				}
				
				if(theMusketeer.ID == 4){
					uc = ucln(midnum(arrEvent[i]),lastnum(arrEvent[i]));
					j=i;
					for(;j>0 && uc >0;){
						if(firstnum(arrEvent[j]) == 1){
							theMusketeer.nBlueDiamonds = theMusketeer.nBlueDiamonds - 1;
							vd = vd - gold(arrEvent[j]);
							uc = uc -1;
						}
						j=j-1;
					}
				}	
			}
		}
		
		if(firstnum(arrEvent[i]) == 9){
			if(checkFibo(i)){
				h1 = gold(arrEvent[i]) * R;
				h2 = (theMusketeer.nHealthPoint + h1) % (100 + R);
				if(theMusketeer.nHealthPoint >= h1){
					theMusketeer.nHealthPoint = theMusketeer.HP;
					theMusketeer.nGoldCoin = 999;
				}else return -1;
			}else return -1;			
		}			
		
		t = theMusketeer.nRedDiamonds + theMusketeer.nBlueDiamonds;
		if(t == N){
			kq = theMusketeer.nHealthPoint + theMusketeer.nGoldCoin + vd;
			return kq;
		}
		if(theMusketeer.nHealthPoint <= 0)
			return -1;
		if(theMusketeer.nGoldCoin < 0)
			return -1;
		if(i == nEvent)
			if(t < N)
				return 0;
		if(h == 3){
			kq = theMusketeer.nHealthPoint + theMusketeer.nGoldCoin + vd;
			return kq;
		}
	}
	
	// Write your code here. Please!
	// Update the return value also. Please!
	return nOut ;
}
int firstnum(int a)
{
	int n;
	for(;a>0;a/=10)
		n=a%10;
	return n;
}
int lastnum(int a)
{
	return a%10;
}
int midnum(int a)
{
	a=a/10;
	return a%10;
}
int gold(int n)
{
	int a=0,b=0;
	b = firstnum(n);
	a = n - b*100;
	return a;
}
 int min(int a, int b)
 {
	int m;
	m=a;
	if(m>b)
		m=b;
	return m;
 }
 int isprime(int n)
 {
	int i;
	if(n<=1)
		return 0;
	for(i=2;i<n;i++)
		if(n%i == 0) return 0;
	return 1;
 }
 int ktrangto(int n)
 {
	int i,h=0;
	for(i=n-1;i>1;i--)
		if(isprime(i) == 1){
			h=i;
			return h;
		}
	return h;
 }
 int ucln(int a,int b)
 {
	while(a != b){
		if(a > b) a = a - b;
		else b = b - a;
	}
	return a;
 }
int checkFibo( int ele ){ 
   int fn1, fn2, fn; 
   fn1 = 0, fn2 = 1; 
   if( ele == fn1 || ele == fn2 ) 
       return 1; 
   else{ 
       while( 1 ){ 
           fn = fn1 + fn2; 
           fn1 = fn2; 
           fn2 = fn; 
           if( ele == fn ) 
               return 1; 
           if( ele < fn ) 
               return 0; 
       } 
   } 
}

int Da(int effect, int r, int xy)
{
    float a = 1;
    if(effect)
        a = (r + 1)/pow(2,r);
     return round(xy*a);
} 








