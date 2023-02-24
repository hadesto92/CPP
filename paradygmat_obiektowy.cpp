#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double PI=3.1416;

struct czuroj
{
	float x1;
	float x2;
	float s;
	float r;
	float il;
	float ir;
};

struct czrzecz
{
	float x1;
	float x2;
	float s;
	float r;
	float il;
	float ir;
};

class rownanie
{
private:

	int * param;
	float d;
	float m;
    float fi;
	struct czrzecz r;
	struct czuroj u;

public:

   void formatuj_rownanie(class rownanie * r);
   float oblicz_d(int a , int b, int c);
   float obliczm(class rownanie * r);
   void oblicz_pierwiastki(class rownanie * r);
   void dodaj(class rownanie * r);
   void odejmij(class rownanie * r);
   void pomnoz(class rownanie * r);
   void podziel(class rownanie * r);
   void formatuj_lzesp(float x1r , float x1u);
   void wyswietl_wynik(class rownanie * r);
   float rad2st(float _fi);
   float obliczfi(int a,int b ,int c);
   rownanie(int a,int b ,int c );
   ~rownanie();

};

void rownanie::formatuj_rownanie(class rownanie * r)
{
    int a = param[0];
    int b = param[1];
    int c = param[2];


    printf("Wzor :\n");
    if (a > 0) {
			if (b > 0) {
				if (c > 0) {
					if (a == 1)
					if (b == 1) printf("xx+x+%d=0\n", c); //1 1 (>0)
					else printf("xx+%dx+%d=0\n", b, c); //1 (>0, !=1) (>0)
					else
					if (b == 1) printf("%dxx+x+%d=0\n", a, c); //(>0, !=1) 1 (>0)
					else printf("%dxx+%dx+%d=0\n", a, b, c); //(>0, !=1) (>0, !=1) (>0)
				}
				else if (c == 0) {
					if (a == 1)
					if (b == 1) printf("xx+x=0\n"); //1 1 0
					else printf("xx+%dx=0\n", b); //1 (>0, !=1) 0
					else
					if (b == 1) printf("%dxx+x=0\n", a); //(>0, !=1) 1 0
					else printf("%dxx+%dx=0\n", a, b); //(>0, !=1) (>0, !=1) 0
				}
				else { //c<0
					if (a == 1)
					if (b == 1) printf("xx+x-%d=0\n", -c); //1 1 (<0)
					else printf("xx+%dx-%d=0\n", b, -c); //1 (>0, !=1) (<0)
					else
					if (b == 1) printf("%dxx+x-%d=0\n", a, -c); //(>0, !=1) 1 (<0)
					else printf("%dxx+%dx-%d=0\n", a, b, -c); //(>0, !=1) (>0, !=1) (<0)
				}
			}
			else if (b == 0) {
				if (c > 0) {
					if (a == 1) printf("xx+%d=0\n", c); //1 0 (>0)
					else printf("%dxx+%d=0\n", a, c); //(>0, !=1) 0 (>0)
				}
				else if (c == 0) {
					if (a == 1) printf("xx=0\n"); //1 0 0
					else printf("%dxx=0\n", a); //(>0, !=1) 0 0
				}
				else { //c<0
					if (a == 1) printf("xx-%d=0\n", -c); //1 0 (<0)
					else printf("%dxx-%d=0\n", a, -c); //(>0, !=1) 0 (<0)
				}
			}
			else { //b<0
				if (c > 0) {
					if (a == 1)
					if (b == -1) printf("xx-x+%d=0\n", c); //1 -1 (>0)
					else printf("xx-%dx+%d=0\n", -b, c); //1 (<0, !=-1) (>0)
					else
					if (b == -1) printf("%dxx-x+%d=0\n", a, c); //(>0, !=1) -1 (>0)
					else printf("%dxx-%dx+%d=0\n", a, -b, c); //(>0, !=1) (<0, !=-1) (>0)
				}
				else if (c == 0) {
					if (a == 1)
					if (b == -1) printf("xx-x=0\n"); //1 -1 0
					else printf("xx-%dx=0\n", -b); //1 (<0, !=-1) 0
					else
					if (b == -1) printf("%dxx-x=0\n", a); //(>0, !=1) -1 0
					else printf("%dxx-%dx=0\n", a, -b); //(>0, !=1) (<0, !=-1) 0
				}
				else { //c<0
					if (a == 1)
					if (b == -1) printf("xx-x-%d=0\n", -c); //1 -1 (<0)
					else printf("xx-%dx-%d=0\n", -b, -c); //1 (<0, !=-1) (<0)
					else
					if (b == -1) printf("%dxx-x-%d=0\n", a, -c); //(>0, !=1) -1 (<0)
					else printf("%dxx-%dx-%d=0\n", a, -b, -c); //(>0, !=1) (<0, !=-1) (<0)
				}
			}
		}

		else if (a == 0) {
			if (b > 0) {
				if (c > 0) {
					if (b == 1) printf("x+%d=0\n", c); //0 1 (>0)
					else printf("%dx+%d=0\n", b, c); //0 (>0, !=1) (>0)
				}
				else if (c == 0) {
					if (b == 1) printf("x=0\n"); //0 1 0
					else printf("%dx=0\n", b); //0 (>0, !=1) 0
				}
				else {//c<0
					if (b == 1) printf("x-%d=0\n", -c); //0 1 (<0)
					else printf("%dx-%d=0\n", b, -c); //0 (>0, !=1) (<0)
				}
			}
			else if (b == 0) {
				if (c > 0) printf("%d=0\n", c); //0 0 (>0)
				else if (c == 0) printf("0=0\n"); //0 0 0
				else printf("-%d=0\n", -c); //0 0 (<0)
			}
			else {//b<0
				if (c > 0) {
					if (b == -1) printf("-x+%d=0\n", c); //0 -1 (>0)
					else printf("-%dx+%d=0\n", -b, c); //0 (<0, !=-1) (>0)
				}
				else if (c == 0) {
					if (b == -1) printf("-x=0\n"); //0 -1 0
					else printf("-%dx=0\n", -b); //0 (<0, !=-1) 0
				}
				else {//c<0
					if (b == -1) printf("-x-%d=0\n", -c); //0 -1 (<0)
					else printf("-%dx-%d=0\n", -b, -c); //0 (<0, !=-1) (<0)
				}
			}
		}

		else { //a<0
			if (b > 0) {
				if (c > 0) {
					if (a == -1)
					if (b == 1) printf("-xx+x+%d=0\n", c); //-1 1 (>0)
					else printf("-xx+%dx+%d=0\n", b, c); //-1 (>0, !=1) (>0)
					else
					if (b == 1) printf("-%dxx+x+%d=0\n", -a, c); //(<0, !=-1) 1 (>0)
					else printf("-%dxx+%dx+%d=0\n", -a, b, c); //(<0, !=-1) (>0, !=1) (>0)
				}
				else if (c == 0) {
					if (a == -1)
					if (b == 1) printf("-xx+x=0\n"); //-1 1 0
					else printf("-xx+%dx=0\n", b); //-1 (>0, !=1) 0
					else
					if (b == 1) printf("-%dxx+x=0\n", -a); //(<0, !=-1) 1 0
					else printf("-%dxx+%dx=0\n", -a, b); //(<0, !=-1) (>0, !=1) 0
				}
				else {//c<0
					if (a == -1)
					if (b == 1) printf("-xx+x-%d=0\n", -c); //-1 1 (<0)
					else printf("-xx+%dx-%d=0\n", b, -c); //-1 (>0, !=1) (<0)
					else
					if (b == 1) printf("-%dxx+x-%d=0\n", -a, -c); //(<0, !=-1) 1 (<0)
					else printf("-%dxx+%dx-%d=0\n", -a, b, -c); //(<0, !=-1) (>0, !=1) (<0)
				}
			}
			else if (b == 0) {
				if (c > 0) {
					if (a == -1) printf("-xx+%d=0\n", c); //-1 0 (>0)
					else printf("-%dxx+%d=0\n", -a, c); //(<0, !=-1) 0 (>0)
				}
				else if (c == 0) {
					if (a == -1) printf("-xx=0\n"); //-1 0 0
					else printf("-%dxx=0\n", -a); //(<0, !=-1) 0 0
				}
				else {//c<0
					if (a == -1) printf("-xx-%d=0\n", -c); //-1 0 (<0)
					else printf("-%dxx-%d=0\n", -a, -c); //(<0, !=-1) 0 (<0)
				}
			}
			else { //b<0
				if (c > 0) {
					if (a == -1)
					if (b == -1) printf("-xx-x+%d=0\n", c); //-1 -1 (>0)
					else printf("-xx-%dx+%d=0", -b, c); //-1 (<0, !=-1) (>0)
					else
					if (b == -1) printf("-%dxx-x+%d=0\n", -a, c); //(<0, !=-1) -1 (>0)
					else printf("-%dxx-%dx+%d=0\n", -a, -b, c); //(<0, !=-1) (<0, !=-1) (>0)
				}
				else if (c == 0) {
					if (a == -1)
					if (b == -1) printf("-xx-x=0\n"); //-1 -1 0
					else printf("-xx-%dx=0\n", -b); //-1 (<0, !=-1) 0
					else
					if (b == -1) printf("-%dxx-x=0\n", -a); //(<0, !=-1) -1 0
					else printf("-%dxx-%dx=0\n", -a, -b); //(<0, !=-1) (<0, !=-1) 0
				}
				else { //c<0
					if (a == -1)
					if (b == -1) printf("-xx-x-%d=0\n", -c); //-1 -1 (<0)
					else printf("-xx-%dx-%d=0\n", -b, -c); //-1 (<0, !=-1) (<0)
					else
					if (b == -1) printf("-%dxx-x-%d=0\n", -a, -c); //(<0, !=-1) -1 (<0)
					else printf("-%dxx-%dx-%d=0\n", -a, -b, -c); //(<0, !=-1) (<0, !=-1) (<0)
				}
			}
		}
}

