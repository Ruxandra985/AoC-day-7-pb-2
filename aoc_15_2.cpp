#include <cstdio>
#include <deque>
#include <bitset>
#include <algorithm>
#define DIMI 32
#define DIMJ 32
#define INF 2000000000
using namespace std;
struct unit{
    int x,y,tip,attack,hit;
};
unit v[1000];
int nr,g,e;
deque <pair <int,int> >dq;
bitset <DIMJ> f[DIMI];
int d[1000][1000];
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
int a[1000][1000];
int cmp (unit a,unit b){
    if (a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
int check (int poz){
    int i,iv,jv,ic,jc,dir;
    for (i=1;i<=nr;i++){
        if (v[i].tip!=v[poz].tip){
            for (dir=0;dir<4;dir++){
                iv=v[poz].x+di[dir];
                jv=v[poz].y+dj[dir];
                if (iv==v[i].x && jv==v[i].y)/// in vecinatate
                    return 1;
            }
        }
    }
    dq.clear();
    dq.push_back(make_pair(v[poz].x,v[poz].y));
    for (i=1;i<=DIMI;i++)
        f[i].reset();
    f[v[poz].x][v[poz].y]=1;
    while (!dq.empty()){
        ic=dq.front().first;
        jc=dq.front().second;
        dq.pop_front();
        for (dir=0;dir<4;dir++){
            iv=ic+di[dir];
            jv=jc+dj[dir];
            if (iv && jv && iv<=DIMI && jv<=DIMJ && f[iv][jv]==0){
                if (a[iv][jv]==0){
                    f[iv][jv]=1;
                    dq.push_back(make_pair(iv,jv));
                }
                if ((a[iv][jv]==-2 && v[poz].tip==1) || (a[iv][jv]==-1 && v[poz].tip==2))
                    return 0;
            }
        }
    }
    return 1;
}
void lee (int ic,int jc){
    int i,j,iv,jv,dir;
    for (i=1;i<=DIMI;i++){
        for (j=1;j<=DIMJ;j++)
            d[i][j]=0;
        f[i].reset();
    }
    dq.clear();
    dq.push_back(make_pair(ic,jc));
    f[ic][jc]=1;
    while (!dq.empty()){
        ic=dq.front().first;
        jc=dq.front().second;
        //printf ("%d %d\n",ic,jc);
        dq.pop_front();
        for (dir=0;dir<4;dir++){
            iv=ic+di[dir];
            jv=jc+dj[dir];
            //if (iv==2 && jv==5)
              //  printf ("a");
            if (iv && jv && iv<=DIMI && jv<=DIMJ && f[iv][jv]==0 && a[iv][jv]==0){
                f[iv][jv]=1;
                d[iv][jv]=1+d[ic][jc];
                dq.push_back(make_pair(iv,jv));
            }
        }
    }
}
int vecinatate (int i,int j,int t){
    int iv,jv;
    for (int dir=0;dir<4;dir++){
        iv=i+di[dir];
        jv=j+dj[dir];
        if (a[iv][jv]==-t)
            return 1;
    }
    return 0;
}
void atac (int &op){
    int mini,poz,i,dir,iv,jv;
    mini=2000000000;
    poz=0;
    for (i=1;i<=nr;i++){
        if (v[i].tip!=v[op+1].tip){
            for (dir=0;dir<4;dir++){
                iv=v[op+1].x+di[dir];
                jv=v[op+1].y+dj[dir];
                if (iv==v[i].x && jv==v[i].y){/// in vecinatate
                    if (mini>v[i].hit){ /// iau cea mai sensibila tinta
                        mini=v[i].hit;
                        poz=i;
                    }
                    if (mini==v[i].hit && (v[poz].x>v[i].x || (v[poz].x==v[i].x && v[poz].y>v[i].y) ))
                        poz=i;
                }
            }
        }
    }
    if (poz){ /// am ce sa atac
        v[poz].hit-=v[op+1].attack;
        if (v[poz].hit<=0){ /// mort
            a[v[poz].x][v[poz].y]=0;
            if (v[poz].tip==1)
                g--;
            else e--;
            for (i=poz+1;i<=nr;i++)
                v[i-1]=v[i];
            nr--;
            if (poz<op+1)
                op--;
        }
    }
}
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int op,i,j,runde,mx,my,px,py,ic,jc,iv,jv,ok,mini,dir,s,nri,st,dr,mid,ei;
    char c;
    st=4;
    dr=1000000000;
    while (st<=dr){
        mid=(st+dr)/2;
        fclose (fin);
        fin=fopen ("a.in","r");
        nr=0;
        e=g=0;
        ei=0;
        for (i=1;i<=DIMI;i++){
            for (j=1;j<=DIMJ;j++){
                c=fgetc (fin);
                if (c=='.')
                    a[i][j]=0;
                else if (c=='#')
                    a[i][j]=1;
                else if (c=='G'){
                    a[i][j]=-1;
                    nr++;
                    v[nr].x=i;
                    v[nr].y=j;
                    v[nr].tip=1;
                    v[nr].attack=3;
                    v[nr].hit=200;
                    g++;
                }
                else if (c=='E'){
                    a[i][j]=-2;
                    nr++;
                    v[nr].x=i;
                    v[nr].y=j;
                    v[nr].tip=2;
                    v[nr].attack=mid;
                    v[nr].hit=200;
                    e++;
                    ei++;
                }
            }
            fgetc (fin);
        }
        nri=nr;
        op=0;
        runde=0;
        int actual_runde=0;
        while (g && e){
            /*ok=1;
            for (i=1;i<=nr;i++)
                ok=(ok&check(i));*/
            if (check (op+1) && vecinatate (v[op+1].x,v[op+1].y,3-v[op+1].tip)){ /// ok = 1 => ataca
                atac (op);

            }
            else { /// trebuie sa mut
                lee (v[op+1].x,v[op+1].y);
                mini=INF;
                px=py=0;
                for (i=1;i<=DIMI;i++){
                    for (j=1;j<=DIMJ;j++){
                        if (d[i][j] && vecinatate(i,j,3-v[op+1].tip) && d[i][j]<mini){
                            mini=d[i][j];
                            px=i;
                            py=j;
                        }
                    }
                }
                if (px+py>0){
                    /// un pas pana la px,py
                    mx=my=INF;
                    dq.clear();
                    dq.push_back(make_pair(px,py));
                    while (!dq.empty()){
                        ic=dq.front().first;
                        jc=dq.front().second;
                        dq.pop_front();
                        for (dir=0;dir<4;dir++){
                            iv=ic+di[dir];
                            jv=jc+dj[dir];
                            if (iv && jv && iv<=DIMI && jv<=DIMJ){
                                if (iv==v[op+1].x && jv==v[op+1].y){
                                    if (mx>ic || (mx==ic && my>jc)){
                                        mx=ic;
                                        my=jc;
                                    }
                                }
                                else {
                                    if (d[iv][jv]==d[ic][jc]-1)
                                        dq.push_back(make_pair(iv,jv));
                                }
                            }
                        }
                    }
                    dq.clear();
                    a[mx][my]=a[v[op+1].x][v[op+1].y];
                    a[v[op+1].x][v[op+1].y]=0;
                    v[op+1].x=mx;
                    v[op+1].y=my;
                    if (check (op+1) && vecinatate (v[op+1].x,v[op+1].y,3-v[op+1].tip)) /// ok = 1 => ataca
                        atac (op);
                    /*if (runde+1>=10){
                        for (i=1;i<=DIMI;i++){
                            for (j=1;j<=DIMJ;j++)
                                printf ("%d ",a[i][j]);
                            printf ("\n");
                        }
                        printf ("\n");
                    }*/
                }
            }
            op++;
            runde++;
            if (op>=nr){
                actual_runde++;
                op=0;
                sort (v+1,v+nr+1,cmp);
            }

        }
        if (g==0 && e==ei)
            dr=mid-1;
        else st=mid+1;
    }
    mid=st;
    fclose (fin);
        fin=fopen ("a.in","r");
        nr=0;
        e=g=0;
        for (i=1;i<=DIMI;i++){
            for (j=1;j<=DIMJ;j++){
                c=fgetc (fin);
                if (c=='.')
                    a[i][j]=0;
                else if (c=='#')
                    a[i][j]=1;
                else if (c=='G'){
                    a[i][j]=-1;
                    nr++;
                    v[nr].x=i;
                    v[nr].y=j;
                    v[nr].tip=1;
                    v[nr].attack=3;
                    v[nr].hit=200;
                    g++;
                }
                else if (c=='E'){
                    a[i][j]=-2;
                    nr++;
                    v[nr].x=i;
                    v[nr].y=j;
                    v[nr].tip=2;
                    v[nr].attack=mid;
                    v[nr].hit=200;
                    e++;
                }
            }
            fgetc (fin);
        }
        nri=nr;
        op=0;
        runde=0;
        int actual_runde=0;
        while (g && e){
            /*ok=1;
            for (i=1;i<=nr;i++)
                ok=(ok&check(i));*/
            if (check (op+1) && vecinatate (v[op+1].x,v[op+1].y,3-v[op+1].tip)){ /// ok = 1 => ataca
                atac (op);

            }
            else { /// trebuie sa mut
                lee (v[op+1].x,v[op+1].y);
                //if (v[op+1].x==14&& v[op+1].y==23 && actual_runde==6)
                 //   printf ("a");
                mini=INF;
                px=py=0;
                for (i=1;i<=DIMI;i++){
                    for (j=1;j<=DIMJ;j++){
                        if (d[i][j] && vecinatate(i,j,3-v[op+1].tip) && d[i][j]<mini){
                            mini=d[i][j];
                            px=i;
                            py=j;
                        }
                    }
                }
                if (px+py>0){
                    /// un pas pana la px,py
                    mx=my=INF;
                    dq.clear();
                    dq.push_back(make_pair(px,py));
                    while (!dq.empty()){
                        ic=dq.front().first;
                        jc=dq.front().second;
                        dq.pop_front();
                        for (dir=0;dir<4;dir++){
                            iv=ic+di[dir];
                            jv=jc+dj[dir];
                            if (iv && jv && iv<=DIMI && jv<=DIMJ){
                                if (iv==v[op+1].x && jv==v[op+1].y){
                                    if (mx>ic || (mx==ic && my>jc)){
                                        mx=ic;
                                        my=jc;
                                    }
                                }
                                else {
                                    if (d[iv][jv]==d[ic][jc]-1)
                                        dq.push_back(make_pair(iv,jv));
                                }
                            }
                        }
                    }
                    dq.clear();
                    a[mx][my]=a[v[op+1].x][v[op+1].y];
                    a[v[op+1].x][v[op+1].y]=0;
                    v[op+1].x=mx;
                    v[op+1].y=my;
                    if (check (op+1) && vecinatate (v[op+1].x,v[op+1].y,3-v[op+1].tip)) /// ok = 1 => ataca
                        atac (op);
                    /*if (runde+1>=10){
                        for (i=1;i<=DIMI;i++){
                            for (j=1;j<=DIMJ;j++)
                                printf ("%d ",a[i][j]);
                            printf ("\n");
                        }
                        printf ("\n");
                    }*/
                }
            }
            op++;
            runde++;
            if (op>=nr){
                actual_runde++;
                op=0;
                sort (v+1,v+nr+1,cmp);
            }

        }
    s=0;
    for (i=1;i<=nr;i++)
        s+=v[i].hit;
    fprintf (fout,"%d",s*actual_runde);

    return 0;
}
