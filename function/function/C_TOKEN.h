#pragma once

class C_TOKEN
{
private:

public:
	int strToken(char* pszDst, char* pszSrc, int nPosition, const char cDelimiter);
	int intToken(int* pDst, char* pszSrc, int nPosition, const char cDelimiter);
	int charToken(char* pDst, char* pszSrc, int nPosition, const char cDelimiter);
};

