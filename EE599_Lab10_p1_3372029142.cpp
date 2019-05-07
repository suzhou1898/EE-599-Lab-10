#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class graph{
public:
    char *v;
    int **e;
    int vn;
    int *visit;
    int *pre;
    bool f1=true;
    bool f2=true;
    void DFS();
    void dfs(int i);
};

void graph::DFS() {
    int n=0;
    for(int i=0;i<vn;i++){
        visit[i]=-1;
    }
    dfs(n);
}

void graph::dfs(int i){
    visit[i]=0;
    for(int j=0;j<vn;j++){
        if(e[i][j]==1 && visit[j]==-1){
            pre[j]=i;
            dfs(j);
        }
        else if(e[i][j]==1 && visit[j]==0){
            if(pre[i]!=j)
                f1=false;
        }
    }
}

int main(int argv, char **argc) {
    string s;
    ifstream infile;
    infile.open("input.txt");
    graph *a=new graph();
    int num;
    int n = 0;
    getline(infile, s);
    stringstream ss(s);
    ss >> num;
    getline(infile, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            n++;
    }
    string *str = new string[n + 1];
    for (int i = 0; i < n + 1; i++) {
        str[i] = s.substr(i * 5, 3);
    }
    a->vn = num;
    a->v = new char[a->vn];
    for (int i = 0; i < a->vn; i++) {
        *(a->v + i) = '0' + i;
    }
    a->e = new int *[a->vn];
    for (int i = 0; i < a->vn; i++) {
        a->e[i] = new int[a->vn];
    }
    for (int i = 0; i < a->vn; i++) {
        for (int j = 0; j < a->vn; j++) {
            a->e[i][j] = 0;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        stringstream st;
        int b,c;
        char comma;
        st << str[i];
        st >> c >> comma >> b;
        a->e[c][b] = 1;
        a->e[b][c] = 1;
    }
    for(int i=0;i<a->vn;i++){
        for(int j=0;j<a->vn;j++){
        }
    }

    a->visit=new int[a->vn];
    a->pre=new int[a->vn];

    a->DFS();
    for(int i=0;i<a->vn;i++){
        if(a->visit[i]==-1)
            a->f2=false;
    }

    if(a->f1 && a->f2){
        cout<<"Graph is a valid tree"<<endl;
    }
    else{
        cout<<"Graph is not a valid tree"<<endl;
    }
    
    delete [] a->v;

    for (int i = 0; i < a->vn; i++) {
        delete [] a->e[i];
    }

    delete [] a->e;

    return 0;
}