float rownanie::oblicz_d(int a , int b, int c)
{
    float d;
    a = param[0];
    b = param[1];
    c = param[2];

	d=(float)(b*b-4*a*c); 
	return d;
}

float rownanie::obliczm(class rownanie * r)
{
    float m;
         m = sqrt( (r->r.x1 * r->r.x1) + (r->u.x1 * r->u.x1) );
         return m;
}

void rownanie::oblicz_pierwiastki(class rownanie * r)
{
    int a = param[0];
    int b = param[1];
    int c = param[2];

    int zmienna =0;

    if(a != 0)
    {
        if (r->d > 0) 
        {
			 r->r.x1=(float)(-b - sqrt(r->d)) / (2 * a);
             r->r.x2=(float)(-b + sqrt(r->d)) / (2 * a);
		}
			if (r->d == 0) 
            {
                r->r.x1= (float)-b / (2 * a);
			}
			if (r->d < 0)
            {
             r->r.x1 = (float)-b / (2 * a);
			 r->r.x2 = (float)-b / (2 * a);
             r->u.x1 = (float)-sqrt(fabs(r->d)) / (2 * a);
             r->u.x2 = (float)-(-sqrt(fabs(r->d)) / (2 * a));

              r->m  = obliczm(r);
              r->fi = obliczfi(a,b,c);
            }
    }
    else
    { //a=0
			if (b != 0) 
            {
               r->r.x1=(float)-c / b;
			}
	}
}

