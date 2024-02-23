#include "AAnt.h"
AAnt::AAnt() :left{ 960 }, right{ left + scale }, top{ 520 }, bot{ top + scale },
scale{ 10 },cntr_rect{ scale / 2}, dir{ LEFT }, next{ true },
red(CreateSolidBrush(RGB(255, 0, 0))),
black(CreateSolidBrush(RGB(0, 0, 0))),
white(CreateSolidBrush(RGB(255, 255, 255))){}

void AAnt::Go(HDC hdc)
{
	auto black_white = [](COLORREF color) {return color == RGB(0, 0, 0) ? true : false; };

	while (left > 0 && left < 1900 - scale &&  top > 0 && top < 1000 - scale)
	{
		//next = (GetPixel(hdc, left + cntr_rect, top + cntr_rect) == RGB(0, 0, 0)) ? true : false;
		next = black_white(GetPixel(hdc, left + cntr_rect, top + cntr_rect));
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
		Rectangle(hdc, left, top, right, bot);
		Sleep(5);

		SelectObject(hdc, next? white : black);
		Rectangle(hdc, left, top, right, bot);

		direction(dir);
	}	
}

void AAnt::direction(eDirection dir)
{
	switch (dir)
	{
	case LEFT:
		left -= scale;
		right -= scale;
		break;
	case RIGHT:
		left += scale;
		right += scale;
		break;
	case UP:
		top -= scale;
		bot -= scale;
		break;
	case DOWN:
		top += scale;
		bot += scale;
		break;
	default:
		break;
	}
}