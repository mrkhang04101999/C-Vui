#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#include <math.h>
#endif

int isprime(int);
int max(int ,int);
int min(int ,int);
int damage(int ,double,int,int);
int ktrangto(int);
int kiemtra(int,int,int,int);
int chiahet(int);
int hoimau(int);

//initialize the originally values of the musketeers
void init(int D[], int A[], int P[], int R[], struct musketeer M[]) {
	//TODO
	M[0].HP=999;M[1].HP=900;M[2].HP=888;M[3].HP=777;
	
	if(D[0] == 0){
		M[0].pC1 = NULL; M[0].npC1 = 0;
	}else{
		newCrystal(&M[0].pC1,0,D[0]);M[0].npC1 = 1;
	}
	if(D[1] == 0){
		M[0].pC2 = NULL; M[0].npC2 = 0;
	}else{
		newCrystal(&M[0].pC2,0,D[1]);M[0].npC2 = 1;
	}
	if(D[2] == 0){
		M[0].pC3 = NULL; M[0].npC3 = 0;
	}else{
		newCrystal(&M[0].pC3,0,D[2]);M[0].npC3 = 1;
	}
	
	
	if(A[0] == 0){
		M[1].pC1 = NULL; M[1].npC1 = 0;
	}else{
		newCrystal(&M[1].pC1,0,A[0]);M[1].npC1 = 1;
	}
	if(A[1] == 0){
		M[1].pC2 = NULL; M[1].npC2 = 0;
	}else{
		newCrystal(&M[1].pC2,0,A[1]);M[1].npC2 = 1;
	}
	if(A[2] == 0){
		M[1].pC3 = NULL; M[1].npC3 = 0;
	}else{
		newCrystal(&M[1].pC3,0,A[2]);M[1].npC3 = 1;
	}
	
	
	if(P[0] == 0){
		M[2].pC1 = NULL; M[2].npC1 = 0;
	}else{
		newCrystal(&M[2].pC1,0,P[0]);M[2].npC1 = 1;
	}
	if(P[1] == 0){
		M[2].pC2 = NULL; M[2].npC2 = 0;
	}else{
		newCrystal(&M[2].pC2,0,P[1]);M[2].npC2 = 1;
	}
	if(P[2] == 0){
		M[2].pC3 = NULL; M[2].npC3 = 0;
	}else{
		newCrystal(&M[2].pC3,0,P[2]);M[2].npC3 = 1;
	}
	
	
	if(R[0] == 0){
		M[3].pC1 = NULL; M[3].npC1 = 0;
	}else{
		newCrystal(&M[3].pC1,0,R[0]);M[3].npC1 = 1;
	}
	if(R[1] == 0){
		M[3].pC2 = NULL; M[3].npC2 = 0;
	}else{
		newCrystal(&M[3].pC2,0,R[1]);M[3].npC2 = 1;
	}
	if(R[2] == 0){
		M[3].pC3 = NULL; M[3].npC3 = 0;
	}else{
		newCrystal(&M[3].pC3,0,R[2]);M[3].npC3 = 1;
	}

	
	
	/*newCrystal(&M[0].pC2, 0, 2); 
	M[0].npC2 = 1;
	printf("M[0].pC2->level: %d \n", M[0].pC2->level);
	
	newCrystal(&M[0].pC2, M[0].npC2, 5); 
	M[0].npC2 = M[0].npC2+1;
	printf("M[0].pC2->nextCystal->level: %d \n", M[0].pC2->nextCrystal->level);*/
	
	
	
	
	
}

