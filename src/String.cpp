#include "String.h"

String::String(const String& string, const char* newString, const unsigned short& newLength)
{
	malloc(string.m_length + newLength);
	copy(m_string, string.m_string);
	copy(&m_string[string.m_length], newString);
}

void String::malloc(unsigned short length)
{
	m_length = length;
	m_string = new char[m_length + 1];
	m_string[m_length] = '\0';
}

unsigned short String::getLength(const char* string)
{
	const char* begin = string;
	while (*string != '\0') string++;
	return static_cast<unsigned short>(string - begin);
}

void String::copy(char* destination, const char* source)
{
	while (*destination++ = *source++);
}

String String::toString(const int& value)
{
	unsigned short length = 0;
	char* string = new char[12];

	int number = value;
	int sign = number;

	if (number < 0) number = -number;
	do {
		string[length++] = number % 10 + '0';
	} while ((number /= 10) > 0);

	if (sign < 0) string[length++] = '-';
	string[length] = '\0';

	char temp;
	char* begin = string;
	char* end = string + length - 1;
	while (begin < end) {
		temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
	
	String newString(string);

	delete[] string;
	string = nullptr;

	return newString;
}

String::String()
{
	malloc(0);
}

String::String(const char* string)
{
	malloc(getLength(string));
	copy(m_string, string);
}

String::String(const String& string)
{
	malloc(string.m_length);
	copy(m_string, string.m_string);
}

String::~String()
{
	delete[] m_string;
	m_string = nullptr;
}

String& String::operator =(const String& string)
{
	delete[] m_string;
	malloc(string.m_length);
	copy(m_string, string.m_string);
	return *this;
}

String& String::operator +=(const String& string)
{
	m_length += string.m_length;
	char* newString = new char[m_length + 1];
	newString[m_length] = '\0';

	copy(newString, m_string);
	copy(&newString[m_length - string.m_length], string.m_string);

	delete[] m_string;
	m_string = newString;

	return *this;
}

String& String::operator =(const int& value)
{
	return operator =(toString(value));
}

String& String::operator +=(const int& value)
{
	return operator +=(toString(value));
}

String String::operator +(const char* string)
{
	return String(*this, string, getLength(string));
}

String String::operator +(const String& string)
{
	return String(*this, string.m_string, string.m_length);
}

String String::operator +(const int& value)
{
	return operator +(toString(value));
}

bool String::operator ==(const String& string)
{
	if (m_length != string.m_length) return false;

	for (int i = 0; i < m_length; i++)
	{
		if (m_string[i] != string.m_string[i]) return false;
	}

	return true;
}

bool String::operator !=(const String& string)
{
	return !(*this == string);
}