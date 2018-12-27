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
    int i,j,k,c,l,dmin,st,poz,sol,ar,dist;
    for (i=1;i<=DIM;i++){
        c=getnr();
        l=getnr();
        v[i]=make_pair(l+DMAT/4,c+DMAT/4);
    }
    for (i=0;i<=DMAT;i++){
        for (j=0;j<=DMAT;j++){
            dmin=1000000000;
            st=0;
            poz=0;
            for (k=1;k<=DIM;k++){
                dist=modul(v[k].first-i)+modul(v[k].second-j);
                if (dist<dmin){
                    dmin=dist;
                    st=0;
                    poz=k;
                }
                else if (dist==dmin)
                    st=1;
            }
            if (st)
                a[i][j]=-1;
            else a[i][j]=poz;
            //printf ("%d ",a[i][j]);
        }
        //printf ("\n");
    }
    for (i=0;i<=DMAT;i++){
        f[a[i][0]]++;
        f[a[i][DMAT]]++;
        f[a[0][i]]++;
        f[a[DMAT][i]]++;
    }
    sol=0;
    for (k=1;k<=DIM;k++){
        if (f[k])
            continue;
        ar=0;
        for (i=1;i<=DMAT;i++){
            for (j=1;j<=DMAT;j++)
                if (a[i][j]==k)
                    ar++;
        }
        sol=max(sol,ar);
    }
    fprintf (fout,"%d",sol);
    return 0;
}
