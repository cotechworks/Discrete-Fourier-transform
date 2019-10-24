#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define PI 3.141592653589793     // �~����

int main(int argc, char *argv[])
{  
	
	int k, n, N;
    int max = 20000;  // �ǂݍ��ރf�[�^���̏��
    double f[max+1], re, im, a;

    FILE *fp1, *fp2;
    // �t�@�C���I�[�v��(�t�[���G�ϊ��������f�[�^�t�@�C��, �t�[���G�ϊ���̃f�[�^�ۑ��p�t�@�C��)
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
	
    //���������Ƌ��������ɕ����ăt�[���G�ϊ�
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
	//�C�ӂ̃L�[���͂ŏI��
	//printf("\n");
	//system("pause"); 
    return 0;
}
