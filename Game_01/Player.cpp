#include "Zombies.hpp"
#include "Player.hpp"
#include "util.hpp"
#include "Arena.hpp"

//Player::Player(Arena* a_pt,int width,int height){
Player::Player(int width,int height){
    
    //m_x = m_W;
    //m_y = m_H;
    
    //    m_arena = a_pt;
    //??
    //pointer_obj->func()  := [*(pointer_obj)].func()
    //* a*b
    //int* a;
    // *(pointer)
    m_W = width;
    m_H = height;
    //    m_x = rand()%m_arena->W();
    //    m_y = rand()%m_arena->H();
    m_x = rand()%m_W;
    m_y = rand()%m_H;
    //???
    
    
    
    
}

int Player::x() const{
    return m_x;
}

int Player::y() const{
    return m_y;
}


void Player::set_mine(int xmine, int ymine){
    m_mines.push_back(loc2strij(xmine,ymine));
}


//bool Player::check_mines(int i,int j){
//    int ans=false;
//    if(find(m_mines.begin(), m_mines.end(), loc2strij(i,j)) != m_mines.end())
//        ans=true;
//    return ans;
//}

list<string> Player::mine_info(){
    return m_mines;
}



void Player::move(char step){
    if(step=='w'){
        if(m_y-1>=0)
            m_y--;
    }
    else if(step=='s'){
        if(m_y+1<m_H)
            m_y++;
    }
    else if (step=='a'){
        if(m_x-1>=0)
            m_x--;
    }
    else if (step=='d'){
        if(m_x+1<m_W)
            m_x++;
    }
    else if (step=='f'){
        set_mine(m_x, m_y);
    }
    
}

void Player::clean_mine(list<string> explored){
    
    for (list<string>::iterator it=explored.begin(); it != explored.end(); ++it){
        m_mines.remove(*it);
    }
    
}


