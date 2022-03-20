#include <iostream>
#include <queue>
using namespace std;
const int MAX=3e5;
int n,p1,p2,cnt;

struct edge{
    int to;
    int next;
}edges[MAX];
int head[MAX];
//int visited[MAX]={0};//判断是否访问过
int degree[MAX]={0};//记录每个点的入度
int pos[MAX]={0};//记录拓扑排序
void add_edge(int u,int v){
    edges[cnt].to=v;
    edges[cnt].next=head[u];
    head[u]=cnt++;
}
void init(){
    for(int i=0;i<=n;++i) head[i]=-1;
    cnt=0;
}

int main() {
    cin>>n>>p1>>p2;
    init();
    int a,b;
    for(int i=0;i<p1;++i){
        cin>>a>>b;
        add_edge(a,b);
        degree[b]+=1;
    }
    //拓扑排序
    queue<int> zero;
    for(int i=1;i<=n;++i){
        if(degree[i]==0) zero.push(i);
    }
    int Pos=1;
    while(!zero.empty()){
        int temp=zero.front();
        zero.pop();
        if(pos[temp]==0){
            pos[temp]=Pos++;
            for(int j=head[temp];j!=-1;j=edges[j].next){
                degree[edges[j].to]-=1;
                if(degree[edges[j].to]==0) {
                    zero.push(edges[j].to);
                }
            }
        }
    }
    for(int i=0;i<p2;++i){
        cin>>a>>b;
        if(pos[a]<pos[b]) cout<<a<<' '<<b<<endl;
        else cout<<b<<' '<<a<<endl;
    }

}
