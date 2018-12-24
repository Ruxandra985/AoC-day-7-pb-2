#include <cstdio>
#include <iostream>
#define DIM 1409

using namespace std;
int a[5001][5001];
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
inline int getnr(){
    int nr=0;
    int semn=1;
    char c;
    c=fgetc (fin);
    while ('0'>c || '9'<c){
        if (c=='-')
            semn=-1;
        c=fgetc (fin);
    }
    while ('0'<=c && c<='9'){
        nr=nr*10+c-'0';
        c=fgetc (fin);
    }
    return nr*semn;
}
int main()
{
    int i,id,col,lin,nrc,nrl,j,k,sol,maxi;
    for (i=1;i<=DIM;i++){
        id=getnr();
        col=getnr();
        lin=getnr();
        nrc=getnr();
        nrl=getnr();
        for (j=0;j<nrl;j++){
            for (k=0;k<nrc;k++)
                a[lin+j][col+k]++;
        }
    }
    fclose(fin);
    fin=fopen ("a.in","r");
    for (i=1;i<=DIM;i++){
        id=getnr();
        col=getnr();
        lin=getnr();
        nrc=getnr();
        nrl=getnr();
        maxi=0;
        for (j=0;j<nrl;j++){
            for (k=0;k<nrc;k++)
                maxi=max(maxi,a[j+lin][k+col]);
        }
        if (maxi==1){
            fprintf (fout,"%d",i);
            return 0;
        }
    }
    fprintf (fout,"%d",sol);
    return 0;
}
