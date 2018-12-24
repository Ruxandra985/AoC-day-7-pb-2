#include <cstdio>
#include <algorithm>
#define DIM 10

using namespace std;

FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");

struct ceva{
    int un,hit,atc,init,tip,index;
};
ceva v[20],w[20];
int weak_v[20][20],weak_w[20][20],fv[20],fw[20],vi[20],wi[20];
pair <int,int> chosen_by_v[20],chosen_by_w[20],v2[20],w2[20];
int cmp (ceva x,ceva y){
    if (x.un*x.atc!=y.un*y.atc)
        return x.un*x.atc>y.un*y.atc;
    return x.init>y.init;
}
inline int getnr(){
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
int cmp2 (pair <int,int> x,pair <int,int> y){
    return x>y;
}
int main()
{
    int immune,i,j,k,damage,infection,maxdmg,poz,im,wk,iv,jv,pi,pj,st,dr,mid;
    immune=0;
    for (i=1;i<=DIM;i++){
        v[i].un=getnr();
        v[i].hit=getnr();
        v[i].atc=getnr();
        v[i].init=getnr();
        immune+=v[i].un;
        v[i].index=i;
    }
    v[1].tip=5;
    weak_v[1][0]=1; weak_v[1][1]=-1;
    v[2].tip=2;
    weak_v[2][0]=0;
    v[3].tip=1;
    weak_v[3][0]=2; weak_v[3][1]=1; weak_v[3][2]=3;
    v[4].tip=1;
    weak_v[4][0]=2; weak_v[4][1]=2; weak_v[4][2]=4;
    v[5].tip=3;
    weak_v[5][0]=2; weak_v[5][1]=3; weak_v[5][2]=4;
    v[6].tip=3;
    weak_v[6][0]=0;
    v[7].tip=4;
    weak_v[7][0]=3;weak_v[7][1]=-2; weak_v[7][2]=-3; weak_v[7][3]=-1;
    v[8].tip=4;
    weak_v[8][0]=3;weak_v[8][1]=2; weak_v[8][2]=-3; weak_v[8][3]=-1;
    v[9].tip=5;
    weak_v[9][0]=1; weak_v[9][1]=-1;
    v[10].tip=5;
    weak_v[10][0]=2; weak_v[10][1]=1; weak_v[10][2]=-4;

    infection=0;
    for (i=1;i<=DIM;i++){
        w[i].un=getnr();
        w[i].hit=getnr();
        w[i].atc=getnr();
        w[i].init=getnr();
        infection+=w[i].un;
        w[i].index=i;
    }
    w[1].tip=3;
    weak_w[1][0]=1; weak_w[1][1]=2;
    w[2].tip=3;
    weak_w[2][0]=1; weak_w[2][1]=-1;
    w[3].tip=5;
    weak_w[3][0]=4; weak_w[3][1]=1; weak_w[3][2]=4; weak_w[3][3]=-2; weak_w[3][4]=-3;
    w[4].tip=5;
    weak_w[4][0]=2; weak_w[4][1]=-3; weak_w[4][2]=4;
    w[5].tip=2;
    weak_w[5][0]=3; weak_w[5][1]=3; weak_w[5][2]=4; weak_w[5][3]=-1;
    w[6].tip=1;
    weak_w[6][0]=2; weak_w[6][1]=5; weak_w[6][2]=4;
    w[7].tip=1;
    weak_w[7][0]=3;weak_w[7][1]=-5; weak_w[7][2]=-4; weak_w[7][3]=-1;
    w[8].tip=3;
    weak_w[8][0]=0;
    w[9].tip=2;
    weak_w[9][0]=2; weak_w[9][1]=-2; weak_w[9][2]=5;
    w[10].tip=2;
    weak_w[10][0]=1; weak_w[10][1]=5;
    immune=infection=0;
        for (i=1;i<=DIM;i++){
            immune+=v[i].un;
            infection+=w[i].un;
        }
    /// gata citirea
    //st=0;
    //dr=10000;
    //while (st<=dr){
      //  mid=(st+dr)/2;
       // mid=25;
        for (i=1;i<=DIM;i++){
            v[i].atc+=0;
        }
        while (immune && infection){
            //if (immune == 3400 && infection == 2268)
            printf ("%d %d\n",immune,infection);

            for (i=1;i<=DIM;i++)
                chosen_by_v[i]=chosen_by_w[i]=make_pair(0,0);

            sort (v+1,v+DIM+1,cmp);
            sort (w+1,w+DIM+1,cmp);
            for (i=1;i<=DIM;i++){ /// grupul i alege

                if (fv[v[i].index]==1)
                    continue; /// e grup mort
                maxdmg=-1;
                poz=0;

                for (j=1;j<=DIM;j++){

                    if (fw[w[j].index]==1 || chosen_by_v[j].second!=0) /// e grup mort sau deja ales
                        continue;
                    im=wk=0;

                    for (k=1;k<=weak_w[w[j].index][0];k++){
                        if (weak_w[w[j].index][k]==-v[i].tip)
                            im=1;
                        else if (weak_w[w[j].index][k]==v[i].tip)
                            wk=1;
                    }
                    if (im)
                        damage=0;
                    else if (wk)
                        damage=2*v[i].atc*v[i].un;
                    else damage=v[i].atc*v[i].un;
                    if (maxdmg<damage){
                        maxdmg=damage;
                        poz=j;
                    }
                    else if (maxdmg==damage && cmp(w[j],w[poz]))
                        poz=j;
                }
                if (maxdmg>0)
                    chosen_by_v[poz]=make_pair(maxdmg,i);
            }/// GRUPUL V A ALES


            for (i=1;i<=DIM;i++){ /// grupul i alege

                if (fw[w[i].index]==1)
                    continue; /// e grup mort
                maxdmg=-1;
                poz=0;

                for (j=1;j<=DIM;j++){

                    if (fv[v[j].index]==1 || chosen_by_w[j].second!=0) /// e grup mort sau deja ales
                        continue;
                    im=wk=0;

                    for (k=1;k<=weak_v[v[j].index][0];k++){
                        if (weak_v[v[j].index][k]==-w[i].tip)
                            im=1;
                        else if (weak_v[v[j].index][k]==w[i].tip)
                            wk=1;
                    }
                    if (im)
                        damage=0;
                    else if (wk)
                        damage=2*w[i].atc*w[i].un;
                    else damage=w[i].atc*w[i].un;
                    if (maxdmg<damage){
                        maxdmg=damage;
                        poz=j;
                    }
                    else if (maxdmg==damage && cmp(v[j],v[poz]))
                        poz=j;
                }
                if (maxdmg>0)
                    chosen_by_w[poz]=make_pair(maxdmg,i);
            } /// A ALES SI GRUPUL W

            /// INCEPE COMBAT UL
            for (i=1;i<=DIM;i++){
                v2[i]=make_pair(v[i].init,i);
                vi[i]=v[i].un;
                w2[i]=make_pair(w[i].init,i);
                wi[i]=w[i].un;
            }
            sort (v2+1,v2+DIM+1,cmp2);
            sort (w2+1,w2+DIM+1,cmp2);
            iv=jv=1;
            while (iv<=DIM || jv<=DIM){
                pi=v2[iv].second;
                pj=w2[jv].second;
                if (jv>DIM || v[pi].init>w[pj].init){ /// ataca cel din v
                    for (i=1;i<=DIM;i++){
                        if (chosen_by_v[i].second==pi && !fw[w[i].index]){
                            damage=min(chosen_by_v[i].first/vi[pi] * v[pi].un,w[i].un*w[i].hit);
                            w[i].un-=(damage/w[i].hit);
                            if (!w[i].un)
                                fw[w[i].index]=1;
                            break;
                        }
                    }
                    iv++;
                }
                else { /// ataca w
                    for (i=1;i<=DIM;i++){
                        if (chosen_by_w[i].second==pj && !fv[v[i].index]){
                            damage=min(chosen_by_w[i].first/wi[pj] * w[pj].un,v[i].un*v[i].hit);
                            v[i].un-=(damage/v[i].hit);
                            if (!v[i].un)
                                fv[v[i].index]=1;
                            break;
                        }
                    }
                    jv++;
                }
            }
            immune=infection=0;
            for (i=1;i<=DIM;i++){
                immune+=v[i].un;
                infection+=w[i].un;
            }

        }
        if (immune){
            printf ("%d ",mid);
            dr=mid-1;
        }
        //else st=mid+1;
        //for (i=1;i<=DIM;i++){
          //  v[i].atc-=mid;
        //}
    //}
    //fprintf (fout,"%d\n",st);
    fprintf (fout,"%d",infection);
    return 0;
}
