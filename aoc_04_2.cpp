#include <cstdio>
#include <algorithm>
#define DIM 17

using namespace std;
struct ceva{
    long long nr;
    int tip;
};
ceva v[DIM+2];
int timp[5000][24*60];
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
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
int cmp (ceva x,ceva y){
    return x.nr<y.nr;
}
int main()
{
    int i,gc,j,maxi,val;
    char c;
    for (i=1;i<=DIM;i++){
        v[i].nr=(long long)getnr()*100000000+getnr()*1000000+getnr()*10000+getnr()*100+getnr();
        c=fgetc (fin);
        c=fgetc (fin);
        if (c=='w'){
            v[i].tip=-1;
        }
        else if (c=='f')
            v[i].tip=-2;
        else v[i].tip=getnr();
    }
    sort (v+1,v+DIM+1,cmp);
    for (i=1;i<=DIM;i++){
        if (v[i].tip>0){
            gc=v[i].tip;
        }
        else if (v[i].tip==-2){
            timp[gc][((v[i].nr/100)%100)*60 + (v[i].nr%100)] ++;
        }
        else {
            timp[gc][((v[i].nr/100)%100)*60 + (v[i].nr%100)] --;
        }
    }
    maxi=0;
    val=0;
    for (i=1;i<5000;i++){
        for (j=1;j<60;j++){
            timp[i][j]+=timp[i][j-1];
            if (timp[i][j]>maxi){
                maxi=timp[i][j];
                val=i*j;
            }
        }
    }
    fprintf (fout,"%d",val);
    return 0;
}
