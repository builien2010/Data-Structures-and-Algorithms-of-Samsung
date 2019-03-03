/* Waterjub */
 /* Xonggggggggggggggg

     3 8 5
     3 4 5
     2
     56 87 65
     34 52 89

     2
     -1
     130
     -1
 */



#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int visited[1000][1000];
queue<std::vector<int> > Q;
int flag = -1;

int initVisited(){

    for(long i = 0; i < 1000; i++)
        for ( long j = 0; j < 1000; j++)
            visited[i][j] = 0;      //chưa được thăm
}
/*
bool reachTarget(vector<int> s){
    return s[0] == c || s[1] == c;
}
*/

void markVisit(vector<int> s){

    visited[s[0]][s[1]] = 1;         // đánh dấu đã duyệt trạng thái đó
}

// đổ đầy nước vào cốc 1
bool genMoveFill1(std::vector<int> s, int a, int b , int c){

    //cout << "Do day nuoc vao coc 1" << endl;

    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[a][s[1]])
        return false;

    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0] = a;
    newS[1] = s[1];
    newS[2] = s[2] + 1;

    Q.push(newS);
    markVisit(newS);

    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] << endl;
        return true;
    }

    return false;

}

// đổ đầy nước vào cốc 2
bool genMoveFill2(std::vector<int> s, int a, int b, int c){

    //cout << "do day nuoc vao coc 2" << endl;
    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[s[0]][b])
        return false;

    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0] = s[0];
    newS[1] = b;
    newS[2] = s[2] + 1;

    Q.push(newS);
    markVisit(newS);

    //Kiểm tra có phải trạng thái kết thúc
    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] << endl;
        return true;
    }

    return false;

}

bool genMove1Out(std::vector<int> s, int a, int b, int c){

    //cout << "do nuoc tu coc 1 ra ngoai " << endl;
    //cout << s[0] << s[1] << endl;

    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[0][s[1]])
        return false;
    //cout << s[0] << s[1] << endl;
    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0] = 0;
    newS[1] = s[1];
    newS[2] = s[2] + 1;
    //cout << s[0] << s[1] << endl;
    Q.push(newS);
    markVisit(newS);

    //Kiểm tra có phải trạng thái kết thúc
    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] + 1 << endl;
        return true;
    }

    //cout << s[0] << s[1] << endl;

    return false;

}

bool genMove2Out(std::vector<int> s, int a, int b, int c){

    //cout << " do nuoc tu coc 2 ra ngoai " <<s[0]  << "  "<< s[1]<< endl;
    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[s[0]][0])
        return false;

    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0] = s[0];
    newS[1] = 0;
    newS[2] = s[2] + 1;

     Q.push(newS);
    markVisit(newS);

    //Kiểm tra có phải trạng thái kết thúc
    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] << endl;
        return true;
    }

    return false;

}

bool genMove1Full2(std::vector<int> s, int a, int b, int c){

    //cout << "do nuoc tu coc 1 sang coc 2" << endl;
    if( s[0] + s[1] < b)
        return false;

    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[s[0] + s[1] - b][b])
        return false;

    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0] = s[0] + s[1] - b;
    newS[1] = b;
    newS[2] = s[2] + 1;

    Q.push(newS);
    markVisit(newS);

    //Kiểm tra có phải trạng thái kết thúc
    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] << endl;
        return true;
    }

    return false;

}

bool genMove2Full1(std::vector<int> s, int a, int b, int c){

    //cout << "do nuoc tu coc 2 sang coc 1" << endl;
    if( s[0] + s[1] < a)
        return false;

    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[a][s[0] + s[1] - a])
        return false;

    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0]= a;
    newS[1]= s[0] + s[1] - a;
    newS[2] = s[2] + 1;

    Q.push(newS);
    markVisit(newS);

    //Kiểm tra có phải trạng thái kết thúc
    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] << endl;
        return true;
    }

    return false;

}

bool genMoveAll12(std::vector<int> s, int a, int b, int c){

    //cout << " do het nuoc coc 1 sang coc 2" << endl;
    if( s[0] + s[1] > b)
        return false;

    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[0][s[0] + s[1]])
        return false;

    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0] = 0;
    newS[1]= s[0] + s[1];
    newS[2] = s[2] + 1;

    Q.push(newS);
    markVisit(newS);

    //Kiểm tra có phải trạng thái kết thúc
    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] << endl;
        return true;
    }

    return false;

}

bool genMoveAll21(std::vector<int> s, int a, int b, int c){

    //cout << "do het nuoc coc 2 sang coc 1" <<endl;
    if( s[0] + s[1] > a)
        return false;

    //Nếu trạng thái đã được duyệt thì ko xét lại
    if(visited[s[0] + s[1] ][0])
        return false;

    //Sinh ra trạng thái mới
    std::vector<int> newS(3);
    newS[0] = s[0] + s[1];
    newS[1] = 0;
    newS[2] = s[2] + 1;

    Q.push(newS);
    markVisit(newS);


    //Kiểm tra có phải trạng thái kết thúc
    if (newS[0] == c || newS[1] == c){
        flag = 1;
        cout << newS[2] << endl;
        return true;
    }

    return false;

}

void solve(int a, int b,int c){

    // khởi tạo trạng thái ban đầu (0,0) và đưa vào Q
    std::vector<int> s(3);
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;

    //cout << s[0] << s[1] << s[2] <<endl;
    Q.push(s);
    markVisit(s);

    while(!Q.empty()){

        std::vector<int> s(3);
        s = Q.front();
        //cout << s[0] << s[1] << s[2] <<endl;

        Q.pop();

        if(genMove1Out(s,a,b,c))
           break;
        if(genMove2Out(s,a,b,c))
            break;
        if(genMoveFill1(s,a,b,c))
            break;
        if(genMoveFill2(s,a,b,c))
            break;

        if(genMove1Full2(s, a, b, c))
            break;
        if(genMove2Full1(s,a , b, c))
            break;
        if(genMoveAll12(s, a, b, c))
            break;
        if(genMoveAll21(s, a, b, c))
            break;

    }

}


int main(){

    int T;
    cin >> T;

    int a[T][3];

    for(int i = 1; i <= T; i++){
        cin >> a[i][0];
        cin >> a[i][1];
        cin >> a[i][2];
    }

    for(int i = 1; i <= T; i++){
        initVisited();

        //cout << s[0] << s[1] << s[2] <<endl;

        //Q.pop();

        flag = -1;
        solve(a[i][0], a[i][1], a[i][2]);
        if( flag == -1)
            cout << -1 << endl;

        //std::vector<int> s(3);

        while(!Q.empty()){
            //s = Q.front();
            Q.pop();
        }

    }

    return 0;

}



