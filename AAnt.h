#pragma once
#include <Windows.h>
#include <conio.h>
enum eDirection { LEFT = 0, RIGHT, UP, DOWN };

class AAnt
{
	bool next{};
	int scale{};
	int cntr_rect{};
	HBRUSH red{}, black{}, white{};
	eDirection dir;
	RECT Ant_Rect{};
public:
	AAnt();

	void Init(HWND hWnd);
	void Go(HDC hdc);
	int On_Time(HWND hWnd) const;
private:
	void direction(eDirection dir);
};

