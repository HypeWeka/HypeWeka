//na mne menu igri
void setMenu(char **k, int *h, int *w,int x,int y)
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