//battle 
int battle(struct musketeer M[], int I, int E[], int nEvent) {
	//TODO
	int j,XY,firstnum,a,k,dam,kill,h,t,r,doi,x;
	for(j=0;j<nEvent;j++){
		XY = E[j] % 100;
		firstnum = E[j] / 100;
		kill = 0;
		h=0;
		
		for(k=0;k<4;k++){
			if(k != I){
				if(k == 0 && M[k].HP < 999 )
					M[k].HP = min(M[k].HP + 200,999); 
				if(k == 1 && M[k].HP < 900 )
					M[k].HP = min(M[k].HP + 150,900); 
				if(k == 2 && M[k].HP < 888 )
					M[k].HP = min(M[k].HP + 100,888); 
				if(k == 3 && M[k].HP < 777 )
					M[k].HP = min(M[k].HP + 50,777); 
			}
		}
		
		if(firstnum == 1){
			if(M[I].npC1 == 0)
				M[I].pC1 = NULL;
			newCrystal(&M[I].pC1,M[I].npC1,XY);
			M[I].npC1 += 1;
		}
		
		if(firstnum == 2){
			if(M[I].npC2 == 0)
				M[I].pC2 = NULL;
			newCrystal(&M[I].pC2,M[I].npC2,XY);
			M[I].npC2 += 1;
		}
		
		if(firstnum == 6){
			if(M[I].npC3 == 0)
				M[I].pC3 = NULL;
			newCrystal(&M[I].pC3,M[I].npC3,XY);
			M[I].npC3 += 1;
		}
		
/////////////////////////////////		
		if(firstnum == 4 || firstnum == 5){
			a=I;
			while(kill == 0){
				if(kiemtra(M[0].npC2,M[1].npC2,M[2].npC2,M[3].npC2) == 1){
					t = chiahet(XY);
					if(I==3 && M[I].HP >= t){
						r=I;
						if(kiemtra(M[0].npC3,M[1].npC3,M[2].npC3,M[3].npC3) == 0){
							doi = 0;
							x=0;
							while(doi == 0){
								if(M[r].pC3 == NULL){
									if(r < 3) r++;
									else r=0;
									x += 1;								
								}else{ 
									if(M[r].pC3->level > XY){
										newCrystal(&M[I].pC2,M[I].npC2,M[r].pC3->level -1);
										M[I].npC2 += 1;
										M[I].HP -= t;
										//deleteCrystal(M[r].pC3->level);
										if(M[r].pC3->nextCrystal != NULL){
											M[r].pC3 = M[r].pC3->nextCrystal;
											M[r].npC3 -= 1;
											deleteCrystal(NULL);
										}else{
											deleteCrystal(M[r].pC3);
											M[r].pC3 = NULL;
											M[r].npC3 = 0;
										}
										doi =1;
									}else{
										if(M[r].pC3->nextCrystal != NULL)
											M[r].pC3 = M[r].pC3->nextCrystal;
										else{
											if(r < 3) r++;
											else r=0;
											x += 1;
										}
									}
								}
								if(x==4) doi = 1;	
							}
						}
						if(M[I].pC2 == NULL){
							if(kiemtra(M[0].npC1,M[1].npC1,M[2].npC1,M[3].npC1) == 0){
								doi = 0;
								x=0;
								while(doi == 0){
									if(M[r].pC1 == NULL){
										if(r < 3) r++;
										else r=0;
										x += 1;
									}else{ 
										if(M[r].pC1->level > XY){
											newCrystal(&M[I].pC2,M[I].npC2,M[r].pC1->level -1);
											M[I].npC2 += 1;
											M[I].HP -= t;
											//deleteCrystal(M[r].pC1->level);
											if(M[r].pC1->nextCrystal != NULL){
												M[r].pC1 = M[r].pC1->nextCrystal;
												M[r].npC1 -= 1;
												deleteCrystal(NULL);
											}else{
												deleteCrystal(M[r].pC1);
												M[r].pC1 = NULL;
												M[r].npC1 = 0;
											}
											doi =1;
										}else{
											if(M[r].pC1->nextCrystal != NULL)
												M[r].pC1 = M[r].pC1->nextCrystal;
											else{
												if(r < 3) r++;
												else r=0;
												x += 1;
											}
										}
									}
									if(x == 4) doi = 1;	
								}
							}
						}
					}
				}
			//while(kill == 0){
				if(M[I].pC2 == NULL){
					if(a < 3) a++;
					else a = 0;
					if(a != I) XY += 3;
					M[I].pC2 = M[a].pC2;
					h=h+1;
				}else{
					if(XY > M[I].pC2->level){
						XY -= M[I].pC2->level;
						if(M[I].pC2->nextCrystal != NULL){
							M[I].pC2 = M[I].pC2->nextCrystal;
							M[I].npC2 --;
							deleteCrystal(NULL);
						}else{
							deleteCrystal(M[I].pC2);
							M[I].pC2=NULL;
							M[I].npC2=0;
							M[a].pC2=NULL;
							M[a].npC2=0;
							if(a<3) a++;
							else a=0;
							if(a != I) XY += 3;
							M[I].pC2 = M[a].pC2;
						}
					}else{
						(M[I].pC2)->level -= XY;
						if((M[I].pC2)->level == 0){
							if(M[I].pC2->nextCrystal != NULL){
								M[I].pC2 = M[I].pC2->nextCrystal;
								M[I].npC2 --;
								deleteCrystal(NULL);
							}else{
								deleteCrystal(M[I].pC2);
								M[I].pC2=NULL;
								M[I].npC2=0;
								M[a].pC2=NULL;
								M[a].npC2=0;
							}
						}
						kill =1;
					}
				}
				if(h == 4){
					if(firstnum == 4) dam = damage(XY,QUEZACOLT,I,ktrangto(XY));
					if(firstnum == 5) dam = damage(XY,BAHAMUT,I,ktrangto(XY));
					if(firstnum == 4){
						if(I < 3) I++;
						else I = 0;
						kill = -1;
					}else{
						M[I].HP = max(M[I].HP - dam,0);
						kill = -1;
					}
				}
			}
			
			if(M[I].HP <= 0){
				if(I < 3) I++;
				else I = 0;			
			}
			
		}
////////////////////////////////////		
		
		if(firstnum == 3 || firstnum == 7){
			a=I;
			while(kill == 0){
				if(kiemtra(M[0].npC1,M[1].npC1,M[2].npC1,M[3].npC1) == 1){
					t = chiahet(XY);
					if(I==3 && M[I].HP >= t){
						r=I;
						if(kiemtra(M[0].npC2,M[1].npC2,M[2].npC2,M[3].npC2) == 0){
							doi = 0;
							x=0;
							while(doi == 0){
								if(M[r].pC2 == NULL){
									if(r < 3) r++;
									else r=0;
									x += 1;
								}else{ 
									if(M[r].pC2->level > XY){
										newCrystal(&M[I].pC1,M[I].npC1,M[r].pC2->level -1);
										M[I].npC1 += 1;
										M[I].HP -= t;
										if(M[r].pC2->nextCrystal != NULL){
											M[r].pC2 = M[r].pC2->nextCrystal;
											M[r].npC2 -= 1;
											deleteCrystal(NULL);
										}else{
											deleteCrystal(M[r].pC2);
											M[r].pC2 = NULL;
											M[r].npC2 = 0;
										}
										doi =1;
									}else{
										if(M[r].pC2->nextCrystal != NULL)
											M[r].pC2 = M[r].pC2->nextCrystal;
										else{
											if(r < 3) r++;
											else r=0;
											x += 1;
										}
									}
								}
								if(x==4) doi = 1;
							}
						}
						if(M[I].pC1 == NULL){
							if(kiemtra(M[0].npC3,M[1].npC3,M[2].npC3,M[3].npC3) == 0){
								doi = 0;
								x=0;
								while(doi == 0){
									if(M[r].pC3 == NULL){
										if(r < 3) r++;
										else r=0;	
										x += 1;
									}else{ 
										if(M[r].pC3->level > XY){
											newCrystal(&M[I].pC1,M[I].npC1,M[r].pC3->level -1);
											M[I].npC1 += 1;
											M[I].HP -= t;
											if(M[r].pC3->nextCrystal != NULL){
												M[r].pC3 = M[r].pC3->nextCrystal;
												M[r].npC3 -= 1;
												deleteCrystal(NULL);
											}else{
												deleteCrystal(M[r].pC3);
												M[r].pC3 = NULL;
												M[r].npC3 = 0;
											}
											doi =1;
										}else{
											if(M[r].pC3->nextCrystal != NULL)
												M[r].pC3 = M[r].pC3->nextCrystal;
											else{
												if(r < 3) r++;
												else r=0;
												x += 1;
											}
										}
									}
									if(x == 4) doi = 1;
								}
							}
						}
					}
				}
			
			//while(kill == 0){
				if(M[I].pC1 == NULL){
					if(a < 3) a++;
					else a = 0;
					if(a != I) XY += 3;
					M[I].pC1 = M[a].pC1;
					h=h+1;
				}else{	
					if(XY > M[I].pC1->level){
						XY -= M[I].pC1->level;
						if(M[I].pC1->nextCrystal != NULL){
							M[I].pC1 = M[I].pC1->nextCrystal;
							M[I].npC1 --;
							deleteCrystal(NULL);
						}else{
							deleteCrystal(M[I].pC1);
							M[I].pC1=NULL;
							M[I].npC1=0;
							M[a].pC1=NULL;
							M[a].npC1=0;
							if(a<3) a++;
							else a=0;
							if(a != I) XY += 3;
							M[I].pC1 = M[a].pC1;
						}
					}else{
						(M[I].pC1)->level -= XY;
						if((M[I].pC1)->level == 0){
							if(M[I].pC1->nextCrystal != NULL){
								M[I].pC1 = M[I].pC1->nextCrystal;
								M[I].npC1 --;
								deleteCrystal(NULL);
							}else{
								deleteCrystal(M[I].pC1);
								M[I].pC1=NULL;
								M[I].npC1=0;
								M[a].pC1=NULL;
								M[a].npC1=0;
							}
						}
						kill =1;
					}
				}
				if(h == 4){
					if(firstnum == 3) dam = damage(XY,CERBERUS,I,ktrangto(XY));
					if(firstnum == 7) dam = damage(XY,IFRIT,I,ktrangto(XY));
					M[I].HP = max(M[I].HP - dam,0);
					kill = -1;
					
				}
			}
			
			if(M[I].HP <= 0){
				if(I < 3) I++;
				else I = 0;			
			}
			
		}
		
////////////////////////////////////////////		
		if(firstnum ==8  || firstnum == 9){
			a=I;
			while(kill == 0){
				if(kiemtra(M[0].npC3,M[1].npC3,M[2].npC3,M[3].npC3) == 1){
					t = chiahet(XY);
					if(I==3 && M[I].HP >= t){
						r=I;
						if(kiemtra(M[0].npC1,M[1].npC1,M[2].npC1,M[3].npC1) == 0){
							doi = 0;
							x = 0;
							while(doi == 0){
								if(M[r].pC1 == NULL){
									if(r < 3) r++;
									else r=0;
									x += 1;
								}else{ 
									if(M[r].pC1->level > XY){
										newCrystal(&M[I].pC3,M[I].npC3,M[r].pC1->level -1);
										M[I].npC3 += 1;
										M[I].HP -= t;
										if(M[r].pC1->nextCrystal != NULL){
											M[r].pC1 = M[r].pC1->nextCrystal;
											M[r].npC1 -= 1;
											deleteCrystal(NULL);
										}else{
											deleteCrystal(M[r].pC1);
											M[r].pC1 = NULL;
											M[r].npC1 = 0;
										}
										doi =1;
									}else{
										if(M[r].pC1->nextCrystal != NULL)
											M[r].pC1 = M[r].pC1->nextCrystal;
										else{
											if(r < 3) r++;
											else r=0;
											x +=1 ;
										}
									}
								}
								if(x == 4) doi =1;
							}
						}
						if(M[I].pC3 == NULL){
							if(kiemtra(M[0].npC2,M[1].npC2,M[2].npC2,M[3].npC2) == 0){
								doi = 0;
								x=0;
								while(doi == 0){
									if(M[r].pC2 == NULL){
										if(r < 3) r++;
										else r=0;	
										x += 1;
									}else{ 
										if(M[r].pC2->level > XY){
											newCrystal(&M[I].pC3,M[I].npC3,M[r].pC2->level -1);
											M[I].npC3 += 1;
											M[I].HP -= t;
											if(M[r].pC2->nextCrystal != NULL){
												M[r].pC2 = M[r].pC2->nextCrystal;
												M[r].npC2 -= 1;
												deleteCrystal(NULL);
											}else{
												deleteCrystal(M[r].pC2);
												M[r].pC2 = NULL;
												M[r].npC2 = 0;
											}
											doi =1;
										}else{
											if(M[r].pC1->nextCrystal != NULL)
												M[r].pC1 = M[r].pC1->nextCrystal;
											else{
												if(r < 3) r++;
												else r=0;
												x += 1;
											}
										}
									}
								if(x == 4) doi =1;
								}
							}
						}
					}
				}
			//while(kill == 0){
				if(M[I].pC3 == NULL){
					if(a < 3) a++;
					else a = 0;
					if(a != I) XY += 3;
					M[I].pC3 = M[a].pC3;
					h=h+1;
				}else{
					if(XY > M[I].pC3->level){
						XY -= M[I].pC3->level;
						if(M[I].pC3->nextCrystal != NULL){
							M[I].pC3 = M[I].pC3->nextCrystal;
							M[I].npC3 --;
							deleteCrystal(NULL);
						}else{
							deleteCrystal(M[I].pC3);
							M[I].pC3=NULL;
							M[I].npC3=0;
							M[a].pC3=NULL;
							M[a].npC3=0;
							if(a<3) a++;
							else a=0;
							if(a != I) XY += 3;
							M[I].pC3 = M[a].pC3;
						}
					}else{
						(M[I].pC3)->level -= XY;
						if((M[I].pC3)->level == 0){
							if(M[I].pC3->nextCrystal != NULL){
								M[I].pC3 = M[I].pC3->nextCrystal;
								M[I].npC3 --;
								deleteCrystal(NULL);
							}else{
								deleteCrystal(M[I].pC3);
								M[I].pC3=NULL;
								M[I].npC3=0;
								M[a].pC3=NULL;
								M[a].npC3=0;
							}
						}
						kill =1;
					}
				}
				if(h == 4){
					if(firstnum == 8) dam = damage(XY,LEVIATHAN,I,ktrangto(XY));
					if(firstnum == 9) dam = damage(XY,SIREN,I,ktrangto(XY));
					M[I].HP = max(M[I].HP - dam,0);
					kill = -1;
				}
					
			}
			if(M[I].HP <= 0){
				if(I < 3) I++;
				else I = 0;			
			}
			
		}
		
		
	}
	return 0;
}
int max(int a,int b)
{
	if(a<b)
		return b;
	else return a;
}
int min(int a,int b)
{
	if(a>b)
		return b;
	else return a;
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
 int damage(int XY,double fe,int I,int K)
 {
	int dam=0;
	dam = floor(pow(XY,fe) + (int)(floor(pow(fe,I) * K)) % 100);
	return dam;
 }
  int ktrangto(int n)
 {
	int i,h=0;
	for(i=n-1;i>1;i--)
		if(isprime(i)){
			h=i;
			return h;
		}
	return h;
 }
 int chiahet(int n)
 {
	int i;
	i = n + 1;
	while(i%3 != 0)
		i += 1;
	return i;
 }
  int kiemtra(int a,int b,int c,int d)
 {	
	if(a == 0 && b == 0 && c == 0 && d == 0)
		return 1;
	return 0;
 }

