#include "Zombies.hpp"
#include "Player.hpp"
#include "util.hpp"
#include "Arena.hpp"
Zombies::Zombies(int width,int height){
    m_W = width;
    m_H = height;
}


void Zombies::generate_Zombies(Player* p_pt,int n_Zs){
    
    //    m_arena  = a_pt;
    m_player = p_pt;
    m_n_Zs   = n_Zs;
    
    //    m_W = m_arena->W();
    //    m_H = m_arena->H();
    bool flag;
    
    //Include the loc of the player
    int loc_temp[2];
    loc_temp[0] = m_player->x();
    loc_temp[1] = m_player->y();
    string loc_str = loc2str(loc_temp);
    m_loc.push_back(loc_str);
    
    cout<<" "<<loc_str<<" "<<endl;
    
    for(int i=1;i<=m_n_Zs;i++){
        flag = false;
        int ii=0;
        while(!flag){
            cout<<ii<<" ";
            ii++;
            flag = true;
            loc_temp[0] = rand()%m_W;
            loc_temp[1] = rand()%m_H;
            cout << loc_temp[0] <<" "<<loc_temp[1]<<endl;
            loc_str = loc2str(loc_temp);
            cout <<loc_str<<endl;
            if(find(m_loc.begin(), m_loc.end(), loc_str) != m_loc.end())
                flag=false;
        }
        m_loc.push_back(loc_str);
        cout<<" "<<loc_str<<" "<<endl;
        
    }
    m_loc.pop_front();
    
}

void Zombies::print_Z_loc(){
    for (auto v : m_loc)
        cout<<v<<" ";
}



bool Zombies::check_Zombie(int i,int j){
    int ans=false;
    if(find(m_loc.begin(), m_loc.end(), loc2strij(i,j)) != m_loc.end())
        ans=true;
    return ans;
}


void Zombies::kill(string loc_str){
    m_loc.remove(loc_str);
}


void Zombies::move(){
    int loc_move[2];
    string loc_str_move_i;
    int move_dir;
    for(int i=1;i<=m_n_Zs;i++){
        
        loc_str_move_i=m_loc.front();
        m_loc.pop_front();
        str2loc(loc_str_move_i, loc_move);
        
        move_dir = rand()%5;
        
        if(move_dir==1 && loc_move[1]!=0)
            loc_move[1]-=1;
        else if(move_dir==2 && loc_move[1]<m_H-1)
            loc_move[1]+=1;
        else if(move_dir==3 && loc_move[0]!=0)
            loc_move[0]-=1;
        else if(move_dir==4 && loc_move[0]<m_W-1)
            loc_move[0]+=1;
        m_loc.push_back(loc2str(loc_move));
        
        
    }
    
}


size_t Zombies::num_Zombies(){
    return m_loc.size();
}

