#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<iostream.h>

class Snake
{
	public :
		Snake(int x,int y){xPos=x; yPos=y;};
		~Snake(){;};

		int length,size,color,speed,xPos,yPos,stIndex,dlIndex;
		int borderColor,snakeColor,scr;
		int objX,objY;
		int xArr[8000];
		int yArr[8000];
		int moveXRight();
		int moveXLeft();
		int moveYUp();
		int moveYDown();
		void store(void);
		void erase(void);
		void init(void);
		void test(int x);
		void putAnObject(void);
		void getAkey(void);
		int score(void);
		void gameOver();
		void restart();
		void level(int x);
};

int Snake::moveXRight()
{
	for(int i=0 ; i<800; i++)
	{
		setcolor(4);
		store();
		circle(xPos++,yPos,4);
		delay(speed);
		erase();
		test(1);
		if(xPos % 10 ==0)
			if (kbhit())
				break;
	}
	return xPos;
}

int Snake::moveXLeft(void)
{
	for(int i=0 ; i<800; i++)
	{
		setcolor(4);
		store();
		circle(xPos--,yPos,4);
		delay(speed);
		erase();
		test(2);
		if(xPos % 10 ==0)
			if (kbhit())
				break;
	}
	return xPos;
}

int Snake::moveYUp()
{
	for(int i=0 ; i<800; i++)
	{
		setcolor(4);
		store();
		circle(xPos,yPos--,4);
		delay(speed);
		erase();
		test(3);
		if(yPos % 10 ==0)
			if (kbhit())
				break;
	}
	return yPos;
}

int Snake::moveYDown()
{
	for(int i=0 ; i<800; i++)
	{
		setcolor(4);
		store();
		circle(xPos,yPos++,4);
		delay(speed);
		erase();
		test(4);
		if(yPos % 10 ==0)
			if (kbhit())
				break;
	}
	return yPos;
}

void Snake::store()
{
	xArr[stIndex]= xPos;
	yArr[stIndex]= yPos;
	stIndex++;
	if (stIndex == size)
		stIndex=0;
}

void Snake::erase()
{
	setcolor(0);
	if(dlIndex-length >=0)
	{
	circle(xArr[dlIndex-length],yArr[dlIndex-length],4);
	}
	else
	circle(xArr[size-abs(dlIndex-length)],yArr[size-abs(dlIndex-length)],4);
	dlIndex++;
	if(dlIndex == size)
		dlIndex =0;
}

void Snake::getAkey(void)
{
	char key;
	for(int k=0 ;k<3 ;k++)
	{
		k=1;	// infinite loop
		key = getch();
		if (key == 'M')
			xPos = moveXRight();
		if(key == 'K')
			xPos = moveXLeft();
		if (key == 'H')
			yPos = moveYUp();
		if(key == 'P')
			yPos = moveYDown();
		if(key == 'q' || key == 'Q')
			exit(1);
	}
}

void Snake::test(int x)
{
	int tst,a;
	switch (x) {
	case 1: {     //when moving right
			tst = getpixel(xPos+4,yPos);
			if(xPos == objX*10 &&yPos == objY*10)
			       a=score();
			level(a);
			if(tst== borderColor || tst == snakeColor)
			gameOver(); break;}// Game over
			//left
	case 2: {	tst = getpixel(xPos-4,yPos);
			if(xPos == objX*10&&yPos == objY*10)
			       a=score();
			level(a);
			if(tst== borderColor || tst == snakeColor)
			gameOver(); break;}// Game over
			//up
	case 3: {	tst = getpixel(xPos,yPos-4);
			if(xPos == objX*10 &&yPos == objY*10)
			      a=score();
			level(a);
			if(tst== borderColor || tst == snakeColor)
				gameOver(); break;}// Game over
			//down
	case 4: {	tst = getpixel(xPos,yPos+4);
			if(xPos == objX*10 &&yPos == objY*10)
				a=score();
			level(a);
			if(tst== borderColor || tst == snakeColor)
			gameOver();break; }
		}// end of switch
}
void Snake::level(int x)
{
	settextstyle(0,0,2);
	if(x==100)
	{
		ellipse(230,45,30,30,100,20);
		setfillstyle(1,YELLOW);
		fillellipse(300,45,100,20);
		setcolor(BLUE);
		outtextxy(250,40,"LEVEL 2");
		sound(250);
		delay(1000);
		nosound();
		speed=speed-3;
	}
	if(x==200)
	{       ellipse(230,45,30,30,100,20);
		setfillstyle(1,YELLOW);
		fillellipse(300,45,100,20);
		setcolor(RED);
		outtextxy(250,40,"LEVEL 3");
		sound(250);
		delay(1000);
		nosound();
		speed=speed-3;
	}
	if(x==300)
	{       ellipse(320,240,60,60,120,50);
		setfillstyle(9,BLUE);
		fillellipse(320,240,120,50);
		delay(300);
		setcolor(WHITE);
		settextstyle(0,0,3);
		outtextxy(240,230,"YOU WON");
		delay(5000);
		exit(1);
	}
}
void Snake::init(void)
{
	borderColor = YELLOW;
	setcolor(RED);
	settextstyle(0, 1, 6);
	outtextxy(50,10,"RED SNAKE");
	gotoxy(14,6);
	cout<<"SCORE : 0";
	setcolor(GREEN);
	settextstyle(0,0,2);
	ellipse(230,45,30,30,100,20);
	setfillstyle(1,YELLOW);
	fillellipse(300,45,100,20);
	outtextxy(250,40,"LEVEL 1");
	settextstyle(7,0,1);
	setcolor(GREEN);
	outtextxy(255,450,"***Q=Quit ***");
	setcolor(borderColor);
	rectangle(100,100,540,380);
	rectangle(105,105,535,375);
	rectangle(110,110,530,370);
	scr=0;
	dlIndex=0;
	stIndex=0;
	speed=12;
	snakeColor = RED;
	size   = 7999;
	length = 50;
	for(int i=0 ;i<8000; i++)
	{
		xArr[i] = 0;
		yArr[i] = 0;
	}
}
void Snake::putAnObject()
{
	int test2=0;
	for(int i=0 ;i<1000 ; i++)
	{
		objX = random(41)+12 ;
		objY = random(25)+12 ;     // the less minus 10
		test2 = getpixel(objX*10,objY*10);
		setcolor(WHITE);
		if(test2 != snakeColor)
		{
			circle(objX*10,objY*10,4);
			setfillstyle(2 ,WHITE);
			fillellipse(objX*10,objY*10,4,4);
			break;
		}
	}
}
void Snake::gameOver()
{
	setcolor(WHITE);
	ellipse(320, 240,30,30, 120, 25);
	setfillstyle(9 ,BLUE);
	fillellipse(320, 240, 120, 25);
	settextstyle(0,0,2);
	setcolor(RED);
	outtextxy(250,232,"GAME OVER ");
	getch();
	getch();
	restart();
}
void Snake::restart()
{
	cleardevice();
	xPos=320;yPos=240;
	init();
	randomize();
	putAnObject();
	getAkey();
}

int Snake::score()
{
	scr+=10;
	gotoxy(14,6);
	cout<<"SCORE : ";
	cout<<scr;
	sound(2500);
	delay(80);
	nosound();
	length+=20;
	putAnObject();
	return (scr);
}
void main(void)      /* MAIN */
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	randomize();
	Snake snake(320,240);
	snake.init();
	snake.putAnObject();
	snake.getAkey();
	getch();
	closegraph();
}
