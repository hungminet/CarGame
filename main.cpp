#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include "csl.h"
#include<string.h>
#include<math.h>
const int TOADO_X = 5*6;
const int TOADO_Y = 35;
enum TrangThai { UP, DOWN, LEFT, RIGH,NO };
struct NhanVat
{
	int x;
	int y;
    char A[6]= "[]_[]";
    char B[6]= " | | ";
    char C[6]= "[]_[]";
    TrangThai tt;
    int DIEM;
};
struct GOLDx
{
    int x;
    int y;
    int GT=50;
    char A[2]="$";
    int tt;
};
GOLDx GOLD;

struct VCx
{
    int x;
    int y;
    int tt;
};
VCx VC;
NhanVat Xe;
int soQua=0;
int soVC=0;
int tocdo=150;
void xuLyBanPhim();
void khoiTao();
void xuat();
void diChuyen();
void vaCham();
void taoQua();
void xuatKhung();
void xuLy();
void taosoVC();
void xuatVC();
void xuatXe();
void xuLyTocDo();
int main()
{
    srand(time (NULL));
	khoiTao();
	while(1)
	{
        clrscr();
		xuat();
		xuLyBanPhim();
        if(soQua<2)
            taoQua();
        if(soVC<2)
            taosoVC();
        xuLy();
        vaCham();
        xuLyTocDo();
	}
	return 0;
}
void xuLyBanPhim()
{
    if(_kbhit())
    {
        char k;
        k=_getch();
        if(k=='D'||k=='d')
            Xe.tt=RIGH;
        if(k=='A'||k=='a')
            Xe.tt=LEFT;
    }
}
void xuLyTocDo()
{
    Sleep(tocdo);
    if(tocdo>50)
        tocdo-=5;
}
void taosoVC()
{
    do{
        VC.x=2+rand()%(TOADO_X-4);
    }
    while((VC.x-GOLD.x)<=5&&(VC.x-GOLD.x)>=-5);

    VC.y=10;
    VC.tt=1;
    soVC++;
}
void xuLy()
{
    GOLD.y++;
    VC.y++;
    if(GOLD.y>TOADO_Y)
       {
           GOLD.tt=0;
           soQua--;
       }
    if(VC.y>TOADO_Y)
       {
           VC.tt=0;
           soVC--;
       }
}
void taoQua()
{
    GOLD.tt=1;
    GOLD.x=2+rand()%(TOADO_X-1);
    GOLD.y=10;
    soQua++;
}
void vaCham()
{
    if(GOLD.x>=Xe.x&&GOLD.x<=Xe.x+7&&GOLD.y>=Xe.y-2)
        {
        Xe.DIEM+=GOLD.GT;
        GOLD.tt=0;
        soQua--;
        }
    if((abs(VC.x-Xe.x)<=4)&&(abs(VC.y-Xe.y)<=3))//dung man hinh
        _getch();
}
void diChuyen()
{
    if(Xe.tt==LEFT&&Xe.x-5>=0)
    {
        Xe.x-=5;

    }
    if(Xe.tt==RIGH&&Xe.x+5<=TOADO_X)
    {
        Xe.x+=5;
    }
}
void xuatXe()
{
    gotoxy(Xe.x, Xe.y-2);
    puts(Xe.A);
    gotoxy(Xe.x, Xe.y-1);
    puts(Xe.B);
    gotoxy(Xe.x, Xe.y);
    puts(Xe.C);
    Xe.tt = NO;
}
void xuatQua()
{
        if(GOLD.tt)
    {
        gotoxy(GOLD.x,GOLD.y);
        puts(GOLD.A);
    }
}
void xuatVC()
{
    if(VC.tt)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<5;j++)
            {
                int x=VC.x+j;
                int y=VC.y+i;
                gotoxy(x,y);
                putchar(177);

            }
    }
}
void xuat()
{
    diChuyen();
    xuatXe();
    xuatQua();
    xuatVC();
    xuatKhung();
    sprint(50,20,"A: TRAI     D: PHAI");
}
void xuatKhung()
{
        for(int i=0;i<TOADO_Y+3;i++)
    {
        gotoxy(TOADO_X+1,i);
        printf("|");
    }
   for(int i=0;i<TOADO_Y+3;i++)
    {
        gotoxy(0,i);
        printf("|");
    }
    gotoxy(TOADO_X+6,TOADO_Y/2);
    printf("DIEM: %d",Xe.DIEM);
}
void khoiTao()
{
	Xe.x = TOADO_X/2+1;
	Xe.y = TOADO_Y;
	Xe.tt= NO;
	Xe.DIEM=0;
}
