#include <cstdio>
#include <algorithm>
#define DIM 50
#define DMAT 2000
using namespace std;
int a[DMAT+1][DMAT+1],f[DIM+10];
pair <int,int> v[DIM+10];
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
int modul (int x){
    if (x<0)
        return -x;
    return x;
}
int getnr(){
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
    int i,j,k,c,l,dmin,st,poz,sol,ar,dist,sum;
    for (i=1;i<=DIM;i++){
        c=getnr();
        l=getnr();
        v[i]=make_pair(l+DMAT/4,c+DMAT/4);
    }
    sol=0;
    for (i=0;i<=DMAT;i++){
        for (j=0;j<=DMAT;j++){
            sum=0;
            for (k=1;k<=DIM;k++){
                sum+=modul(v[k].first-i)+modul(v[k].second-j);

            }
            if (sum<10000)
                sol++;
            //printf ("%d ",a[i][j]);
        }
        //printf ("\n");
    }

    fprintf (fout,"%d",sol);
    return 0;
}
