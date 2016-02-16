// Урок_25.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
int tableHuman[c][s];
int tableCpu[c][s];
char hstring[12]={" ""A""B""C""D""E""F""G""H""I""J"};
unsigned int ship4=1;int ship3=2;int ship2=3;int ship1=4;
int compl=1;
bool menu();
void setTable(int table[c][s]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			table[i][j]=0;
		}
	}
}
struct aim{
	int x;
	int y;
};
void printTable(int table[c][s], int x, int y){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=x;
	coord.Y=y;
	system("color 1F");
	SetConsoleCursorPosition(hendle,coord);
	cout<<hstring;
	coord.Y=y+1;
	for (int i=0;i<10;i++){
		SetConsoleCursorPosition(hendle,coord);
		cout<<i;
		coord.Y++;
	}
	coord.X=x+1;
	coord.Y=y+1;
	SetConsoleCursorPosition(hendle,coord);
	for (int i = 0; i < c; i++)
    {
	  for (int j = 0; j < s; j++)
        {
			if(table[i][j]==0){
			cout<<" ";
			continue;
			}
			if(table[i][j]==1){
				cout<<"@";
			continue;
			}
			//cout<<table[i][j];
        }
	  coord.Y++;
	  SetConsoleCursorPosition(hendle,coord);
}
}
int chekLocation(int table[c][s],int size,int dir, int x, int y){
	int l = 1;
	switch (dir)
	{
		case 0:
		if (y+size>10){
			l = 0;
		}
		if (table[x-1][y-1] == 1){
		l = 0;
			/*X      
			   ship*/
		}
		if (table[x-1][y+size] == 1){
		l = 0;
			/*	   X 
			   ship*/
		}
		if (table[x+1][y-1] == 1){
		l = 0;
			/* ship    
			  X*/
		}
		if (table[x+1][y+size] == 1){
		l = 0;
			/*ship    
				  X*/
		}
		if (table[x][y-1] == 1){
		l = 0;
			/*Xship*/
		}
		if (table[x][y+size] == 1){
		l = 0;
			/*shipX*/
		}
		for (int i = 0; i < size; i++){
			if (table[x-1][y+i] == 1){
			l = 0;
				/*XXXX
				  ship*/
			}
			if (table[x+1][y+i] == 1){
			l = 0;
				/*ship    
				  XXXX*/
			}
		}
		break;
	case 1:
		if (x+size>10){
			l = 0;
		}
		if (table[x-1][y-1] == 1){
			l = 0;
			/*X      
			   s    
			   h   
			   i     
			   p*/
		}
		if (table[x-1][y+1] == 1){
			l = 0;
			/*X    
			 s    
			 h   
			 i     
			 p*/
		}
		if (table[x+size][y-1] == 1){
			l = 0;
		   /*s    
			 h  
			 i    
			 p    
			X*/
		}
		if (table[x+size][y+1] == 1){
			l = 0;
		  /*s    
			h   
			i     
			p    
			 X*/
		}
		if (table[x-1][y] == 1){
			l = 0;
		  /*X     
			s    
			h   
		    i     
			p*/
		}
		if (table[x+size][y] == 1){
			l = 0;
		  /*s    
			h   
			i     
			p    
			X*/
		}
		for (int i = 0; i < size; i++)
		{
			if (table[x+i][y-1] == 1){
			l = 0;
			  /*Xs    
				Xh   
				Xi     
				Xp*/
			}
			if (table[x+i][y+1] == 1){
			l = 0;
			  /*sX    
				hX   
				iX     
				pX*/
			}
}
		break;
}
	return l;
}
int setShip(int table[c][s],int size,int x,int y,int dir,int a){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
		int l=0;
		int set=0;
		l=chekLocation(table,size,dir,x,y);
		if(l==1){
		switch (dir){
		case 1: for(int i=0;i<size;i++)
			table[x+i][y]=1;
			break;
		case 0: for(int i=0;i<size;i++)
			table[x][y+i]=1;
			break;
		}
		if(a==0){
		coord.X=0;
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Выполнено!"<<endl;
		Sleep(800);
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"          "<<endl;
		}
		set=1;
		}
		else if (l==0){
			if(a==0){
		coord.X=0;
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Так ставить нельзя!"<<endl;
		Sleep(800);
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"                   "<<endl;
		}
		}
			return set;
}
void setRandom(int table[c][s],int size){
		int x=0;
		int y=0;
		int dir=0;	
		marker:x=rand()%10+1;
		y=rand()%10+1;
		dir=rand()%2;
		//setShip(table,size,x,y,dir,1);
		int set=setShip(table,size,x,y,dir,1);
		if (set==0)
			goto marker;
}
void coordinates(int x, int y);
aim* movesOnTable(){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	int a=0;
	int b=0;
	aim *current=new aim;
	coord.X=5;
	coord.Y=5;
	SetConsoleCursorPosition(hendle,coord);
	int key=0;
	do 
	{
		key=_gettch();
		switch (key)
		{
		case 80: 
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl;
		coord.Y++;
		if(coord.Y>10){
		coord.Y=10;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.X;
		b=coord.Y-1;
		coordinates(a,b);
			break;
		case 72:
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl; 
		coord.Y--;
		if(coord.Y<1){
			coord.Y=1;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.X;
		b=coord.Y-1;
		coordinates(a,b);
			break;
		case 77: 
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl;
		coord.X++;
		if(coord.X>10){
			coord.X=10;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.X;
		b=coord.Y-1;
		coordinates(a,b);
			break;
	    case 75:
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl; 
		coord.X--;
		if(coord.X<1){
			coord.X=1;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.X;
		b=coord.Y-1;
		coordinates(a,b);
			break;		
		case 13: 
			current->y=coord.X-1;
			current->x=coord.Y-1;
			
			goto marker;
			break;
		case 27:
			menu();
			}
}
	while(key!=27);
	marker:return current;
}
aim* movesOnTableRight(){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	int a=0;
	int b=0;
	aim *current=new aim;
	coord.X=20;
	coord.Y=5;
	SetConsoleCursorPosition(hendle,coord);
	int key=0;
	do 
	{
		key=_gettch();
		switch (key)
		{
		case 80: 
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl;
		coord.Y++;
		if(coord.Y>10){
		coord.Y=10;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.Y;
		b=coord.X;
		coordinates(b-15,a-1);
			break;
		case 72:
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl; 
		coord.Y--;
		if(coord.Y<1){
			coord.Y=1;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.Y;
		b=coord.X;
		coordinates(b-15,a-1);
			break;
		case 77: 
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl;
		coord.X++;
		if(coord.X>25){
			coord.X=25;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.Y;
		b=coord.X;
		coordinates(b-15,a-1);
			break;
	    case 75:
		SetConsoleCursorPosition(hendle,coord);
		cout<<" "<<endl; 
		coord.X--;
		if(coord.X<16){
			coord.X=16;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"+"<<endl;
		a=coord.Y;
		b=coord.X;
		coordinates(b-15,a-1);
			break;		
		case 13: 
			a=current->y=coord.Y;
			b=current->x=coord.X;
			coordinates(b-15,a);
			movesOnTableRight();
			goto marker;
			break;
		case 27:
			menu();
			}
}
	while(key!=27);
	marker:return current;
}
int setManual(){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	printTable(tableHuman,0,0);
	unsigned int size=0; 
	unsigned int dir=0;
	aim* current=new aim;
	current=movesOnTable();
	coord.X=0;	
	marker:do {
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
	    cout<<"Введите количество палуб от 1 до 4 -> ";
		cin>>size;
	if(size<1||size>4){
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Введите корректное значение!           ";
		Sleep(1700);
		}
		
}
	while (size<1||size>4);
	if(size==4&&ship4==0){
		coord.X=0;
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Такие корабли уже закончились, выберите другой";
		Sleep(1700);
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"                                              ";
		goto marker;
	}
	if(size==3&&ship3==0){
		coord.X=0;
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Такие корабли уже закончились, выберите другой";
		Sleep(1700);
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"                                              ";
		goto marker;
	}	
	if(size==2&&ship2==0){
		coord.X=0;
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Такие корабли уже закончились, выберите другой";
		Sleep(1700);
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"                                              ";
		goto marker;
	}	
	if(size==1&&ship1==0){
		coord.X=0;
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Такие корабли уже закончились, выберите другой";
		Sleep(1700);
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"                                              ";
		goto marker;
	}
		
	do{
		coord.X=0;
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Направление-> 0-горизонталь, 1-вертикаль -> "; 
		cin>>dir;
		if(dir<0||dir>1){
		coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Введите корректное значение!                 ";
		Sleep(1700);
	}
	}
	while (dir<0||dir>1);
	coord.Y=14;
		SetConsoleCursorPosition(hendle,coord);
	cout<<"                                             ";
	int x=0;
	x=current->x;
	int y=0;
	y=current->y;
	int set=setShip(tableHuman,size,x,y,dir,0);
	if(set==1){
		if(size==1)
			ship1--;
		if(size==2)
			ship2--;
		if(size==3)
			ship3--;
		if(size==4)
			ship4--;
	}
	return 0;
}
void chekShoot(int tableHuman[c][s],int x,int y);
void coordinates(int x, int y){
		HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord;
		coord.X=0;
		coord.Y=15;
		SetConsoleCursorPosition(hendle,coord);
		cout<<"Вертикаль= "<<hstring[x]<<" Горизонталь= "<<y;
		//chekShoot(tableHuman,y,x);
}
int hit(int table[c][s],int x,int y);
void chekShoot(int table[c][s],int x,int y){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	if(table[x-1][y-1]==2){
			coord.X=0;
			coord.Y=15;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"Уже стреляли";
			Sleep(800);
			coord.Y=14;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"            ";
			coord.X=y;
			coord.Y=x;
			SetConsoleCursorPosition(hendle,coord);	
		}
	if(table[x-1][y-1]==1){
			coord.X=y;
			coord.Y=x;
			SetConsoleCursorPosition(hendle,coord);	
			cout<<"X";
			table[x-1][y-1]=3;
			int h=hit(tableHuman,x,y);
			coord.X=0;
			coord.Y=14;
			SetConsoleCursorPosition(hendle,coord);
			if(h==0){
			cout<<"Убил!";
			Sleep(800);
			coord.Y=14;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"     ";
			}
			if(h==1){
			cout<<"Ранил!";
			Sleep(800);
			coord.Y=14;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"      ";
			}
			coord.X=y;
			coord.Y=x;
			SetConsoleCursorPosition(hendle,coord);
}
	if(table[x-1][y-1]==0){
			coord.X=0;
			coord.Y=14;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"В молоко!";
			Sleep(800);
			coord.Y=14;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"         ";
			table[x-1][y-1]=2;
			coord.X=y;
			coord.Y=x;
			SetConsoleCursorPosition(hendle,coord);
}
}
int hit(int table[c][s],int x,int y){
	int h = 0;
		if (table[x][y-1] == 1){
		h = 1;
			/*Xs*/
		}
		if (table[x][y+1] == 1){
		h = 1;
			/*sX*/
		}
		if (table[x-1][y] == 1){
		h = 1;
			/*X
			  s*/
		}
		if (table[x+1][y] == 1){
		h = 1;
			/*s
			  X*/
		}
		return h;
}
int about();
bool menuNext();
bool menuCompl();
bool menuArrow(){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=33;
	coord.Y=10;
	int key=0;
	do
	{
		key=_gettch();
		switch (key)
		{
		case 80: 
		SetConsoleCursorPosition(hendle,coord);
		cout<<"  "<<endl;
		coord.Y++;
		if(coord.Y>13){
			coord.Y=13;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"->"<<endl;
		break;
		case 72:
		SetConsoleCursorPosition(hendle,coord);
		cout<<"  "<<endl; 
		coord.Y--;
		if(coord.Y<10){
			coord.Y=10;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"->"<<endl;
		break;
		case 13:
		if(coord.Y==10){
			system("CLS");
			menuNext();
			}
		if(coord.Y==11){
			menuCompl();
			}
		if(coord.Y==12){
				about();
			}
		if(coord.Y==13){
			system("CLS");
			coord.X=33;
			coord.Y=10;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"СПАСИБО ЗА ИГРУ;)";
			}
		break;
		case 27: menu();
		break;
		}
}
	while(key!=13);
	return 0;
}
int about(){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	system("CLS");
			coord.X=33;
			coord.Y=11;
			SetConsoleCursorPosition(hendle,coord);
			cout<<"МОРСКОЙ БОЙ by ВОЙНАРОВСКИЙ АЛЕКСАНДР";
	Sleep(3000);
	menu();
			return 0;
}
bool menu(){
	system("CLS");
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=35;
	coord.Y=10;
	//SetConsoleTextAttribute(hendle,00);
	SetConsoleCursorPosition(hendle,coord);
	cout<<"СТАРТ"<<endl;
	coord.Y=11;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"СЛОЖНОСТЬ"<<endl;
	coord.Y=12;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"О ИГРЕ"<<endl;
	coord.Y=13;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"ВЫХОД"<<endl;
	menuArrow();
	return true;
}
int menuArrowNext();
bool menuNext(){
	system("CLS");
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=0;
	coord.Y=15;
	//SetConsoleTextAttribute(hendle,00);
	SetConsoleCursorPosition(hendle,coord);
	cout<<"Расположените корабли вручную или выберите АВТО"<<endl;
	coord.X=35;
	coord.Y=11;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"АВТО"<<endl;
	coord.Y=12;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"РУКАМИ"<<endl;
	menuArrowNext();
	return true;
}
int menuArrowNext(){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=33;
	coord.Y=11;
	int key=0;
	do
	{
		key=_gettch();
		switch (key)
		{
		case 80: 
		SetConsoleCursorPosition(hendle,coord);
		cout<<"  "<<endl;
		coord.Y++;
		if(coord.Y>12){
			coord.Y=12;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"->"<<endl;
		break;
		case 72:
		SetConsoleCursorPosition(hendle,coord);
		cout<<"  "<<endl; 
		coord.Y--;
		if(coord.Y<11){
			coord.Y=11;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"->"<<endl;
		break;
		case 13:
			if(coord.Y==11){
				system("CLS");
				setRandom(tableHuman,4);
				setRandom(tableHuman,3);
				setRandom(tableHuman,3);
				setRandom(tableHuman,2);
				setRandom(tableHuman,2);
				setRandom(tableHuman,2);
				setRandom(tableHuman,1);
				setRandom(tableHuman,1);
				setRandom(tableHuman,1);
				setRandom(tableHuman,1);
				printTable(tableHuman,0,0);
				printTable(tableCpu,15,0);
				
			}
			if(coord.Y==12){
			system("CLS");
				
				setManual();
				printTable(tableHuman,0,0);
				setManual();
				printTable(tableHuman,0,0);
				setManual();
				printTable(tableHuman,0,0);
				setManual();
				printTable(tableHuman,0,0);
				setManual();
				printTable(tableCpu,15,0);
				cout<<ship1;
				return 0;
			}
		break;
		case 27: menu();
		break;
		}
}
	while(key!=13);
	return 0;
}
int menuArrowCompl(){
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=33;
	coord.Y=11;
	int key=0;
	do
	{
		key=_gettch();
		switch (key)
		{
		case 80: 
		SetConsoleCursorPosition(hendle,coord);
		cout<<"  "<<endl;
		coord.Y++;
		if(coord.Y>13){
			coord.Y=13;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"->"<<endl;
		break;
		case 72:
		SetConsoleCursorPosition(hendle,coord);
		cout<<"  "<<endl; 
		coord.Y--;
		if(coord.Y<11){
			coord.Y=11;
		}
		SetConsoleCursorPosition(hendle,coord);
		cout<<"->"<<endl;
		break;
		case 13:
			if(coord.Y==11){
				system("CLS");
				compl=1;
				cout<<" easy";
				}
			if(coord.Y==12){
				system("CLS");
				compl=2;
				cout<<" middle";
				}
			if(coord.Y==13){
				system("CLS");
				compl=3;
				cout<<" hard";
				}
		break;
		case 27: menu();
		break;
		}
}
	while(key!=13);
	return 0;
}
bool menuCompl(){
	system("CLS");
	HANDLE hendle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=0;
	coord.Y=15;
	//SetConsoleTextAttribute(hendle,00);
	SetConsoleCursorPosition(hendle,coord);
	cout<<"Выберите сложность. По умолчанию ""ЛЕГКО"". ""ЖЕСТЯК"" просто Адик)"<<endl;
	coord.X=35;
	coord.Y=11;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"ЛЕГКО"<<endl;
	coord.Y=12;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"СРЕДНЯК"<<endl;
	coord.Y=13;
	SetConsoleCursorPosition(hendle,coord);
	cout<<"ЖЕСТЯК"<<endl;
	menuArrowCompl();
	return true;
}
int _tmain()
{
	setlocale(LC_ALL,"rus");
	srand(time(NULL));
	setTable(tableHuman);
	setTable(tableCpu);
	setRandom(tableCpu,4);
	setRandom(tableCpu,3);
	setRandom(tableCpu,3);
	setRandom(tableCpu,2);
	setRandom(tableCpu,2);
	setRandom(tableCpu,2);
	setRandom(tableCpu,1);
	setRandom(tableCpu,1);
	setRandom(tableCpu,1);
	setRandom(tableCpu,1);
	printTable(tableHuman,0,0);
	printTable(tableCpu,15,0);
	movesOnTable();
	_gettch();
	return 0;
}

