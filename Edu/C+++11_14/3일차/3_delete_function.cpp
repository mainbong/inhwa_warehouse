// 3_delete_function - 116  page

class Mutex
{
private:
	// ���� �����ڰ� �ʿ� ������� ������ �޶�� �ϸ� �ȴ�.
	Mutex(const Mutex&) = delete;
	Mutex& operator=(const Mutex&) = delete;
public:
	Mutex() = default;
	Mutex(const char* name) {}
};

int main()
{
	Mutex m1;
	Mutex m2 = m1; // �Ǵ°� ������� ? �ȵǴ°� ������� ?
}