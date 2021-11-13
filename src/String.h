#ifndef STRING_H
#define STRING_H

class String
{
private:
	unsigned short m_length;
	char* m_string;

	inline String(const String& string, const char* newString, const unsigned short& newLength);

	inline void malloc(unsigned short length);
	inline unsigned short getLength(const char* string);
	inline void copy(char* destination, const char* source);

public:
	String();
	String(const char* string);
	String(const String& string);
	~String();
	
	String& operator =(const String& string);
	String& operator +=(const String& string);
	
	String operator +(const char* string);
	String operator +(const String& string);

	bool operator ==(const String& string);
	bool operator !=(const String& string);
	
	inline operator const char*() const { return m_string; }
	inline unsigned short length() const { return m_length; }
};

#endif