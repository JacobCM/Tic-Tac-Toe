//
//  Tic Tac Toe Two.cpp
//  
//
//  Created by Jacob CM on 2016-04-08.
//
//

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

char n1='1',n2='2',n3='3',n4='4',n5='5',n6='6',n7='7',n8='8',n9='9',n;
int turn=1,r,comp;

void game();
void clearBoard();
void printBoard();
void playerTurn(int n);
void compTurn(int comp);
void endCheck();
int computer();
int firstTurn();
int secondTurn();
int winnable();
int loseable();
int randomize();
int testEndCheck();
void testGame();
void testPlayerTurn(int n);

int main (){
    srand(time(0));
    
    cout<<endl;
    printBoard();
    
    cout<<"======================================="<<endl;
    cout<<"||           Tic, Tac, Toe           ||"<<endl;
    cout<<"======================================="<<endl;
    cout<<endl;
    cout<<"You know how to play."<<endl;

    clearBoard();
    
    game();
    
    cout<<"Thanks for playing!!"<<endl;

    return 0;
}

void clearBoard(){
    n1=' ',n2=' ',n3=' ',n4=' ',n5=' ',n6=' ',n7=' ',n8=' ',n9=' ';
}

void printBoard(){
    cout<<" "<<n1<<" | "<<n2<<" | "<<n3<<" "<<endl;
    cout<<" _   _   _ "<<endl;
    cout<<" "<<n4<<" | "<<n5<<" | "<<n6<<" "<<endl;
    cout<<" _   _   _ "<<endl;
    cout<<" "<<n7<<" | "<<n8<<" | "<<n9<<" "<<endl;
    cout<<endl;
}

int computer(){
    if (turn==1)
        return firstTurn();
    else if (winnable()!=0)
        return winnable();
    else if (loseable()!=0)
        return loseable();
    else if (turn==2)
        return secondTurn();
    else
        return randomize();
}
    
int firstTurn(){
    if (n5==' ')
        return 5;
    else
        return 1;
}
    
int secondTurn(){
    if (n1=='X'&&n8=='X')
        return 7;
    else if (n1=='X'&&n6=='X')
        return 3;
    else if (n3=='X'&&n8=='X')
        return 9;
    else if (n3=='X'&&n4=='X')
        return 1;
    else if (n7=='X'&&n2=='X')
        return 1;
    else if (n7=='X'&&n6=='X')
        return 9;
    else if (n9=='X'&&n2=='X')
        return 3;
    else if (n9=='X'&&n4=='X')
        return 7;
    else if (n1=='X'&&n9=='X')
        return 2;
    else if (n3=='X'&&n7=='X')
        return 2;
    else if (n2=='X'&&n4=='X')
        return 1;
    else if (n2=='X'&&n6=='X')
        return 3;
    else if (n6=='X'&&n8=='X')
        return 9;
    else if (n4=='X'&&n8=='X')
        return 7;
    else if (n5=='X'&&n9=='X')
        return 3;
    else
        return randomize();
}

int winnable(){
    
    if (n1==' ' && ((n2=='O'&&n3=='O')||(n5=='O'&&n9=='O')||(n4=='O'&&n7=='O')))
        return 1;
    else if (n2==' ' && ((n1=='O'&&n3=='O')||(n5=='O'&&n8=='O')))
        return 2;
    else if (n3==' ' && ((n1=='O'&&n2=='O')||(n5=='O'&&n7=='O')||(n6=='O'&&n9=='O')))
        return 3;
    else if (n4==' ' && ((n1=='O'&&n7=='O')||(n5=='O'&&n6=='O')))
        return 4;
    else if (n5==' ' && ((n1=='O'&&n9=='O')||(n2=='O'&&n8=='O')||(n3=='O'&&n7=='O')||(n4=='O'&&n6=='O')))
        return 5;
    else if (n6==' ' && ((n3=='O'&&n9=='O')||(n4=='O'&&n5=='O')))
        return 6;
    else if (n7==' ' && ((n1=='O'&&n4=='O')||(n5=='O'&&n3=='O')||(n8=='O'&&n9=='O')))
        return 7;
    else if (n8==' ' && ((n2=='O'&&n5=='O')||(n7=='O'&&n9=='O')))
        return 8;
    else if (n9==' ' && ((n1=='O'&&n5=='O')||(n3=='O'&&n6=='O')||(n7=='O'&&n8=='O')))
        return 9;
    
    return 0;
}

