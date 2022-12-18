#pragma once


class Fraction
{
	int numerator;
	int deniminator;

public:
	Fraction() : Fraction(0) {}

	Fraction(int n) : Fraction(n, 1) {}

	Fraction(int n, int d)
	{
		numerator = n;
		deniminator = d;
	}

	Fraction(double n)
	{

	}

	//friend Fraction operator+(Fraction f1, Fraction f2);

	Fraction operator+(Fraction f1)
	{
		Fraction res;
		res.numerator = numerator * f1.deniminator + f1.numerator * deniminator;
		res.deniminator = deniminator * f1.deniminator;

		return res;
	}

	Fraction operator+(int f1)
	{
		return *this + Fraction(f1);
	}

	void print()
	{
		cout << numerator << "/" << deniminator << endl;
	}

	Fraction operator-()
	{
		return Fraction(-numerator, deniminator);
	}

	Fraction operator++() // pefix
	{
		numerator += deniminator;
		return *this;
	}

	Fraction operator++(int) // postfix
	{
		Fraction f = *this;

		numerator += deniminator;
		return f;
	}

	void operator+=(Fraction f1)
	{
		*this = *this + f1;
	}

	auto operator<=>(Fraction f1)
	{
		return (double)numerator / deniminator <=> (double)f1.numerator / f1.deniminator;
	}

	bool operator&&(Fraction f1)
	{
		return numerator && f1.numerator;
	}

	operator double()
	{
		return (double)numerator / deniminator;
	}

	friend ostream& operator<<(ostream& out, const Fraction& f);
	friend istream& operator>>(istream& in, Fraction& f);

	void operator()(int n, int d)
	{
		numerator = n;
		deniminator = d;
	}
};

ostream& operator<<(ostream& out, const Fraction& f)
{
	out << f.numerator << "/" << f.deniminator;
	return out;
}

istream& operator>>(istream& in, Fraction& f)
{
	cout << "Num  : ";  in >> f.numerator;
	cout << "Denom: "; in >> f.deniminator;
	return in;
}


Fraction operator+(int f1, Fraction f2)
{
	return Fraction(f1) + f2;
}

//Fraction operator+(Fraction f1, Fraction f2)
//{
//	Fraction res;
//	res.deniminator = 1;
//	res.numerator = 1;
//
//	return res;
//}


class MString
{
private:
	char* str;
	int length;

public:
	static int num;
	MString();
	explicit MString(int);
	MString(const char*);
	MString(const MString&);

	~MString();
	void set(const char*);
	void set();

	const char* get_str() const;
	int get_length() const;
	static int get_num()
	{
		return num;
	};
	///Функция ввода с консоли

	void print()
	{
		cout << str << endl;
		cout << get_num();
	}

	///// TODO

	friend ostream& operator<<(ostream& out, const MString& obj);

	friend istream& operator>>(istream& in, MString& obj);

	MString operator+(const MString& str);

	void operator+=(const MString& str);

	void operator*=(int n); //mama*3 = mamamamamama

	MString operator*(int n); //mama*3 = mamamamamama

	friend MString operator*(int n, const MString& str);

	bool operator==(const MString& str);

	bool operator!=(const MString& str);

	bool operator>(const MString& str);

	bool operator<(const MString& str);

	bool operator<=(const MString& str);

	bool operator>=(const MString& str);

	char operator[](size_t index);

};
int MString::num(0);

MString::MString() :MString(80)
{

}
MString::MString(int lenght)
{
	num++;
	this->length = lenght;
	str = new char[length];
	str[0]='\0';
}
MString::MString(const char* str) :
	str(nullptr), length(0)
{
	num++;
	set(str);
}
MString::MString(const MString& str)
{
	num++;
	set(str.str);
}
void MString::set()
{
	char buff[80];
	cin.getline(buff, 80);
	set(buff);
}

MString::~MString()
{
	num--;
	delete[] this->str;
}

void MString::set(const char* str)
{

	while (str[length] != '\0')
	{
		length++;
	}
	delete str;
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

const char* MString::get_str() const
{
	return str;
}
int MString::get_length() const
{
	return length;
}