void rownanie::dodaj(class rownanie * r)
{
    if( r->d > 0)
    {
		r->r.s = r->r.x1 + r->r.x2;
    }
    else if(r->d < 0)
    {
        r->r.s = r->r.x1 + r->r.x2;
		r->u.s = r->u.x1 + r->u.x2;
    }
}

void rownanie::odejmij(class rownanie * r)
{
    if( r->d > 0)
    {
        r->r.r = r->r.x1 - r->r.x2;
    }
    else if(r->d < 0)
    {
        r->r.r = r->r.x1 - r->r.x2;
        r->u.r = r->u.x1 - r->u.x2;
    }
}

void rownanie::pomnoz(class rownanie * r)
{
    if( r->d > 0)
    {
		r->r.il = r->r.x1 * r->r.x2;
    }
    else if(r->d < 0)
    {
        r->r.il = (r->r.x1 * r->r.x2) - (r->u.x1 * r->u.x2);
        r->u.il = (r->r.x1 * r->u.x2) + (r->r.x2 * r->u.x1);
    }
}

void rownanie::podziel(class rownanie * r)
{
	if( r->d > 0)
    {
		r->r.ir = r->r.x1/r->r.x2; 
    }
	else if(r->d < 0)
    {
    r->r.ir = ( (r->r.x1 * r->r.x2) + (r->u.x1 * r->u.x2) )/( (r->r.x2 * r->r.x2)+(r->u.x2 * r->u.x2) );
	r->u.ir = ( (r->u.x1 * r->r.x2) - (r->r.x1 * r->u.x2) )/( (r->r.x2 * r->r.x2)+(r->u.x2 * r->u.x2) );
    }
}

