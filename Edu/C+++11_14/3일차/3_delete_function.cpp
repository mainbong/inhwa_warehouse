// 3_delete_function - 116  page

class Mutex
{
private:
	// 복사 생성자가 필요 없을경우 제거해 달라고 하면 된다.
	Mutex(const Mutex&) = delete;
	Mutex& operator=(const Mutex&) = delete;
public:
	Mutex() = default;
	Mutex(const char* name) {}
};

int main()
{
	Mutex m1;
	Mutex m2 = m1; // 되는게 좋을까요 ? 안되는게 좋을까요 ?
}