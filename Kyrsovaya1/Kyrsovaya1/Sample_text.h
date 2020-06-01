
#pragma once
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <codecvt>
using namespace std;

/**
 * \author Alexey Levin
 *  \date 01.06.2020
 */

/**
 * \brief Класс аудит *	
 * \details Внутри данного класса происходит переход в папку SYSTEM\\ControlSet001\\Enum\\USBSTOR, выборка информации и последующий вывод её в .txt файл.
 *  
 */

class audit
{
public:

	/**
	 * \brief Логическая переменная, принимающая на вход несколько параметров и возвращающая названия USB устройств.
	 * 
	 * \details hkeyRoot - Описатель открываемого раздела, который может быть получен функциями RegCreateKeyEx и RegOpenKeyEx.
	 * 
     *  lpSubKey - Указатель на строку, завершающуюся нулевым байтом, которая содержит имя открываемого раздела.
     * 
     *  number - Номер цикла.
	 */

	BOOL WritenodeRecurse(HKEY hKeyRoot, LPCTSTR lpSubKey, int number);

	/**
	 * \brief Функция, не возвращающая никакого значения.
	 * 
	 * \details Вывод информации в .txt файл.
	 */

	void output();

	/**
	 *  \brief Конструктор по умолчанию.
	 */

    audit() :value(new char[1]{}), len(0) {};
private:
	char* value;
	int len;
	
	LONG lResult;
	DWORD dwSize;
	TCHAR szName[MAX_PATH];
	HKEY hKey;
	FILETIME ftWrite;
};