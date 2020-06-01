
#include "Sample_text.h"
using namespace std;

int __cdecl main()
{
	audit(a);
	for (int i = -1; i < 50; i++)
	{
		a.WritenodeRecurse(HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Enum\\USBSTOR", i);
		a.output();
		
	}

	return 0;

}
