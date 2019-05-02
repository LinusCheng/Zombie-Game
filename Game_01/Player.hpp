#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <random>
#include <cstdlib>
//#include "Arena.hpp"


using namespace std;
class Arena;

class Player{
public:
    //    Player(Arena* a_pt,int width,int height);
    Player(int width,int height);
    
    int x() const;
    int y() const;
    
    void move(char step);
//    bool check_mines(int i,int j);
    void clean_mine(list<string> explored);
    
    list<string> mine_info();
    
    
private:
    int m_x;
    int m_y;
    
    int m_W;
    int m_H;
    list<string> m_mines;
    
    void set_mine(int xmine, int ymine);
    
    
    
    Arena* m_arena;
    //    ???
};




#endif /* Player_hpp */

// type varname
// type* varname
// type * varname
// type *varname

// type* varname = init_val_address, * var2name = init_val2_Address;
// int a1,a2;
// int* a1;  declare int* a1 and int a2


