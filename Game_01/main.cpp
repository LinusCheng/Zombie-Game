#include <iostream>
#include <random>
#include <cstdlib>
#include "Zombies.hpp"
#include "Player.hpp"
#include "util.hpp"
#include "Arena.hpp"


using namespace std;



int main(int argc, const char * argv[]) {
    char step;
    bool alive = true;
    int width;
    int height;
    int num_Zombies = 10;
    list<string> explored_mines;
    list<string> mines_list;
    
    bool try_again = true;
    string try_again_str;
    clearScreen();

    while(try_again){
        alive = true;
        mines_list.clear();
        cout << "Enter the width\n";
        cin  >> width;
        cout << "Enter the height\n";
        cin  >> height;
        
        bool inputcheck=true;
        
        while(inputcheck){
        cout << "Enter the Numbers of Zombies, ex 5.\n";
            cin  >> num_Zombies;
            if(num_Zombies<width*height/2){
                inputcheck = false;
                break;
            }
            cout<<"Too many Zombies"<<endl;
        }

        
        Arena arena(width,height);
        Player p_1(width,height);
        Zombies zs(width,height);
        zs.generate_Zombies(&p_1,num_Zombies);
        
        
        arena.show(p_1.x(),p_1.y(),&zs,mines_list);
        
        
        cout<<"Enter An Action..."<<endl;
        
        while(alive){
            
            cin >> step;
            zs.move();
            
            if(step=='q'){
                alive=false;
                break;
            }
            else if(step=='w' ||step=='s'||step=='a'||step=='d'||step=='f')
                p_1.move(step);
            else{
                cout <<"Wrong Key"<<endl;
                continue;
            }
            
            mines_list = p_1.mine_info();
            
            
            if (zs.check_Zombie(p_1.x(), p_1.y())){
                alive=false;
                arena.show(p_1.x(),p_1.y(),&zs,mines_list);
                cout<<"Game Over"<<endl;
                
            }
            
            else{
                explored_mines = arena.show(p_1.x(),p_1.y(),&zs,mines_list);
                p_1.clean_mine(explored_mines);
                
                if(zs.num_Zombies()==0){
                    alive=false;
                    cout<<"You win!!"<<endl;
                    cout<<"congratulation!!"<<endl;
                }
                
                
            }
            
            }
        
        inputcheck=true;
        cout<<"Try again? (Y/N)"<<endl;
        
        while(inputcheck){
            cin>>try_again_str;
                if(try_again_str=="y" ||try_again_str=="Y" ||try_again_str=="N" ||try_again_str=="n"){
                    inputcheck=false;
                    break;
                }
            cout<<"Please input Y or N"<<endl;
        }
            if(try_again_str=="y" ||try_again_str=="Y"){
                clearScreen();
                cout<<"Let's play again!"<<endl;
            }
            else{
                clearScreen();
                cout<<"Good bye!\n\n\n\n"<<endl;
                try_again=false;
            }

        
        }
    
    return 0;
}




