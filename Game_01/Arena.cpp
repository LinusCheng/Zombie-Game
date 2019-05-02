#include "Zombies.hpp"
//#include "Player.hpp"
#include "util.hpp"
#include "Arena.hpp"


Arena::Arena(int width,int height){
    m_W = width;
    m_H = height;
}

int Arena::W(){
    return m_W;
}
int Arena::H(){
    return m_H;
}



//void Arena::show(int p_x, int p_y,Zombies* z_pt,Player* pl_pt){
list<string> Arena::show(int p_x, int p_y,Zombies* z_pt,list<string> mines_list){

    clearScreen();
    
    list<string> explored;
    
    cout<<"+";
    for (int i=0;i<m_W;i++)
        cout<<"-";
    cout<<"+"<<endl;
    
    
    
    
    for (int j=0;j<m_H;j++){
        cout<<"|";
        for (int i=0;i<m_W;i++){
            
            if(z_pt->check_Zombie(i,j) && check_mines(i, j,mines_list)){
                cout <<"W";
                z_pt->kill(loc2strij(i,j));
                explored.push_back(loc2strij(i,j));
            }
            
            else if(z_pt->check_Zombie(i,j) && i ==p_x && j==p_y){
                cout <<"G";
            }
            
            else if(z_pt->check_Zombie(i,j)){
                cout <<"z";
            }
            else if(i ==p_x && j==p_y && check_mines(i, j,mines_list))
                cout <<"@";
            
            else if(i ==p_x && j==p_y)
                cout <<"A";
            else if (check_mines(i, j,mines_list))
                cout <<"M";
            else
                cout <<" ";
        }
        cout<<"|"<<endl;
    }
    
    cout<<"+";
    for (int i=0;i<m_W;i++)
        cout<<"-";
    cout<<"+"<<endl;
    
    return explored;
}




//void Arena::show(int p_x, int p_y){
//    clearScreen();
//
//    cout<<"+";
//    for (int i=0;i<m_W;i++)
//        cout<<"-";
//    cout<<"+"<<endl;
//
//
//    for (int j=0;j<m_H;j++){
//        cout<<"|";
//        for (int i=0;i<m_W;i++){
//            if(i ==p_x && j==p_y)
//                cout <<"A";
//            else
//                cout <<" ";
//        }
//        cout<<"|"<<endl;
//    }
//
//    cout<<"+";
//    for (int i=0;i<m_W;i++)
//        cout<<"-";
//    cout<<"+"<<endl;
//
//}
