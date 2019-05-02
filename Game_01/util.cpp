#include <iostream>
#include "Zombies.hpp"
#include "Player.hpp"
#include "util.hpp"
#include "Arena.hpp"
using namespace std;


void clearScreen()  // will just write a newline in an Xcode output window
{
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
        cout << endl;
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}


string loc2str(int loc_i[2]){
    string x = to_string(loc_i[0]);
    string y = to_string(loc_i[1]);
    if(x.length()==1)
        x = "0"+x;
    if(y.length()==1)
        y = "0"+y;
    string out = x+y;
    return out;
}


string loc2strij(int i,int j){
    string x = to_string(i);
    string y = to_string(j);
    if(x.length()==1)
        x = "0"+x;
    if(y.length()==1)
        y = "0"+y;
    string out = x+y;
    return out;
}



void str2loc(string loc_str,int loc_new[2]){
    loc_new[0] = atoi(loc_str.substr(0,2).c_str());
    loc_new[1] = atoi(loc_str.substr(2.2).c_str());
}



bool check_mines(int i,int j,list<string> mines_list){
    int ans=false;
    if(find(mines_list.begin(), mines_list.end(), loc2strij(i,j)) != mines_list.end())
        ans=true;
    return ans;
}
