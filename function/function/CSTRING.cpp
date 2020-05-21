#include "stdafx.h"
#include "CSTRING.h"

int CSTRING::lineParsingForString()
{
	int nResult = 0;
	int nIdx = 1;
	char* pszTokenData = NULL;
	char* pszContext = NULL;
	char szToken[10] = "\r\t";
	char szData[3500] = "validity_mode = month\
		validity_period = 9999\
		algorithm_type = ECDSA\
		signature_algorithm = sha256WithECDSAEncryption\
		key_size = 256\
		csp = software\
		pop = ca\
		km_key_gen = \
		km_key_backup = \
		saved_key_use = f\
		delta_cdp = f\
		template = \
		auto_issue = t\
		short_lived_validity = \
		short_lived_overlap = \
		pol_kup_day = \
		short_lived_policy = \
		ou_setting = \
		authority_key_id = n|ki=t|aci=t|directoryName^cn=ROOTCA01,o=kepco,c=kr!|cs=t|\
		sign_key_usage = c|digitalSignature,nonRepudiation|\
		";
	
	char szFieldList[20][100] = {
		"validity_mode",
		"validity_period",
		"algorithm_type",
		"signature_algorithm",
		"key_size",
		"csp",
		"pop",
		"km_key_gen",
		"km_key_backup",
		"saved_key_use",
		"delta_cdp",
		"template",
		"auto_issue",
		"short_lived_validity",
		"short_lived_overlap",
		"pol_kup_day",
		"short_lived_policy",
		"ou_setting",
		"authority_key_id",
		"sign_key_usage"
	};
	char szFieldValueList[20][1000] = { 0, };

	pszTokenData = strtok_s(szData, szToken, &pszContext);
	while (pszTokenData != NULL) {
		int nLen = 0;
		nResult = strncmp(pszTokenData, szFieldList[nIdx - 1], strlen(szFieldList[nIdx - 1]));
		if (nResult) {
			cout << pszTokenData << " | " << szFieldList[nIdx - 1] << endl;
			cout << "Error" << endl;
			break;
		}

		nLen = strlen(szFieldList[nIdx - 1]) + 3;
		if (strlen(pszTokenData) == nLen) {
			//cout << strlen(pszTokenData) << nLen << endl;
			continue;
		}

		//strcpy_s(szFieldValueList[nIdx - 1], sizeof(szFieldValueList[nIdx - 1]), (pszTokenData + nLen));
		sprintf_s(szFieldValueList[nIdx - 1], "%s", pszTokenData + nLen);

		//cout << nIdx << ". " << pszTokenData << endl;
		cout << szFieldList[nIdx - 1] << " | " << szFieldValueList[nIdx - 1] << endl;

		pszTokenData = strtok_s(pszContext, szToken, &pszContext);
		nIdx++;
	}
	
	return 0;
}
