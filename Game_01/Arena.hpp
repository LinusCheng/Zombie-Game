#ifndef Arena_hpp
#define Arena_hpp

#include <stdio.h>
#include <iostream>
#include "Zombies.hpp"
//#include "Player.hpp"
using namespace std;


class Arena{
public:
    Arena(int width,int height);
    
    int H();
    int W();
//    void show(int p_x,int p_y,Zombies* z_pt,Player* pl_pt);
    list<string> show(int p_x,int p_y,Zombies* z_pt,list<string> mines_list);

    
private:
    int m_W;
    int m_H;
    
};



#endif /* Arena_hpp */
