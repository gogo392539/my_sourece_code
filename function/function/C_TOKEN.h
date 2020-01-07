#pragma once

class C_TOKEN
{
private:

public:
	int m_strToken(char* pszDst, char* pszSrc, int nPosition, const char cDelimiter);
	int m_intToken(int* pDst, char* pszSrc, int nPosition, const char cDelimiter);
	int m_charToken(char* pDst, char* pszSrc, int nPosition, const char cDelimiter);
};

