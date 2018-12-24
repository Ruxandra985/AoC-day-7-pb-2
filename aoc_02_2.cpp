#include <cstdio>
#include <cstring>
#define DIM 250

using namespace std;
int f[30];
char v[DIM+10][50];
int ok (int i,int j){
    int k,st=0;
    for (k=0;k<=25;k++){
        if (v[i][k]!=v[j][k])
            st++;
    }
    if (st==1)
        return 1;
    return 0;
}
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,a2,a3,s2,s3,j,k;
    char c;
    a2=a3=0;
    for (j=1;j<=DIM;j++){
        fscanf (fin,"%s",v[j]);
    }
    for (i=1;i<=DIM;i++){
        for (j=1;j<=DIM;j++){
            if (ok(i,j)){
                for (k=0;k<=25;k++){
                    if (v[i][k]==v[j][k])
                        fputc(v[i][k],fout);
                }
                return 0;
            }
        }
    }
    //fprintf (fout,"%d",a2*a3);
    return 0;
}
