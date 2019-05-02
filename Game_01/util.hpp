#ifndef util_hpp
#define util_hpp
#include <iostream>
using namespace std;


void clearScreen();

string loc2str(int loc_i[]);
string loc2strij(int i,int j);

void   str2loc(string loc_str,int loc_new[2]);

bool check_mines(int i,int j,list<string> mines_list);



#endif /* util_h */
