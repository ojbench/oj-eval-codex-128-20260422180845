#include <bits/stdc++.h>
using namespace std;

static bool lineWin(const array<string,3>& b, char c){
    // rows and cols
    for(int i=0;i<3;i++){
        if(b[i][0]==c && b[i][1]==c && b[i][2]==c) return true;
        if(b[0][i]==c && b[1][i]==c && b[2][i]==c) return true;
    }
    // diagonals
    if(b[0][0]==c && b[1][1]==c && b[2][2]==c) return true;
    if(b[0][2]==c && b[1][1]==c && b[2][0]==c) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    array<string,3> b;
    for(int i=0;i<3;i++){
        if(!(cin>>b[i])) return 0;
        if((int)b[i].size()!=3){
            cout<<"invalid\n";
            return 0;
        }
    }

    int cx=0, co=0, cd=0;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){
        char ch=b[i][j];
        if(ch=='x') cx++; else if(ch=='o') co++; else if(ch=='-') cd++; else {
            cout<<"invalid\n"; return 0;
        }
    }

    // Basic count validity: x starts, so cx == co or cx == co+1
    if(!(cx==co || cx==co+1)){
        cout<<"invalid\n";
        return 0;
    }

    bool xwin = lineWin(b,'x');
    bool owin = lineWin(b,'o');

    // Cannot both win
    if(xwin && owin){
        cout<<"invalid\n";
        return 0;
    }

    // If x wins, x must have just played: cx == co+1
    if(xwin){
        if(cx!=co+1){ cout<<"invalid\n"; return 0; }
        cout<<"win\n";
        return 0;
    }
    // If o wins, counts must be equal
    if(owin){
        if(cx!=co){ cout<<"invalid\n"; return 0; }
        cout<<"lose\n";
        return 0;
    }

    // No winner: either ongoing (has '-') or tie (full)
    if(cd>0) cout<<"ongoing\n";
    else cout<<"tie\n";
    return 0;
}

