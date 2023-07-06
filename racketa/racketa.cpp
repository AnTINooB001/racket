
#include "Header.h"


void setcur(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hit()
{
	if (map[bullet.y1][bullet.x1] == 'Q' || map[bullet.y1][bullet.x1] == 'o')
	{
		ball.hp -= bullet.damage;
		fire = false;
	}
	if (map[bullet.y2 + 1][bullet.x2] == 'Q' || map[bullet.y2][bullet.x2] == 'o')
	{
		ball.hp -= bullet.damage;
		fire = false;

	}
}

void slow()
{
	if (count == 2)
	{
		ball.Ly -= 1;
		//count = 0;
	}
	if (count == 3)
	{
		ball.Ly -= 1;

	}
	if (count == 4)
	{
		ball.Ly -= 1;

	}
	if (count == 5)
	{
		ball.Ly -= 1;

	}
	if (count == 6)
	{
		ball.Ly -= 1;
		
	}
	if (count == 7)
	{
		ball.Ly -= 1;
	
	}
	if (count == 8)
	{
		ball.Ly -= 1;
		
	}
	if (count == 9)
	{
		ball.Ly -= 1;

	}
	if (count == 10)
	{
		ball.Ly -= 1;
		count = 0;
	}
}

void moveball()
{
	ball.Ly += 1;//(int)round(ball.speed);
	count++;
	
	slow();

	if (ball.Ly - 10 >= mapH || ball.hp <= 0)
		initBall();
}

void initBall()
{
	ball.x = rand() % mapW - 20;
	

	ball.Ly = 0;
	ball.Swidth = 10;
	ball.Lwidth = 24;
	ball.ex = ball.x + ball.Swidth;
	ball.Lex = ball.x + ball.Lwidth;


	ball.hp = 100;   //


	ball.LxMin = ball.x - 7;

	while (ball.LxMin < 0)
	{
		ball.LxMin = ball.x - 7;
		ball.x += 1;
	}
	
}


void putLargeBall()
{
	

	if (ball.Ly >= 0 && ball.Ly < mapH)
	{
		for (int i = ball.x + 1; i < ball.ex - 1; i++)
		{
			map[ball.Ly][i] = 'Q';
		}
	}
	if (ball.Ly >= 1 && ball.Ly < mapH + 1)
	{
		for (int i = ball.x - 2; i < ball.ex + 2; i++)
		{
			map[ball.Ly - 1][i] = 'Q';
		}
	}
	if (ball.Ly >= 2 && ball.Ly < mapH + 2)
	{
		for (int i = ball.x - 5; i < ball.ex + 5; i++)
		{
			map[ball.Ly - 2][i] = '1';
		}
	}
	if (ball.Ly >= 3 && ball.Ly < mapH + 3)
	{
		for (int i = ball.x - 6; i < ball.ex + 6; i++)
		{
			map[ball.Ly - 3][i] = 'o';
		}
	}
	if (ball.Ly >= 4 && ball.Ly < mapH + 4)
	{
		for (int i = ball.x - 7; i < ball.ex + 7; i++)
		{
			map[ball.Ly - 4][i] = 'o';
		}
	}
	if (ball.Ly >= 5 && ball.Ly < mapH + 5)
	{
		for (int i = ball.x - 7; i < ball.ex + 7; i++)
		{
			map[ball.Ly - 5][i] = 'o';
		}
	}
	if (ball.Ly >= 6 && ball.Ly < mapH + 6)
	{
		for (int i = ball.x - 6; i < ball.ex + 6; i++)
		{
			map[ball.Ly - 6][i] = 'o';
		}
	}
	if (ball.Ly >= 7 && ball.Ly < mapH + 7)
	{
		for (int i = ball.x - 5; i < ball.ex + 5; i++)
		{
			map[ball.Ly - 7][i] = 'o';
		}
	}
	if (ball.Ly >= 8 && ball.Ly < mapH + 8)
	{
		for (int i = ball.x - 2; i < ball.ex + 2; i++)
		{
			map[ball.Ly - 8][i] = 'o';
		}
	}
	if (ball.Ly >= 9 && ball.Ly < mapH + 9)
	{
		for (int i = ball.x + 1; i < ball.ex - 1; i++)
		{
			map[ball.Ly - 9][i] = 'o';
		}
	}
	if (ball.Ly >= 10 && ball.Ly < mapH + 10)
	{
		for (int i = ball.x + 4; i < ball.ex - 4; i++)
		{
			map[ball.Ly - 10][i] = 'o';
		}
	}
}


void movebullet(float x, float y)
{
	if (bullet.y1 >= 0)
	{
		bullet.dx1 = x + 2;
		bullet.dy1 = y - 2;
		bullet.dx2 = x + racket.width - 2;
		bullet.dy2 = y - 2;

		bullet.x1 = (int)round(bullet.dx1);
		bullet.y1 = (int)round(bullet.dy1);
		bullet.x2 = (int)round(bullet.dx2);
		bullet.y2 = (int)round(bullet.dy2);
	}
	else
	{
		if (bullet.y1 < 0)
		{
			bullet.y1 += 5;
			bullet.y2 += 5;
		}
		fire = false;

		
	}
}

void firebullet()
{
	movebullet(bullet.x1 + cos(bullet.alpha) * bullet.speed - 1.6, bullet.y1 + sin(bullet.alpha) * bullet.speed);
}

void putbullet()
{
	if (bullet.x1 == bullet.dx1)
	{
		map[bullet.y1][bullet.x1] = ' ';
		map[bullet.y2][bullet.x2] = ' ';
	}
	else
	{
		map[bullet.y1 + 2][bullet.x1] = '*';
		map[bullet.y2 + 2][bullet.x2] = '*';
	}

}

void initbullet()
{
	movebullet(2, 2);
	bullet.speed = 0;
	bullet.alpha = 1;
	bullet.damage = 1;
}

void ininRacket()
{

	racket.width = 9;
	racket.y = mapH - 1;
	racket.x = (mapW / 2) - racket.width;

}

void putRacket()
{
	for (int i = racket.x + 1; i < racket.x + racket.width; i++)
	{
		map[racket.y][i] = '_';
		map[racket.y - 1][i] = '_';
	}
	map[racket.y][racket.x] = '|';
	map[racket.y][racket.x + racket.width] = '|';

	map[racket.y][racket.x + 4] = '|';
	map[racket.y][racket.x + racket.width - 4] = '|';

	map[racket.y - 1][racket.x + 4] = '|';
	map[racket.y - 1][racket.x + racket.width - 4] = '|';

	map[racket.y - 2][racket.x + 4] = '/';
	map[racket.y - 2][racket.x + racket.width - 4] = '\\';

	map[racket.y - 1][racket.x + 2] = '|';
	map[racket.y - 1][racket.x + racket.width - 2] = '|';


}

void racketMove(int x, int y)
{
	racket.x = x;
	racket.y = y;



	//Sleep(5);
	if (racket.x < 1)
		racket.x = racket.x + 1;
	if (racket.x + racket.width > mapW - 1)
		racket.x = racket.x - 1;
	if (racket.y < 1)
		racket.y += 1;
	if (racket.y > mapH - 1)
		racket.y -= 1;
}

void initMap()
{

	for (int i = 1; i < mapW; i++)
		map[0][i] = ' ';

	map[0][0] = '|';
	map[0][mapW - 1] = '|';
	map[0][mapW] = '\0';

	for (int i = 0; i < mapH; i++)
		sprintf_s(map[i], map[0]);
	map[mapH - 1][mapW] = '\0';

}

void showMap()
{

	for (int i = 0; i < mapH; i++)
	{
		printf_s(map[i]);
	}
}




int main()
{
	char c;
	srand(time(NULL));
	ininRacket();
	initbullet();
	initBall();

	
	do
	{
		
		setcur(0, 0);

		initMap();
		putLargeBall();
		putbullet();
		if (fire)
			firebullet();
		if(!fire)
			movebullet(racket.x, racket.y);
		putRacket();
		showMap();
		moveball();
		hit();

		

		if (GetKeyState('A') < 0)
			racketMove(racket.x - 1, racket.y);
		if (GetKeyState('D') < 0)
			racketMove(racket.x + 1, racket.y);
		if (GetKeyState('W') < 0)
			racketMove(racket.x, racket.y - 1);
		if (GetKeyState('S') < 0)
			racketMove(racket.x, racket.y + 1);
		if (GetKeyState('E') < 0)
			fire = true;
		Sleep(10);
		
		
	} while (GetKeyState(VK_ESCAPE) >= 0);

	
	return 0;
}