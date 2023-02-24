// Lab3.cpp : Defines the entry point for the console application.
// klach

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct czrzecz
{
	float x1,x2,s,r,il,ir;
};

struct czuroj
{
	float x1,x2,s,r,il,ir;
};

struct rownanie
{
	int * param; //a,b,c
	float d,m;
	struct czrzecz r;
	struct czuroj u;
};

float obliczm(struct rownanie * r){
	float m;

    m = sqrt( (r->r.x1 * r->r.x1) + (r->u.x1 * r->u.x1) );

	return m;
}

void formatuj_rownanie(struct rownanie * r){
	
	(r->param)-=2; 
    int a = *(r->param);
    (r->param)++;
    int b = *(r->param);
    (r->param)++;
    int c = *(r->param);

	if((a==0)&&(b==0)&&(c==0)){
		printf("0=0 \n");
	}
	else if((a==0)&&(b==0)){
		if((c==-1)||(c==1)||(c<-1)||(c>1)){
			printf("%d=0 \n",c);
			printf("To rownanie jest sprzeczne! \n");
			
			getchar();
			getchar();
			
		}
	}
	else{
		if(a==1){
			printf("xx");
		}
		if(a==-1){
			printf("-xx");
		}
		if((a>1)||(a<-1)){
			printf("%dxx",a);
		}
		if(b==1){
			if(a==0){
				printf("x",b);
			}
			else{
				printf("+x",b);
			}
		}
		if(b==-1){
			printf("-x");
		}
		if(b>1){
			if(a==0){
				printf("%dx",b);
			}
			else{
				printf("+%dx",b);
			}
		}
		if(b<-1){
			printf("%dx",b);
		}
		if(c==0){
			printf("=0 \n");
		}
		if((c==1)||(c>1)){
			printf("+%d=0 \n",c);
		}
		if((c==-1)||(c<-1)){
			printf("%d=0 \n",c);
		}
	}
}

void formatuj_liczbe_zespolona(float x1r, float x1u){

			if(((x1r>0)&&(x1r!=1))||((x1r<0)&&(x1r!=-1))){
				if(x1u==-1){
					printf("%3.2f-i \n",x1r);
				}
				if(x1u==1){
					printf("%3.2f+i \n",x1r);
				}
				if((x1u>0)&&(x1u!=1)){
					printf("%3.2f+%3.2f*i \n",x1r,x1u);
				}
				if((x1u<0)&&(x1u!=-1)){
					printf("%3.2f%3.2f*i \n",x1r,x1u);
				}
				if(x1u==0){
					printf("%3.2f \n",x1r);
				}
			}
			if(x1r==0){
				if(x1u==-1){
					printf("-i \n");
				}
				if(x1u==1){
					printf("i \n");
				}
				if((x1u>0)&&(x1u!=1)){
					printf("%3.2f*i \n",x1u);
				}
				if((x1u<0)&&(x1u!=-1)){
					printf("%3.2f*i \n",x1u);
				}
				if(x1u==0){
					printf("brak \n");
				}
			}
			if((x1r==1)||(x1r==-1)){
				if(x1u==-1){
					printf("%3.2f-i \n",x1r);
				}
				if(x1u==1){
					printf("%3.2f+i \n",x1r);
				}
				if((x1u>0)&&(x1u!=1)){
					printf("%3.2f+%3.2f*i \n",x1r,x1u);
				}
				if((x1u<0)&&(x1u!=-1)){
					printf("%3.2f%3.2f*i \n",x1r,x1u);
				}
				if(x1u==0){
					printf("%3.2f \n",x1r);
				}
				}


}

float oblicz_d(struct rownanie * r){
	float d;

	int a = *(r->param);
    (r->param)++;
    int b = *(r->param);
    (r->param)++;
    int c = *(r->param);

	d=(((float)b*(float)b)-(4*(float)a*(float)c));

	return(d);
}

void oblicz_pierwiastki(struct rownanie * r){

	float d;

	(r->param)-=2; 
    int a = *(r->param);
    (r->param)++;
    int b = *(r->param);
    (r->param)++;
    int c = *(r->param);

	if(a!=0){

		if(r->d>0){
			r->r.x1=(-((float)b)-(sqrt(r->d))/(2*(float)a));
			r->r.x2=(-((float)b)+(sqrt(r->d))/(2*(float)a));
		}
		if(r->d==0){
			r->r.x1=((-(float)b/((float)a*2)));
		}
		if(r->d<0){

			r->r.x1=((-(float)b/((float)a*2)));
			r->u.x1=((0-(sqrt(-(r->d))))/(2*(float)a));
			r->r.x2=((-(float)b/((float)a*2)));
			r->u.x2=-((0-(sqrt(-(r->d))))/(2*(float)a));
			r->m  = obliczm(r);
		}
	}
	if(a==0){
		if(b!=0){
			r->r.x1=((-((float)c))/(float)b);
		}
	}


}

