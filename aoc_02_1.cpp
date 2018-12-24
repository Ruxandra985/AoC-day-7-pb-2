#include <cstdio>
#include <cstring>
#define DIM 250

using namespace std;
int f[30];
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,a2,a3,s2,s3;
    char c;
    a2=a3=0;
    for (int j=1;j<=DIM;j++){
        memset (f,0,sizeof(f));
        c=fgetc (fin);
        while ('a'<=c && c<='z'){
            f[c-'a'+1]++;
            c=fgetc (fin);
        }
        s2=s3=0;
        for (i='a';i<='z';i++){
            if (f[i-'a'+1]==2)
                s2=1;
            else if (f[i-'a'+1]==3)
                s3=1;
        }
        a2+=s2;
        a3+=s3;
    }
    fprintf (fout,"%d",a2*a3);
    return 0;
}
