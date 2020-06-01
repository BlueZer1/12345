
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
 * \brief ����� ����� *	
 * \details ������ ������� ������ ���������� ������� � ����� SYSTEM\\ControlSet001\\Enum\\USBSTOR, ������� ���������� � ����������� ����� � � .txt ����.
 *  
 */

class audit
{
public:

	/**
	 * \brief ���������� ����������, ����������� �� ���� ��������� ���������� � ������������ �������� USB ���������.
	 * 
	 * \details hkeyRoot - ��������� ������������ �������, ������� ����� ���� ������� ��������� RegCreateKeyEx � RegOpenKeyEx.
	 * 
     *  lpSubKey - ��������� �� ������, ������������� ������� ������, ������� �������� ��� ������������ �������.
     * 
     *  number - ����� �����.
	 */

	BOOL WritenodeRecurse(HKEY hKeyRoot, LPCTSTR lpSubKey, int number);

	/**
	 * \brief �������, �� ������������ �������� ��������.
	 * 
	 * \details ����� ���������� � .txt ����.
	 */

	void output();

	/**
	 *  \brief ����������� �� ���������.
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