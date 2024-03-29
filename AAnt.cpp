#include "AAnt.h"
AAnt::AAnt() :scale{ 15 },cntr_rect{ scale / 2}, dir{ LEFT }, next{ true },
red(CreateSolidBrush(RGB(255, 0, 0))),
black(CreateSolidBrush(RGB(0, 0, 0))),
white(CreateSolidBrush(RGB(255, 255, 255))){}

void AAnt::Init(HWND hWnd)
{
	Ant_Rect.left = 960;
	Ant_Rect.right = Ant_Rect.left + scale;
	Ant_Rect.top = 520;
	Ant_Rect.bottom = Ant_Rect.top + scale;
	SetTimer(hWnd, WM_USER + 1, 0, 0);
}

void AAnt::Go(HDC hdc)
{
	next = (GetPixel(hdc, Ant_Rect.left + cntr_rect, Ant_Rect.top + cntr_rect) == RGB(0, 0, 0)) ? true : false;

	Direction(dir);
	Draw(hdc, red);
	Draw(hdc, next ? white : black);
	Movement(dir);
}

int AAnt::On_Time(HWND hWnd) const
{
	InvalidateRect(hWnd, &Ant_Rect, FALSE);
	return 0;
}

void AAnt::Direction(eDirection &dir) const 
{
	switch (dir)
	{
	case LEFT:
		dir = next ? DOWN : UP;
		break;
	case RIGHT:
		dir = next ? UP : DOWN;
		break;
	case UP:
		dir = next ? LEFT : RIGHT;
		break;
	case DOWN:
		dir = next ? RIGHT : LEFT;
		break;
	default:
		break;
	}
}

void AAnt::Draw(HDC hdc, HBRUSH color)
{
	SelectObject(hdc, color);
	Rectangle(hdc, Ant_Rect.left, Ant_Rect.top, Ant_Rect.right, Ant_Rect.bottom);
}

void AAnt::Movement(eDirection dir)
{
	switch (dir)
	{
	case LEFT:
		Ant_Rect.left -= scale;
		Ant_Rect.right -= scale;
		break;
	case RIGHT:
		Ant_Rect.left += scale;
		Ant_Rect.right += scale;
		break;
	case UP:
		Ant_Rect.top -= scale;
		Ant_Rect.bottom -= scale;
		break;
	case DOWN:
		Ant_Rect.top += scale;
		Ant_Rect.bottom += scale;
		break;
	default:
		break;
	}
}