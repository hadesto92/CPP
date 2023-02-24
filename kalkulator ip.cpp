#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
//192.168.204.109
//192 168 204 109
//255.255.255.0
//int tab1[4]={0,0,0,0};
//int tab2[4]={0,0,0,0},j=0;
int tab1[4]={192,168,204,109};
int tab2[4]={255,255,0,0},j=0;
unsigned int tab3[4]={0,0,0,0};
unsigned int tab4[4]={0,0,0,0};
int zm=1,i=0,zmm1=0,zmm2=0;
unsigned int zmm3=0, zmm4=0,zmienna=1;

int main(){
    printf("Podaj ilosc testow\n");
	 scanf("%d",&zm);
	while(zm!=0){
        printf("Podaj adres IP oraz maske (po spacjach)\n");
		//scanf("%d %d %d %d %d %d %d\n",&tab1[0],&tab1[1],&tab1[2],&tab1[3],&tab2[0],&tab2[1],&tab2[2],&tab2[3]);
		//scanf("%d %d %d %d\n",&tab1[0],&tab1[1],&tab1[2],&tab1[3]);
		scanf("%d %d %d %d",&tab2[0],&tab2[1],&tab2[2],&tab2[3]);
		cout<<endl;
		zmm1=(tab1[0]<<24)|(tab1[1]<<16)|(tab1[2]<<8)|(tab1[3]<<0);
		zmm2=(tab2[0]<<24)|(tab2[1]<<16)|(tab2[2]<<8)|(tab2[3]<<0);
		zmm3=zmm1 & zmm2;
		zmm4=zmm3 | 0xff;
		tab3[0]=zmm3>>24;
		tab3[1]=(zmm3<<8)>>24;
		tab3[2]=(zmm3<<16)>>24;
		tab3[3]=(zmm3<<24)>>24;

		tab4[0]=zmm4>>24;
		tab4[1]=(zmm4<<8)>>24;
		tab4[2]=(zmm4<<16)>>24;
		tab4[3]=(zmm4<<24)>>24;
		for(i =0;i<4;i++){
			printf("%d ",tab1[i]);    
		}
		printf("\n");
		for(i =0;i<4;i++){
			printf("%d.",tab3[i]);                     
		}
		printf("\n");
		for(i =0;i<4;i++){
			printf("%d.",tab4[i]);                     
		}
		//printf("\n%x \n",zmm1);                          
		//printf("\nzmm2: %i \n",zmm2);
		// printf("\n%x \n",zmm3);                                                                      
		tab3[3]++;
		printf("\n");
		for(i =0;i<4;i++){
			printf("%d.",tab3[i]);                     
		}    
		printf("-");
		tab4[3]--;
		for(i =0;i<4;i++){
			printf("%d.",tab4[i]);                     
		}
		for(i =0;i<4;i++){
			if(tab2[i]==0) j++;
		}
		zmienna=pow((double) 2,(8*j));
		printf("\n%u \n\n",zmienna-2);
		getchar();    
		getchar();    
		getchar();    
		getchar();  
		zm--;

	}     
	
	getchar(); 
	return 0;        
}
