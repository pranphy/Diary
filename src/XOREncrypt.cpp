#include "XOREncrypt.h"

XOREncrypt::XOREncrypt(string Value,string Ki): Text(Value) {
	if(Ki == "") {
		string p;
		p += char(0xff);
		Key = p;
	} else {
		Key = Ki;
	}
	//unsigned TextLength = Value.size();
}
void XOREncrypt::SetText(string Value){
	Text =  Value;
}

void XOREncrypt::SetKey(string Value) {
	if(Value == string("")) {
		string p;
		p += char(0xff);
		Key = p;
	} else {
		Key = Value;
	}
}

void XOREncrypt::Encrypt() {
	unsigned KeyLength = Key.size();
	unsigned TextLength = Text.size();
	Encrypted.reserve(TextLength);
	unsigned j = 0;
	for(unsigned i=0 ; i<TextLength; i++) {
		char CurChar = Key.at(j++);
		char Chr = Text.at(i) ^ CurChar;
		Encrypted.push_back(Chr);
		if(j >= KeyLength ) j = 0;
	}
}

char* XOREncrypt::GetCharArray() {
	unsigned Length = Encrypted.size();
	char* Return = new char[Length+1];
	unsigned i = 0;
	for(; i<Length ;i++){
		Return[i] = char(Encrypted.at(i));
	}
	Return[i] = '\0';
	return Return;
}

string XOREncrypt::GetEncrypted(){
	return Encrypted;
}