void rownanie::formatuj_lzesp(float x1r , float x1u)
{
				if (x1r > 0)
                {
				    if (x1u > 0)
                    {
				            if (x1u == 1) 
                            {

                                printf(" %f+i\n", x1r);
                            }
				            else 
                            {
                                printf(" %f+%fi\n", x1r, x1u);
                            }
                    }
                    else if(x1u == 0)
                    {
                        printf(" %f\n", x1r);
                    }
				     else //x1u<0
                     {
				            if (x1u == -1)
                            {
                                printf(" %f-i\n", x1r);
                            }
				            else 
                            {
                                printf(" %f-%fi\n", x1r, -x1u);
                            }
                     }
                }
			    else if (x1r == 0)
                {
				        if (x1u > 0)
                        {
				            if (x1u == 1) 
                            {
                                printf(" i\n");
                            }
				            else
                            {
                                printf(" %fi\n", x1u);
                            }
                        }
                        else if(x1u == 0)
                        {
                            printf("0\n");
                        }
				        else  //x1u<0
                        {
				            if (x1u == -1) 
                            {
                                printf(" -i\n");
                            }
				            else
                            {
                                printf(" -%fi\n", -x1u);
                            }
                        }
                }
				else //x1r<0
                {
				    if (x1u > 0)
                    {
				        if (x1u == 1)
                        {
                            printf(" -%f+i\n", -x1r);
                        }
				        else
                        {
                            printf(" -%f+%fi\n", -x1r, x1u);
                        }
                    }
                    else if(x1u == 0)
                    {
                        printf(" -%f\n",-x1r);
                    }
				    else //x1u<0
                    {
				        if (x1u == -1)
                        {
                            printf(" -%f-i\n", -x1r);
                        }
				        else 
                        {
                            printf(" -%f-%fi\n", -x1r, -x1u);
                        }
                    }
                }
               
}

