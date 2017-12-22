#ifndef XORENCRYPT_H
#define XORENCRYPT_H

#include <string>
#include <iostream>
using namespace std;


class XOREncrypt
{
	public:
		XOREncrypt(string ,string = "");
		void SetText(string);
		void SetKey(string);
		string GetEncrypted();
		void Encrypt();
		char* GetCharArray();
	private:
		string Text, Key;
		string Encrypted;
};

#endif // XORENCRYPT_H
