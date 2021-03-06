#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAPX 80
#define MAPY 21

void create_map(int arr[MAPY][MAPX]);
void print_map(int arr[MAPY][MAPX]);
void create_tall_grass(int arr[MAPY][MAPX]);
void create_clearings(int arr[MAPY][MAPX]);
void create_borders(int arr[MAPY][MAPX]);
void create_path(int arr[MAPY][MAPX]);
int minimum(int x, int y);
int maximum(int x, int y);
int main()
{
    int map[MAPY][MAPX];
    for(int i=0;i<MAPY;i++){
        for(int j=0;j<MAPX;j++){
            map[i][j]=-1;
        }
    }
    create_map(map);
    print_map(map);
    return 0;
}

void create_map(int map[MAPY][MAPX]){
create_tall_grass(map);
create_clearings(map);
create_borders(map);
create_path(map);
}

void create_tall_grass(int map[MAPY][MAPX]){
    srand(time(NULL));
    int x= rand()%20+10;
    int y= rand()%10+5;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            map[i][j]=2;
        }
    }
    x=rand()%25+40;
    y=rand()%5+12;
     for(int i=MAPY-1;i>y;i--){
        for(int j=MAPX-1;j>x;j--){
            map[i][j]=2;
        }
    }
}
void create_clearings(int map[MAPY][MAPX]){
     srand(time(NULL));
    int x= rand()%20+10;
    int y=rand()%5+12;
    for(int i=MAPY-1;i>y;i--){
        for(int j=0;j<x;j++){
            map[i][j]=0;
        }
    }
    x=rand()%25+40;
    y= rand()%10+5;
     for(int i=0;i<y;i++){
        for(int j=MAPX-1;j>x;j--){
            map[i][j]=0;
        }
    }
}
void create_borders(int map[MAPY][MAPX]){
for(int i=0;i<MAPX;i++){
    map[0][i]=5;
    map[MAPY-1][i]=5;
}
for(int i=0;i<MAPY;i++){
    map[i][0]=5;
    map[i][MAPX-1]=5;
}
}
void create_path(int map[MAPY][MAPX]){
srand(time(NULL));
int y_east= rand()%14+5;
int y_west= rand()%14+5;
map[y_east][MAPX-1]=1;
map[y_west][0]=1;
int x_north= rand()%40+20;
int x_south= rand()%40+20;
map[0][x_north]=1;
map[MAPY-1][x_south]=1;
int middle_x = (x_north+x_south)/2;
int middle_y = (y_east+y_west)/2;
map[middle_y][middle_x]=1;
for(int i=0;i<=middle_y;i++){
    map[i][x_north]=1;
}
for(int i=MAPY-1;i>=middle_y;i--){
    map[i][x_south]=1;
}
int min_x = minimum(x_south, x_north);
int max_x =maximum(x_south, x_north);
for(int i=min_x;i<max_x;i++){
    map[middle_y][i]=1;
}

for(int i=0;i<=middle_x;i++){
    map[y_west][i]=1;
}
for(int i=MAPX-1;i>=middle_x;i--){
    map[y_east][i]=1;
}
int min_y = minimum(y_west, y_east);
int max_y = maximum(y_west, y_east);
for(int i=min_y;i<max_y;i++){
    map[i][middle_x]=1;
}

int random_poke = rand()%16+3;
int mart_or_center = rand()%2;
for(int i=y_west+1;i<y_west+3;i++){
    for(int j=random_poke;j<random_poke+2;j++){
        if(mart_or_center==0){
            map[i][j]=4;
        }
        else{
            map[i][j]=3;
        }
    }
}
random_poke = rand()%16+63;
for(int i=y_east-1;i>y_east-3;i--){
    for(int j=random_poke;j>random_poke-2;j--){
         if(mart_or_center==1){
            map[i][j]=4;
        }
        else{
            map[i][j]=3;
        }
    }
}
}



int minimum(int x, int y){
    if(x>y){
        return y;
    }
    else{
        return x;
    }
}
int maximum(int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}


void print_map(int map[MAPY][MAPX]){
    int rando;
for(int i=0; i<MAPY;i++){
	for(int j=0;j<MAPX;j++){
		switch(map[i][j]){
		    case -1:
		    rando = rand()%100;
		    if(rando<60){
		        printf(":");
		    }
		    else if(rando<90){
		        printf(".");
		    }
		    else if(rando<95){
		        printf("%%");
		    }
		    else{
		        printf("|");
		    }
			break;
			case 0:
			printf(".");
			break;
			case 1:
			printf("#");
			break;
			case 2:
			printf(":");
			break;
			case 3:
			printf("C");
			break;
			case 4:
			printf("M");
			break;
			case 5:
			printf("%%");
			break;
			default:
			printf(".");
			break;
	}
	}
	printf("\n");
}
}