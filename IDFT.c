#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define pi 3.1415926535         // 円周率

int main(int argc, char *argv[])
{  
	int i, k, n, N, a;
	int max = 20000;  // 読み込むデータ数の上限
	double Re[max+1], Im[max+1], re, im, b;

	FILE *fp1, *fp2;
	if((fp1=fopen(argv[1],"r"))==NULL){
		printf("FILE1 not open\n");
		system("pause"); 
		return -1;
	}
	
	strcat(argv[1], "_idft.csv");
	if((fp2=fopen(argv[1],"w"))==NULL){
		printf("FILE2 not open\n");
		system("pause"); 
		return -1;
	}
	//データの読み込み
	for(N=0;N<max;N++) {
	        if(fscanf(fp1,"%d, %lf, %lf, %lf", &i, &Re[N], &Im[N], &b) == EOF) {
	                N--;
	                break;
	        }
	}
	printf("データ数：%d\n\n", N);
	printf("n次成分までを合成\n");
	printf("n=");
	scanf("%d", &a);
	
	if(a >= N){
		printf("Input Error\n");
		system("pause"); 
		return -1;
	}
	
	//実数部分と虚数部分に分けて逆フーリエ変換
	for(k=0; k<N; k++) {
	        double re = 0.0;
	        double im = 0.0;
	        for(n=0; n<a; n++) {
	                re += (Re[n]*cos(2*pi*k*n/N)-Im[n]*sin(2*pi*k*n/N));
	                im += (Re[n]*sin(2*pi*k*n/N)+Im[n]*cos(2*pi*k*n/N)); 
	    	}
			fprintf(fp2,"%d, %.16lf, %.16lf, %.16lf\n", k, re, im, 2*sqrt(re*re + im*im));
			printf("%d\n", k);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}