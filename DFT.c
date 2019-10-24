#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define PI 3.141592653589793     // 円周率

int main(int argc, char *argv[])
{  
	
	int k, n, N;
    int max = 20000;  // 読み込むデータ数の上限
    double f[max+1], re, im, a;

    FILE *fp1, *fp2;
    // ファイルオープン(フーリエ変換したいデータファイル, フーリエ変換後のデータ保存用ファイル)
    if((fp1=fopen(argv[1],"r"))==NULL){
        printf("Input File can not open\n");
    	system("pause"); 
        return -1;
    }
	
	strcat(argv[1], "_dft.csv");
    if((fp2=fopen(argv[1],"w"))==NULL){
        printf("Output File can not open\n");
    	system("pause"); 
        return -1;
    }
	
	N=0;
	while((fscanf(fp1,"%lf,%lf", &a, &f[N]) != EOF) && (N < max)){
		N++;
	}
	
    //実数部分と虚数部分に分けてフーリエ変換
    for(n=0; n<N; n++) {
        double re = 0.;
        double im = 0.;
        for(k=0; k<N; k++) {
            re += f[k]*cos(2*PI*k*n/N);
            im += -f[k]*sin(2*PI*k*n/N);
        }
        fprintf(fp2,"%d, %.16lf, %.16lf,%.16lf\n", n, re/N, im/N, sqrt(re*re + im*im)/N);
    	printf("%d\n", n);
    }

    fclose(fp1);
    fclose(fp2);
	//任意のキー入力で終了
	//printf("\n");
	//system("pause"); 
    return 0;
}
