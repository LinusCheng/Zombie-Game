#ifndef Zombies_hpp
#define Zombies_hpp

#include <stdio.h>
#include <cstdlib>
#include <list>
#include <iostream>
#include <random>
#include <string>
#include "Player.hpp"

class Zombies{
public:
    Zombies(int width,int height);
    void generate_Zombies(Player* p_pt,int n_Zs);
    
    void print_Z_loc();
    bool check_Zombie(int i,int j);
    
    void move();
    
    void kill(string loc_str);
    
    size_t num_Zombies();
    
private:
    int m_W;
    int m_H;
    int m_n_Zs;
    
    //    Arena* m_arena;
    Player* m_player;
    list<string> m_loc;
    //unordered_map<pair<int,int>> hash;
    //if (hash.find(xxx)!=hash.end()){...}
    //hash[key]
    
    
    
};


#endif /* Zombies_hpp */

