#include <iostream>
using namespace std;
 
int main(){
	//Ni为指数，aNi为系数 
	typedef struct poly{
		int Ni; 
		double aNi;
	} poly; 
	
	poly poly1[15]={0},poly2[15]={0},poly3[30]={0};
	int k1=0,k2=0,k3=0;
	
	scanf("%d",&k1);
	for(int i = 1;i<=k1;i++){
		scanf("%d%lf",&poly1[i].Ni,&poly1[i].aNi);
	}
	scanf("%d",&k2);
	for(int i = 1;i<=k2;i++){
		scanf("%d%lf",&poly2[i].Ni,&poly2[i].aNi);
	}
	
	while(k1&&k2){
		//指数相等，和的指数等于1式指数，和的系数等于1式2式的系数和 
		if(poly1[k1].Ni==poly2[k2].Ni){
			//注意若两个多项式系数刚好为相反数时，和会减少一项 
			if(poly1[k1].aNi+poly2[k2].aNi!=0){
				poly3[k3].Ni=poly1[k1].Ni;
				poly3[k3].aNi=poly1[k1].aNi+poly2[k2].aNi;
				k3++;
			}
			k1--;k2--;
		}
		//将指数低的项存入和多项式 数组 
		else if(poly1[k1].Ni<poly2[k2].Ni){
			poly3[k3].Ni=poly1[k1].Ni;
			poly3[k3].aNi=poly1[k1].aNi;
			k1--;k3++;
		}
		else{
			poly3[k3].Ni=poly2[k2].Ni;
			poly3[k3].aNi=poly2[k2].aNi;
			k2--;k3++;
		}
	}
	//将剩余项存入和多项式数组 
	while(k1){
		poly3[k3].Ni=poly1[k1].Ni;
		poly3[k3].aNi=poly1[k1].aNi;
		k1--;k3++;
	}
	while(k2){
		poly3[k3].Ni=poly2[k2].Ni;
		poly3[k3].aNi=poly2[k2].aNi;
		k2--;k3++;
	}
	//输出和多项式 
	printf("%d",k3);
	while(k3){
		printf(" %d %0.1f",poly3[k3-1].Ni,poly3[k3-1].aNi);
		k3--;
	}
}
