#include "Sample_text.h"

using namespace std; 

BOOL audit::WritenodeRecurse(HKEY hKeyRoot, LPCTSTR lpSubKey, int number)

{
	
	lResult = RegOpenKeyEx(hKeyRoot, lpSubKey, 0, KEY_READ, &hKey);

	if (lResult != ERROR_SUCCESS)
	{
		if (lResult == ERROR_FILE_NOT_FOUND) {
			printf("Key not found.\n");
			return TRUE;
		}
		else {
			printf("Error opening key.\n");
			return FALSE;
		}
	}
	lResult = RegEnumKeyEx(hKey, number, szName, &dwSize, NULL, NULL, NULL, &ftWrite);
}
void audit::output()
{
	dwSize = MAX_PATH;
	string name_usb = "";
	if (lResult == ERROR_SUCCESS)
	{

		fstream info;
		info.open("D:/123.txt", fstream::in | fstream::out | ios::app);
		wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
		name_usb = codec.to_bytes(szName);
		info << name_usb << "\n" << endl;
		info.close();

	}
	RegCloseKey(hKey);
}