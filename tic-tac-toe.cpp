#include<iostream>
#include<ctime>
///imp when we pass an array it decays into a pointer............-------------
void drawboard(char *spaces); //spaces will be 1-d array that will keep track of all markers
                               //like what spots are taken and what are not.
void playermove(char *spaces,char player);
void computermove(char *spaces,char computer);
bool checkwinner(char *spaces,char player,char computer);
bool checktie(char *spaces);

int main()
{
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer ='O';
    bool running =true;
    drawboard(spaces); //pass in our array which decays to a pointer😗

    while(running)
    {
        playermove(spaces,player);  
  drawboard(spaces);
  if(checkwinner(spaces,player,computer))
  {
   //running = false;
    break;
  }
  else if(checktie(spaces))
  {
   // running= false;
    break;
  }
  computermove(spaces,computer);
  drawboard(spaces);
  if(checkwinner(spaces,player,computer))
  {
   // running = false;
    break;
  }
  else if(checktie(spaces)== true)
  {
   // running= false;
    break;
  }
    }
    
return 0;
}
void drawboard(char *spaces) //*WHEN WE PASS AN ARRAY TO A FUNCTION IT DECAYS TO A POINTER.
{


std::cout << "  " << spaces[0] <<"  |   " << spaces[1] <<" | "<< spaces[2]<<"\n";
std::cout<<"_____|_____|_____ \n";
std::cout<<"     |     |      \n";
std::cout << "  " << spaces[3] <<"  |   " << spaces[4] <<" | "<< spaces[5]<<"\n";

std::cout<<"_____|_____|_____ \n";
std::cout << "  " << spaces[6] <<"  |   " << spaces[7] <<" | "<< spaces[8]<<"\n";
std::cout<<"     |     | \n";
}

void playermove(char *spaces,char player)
{
    int number;
    do
    {
    std::cout<<"Enter the spot to place 1-9 \n";
    std::cin>>number;
    number--;
    if(spaces[number] == ' ')
    {
        spaces[number]= player;
        break;
    }
    } while (!number>0 || !number < 8);
     

}
void computermove(char *spaces,char computer)
{
    int number;
    srand(time(0));

    while(1)
    {
        number = rand()%9;
        if(spaces[number]== ' ')
        {
            spaces[number]= computer;
            break;
        }

    }
}
bool checkwinner(char *spaces,char player,char computer)
{
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
         spaces[0]==player?std::cout<<"you won\n" : std::cout<<"computer won\n ";
    }
     else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        spaces[3]==player?std::cout<<"you won\n" : std::cout<<"computer won\n ";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        spaces[6]==player?std::cout<<"you won\n" : std::cout<<"computer won \n";
    }
     else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        spaces[0]==player?std::cout<<"you won\n" : std::cout<<"computer won\n ";
    }
     else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        spaces[1]==player?std::cout<<"you won\n" : std::cout<<"computer won \n";
    }
     else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        spaces[2]==player?std::cout<<"you won\n" : std::cout<<"computer won\n ";
    }
     else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        spaces[0]==player?std::cout<<"you won\n" : std::cout<<"computer won\n ";
    }
     else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        spaces[2]==player?std::cout<<"you won\n" : std::cout<<"computer won\n ";
    }
    else{
        return false;
    }
    

    return true;
}
bool checktie(char *spaces)
{
    for(int i = 0; i < 9; i++)
    {
if(spaces[i] == ' '){
return false;
}
    }
std::cout << "IT'S A TIE!\n";
return true;
    
     return 0;

}
