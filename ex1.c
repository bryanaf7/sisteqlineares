#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define n 4

void somarl(float m[][n+1],int p,int i,float lambda)
{int j;
	for(j=p;j<n+1;j++)
	m[i][j]-=lambda*m[p][j];

	return;
}



void trocar(float m[][n+1],int a,int b)
{float aux;
int j;

	for(j=0;j<n+1;j++)
	{aux=m[a][j];
	m[a][j]=m[b][j];
	m[b][j]=aux;}
}


void pivoteamento(float m[][n+1],int p)
{int i,max;
max=p;




	for(i=p+1;i<n;i++)
	{
	if(fabs(m[i][p]))>fabs(m[max][p]))
	m=i;
	}

trocar(m,p,max);
return;
}




void gaussjordan(float m[][n+1],float x[])
{float lambda;
int i,p,j=0;





	//MATRIZ TRIANGULAR
	for(p=0;p<n-1;p++){

	pivoteamento(m,p);
	
		for(i=p+1;i<n;i++){
		lambda=m[i][p]/m[p][p];
		somarl(m,p,i,lambda);
		}
	}
	
	//printando matriz triangular
	for(i=0;i<4;i++){
		for(j=0;j<5;j++)
		printf("%f\t",m[i][j]);

	printf("\n");
	}

	//substituíção
	for(i=n-1;i>=0;i--)
	{
	x[i]=m[i][4];
	
	j=i+1;
		while(j<n)
		{x[i]-=m[i][j]*x[j];
		j++;}
	x[i]=x[i]/m[i][i];
	}


	//print solução
	for(i=0;i<n;i++)
	printf("\n%f\n",x[i]);
return;

	
}
		



int main(){

float m[n][n+1],x[n];
int i,j;
FILE *fp=fopen("matriz.dat","r");


	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++)
		fscanf(fp,"%f",&m[i][j]);
	}

gaussjordan(m,x);




}




/*	for(i=0;i<4;i++){
		for(j=0;j<5;j++)
		printf("%f\n",m[i][j]);
	}
}*/