void rownanie::wyswietl_wynik(class rownanie * r)
{
    int a = r->param[0];
    int b = r->param[1];
    int c = r->param[2];

    if(a != 0)
    {
            printf("Delta : %f\n", r->d);
            if (r->d > 0) 
            {
				printf("Pierwiastek1=%f, Pierwiastek2=%f\n", r->r.x1, r->r.x2);
				printf("Suma : %f\n" , r->r.s);
                printf("Roznica : %f\n" , r->r.r);
                printf("Iloczyn : %f\n" , r->r.il);
                printf("Iloraz : %f\n" , r->r.ir);
		    }
			if (r->d == 0) 
            {
				printf("x1r=%f\n", r->r.x1);
			}
			if (r->d < 0)
            {
                printf("Pierwiastek1: ");
				formatuj_lzesp(r->r.x1, r->u.x1);
                
			    printf("Pierwiastek2: ");
                formatuj_lzesp(r->r.x2, r->u.x2);

			    printf("Suma :"); 
                formatuj_lzesp(r->r.s, r->u.s);

			    printf("Roznica :");
                formatuj_lzesp(r->r.r, r->u.r);

			    printf("Iloczyn :"); 
                formatuj_lzesp(r->r.il, r->u.il);

			    printf("Iloraz :"); 
                formatuj_lzesp(r->r.ir, r->u.ir);

                printf("Modul liczby zespolonej : %f\n",r->m);
                if(b>=0)
                {
					if(r->m==1)
                    {
						printf("Postac trygonometryczna : (cos(%f)+i*sin(%f) )\n",r->fi ,r->fi);
					}
					if(r->m==-1)
                    {
						printf("Postac trygonometryczna : -(cos(%f)+i*sin(%f) )\n",r->fi ,r->fi);
					}
					if((r->m>0)&&(r->m!=1)||(r->m<0)&&(r->m!=-1))
                    {
						printf("Postac trygonometryczna : %f(cos(%f)+i*sin(%f) )\n",r->m ,r->fi ,r->fi);//3.0f przy m
					}
				}
				else
                {
					if(r->m==1)
                    {
						printf("Postac trygonometryczna : (cos(%f)+i*sin(%f))\n",r->fi ,r->fi);
					}
					if(r->m==-1)
                    {
						printf("Postac trygonometryczna : -(cos(%f)+i*sin(%f))\n",r->fi ,r->fi);
					}
					if((r->m>0)&&(r->m!=1)||(r->m<0)&&(r->m!=-1))
                    {
						printf("Postac trygonometryczna : %f(cos(%f)+i*sin(%f))\n",r->m ,r->fi ,r->fi);//3.0f przy m
					}
				}
            }
      }
       else
        { //a=0
			if (b != 0) 
            {
				if (r->r.x1 == 0)
                {
                    printf("x1r=0\n");
                }
				else 
                {
                    printf("x1r=%f\n", r->r.x1);
                }
			}
			else 
            {//b=0
			    if (c != 0)
                {		
                    printf("rownanie sprzeczne\n");
                }
			    else //c=0
                {
                    printf("rowanie tozsamosciowe\n");
                }
            }
	}
}

rownanie::rownanie( int a,int b ,int c  )
{
    m = 0;
    param = new int[3];
    param[0] = a;
    param[1] = b;
    param[2] = c;
    d = oblicz_d(param[0] , param[1] ,param[2] );

}

float rownanie::rad2st(float _fi)
{
    
	fi=( (180/PI) * _fi);
	
	return fi;
}

float rownanie::obliczfi(int a,int b ,int c )
{


	if((b>=0)&&(m!=0)){

		fi = acos(r.x1/m);

	}
	if((b<0)&&(m!=0)){

		fi = -(acos(r.x2/m));

	}


	fi = rad2st(fi);


	return fi;
}


rownanie::~rownanie()
{

    delete [] param;

}

int main()
{
    int i;
    int tab[3];
    printf("Wprowadz  a,b,c :\n");
    for(i=0;i<3;i++)
    {
        scanf_s("%d" , &tab[i]);
    }

    rownanie * rown = new rownanie( tab[0],tab[1] ,tab[2] );
		rown->formatuj_rownanie(rown);
        rown->oblicz_pierwiastki(rown);
        rown->dodaj(rown);
        rown->odejmij(rown);
        rown->pomnoz(rown);
        rown->podziel(rown);
        rown->wyswietl_wynik(rown);
	printf("\n");
    delete rown ;
	system("pause");
	return 0;
}