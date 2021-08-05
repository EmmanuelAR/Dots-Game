#pragma once
#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<string>
#include<conio.h>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS


class Consola
{
public:
	static void inicializarColor();
	static void textColor(int z);
	static void setK(int z);
};
