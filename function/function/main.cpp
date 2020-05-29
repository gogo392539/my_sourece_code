#include "stdafx.h"
#include "fileFunc.h"
#include "C_TOKEN.h"
#include "C_TIME.h"
#include "CSTRING.h"

int main(void)
{
	char szNumber[100] = "1234";
	fileFunc cFileFunc;

	cFileFunc.fn_StringToNumber(szNumber, 16);


	return 0;
}