void dodaj(struct rownanie * r){

	if((r->d>0)){
		r->r.s = r->r.x1 + r->r.x2;
	}
	if((r->d<0)){
		r->r.s = r->r.x1 + r->r.x2;
		r->u.s = r->u.x1 + r->u.x2;
	}
}

void odejmnij(struct rownanie * r){

	if((r->d>0)){
		r->r.r = r->r.x1 - r->r.x2;
	}
	if((r->d<0)){
		r->r.r = r->r.x1-r->r.x2;
		r->u.r = r->u.x1-r->u.x2;
	}
}

void pomnoz(struct rownanie * r){

	if((r->d>0)){
		r->r.il = r->r.x1 * r->r.x2;
	}
	if((r->d<0)){
		r->r.il = (r->r.x1 * r->r.x2) - (r->u.x1 * r->u.x2);
		r->u.il = (r->r.x1 * r->u.x2) + (r->r.x2 * r->u.x1);
	}
}

void podziel(struct rownanie * r){

	if((r->d>0)){
		r->r.ir = r->r.x1/r->r.x2;
	}
	if(r->d < 0){
		r->r.ir = ( (r->r.x1 * r->r.x2) + (r->u.x1 * r->u.x2) )/( (r->r.x2 * r->r.x2)+(r->u.x2 * r->u.x2) );
		r->u.ir = ( (r->u.x1 * r->r.x2) - (r->r.x1 * r->u.x2) )/( (r->r.x2 * r->r.x2)+(r->u.x2 * r->u.x2) );
	}
}

void wyswietl_wynik(struct rownanie * r){

	(r->param)-=2; 
    int a = *(r->param);
    (r->param)++;
    int b = *(r->param);
    (r->param)++;
    int c = *(r->param);

	if(a != 0)
    {
            printf("Delta : %3.2f\n", r->d);
            if (r->d > 0) 
            {
				printf("Pierwiastek x1= %3.2f\n", r->r.x1); 
				printf("Pierwiastek x2= %3.2f\n", r->r.x2);
				printf("Dodawanie : %3.2f\n" , r->r.s);
                printf("Odejmowanie : %3.2f\n" , r->r.r);
                printf("Mnorzenie : %3.2f\n" , r->r.il);
                printf("Dzielenie : %3.2f\n" , r->r.ir);
		    }
			if (r->d == 0) 
            {
				printf("x1r=%f\n", r->r.x1);
			}
			if (r->d < 0)
            {
                printf("Pierwiastek x1: ");
				formatuj_liczbe_zespolona(r->r.x1, r->u.x1);
                
			    printf("Pierwiastek x2: ");
                formatuj_liczbe_zespolona(r->r.x2, r->u.x2);

			    printf("Dodawanie :"); 
                formatuj_liczbe_zespolona(r->r.s, r->u.s);

			    printf("Odejmowanie :");
                formatuj_liczbe_zespolona(r->r.r, r->u.r);

			    printf("Mnorzenie :"); 
                formatuj_liczbe_zespolona(r->r.il, r->u.il);

			    printf("Dzielenie :"); 
                formatuj_liczbe_zespolona(r->r.ir, r->u.ir);

                printf("Modul liczby zespolonej : %3.2f\n",r->m);
            }
      }
       else
        { 
			if (b != 0) 
            {
				if (r->r.x1 == 0)
                {
                    printf("x1r=0\n");
                }
				else 
                {
                    printf("x1r=%3.2f\n", r->r.x1);
                }
			}
			else 
            {
			    if (c != 0)
                {		
                    printf("rownanie sprzeczne\n");
                }
			    else
                {
                    printf("rowanie tozsamosciowe\n");
                }
            }
	}

	getchar();
	getchar();


}

int _tmain(int argc, _TCHAR* argv[])
{

	struct rownanie * rown;
	rown = (rownanie*)malloc(sizeof( rownanie));
    int * tab = (int*)malloc(3*sizeof(int));

	printf("Podaj a: ");
	scanf_s("%i", &tab[0]);
	printf("\nPodaj b: ");
	scanf_s("%i", &tab[1]);
	printf("\nPodaj c: ");
	scanf_s("%i", &tab[2]);

	rown->param = tab;
	rown->d=oblicz_d(rown);

	formatuj_rownanie(rown);
	oblicz_pierwiastki(rown);
	//formatuj_liczbe_zespolona(rown);
	dodaj(rown);
	odejmnij(rown);
	pomnoz(rown);
	podziel(rown);

	wyswietl_wynik(rown);

	getchar();
	getchar();
	

	return 0;
}

