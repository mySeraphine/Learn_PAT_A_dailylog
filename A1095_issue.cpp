#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
#define time_int(hh,mm,ss) (hh*3600+mm*60+ss)       //将时间转化为整形，定义成宏，速度更快些 
typedef struct node{
    string id;                                      //车牌号 
    int time,tag=1;                                 //时间和进出标记，默认1为进，0为出 
}Car;
int cmptag=1;                                       //排序标记 
vector<Car> all;                                    //所有数据 
vector<int> sid,valid;                              //sid用于第一次下标排序，valid用于保存有效信息的下标，并用于第二次的下标排序 
map<string,int> parktime;                           //记录每个车的停车时间 
bool cmp(int a,int b){                              //比较函数 
    if(cmptag==1){                                  //第一次排序，先按照车牌号排，再按照时间先后排 
        if(all[a].id!=all[b].id) return all[a].id<all[b].id;
        else return all[a].time<all[b].time;    
    }
    else{
        return all[a].time<all[b].time;             //第二次只按照时间排序 
    }
}
int main(void){
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt","r",stdin);
#endif
    int n,k,hh,mm,ss,maxtime=-1;                    //初始化参数，maxtime表示停留的最长时间 
    scanf("%d%d",&n,&k); 
    all.resize(n); sid.resize(n);                   //初始化容器大小 
    for(int i=0;i<n;i++){
        sid[i]=i;                                   //初始化下标排序数组的下标 
        cin>>all[i].id;                             //读入信息 
        char temp[4];
        scanf("%d:%d:%d %s",&hh,&mm,&ss,temp);
        all[i].time=time_int(hh,mm,ss);
        if(temp[0]=='o') all[i].tag=0;              //如果是出，tag标记为0 
    }
    sort(sid.begin(),sid.end(),cmp);                //第一次排序 
    for(int i=0;i<n-1;i++){                         //删选有效信息 
        int a=sid[i],b=sid[i+1];                    //从排好序的序列中，取出相邻的两条信息 
        if(all[a].id==all[b].id&&all[a].tag==1&&all[b].tag==0){ //如果这两条是同一辆车，且前一个为进，后一个为出，表示一对有效信心 
            valid.push_back(a); valid.push_back(b); //记录有效记录的下标 
            int intime=all[b].time-all[a].time;     //计算停车时间 
            parktime[all[a].id]+=intime;            //总停车时间累加 
            maxtime=max(maxtime,parktime[all[a].id]);//更新最大停车时间 
        }   
    }
    cmptag=0;                                       //修改排序标记，对有效记录，进行第二次排序 
    sort(valid.begin(),valid.end(),cmp);
    int j=0,numcnt=0;                               //j用于遍历有效记录，numcnt用于记录当前车辆个数 
    for(int i=0;i<k;i++){
        scanf("%d:%d:%d",&hh,&mm,&ss);              //读入查询信息 
        int qtime=time_int(hh,mm,ss);
        for(j;j<valid.size();j++){                  //遍历有效信息，因为查询是按照时间顺序的，因此只需要遍历一遍 
            int ind=valid[j];                       //取出一条有效记录的下标 
            if(all[ind].time>qtime) break;          //如果该记录在查询事件之后，则本次查询结束 
            if(all[ind].tag==1) numcnt++;           //如果是进入，numcnt加一 
            else numcnt--;                          //如果是出去，numcnt减一 
        }
        printf("%d\n",numcnt);                      //输出本次查询结果 
    }
    for(auto it=parktime.begin();it!=parktime.end();it++){
        if(it->second==maxtime)                     //遍历停车时间的容器，并输出和maxparktime相等的车辆id 
            printf("%s ",it->first.c_str());        //map自身有序，保证了id的有序 
    }
    printf("%02d:%02d:%02d",maxtime/3600,maxtime%3600/60,maxtime%60);
    cout<<endl;
    return 0;
} 
