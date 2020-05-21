#include "stdafx.h"
#include "C_TOKEN.h"

int C_TOKEN::strToken(char* pszDst, char* pszSrc, int nPosition, const char cDelimiter)
{
	int i;
	char* front = nullptr;
	char* rear = nullptr;

	front = pszSrc;
	if (pszSrc == nullptr || pszDst == nullptr)
		return -1;

	if (*pszSrc == cDelimiter && nPosition == 1) {
		strcpy_s(pszDst, 1," ");
		return 0;
	}

	for (i = 0; i < nPosition - 1; i++) {
		if (*pszSrc == cDelimiter && i == 0) {
			front = (char*)strchr(front, cDelimiter);
		}
		else {
			front = (char*)strchr(front + 1, cDelimiter);
		}

		if (front == nullptr) {
			return -1;
		}
	}
	rear = (char*)strchr(front + 1, cDelimiter);

	if (rear == nullptr) {
		return -1;
	}

	if (nPosition != 1) {
		front++;
	}
	if (!(rear - front)) {
		strcpy_s(pszDst, 1," ");
		return 0;
	}

	strncpy_s(pszDst, strlen(pszSrc),front, rear - front);
	return 0;
}

int C_TOKEN::intToken(int* pDst, char* pszSrc, int nPosition, const char cDelimiter)
{
	int i;
	char intBuf[100];
	char* front = nullptr;
	char* rear = nullptr;

	front = pszSrc;
	if (pszSrc == nullptr || pDst == nullptr)
		return -1;

	if (*pszSrc == cDelimiter && nPosition == 1) {
		*pDst = 0;
		return 0;
	}

	for (i = 0; i < nPosition - 1; i++) {
		if (*pszSrc == cDelimiter && i == 0) {
			front = (char*)strchr(front, cDelimiter);
		}
		else {
			front = (char*)strchr(front + 1, cDelimiter);
		}

		if (front == nullptr) {
			return -1;
		}
	}
	rear = (char*)strchr(front + 1, cDelimiter);
	if (rear == nullptr) {
		return -1;
	}

	if (nPosition != 1) {
		front++;
	}

	if (!(rear - front)) {
		*pDst = 0;
		return -1;
	}

	memset(intBuf, 0, sizeof(intBuf));
	strncpy_s(intBuf, strlen(pszSrc),front, rear - front);
	*pDst = atoi(intBuf);
	return 0;
}

int C_TOKEN::charToken(char* pDst, char* pszSrc, int nPosition, const char cDelimiter)
{
	int i;
	char* point = nullptr;

 	point = pszSrc;
	if (pszSrc == nullptr || pDst == nullptr)
		return -1;

	for (i = 0; i < nPosition - 1; i++) {
		point = (char*)strchr(point + 1, cDelimiter);
		if (point == nullptr) {
			return -1;
		}
	}

	if (nPosition != 1) {
		point++;
	}

	if (*point == cDelimiter) {
		*pDst = 'f';
		return 0;
	}

	*pDst = *point;
	return 0;
}
