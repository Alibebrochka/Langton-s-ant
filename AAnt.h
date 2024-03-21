#pragma once
#include <Windows.h>
#include <conio.h>
enum eDirection { LEFT = 0, RIGHT, UP, DOWN };

class AAnt
{
	RECT Ant_Rect{};
	eDirection dir;

	bool next{};
	int const scale{};
	int const cntr_rect{};
	HBRUSH const red{}, black{}, white{};
public:
	AAnt();

	void Init(HWND hWnd);
	void Go(HDC hdc);
	int On_Time(HWND hWnd) const;

private:
	void Direction(eDirection &dir) const ;
	void Draw(HDC hdc);
	void Movement(eDirection dir);
};

