#include <cstdio>
#include <iostream>
#include <cstring>
#define INF 1000000000
#define DIM 1000

using namespace std;
struct ceva{
    long long x,y,z,raza;
};
ceva v[DIM+10];
int f[DIM+10];
long long intersect[DIM+10];
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
inline long long getnr(){
    long long nr=0;
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
long long modul (long long a){
    if (a<0)
        return -a;
    return a;
}
int main()
{
    int i,sol,sc,j,poz,ok;
    long long maxi,mini,l,r,xsol,ysol,zsol,k;

    maxi=-INF;
    for (i=1;i<=DIM;i++){
        v[i].x=getnr();
        v[i].y=getnr();
        v[i].z=getnr();
        v[i].raza=getnr();
        if (v[i].raza>maxi){
            maxi=v[i].raza;
            poz=i;
        }
        //printf ("%lld %lld %lld %lld\n",v[i].x,v[i].y,v[i].z,v[i].raza);
    }
    sol=0;
    for (j=1;j<=DIM;j++){
        if (modul(v[poz].z-v[j].z)+modul(v[poz].y-v[j].y)+modul(v[poz].x-v[j].x)<=maxi)
            sol++;
    }
    fprintf (fout,"%d",sol);
    /*while(1)
    {
        memset(intersect,0,sizeof(intersect));
        maxi=0;
        for(i=1;i<=DIM;i++){
            if (!f[i]){
                for(j=1;j<=DIM;j++){
                    if (!f[j])
                        if(modul (v[i].x-v[j].x) + modul (v[i].y-v[j].y) + modul (v[i].z-v[j].z) >v[i].raza+v[j].raza){
                            intersect[j]++;
                            maxi=max(maxi,intersect[j]);
                        }
                }
            }
        }
        if(!maxi)
            break;
        for(i=1;i<=DIM;i++)
            f[i]=(f[i] | (intersect[i]==maxi));
    }
    l=-INF;
    r=INF;
    for(i=1;i<=DIM;i++){
        if (!f[i]){
            l=max(l,v[i].x-v[i].raza);
            r=min(r,v[i].x+v[i].raza);
        }
    }
    for(k=l;k<=r;k++){
        ok=1;
        for(i=1;i<=DIM;i++){
            if(!f[i]){
                if(v[i].raza<modul(k-v[i].x))
                    ok=0;
            }
        }
        if (ok){
            for(i=1;i<=DIM;i++){
                if(!f[i]){
                    for(j=1;j<=DIM;j++){
                        if(!f[j] && modul(v[i].z-v[j].z)+modul(v[i].y-v[j].y)>v[i].raza+v[j].raza-modul(k-v[i].x)-modul(k-v[j].x)){
                            ok=0;
                            break;
                        }
                    }
                    if(!ok)
                        break;
                }
            }
        }
        if(ok)
            break;
    }
    xsol=k;
    for(i=1;i<=DIM;i++){
        if(!f[i])
            v[i].raza-=modul(xsol-v[i].x);
    }
    l=-INF;
    r=INF;
    for(i=1;i<=DIM;i++){
        if (!f[i]){
            l=max(l,v[i].y-v[i].raza);
            r=min(r,v[i].y+v[i].raza);
        }
    }
    //fprintf (fout,"%lld %lld",l,r);
    //return 0;
    for(k=l;k<=r;k++){
        ok=1;
        for(i=1;i<=DIM;i++){
            if(!f[i]){
                if(v[i].raza<modul(k-v[i].y))
                    ok=0;
            }
        }
        if (ok){
            for(i=1;i<=DIM;i++){
                if(!f[i]){
                    for(j=1;j<=DIM;j++){
                        if(!f[j] && modul(v[i].z-v[j].z)>v[i].raza+v[j].raza-modul(k-v[i].y)-modul(k-v[j].y)){
                            ok=0;
                            break;
                        }
                    }
                    if(!ok)
                        break;
                }
            }
        }
        if(ok)
            break;
    }
    ysol=k;
    for(i=1;i<=DIM;i++)
        if(!f[i])
            v[i].raza-=modul(ysol-v[i].y);
    l=-INF;
    r=INF;
    for(i=1;i<=DIM;i++){
        if(!f[i]){
            l=max(l,v[i].z-v[i].raza);
            r=min(r,v[i].z+v[i].raza);
        }
    }
    for(k=l;k<=r;k++){
        ok=1;
        for(i=1;i<=DIM;i++){
            if(!f[i]){
                if(v[i].raza<modul(k-v[i].z))
                    ok=0;
            }
        }
        for(i=1;i<=DIM;i++){
            if (!f[i]){
                for (j=1;j<=DIM;j++){
                    if (!f[j]){
                        if (0>v[i].raza+v[j].raza-modul(k-v[i].x)-modul(k-v[j].x)){
                            ok=0;
                            break;
                        }
                    }
                }
                if (!ok)
                    break;
            }
        }
        if(ok==1)
            break;
    }
    zsol=k;
    fprintf (fout,"%lld",xsol+ysol+zsol);*/
    return 0;
}
