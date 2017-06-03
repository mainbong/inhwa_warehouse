


template<typename T> void foo(T a, T b)
{

}


template<typename T> void goo(T &a, T &b)
{

}

int main()
{
	foo("apple", "banana"); // ok.
	goo("apple", "banana"); //error  char[6], char[7]
}