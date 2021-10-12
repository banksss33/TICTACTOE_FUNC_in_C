#include <stdio.h>

void tictactoe(int x){ //tictactoe func PARAMETER = size of table 
    if (x < 3){
        printf("parameter need to >= 3");
    }
    else{
        char xo;
        int inp;
        int x_win=0,o_win=0;
        char table[x][x];
        int tablepos[x][x];

        for (int rows=0,pos=1;rows<x;rows++){// fill table with *
            for (int column=0;column<x;column++){
                table[rows][column] = '*';
            }
        }

        for (int rows=0,pos=1;rows<x;rows++){// fill table position
            for (int column=0;column<x;column++,pos++){
                tablepos[rows][column] = pos;
            }
        }
        
        printf("Position in table:\n");
        for (int rows=0;rows<x;rows++){// output table position
            for (int column=0;column<x;column++){
                printf("%2d ",tablepos[rows][column]);
            }
            printf("\n");
        }

        while(1){ //input who play first
            printf("Who play first? X or O: ");
            scanf("%c",&xo);
            if (xo == 'x' || xo == 'X' | xo =='o' || xo == 'O'){
                break;
            }
            else{
                printf("Input need to be X or O!\n");
                continue;
            }
        }

        for (int rows=0;rows<x;rows++){// output table
            for (int column=0;column<x;column++){
                printf("%c ",table[rows][column]);
            }
            printf("\n");
        }

        for (int round=0;round<x*x;round++){
            while(1){
                printf("Input table %c: ",xo); //input position
                scanf("%d",&inp);
                if (inp < 1 || inp > x*x){
                    printf("Input need to be bewtween 1-%d\n",x*x);
                    continue;
                }
                else{
                    int not_used = 0;
                    for (int rows=0,pos=1;rows<x;rows++){// check if the position is used;
                        for (int column=0;column<x;column++,pos++){
                            if (inp == tablepos[rows][column]){
                                not_used = 1;
                            }
                        }
                    }
                    if (not_used == 1){
                        break;
                    }
                    else{
                        printf("The position %d is used!\n",inp);
                        continue;
                    }
                }
            }

            if (xo == 'x' || xo == 'X'){
                for (int rows=0;rows<x;rows++){// input table X
                    for (int column=0;column<x;column++){
                        if (inp == tablepos[rows][column]){
                            tablepos[rows][column] = 0;
                            table[rows][column] = 'x';
                        }
                    }
                }
                xo='o';
            }
            else{
                for (int rows=0;rows<x;rows++){// input table O
                    for (int column=0;column<x;column++){
                        if (inp == tablepos[rows][column]){
                            tablepos[rows][column] = 0;
                            table[rows][column] = 'o';
                        }
                    }
                }
                xo='x';
            }

            for (int rows=0;rows<x;rows++){// output table
                for (int column=0;column<x;column++){
                    printf("%c ",table[rows][column]);
                }
                printf("\n");
            }
            
            for (int chcl = 0;chcl < x;chcl++){ // check rows
                int x1 = 0,o=0;
                for (int chr = 0;chr < x;chr++){
                    if (table[chr][chcl] == 'x'){
                        x1 += 1;
                    }
                    else if (table[chr][chcl] == 'o'){
                        o += 1;
                    }
                }
                if (x1 == x){
                    x_win = 1;
                    break;
                }
                else if (o == x){
                    o_win = 1;
                    break;
                }
            }

            for (int chr = 0;chr < x;chr++){ //check column
                if (x_win == 1 || o_win == 1){
                    break;
                }
                int x1 = 0,o = 0;
                for (int chcl = 0;chcl < x;chcl++){
                    if (table[chr][chcl] == 'x'){
                        x1 += 1;
                    }
                    else if (table[chr][chcl] == 'o'){
                        o += 1;
                    }
                }
                if (x1 == x){
                    x_win = 1;
                    break;
                }
                else if (o == x){
                    o_win = 1;
                    break;
                }
            }

            int x1=0,o=0;
            for (int diagnolleft = 0;diagnolleft < x;diagnolleft++){ //check diagnolleft
                if (x_win == 1 || o_win == 1){
                    break;
                }
                if (table[diagnolleft][diagnolleft] == 'x'){
                        x1 += 1;
                }
                else if (table[diagnolleft][diagnolleft] == 'o'){
                        o += 1;
                }
                if (x1 == x){
                    x_win = 1;
                    break;
                }
                else if (o == x){
                    o_win = 1;
                    break;
                }
            }

            x1=0,o=0;
            int rows=0,column=x-1;
            for (int ct = 0;ct<x;ct++,rows++,column--){ //check diagnolright
                if (x_win == 1 || o_win == 1){
                    break;
                }
                if (table[rows][column] == 'x'){
                    x1 += 1;
                }
                else if (table[rows][column] == 'o'){
                    o += 1;
                }
                if (x1 == x){
                    x_win = 1;
                    break;
                }
                else if (o == x){
                    o_win = 1;
                    break;
                }
            }
            if (o_win == 1){
                printf("O is the winner!\n");
                break;
            }
            else if(x_win == 1){
                printf("X is the winner!\n");
                break;
            }
        }
        if (o_win == 0 && x_win == 0){ //if DRAW
            printf("DRAW!\n");
        }
    }
}