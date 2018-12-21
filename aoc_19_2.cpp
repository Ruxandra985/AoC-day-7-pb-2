#include <cstdio>
#define INSTR 36
using namespace std;
long long w[6];
struct ceva{
    int in,a,b,c;
};
ceva v[100];

FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");

inline int getnr(){
    int nr=0;
    char c;
    c=fgetc (fin);
    while ('0'>c || '9'<c)
        c=fgetc (fin);
    while ('0'<=c && c<='9'){
        nr=nr*10+c-'0';
        c=fgetc (fin);
    }
    return nr;
}

inline void addr(int i){
    w[v[i].c]=w[v[i].a]+w[v[i].b];
}
inline void addi(int i){
    //printf ("a");
    w[v[i].c]=w[v[i].a]+v[i].b;
}
inline void mulr(int i){
    w[v[i].c]=w[v[i].a]*w[v[i].b];
}
inline void muli(int i){
    w[v[i].c]=w[v[i].a]*v[i].b;
}
inline void banr(int i){
    w[v[i].c]=(w[v[i].a]&w[v[i].b]);
}
inline void bani(int i){
    w[v[i].c]=(w[v[i].a]&v[i].b);
}
inline void borr(int i){
    w[v[i].c]=(w[v[i].a]|w[v[i].b]);
}
inline void bori(int i){
    w[v[i].c]=(w[v[i].a]|v[i].b);
}
inline void setr(int i){
    w[v[i].c]=w[v[i].a];
}
inline void seti(int i){
    w[v[i].c]=v[i].a;
}
inline void gtir(int i){
    w[v[i].c]=(v[i].a>w[v[i].b]);
}
inline void gtri(int i){
    w[v[i].c]=(w[v[i].a]>v[i].b);
}
inline void gtrr(int i){
    w[v[i].c]=(w[v[i].a]>w[v[i].b]);
}
inline void eqir(int i){
    w[v[i].c]=(v[i].a==w[v[i].b]);
}
inline void eqri(int i){
    w[v[i].c]=(w[v[i].a]==v[i].b);
}
inline void eqrr(int i){
    w[v[i].c]=(w[v[i].a]==w[v[i].b]);
}
int main()
{

    int bounded,i,ip;
    char c1,c2,c3,c4;
    bounded=getnr();
    for (i=0;i<INSTR;i++){
        c1=fgetc (fin);
        c2=fgetc (fin);
        c3=fgetc (fin);
        c4=fgetc (fin);
        if (c1=='a' && c4=='r')
            v[i].in=0;
        else if (c1=='a' && c4=='i')
            v[i].in=1;
        else if (c1=='m' && c4=='r')
            v[i].in=2;
        else if (c1=='m' && c4=='i')
            v[i].in=3;
        else if (c1=='b' && c2=='a' && c4=='r')
            v[i].in=4;
        else if (c1=='b' && c2=='a' && c4=='i')
            v[i].in=5;
        else if (c1=='b' && c2=='o' && c4=='r')
            v[i].in=6;
        else if (c1=='b' && c2=='o' && c4=='i')
            v[i].in=7;
        else if (c1=='s' && c4=='r')
            v[i].in=8;
        else if (c1=='s' && c4=='i')
            v[i].in=9;
        else if (c1=='g' && c3=='i' && c4=='r')
            v[i].in=10;
        else if (c1=='g' && c3=='r' && c4=='i')
            v[i].in=11;
        else if (c1=='g' && c3=='r' && c4=='r')
            v[i].in=12;
        else if (c1=='e' && c3=='i' && c4=='r')
            v[i].in=13;
        else if (c1=='e' && c3=='r' && c4=='i')
            v[i].in=14;
        else if (c1=='e' && c3=='r' && c4=='r')
            v[i].in=15;
        v[i].a=getnr();
        v[i].b=getnr();
        v[i].c=getnr();
    }
    ip=0;
    w[0]=1;
    long long op=1;
    while (ip<INSTR && op<=100){
        op++;
        /// executa instructiunea ip
        w[bounded]=ip;
        if (v[ip].in==0)
            addr(ip);
        else if (v[ip].in==1)
            addi(ip);
        else if (v[ip].in==2)
            mulr(ip);
        else if (v[ip].in==3)
            muli(ip);
        else if (v[ip].in==4)
            banr(ip);
        else if (v[ip].in==5)
            bani(ip);
        else if (v[ip].in==6)
            borr(ip);
        else if (v[ip].in==7)
            bori(ip);
        else if (v[ip].in==8)
            setr(ip);
        else if (v[ip].in==9)
            seti(ip);
        else if (v[ip].in==10)
            gtir(ip);
        else if (v[ip].in==11)
            gtri(ip);
        else if (v[ip].in==12)
            gtrr(ip);
        else if (v[ip].in==13)
            eqir(ip);
        else if (v[ip].in==14)
            eqri(ip);
        else if (v[ip].in==15)
            eqrr(ip);
        //printf ("%lld\n",w[bounded]);
        //printf ("%lld %lld %lld %lld %lld %lld\n",w[0],w[1],w[2],w[3],w[4],w[5],w[6]);
        ip=w[bounded]+1;
        /*if (w[0]>18){
            printf ("%lld ",op);
            break;
        }*/
        //if (op>2000000000)
          //  printf ("%lld %lld\n",w[0],w[5]);
    }
    //printf ("%d ",op);
    //printf ("%lld %lld %lld %lld %lld %lld\n",w[0],w[1],w[2],w[3],w[4],w[5],w[6]);
    /// suma divizori w[2]
    long long sum=0,d=1;
    while (d*d<=w[2]){
        if (w[2]%d==0){
            sum+=d;
            if (d*d<w[2])
                sum+=w[2]/d;
        }
        d++;
    }
    fprintf (fout,"%lld",sum);
    return 0;
}
