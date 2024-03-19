#include "AAnt.h"
AAnt::AAnt() :scale{ 10 },cntr_rect{ scale / 2}, dir{ LEFT }, next{ true },
red(CreateSolidBrush(RGB(255, 0, 0))),
black(CreateSolidBrush(RGB(0, 0, 0))),
white(CreateSolidBrush(RGB(255, 255, 255))){}

void AAnt::Init(HWND hWnd)
{
	Ant_Rect.left = 960;
	Ant_Rect.right = Ant_Rect.left + scale;
	Ant_Rect.top = 520;
	Ant_Rect.bottom = Ant_Rect.top + scale;
	SetTimer(hWnd, WM_USER + 1, 1, 0);
}

void AAnt::Go(HDC hdc)
{
	next = (GetPixel(hdc, Ant_Rect.left + cntr_rect, Ant_Rect.top + cntr_rect) == RGB(0, 0, 0)) ? true : false;
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
	SelectObject(hdc, red);
	Rectangle(hdc, Ant_Rect.left, Ant_Rect.top, Ant_Rect.right, Ant_Rect.bottom);

	SelectObject(hdc, next ? white : black);
	Rectangle(hdc, Ant_Rect.left, Ant_Rect.top, Ant_Rect.right, Ant_Rect.bottom);

	direction(dir);
}

int AAnt::On_Time(HWND hWnd) const
{
	InvalidateRect(hWnd, &Ant_Rect, FALSE);
	return 0;
}

void AAnt::direction(eDirection dir)
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