int loseable(){
    
    if (n1==' ' && ((n2=='X'&&n3=='X')||(n5=='X'&&n9=='X')||(n4=='X'&&n7=='X')))
        return 1;
    else if (n2==' ' && ((n1=='X'&&n3=='X')||(n5=='X'&&n8=='X')))
        return 2;
    else if (n3==' ' && ((n1=='X'&&n2=='X')||(n5=='X'&&n7=='X')||(n6=='X'&&n9=='X')))
        return 3;
    else if (n4==' ' && ((n1=='X'&&n7=='X')||(n5=='X'&&n6=='X')))
        return 4;
    else if (n5==' ' && ((n1=='X'&&n9=='X')||(n2=='X'&&n8=='X')||(n3=='X'&&n7=='X')||(n4=='X'&&n6=='X')))
        return 5;
    else if (n6==' ' && ((n3=='X'&&n9=='X')||(n4=='X'&&n5=='X')))
        return 6;
    else if (n7==' ' && ((n1=='X'&&n4=='X')||(n5=='X'&&n3=='X')||(n8=='X'&&n9=='X')))
        return 7;
    else if (n8==' ' && ((n2=='X'&&n5=='X')||(n7=='X'&&n9=='X')))
        return 8;
    else if (n9==' ' && ((n1=='X'&&n5=='X')||(n3=='X'&&n6=='X')||(n7=='X'&&n8=='X')))
        return 9;
    
    return 0;
}

int randomize(){
    r=rand()%9+1;
    if (r==1&&n1!=' ')
        return randomize();
    else if (r==2&&n2!=' ')
        return randomize();
    else if (r==3&&n3!=' ')
        return randomize();
    else if (r==4&&n4!=' ')
        return randomize();
    else if (r==5&&n5!=' ')
        return randomize();
    else if (r==6&&n6!=' ')
        return randomize();
    else if (r==7&&n7!=' ')
        return randomize();
    else if (r==8&&n8!=' ')
        return randomize();
    else if (r==9&&n9!=' ')
        return randomize();
    else
        return r;
}


void endCheck(){
    if ((n1=='X'&&n2=='X'&&n3=='X')||(n1=='X'&&n4=='X'&&n7=='X')||(n1=='X'&&n5=='X'&&n9=='X')||(n2=='X'&&n5=='X'&&n8=='X')||(n3=='X'&&n6=='X'&&n9=='X')||(n8=='X'&&n7=='X'&&n9=='X')||(n4=='X'&&n5=='X'&&n6=='X')||(n3=='X'&&n5=='X'&&n7=='X')){
        cout<<"You WINN!!!!!"<<endl;
        exit(0);}
    if ((n1=='O'&&n2=='O'&&n3=='O')||(n1=='O'&&n4=='O'&&n7=='O')||(n1=='O'&&n5=='O'&&n9=='O')||(n2=='O'&&n5=='O'&&n8=='O')||(n3=='O'&&n6=='O'&&n9=='O')||(n8=='O'&&n7=='O'&&n9=='O')||(n4=='O'&&n5=='O'&&n6=='O')||(n3=='O'&&n5=='O'&&n7=='O')){
        cout<<"You Lose!"<<endl;
        exit(0);}
    if (n1!=' '&&n2!=' '&&n3!=' '&&n4!=' '&&n5!=' '&&n6!=' '&&n7!=' '&&n8!=' '&&n9!=' '){
        cout<<"TIE!!!"<<endl;
        exit(0);}
}

