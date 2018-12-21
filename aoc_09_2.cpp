#include <cstdio>
#include <iostream>

using namespace std;
long long scor[500];
int urm[8000000],ant[8000000];
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int n,m,mc,lc,juc,i,poz,j,x,y;
    long long maxi;
    fscanf (fin,"%d%d",&n,&m);
    m*=100;
    juc=1;
    mc=1;
    lc=2;
    urm[0]=1;
    urm[1]=0;
    for (i=2;i<=m;i++){
        //printf ("%d ",i);
        /*x=0;
        do{
            printf ("%d ",x);
            x=urm[x];
        }
        while (x!=0);
        printf ("\n");*/
        juc++;
        if (juc>n)
            juc=1;
        if (i%23!=0){
            //poz=pc+2;
            //if (poz>lc+1)
                //  poz-=lc;
            lc++;
            x=urm[mc];
            y=urm[x];
            urm[x]=i;
            urm[i]=y;
            ant[y]=i;
            ant[i]=x;
            mc=i;
        }
        else {
            //printf ("%d ",i/23);
            scor[juc]+=i;
            //printf ("%d ",i);
            x=mc;
            for (j=1;j<=8;j++)
                x=ant[x];
            //x=urm[x];
            lc--;
            scor[juc]+=urm[x];
            ant[urm[urm[x]]]=x;
            urm[x]=urm[urm[x]];
            mc=urm[x];
        }
    }
    maxi=0;
    for (i=1;i<=n;i++)
        maxi=max(maxi,scor[i]);
    fprintf (fout,"%lld",maxi);
    return 0;
}
