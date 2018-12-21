#include <cstdio>
#define DIM 100
#define BEGIN 200
#define OP 32
#define LIM 500
using namespace std;
char v[LIM+100],w[LIM+100];
int f[500],q[50];
int create_stare (char p1,char p2,char p3,char p4,char p5){
    int nr;
    nr=1*(p5=='#') + 2*(p4=='#') + 4*(p3=='#') + 8*(p2=='#') + 16*(p1=='#');
    return nr;

}
void change (){
    int i,nr;
    w[0]=v[0];
    w[1]=v[1];
    for (i=2;i<=LIM-2;i++){
        nr=create_stare(v[i-2],v[i-1],v[i],v[i+1],v[i+2]);
        if (f[nr]==1)
            w[i]='#';
        else w[i]='.';
    }
    w[LIM]=v[LIM];
    w[LIM-1]=v[LIM-1];
}
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,ok;
    char l,l2,c,r,r2,rez;
    for (i=0;i<BEGIN;i++)
        v[i]='.';
    for (i=BEGIN;i<=DIM+BEGIN-1;i++){
        v[i]=fgetc (fin);
    }
    for (i=DIM+BEGIN;i<=LIM;i++)
        v[i]='.';
    c=fgetc (fin);
    c=fgetc (fin);
    for (i=1;i<=OP;i++){
        l=fgetc (fin);
        l2=fgetc (fin);
        c=fgetc (fin);
        r=fgetc (fin);
        r2=fgetc (fin);
        fgetc (fin);
        fgetc (fin);
        fgetc (fin);
        fgetc (fin);
        rez=fgetc (fin);
        fgetc (fin);
        //if (i==8)
          //  printf ("a");
        //printf ("%c %c %c %c %c\n",l,l2,c,r,r2);
        f[create_stare (l,l2,c,r,r2)]=(rez=='#');
    }
    for (i=0;i<=DIM+BEGIN;i++)
        w[i]='.';
    for (int tr=1;tr<=122;tr++){
        change();
        int sol=0;
        for (i=0;i<=LIM;i++){
            v[i]=w[i];
            if (v[i]=='#')
                sol++;
            //if (tr>1 && v[i]==0)
              //  printf ("a");
            //fputc (v[i],fout);
        }
        //fprintf (fout,"\n");
        //if (tr>=122)
        //fprintf (fout,"%d\n",sol);
    }
    int sol=0;
    int ap=0;
    for (i=0;i<=LIM;i++){
        if (v[i]=='#'){
            sol=sol+(i-BEGIN);
            ap++;
        }
    }
    fprintf (fout,"%lld",(long long)sol+((long long)50000000000-122)*ap);
    return 0;
}
