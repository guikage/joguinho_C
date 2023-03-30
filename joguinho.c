#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char ** initCanvas(){
	char ** canvas;
	int i, j, k;
	canvas = malloc(sizeof(int*) * 15);
	for(i=0; i<15; i++){
		canvas[i] = malloc(sizeof(int*) * 15);
	}
	srand(time(NULL));
	for(i = 0; i < 15; i++){
		for(j = 0; j < 15; j++){
			k = rand()%4;
			if(k == 0){
				canvas[i][j] = 'X';
			} else {
				canvas[i][j] = ' ';
			}
		}
	}
	canvas[7][7] = '0';
	return canvas;
}

int mudaCoord(char tecla, int * coord, char ** canvas){
	if(tecla == 'w'){
		if(coord[0] != 0){
			if(canvas[coord[0]-1][coord[1]] == ' '){
				return -1;
			}
		}
	}
	else if(tecla == 's'){
		if(coord[0] != 14){
			if(canvas[coord[0]+1][coord[1]] == ' '){
				return +1;
			}
		}
	}
	if(tecla == 'a'){
		if(coord[1] != 0){
			if(canvas[coord[0]][coord[1]-1] == ' '){
				return -1;
			}
		}
	}
	else if(tecla == 'd'){
		if(coord[1] != 14){
			if(canvas[coord[0]][coord[1]+1] == ' '){
				return +1;
			}
		}
	}
	return 0;
}

int main(){
	int i, j;
	char ** canvas;
	int coord[2];
	char tecla;
	coord[0] = 7;
	coord[1] = 7;

	canvas = initCanvas();
	
	for(;;){
		system("clear");
		for(i=0; i<15; i++){
			for(j=0; j<15; j++){
				putchar(canvas[i][j]);
			}
			putchar('\n');
		}
		tecla = getc(stdin);
		canvas[coord[0]][coord[1]] = ' ';
		if(tecla == 'w' || tecla == 's'){
			coord[0] += mudaCoord(tecla, coord, canvas);
		}
		else if(tecla == 'a' || tecla == 'd'){
			coord[1] += mudaCoord(tecla, coord, canvas);
		}
		canvas[coord[0]][coord[1]] = '0';
	}
	return 0;
}