void game(){
    while (true){
        cin>>n;
        cout<<endl;
        
        playerTurn(n);
        
        printBoard();
        
        endCheck();
        
        comp=computer();
        
        cout<<"Computer chose "<<comp<<endl;
        cout<<endl;
        
        compTurn(comp);
        
        printBoard();
        
        endCheck();
        
        turn++;
        cout<<"Your turn again"<<endl;
    }
}

void playerTurn(int n){
    if (n=='1'&&n1==' ')
        n1='X';
    else if (n=='2'&&n2==' ')
        n2='X';
    else if (n=='3'&&n3==' ')
        n3='X';
    else if (n=='4'&&n4==' ')
        n4='X';
    else if (n=='5'&&n5==' ')
        n5='X';
    else if (n=='6'&&n6==' ')
        n6='X';
    else if (n=='7'&&n7==' ')
        n7='X';
    else if (n=='8'&&n8==' ')
        n8='X';
    else if (n=='9'&&n9==' ')
        n9='X';
    else{
        cout<<"Nice try, dont cheat!"<<endl;
        exit(0);}
}

void compTurn(int comp){
    if (comp==1&&n1==' ')
        n1='O';
    else if (comp==2&&n2==' ')
        n2='O';
    else if (comp==3&&n3==' ')
        n3='O';
    else if (comp==4&&n4==' ')
        n4='O';
    else if (comp==5&&n5==' ')
        n5='O';
    else if (comp==6&&n6==' ')
        n6='O';
    else if (comp==7&&n7==' ')
        n7='O';
    else if (comp==8&&n8==' ')
        n8='O';
    else if (comp==9&&n9==' ')
        n9='O';
}



int testEndCheck(){
    if ((n1=='X'&&n2=='X'&&n3=='X')||(n1=='X'&&n4=='X'&&n7=='X')||(n1=='X'&&n5=='X'&&n9=='X')||(n2=='X'&&n5=='X'&&n8=='X')||(n3=='X'&&n6=='X'&&n9=='X')||(n8=='X'&&n7=='X'&&n9=='X')||(n4=='X'&&n5=='X'&&n6=='X')||(n3=='X'&&n5=='X'&&n7=='X')){
        return 1;}
    else if ((n1=='O'&&n2=='O'&&n3=='O')||(n1=='O'&&n4=='O'&&n7=='O')||(n1=='O'&&n5=='O'&&n9=='O')||(n2=='O'&&n5=='O'&&n8=='O')||(n3=='O'&&n6=='O'&&n9=='O')||(n8=='O'&&n7=='O'&&n9=='O')||(n4=='O'&&n5=='O'&&n6=='O')||(n3=='O'&&n5=='O'&&n7=='O')){
        return 2;}
    else if (n1!=' '&&n2!=' '&&n3!=' '&&n4!=' '&&n5!=' '&&n6!=' '&&n7!=' '&&n8!=' '&&n9!=' '){
        return 3;}
    else
        return 0;
}

void testGame(){
    int games=10000000,lost=0;
    for (int i=0;i<games;i++){
        turn=1;
        clearBoard();
    while (true){
        n=randomize();
        testPlayerTurn(n);
        
        if (testEndCheck()==1){
            lost++;
            break;}
        else if (testEndCheck()!=0)
            break;
        comp=computer();
        
        compTurn(comp);
        if (testEndCheck()==1){
            lost++;
            printBoard();
            break;}
        else if (testEndCheck()!=0)
            break;
        
        turn++;
    }
    }
    cout<<"Games: "<<games<<endl;
    cout<<"Lost: "<<lost<<endl;
}

void testPlayerTurn(int n){
    if (n==1&&n1==' ')
        n1='X';
    else if (n==2&&n2==' ')
        n2='X';
    else if (n==3&&n3==' ')
        n3='X';
    else if (n==4&&n4==' ')
        n4='X';
    else if (n==5&&n5==' ')
        n5='X';
    else if (n==6&&n6==' ')
        n6='X';
    else if (n==7&&n7==' ')
        n7='X';
    else if (n==8&&n8==' ')
        n8='X';
    else if (n==9&&n9==' ')
        n9='X';
    else{
        cout<<"Nice try, dont cheat!"<<endl;
        exit(0);}
}



