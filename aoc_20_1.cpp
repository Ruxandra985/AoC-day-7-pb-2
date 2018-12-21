#include <cstdio>
#include <algorithm>

using namespace std;

char s[1000000];
int usi[1005][1005];
void build_map(int inc,int sf, int x, int y){
    int i,x1,y1,l,r,j,par,l1,r1;
    //printf ("%d %d\n",inc,sf);
    for (i=inc;i<=sf && (s[i]=='N' || s[i]=='S' || s[i]=='E' || s[i]=='W');i++){
        if (s[i]=='N'){
            x--;
            usi[x][y]=min(usi[x][y],usi[x+1][y]+1);
        }
        else if (s[i]=='E'){
            y++;
            usi[x][y]=min(usi[x][y],usi[x][y-1]+1);
        }
        else if (s[i]=='S'){
            x++;
            usi[x][y]=min(usi[x][y],usi[x-1][y]+1);
        }
        else if (s[i]=='W'){
            y--;
            usi[x][y]=min(usi[x][y],usi[x][y+1]+1);
        } /// am tratat miscarile simple
    }
    x1=x;
    y1=y;
    if (i>sf)
        return;
    l=i+1;
    par=0;
    for (j=i;;j++){
        if (s[j]=='(')
          par++;
        else if (s[j]==')')
          par--;
        if (par==0)
          break;
    }
    r=j-1; /// paranteza curenta intre l si r
    l1=l;
    r1=r; /// iau doar paranteza asta si o impart
    while (1){
        par=0;
        for (i=l1;i<=r1;i++){
            if (s[i]=='(')
                par++;
            else if (s[i]==')')
                par--;
            else if (par==0 && s[i]=='|') /// am ajuns la "impartire"
                break;
        }
        build_map(l1,i-1,x,y); /// solve
        if (i>r1)
            break;
        l1=i+1; /// treci peste impartire
    }
    if (j+1<=sf) /// mai fa si restul
        build_map(j+1,sf,x1,y1);
}

int main (){
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,j,sol=0;
    fscanf (fin,"%s",s);
    for (i=1;i<=1000;i++)
        for (j=1;j<=1000;j++)
            usi[i][j]=1000000000;

    usi[500][500] = 0;
    build_map(1,14295, 500, 500);
    for (i=1;i<=1000;i++)
        for (j=1;j<=1000;j++)
            if (usi[i][j]!=1000000000)
                sol=max(sol,usi[i][j]);
    fprintf (fout,"%d",sol);
    return 0;
}
