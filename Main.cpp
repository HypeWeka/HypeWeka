#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;
//эта хуйня не робит
void setMap(char **k, int *h, int *w,int x,int y)
{
 
    for(int i=0;i<*h;i++){
        for(int j=0;j<*w;j++){
            if(i==0 || i==*h-1){k[i][j] = 'w';}
            else if(j==0 || j==*w-1){k[i][j] = 'w';}
            else {k[i][j] = ' ';}
        }
    }
 
    k[x][y]='*';
    k[x+1][y]='*';
    k[x+2][y]='*';
    k[x+1][y-1]='*';
    k[x+1][y+1]='*';
    k[x+3][y-1]='*';
    k[x+3][y+1]='*';
}
 
void printMap(char **m, int* h, int *w){
    for(int i=0;i<*h;i++){
        for(int j=0;j<*w;j++){
            cout<<m[i][j];
        }
    cout<<endl;
    } 
}
    
void clearscreen()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
int main(){
    int height, width;
    cout<<"Enter height and width of a map"<<endl;
    cin>>height>>width;
    int x=8,y=6;
    char** map = new char* [height];
    for(int i=0;i<height;i++){
        map[i] = new char[width];
    }
    setMap(map, &height, &width, x, y);
    char move;
    while(true)
        {
        clearscreen();
        printMap(map,&height, &width);
        move=getch();
        if(move == 'w'  && x>1)
        {
            map[x+1][y+2]=' ';
            map[x+1][y+1]=' ';
            map[x][y]=' ';
            map[x+2][y-2]=' ';
            map[x+2][y-1]=' ';
            map[x+2][y+2]=' ';
            map[x+2][y+1]=' ';
            map[x+1][y]=' ';
            map[x+2][y]=' ';
            map[x+1][y-1]=' ';
            map[x+3][y]=' ';
            map[x+4][y]=' ';
            map[x+1][y+1]=' ';
            map[x+3][y-1]=' ';
            map[x+3][y+1]=' ';
            map[--x][y]='*';
            map[x+1][y]='*';
            map[x+2][y]='*';
            map[x+1][y-1]='*';
            map[x+1][y+1]='*';
            map[x+3][y-1]='*';
            map[x+3][y+1]='*';
        }
        if(move=='s' && x<height-6)
{
    map[x][y]=' ';
    map[x+2][y-2]=' ';
    map[x+2][y-1]=' ';
    map[x+2][y+2]=' ';
    map[x+2][y+1]=' ';
    map[x+1][y+2]=' ';
    map[x+1][y+1]=' ';
    map[x+1][y]=' ';
    map[x+2][y]=' ';
    map[x+1][y-1]=' ';
    map[x+1][y+1]=' ';
    map[x+3][y-1]=' ';
    map[x+3][y+1]=' ';
    map[++x][y]=' ';
    map[x+3][y]='*';
    map[x+4][y]='*';
    map[x+2][y]='*';
    map[x+1][y-1]='*';
    map[x+1][y+1]='*';
    map[x+3][y-1]='*';
    map[x+3][y+1]='*';
        }
        if(move=='d' && y<width-5)
{
    map[x+1][y+2]=' ';
    map[x+1][y+1]=' ';
    map[x][y]=' ';
    map[x+2][y-2]=' ';
    map[x+2][y-1]=' ';
    map[x+1][y]=' ';
    map[x+2][y]=' ';
    map[x+1][y-1]=' ';
    map[x+3][y]=' ';
    map[x+4][y]=' ';
    map[x+1][y+1]=' ';
    map[x+3][y-1]=' ';
    map[x+3][y+1]=' ';
    map[x][++y]=' ';
    map[x+1][y]=' ';
    map[x+2][y+2]='*';
    map[x+2][y+1]='*';
    map[x+2][y]='*';
    map[x+1][y-1]='*';
    map[x+1][y+1]='*';
    map[x+3][y-1]='*';
    map[x+3][y+1]='*';
        }
 
        if(move=='a' && y>3)
        {
            map[x+1][y+2]=' ';
            map[x+1][y+1]=' ';
            map[x][y]=' ';
            map[x+1][y]=' ';
            map[x+2][y]=' ';
            map[x+1][y-1]=' ';
            map[x+3][y]=' ';
            map[x+4][y]=' ';
            map[x+1][y+1]=' ';
            map[x+3][y-1]=' ';
            map[x+3][y+1]=' ';
            map[x][--y]=' ';
            map[x+1][y]=' ';
            map[x+2][y-2]='*';
            map[x+2][y-1]='*';
            map[x+2][y]='*';
            map[x+1][y-1]='*';
            map[x+1][y+1]='*';
            map[x+3][y-1]='*';
            map[x+3][y+1]='*';
        }
   }
   return 0;
}
