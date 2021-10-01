#include <iostream>

using std::cout;
using std::endl;

// Person Ŭ���� ���� �� ���Ǹ� �� ���Ͽ� �մϴ�.
class Person {
private:
	char* name;			// char�� ������ �������� char �迭�Դϴ�.
	int age;
	double height;
public:
	Person(int age, double height, const char* myname) : age(age), height(height) {
		/*
		Person Ŭ���� Ÿ���� ��ü�� ������ �� ���ڸ� �ѱ�ٸ� �ش� �����ڰ� ȣ��˴ϴ�.
		�� �����ڿ����� Person ������ ������ name�� myname�� ���̸�ŭ(null����) �����Ҵ��Ͽ� ���� �����մϴ�.
		*/
		int len = strlen(myname) + 1;		// strlen�� ���ڿ��� ���̸� ��ȯ�մϴ�. �� �� ���ڿ��� ���� �ǹ��ϴ� null�� �������� �ʽ��ϴ�. ex) strlen("Hello") -> 5
		name = new char[len];				// null ���̱��� ������ len��ŭ�� �޸� ������ �����Ҵ��մϴ�. 
		strcpy_s(name, len, myname);		// strcpy_s �� ���ڿ��� ���� �������ִ� �Լ��Դϴ�.
		cout << "Person object's constructor was called" << endl;	// �����ڸ� �˸��� ���� ����մϴ�.
	}
	Person(const Person& copy) {
		/*
		����Ʈ ���� �����ڰ� �ƴ� ����ڰ� ������ ���� �������Դϴ�.
		��ü�� �Լ� �μ��� �޽��ϴ�. �Լ� �μ��� ������ copy�� ������ ���� ���� ������ const�� �޽��ϴ�.
		�� ����� ���縦 ��������� �մϴ�.
		*/
		age = copy.age; height = copy.height;		//���� Person Ŭ�����̸� copy ���� Person Ŭ�����̹Ƿ�  private ������ ������ �ٷ� ������ �����մϴ�.
		// �Ʒ��� ����������� ��ü�� ������ ���� �� name�� �����Ҵ��Ͽ� '�޸� ������ �Ҵ�'�޽��ϴ�.
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);

	}
	void ShowPersonInfo() const {
		/*
		Person Ŭ������ ������ ������ ��� ����ϴ� �Լ��Դϴ�.
		*/
		cout << "Name : " << name << " Age : " << age << " Height : " << height << endl;
	}
	~Person() {
		// Person Ŭ������ �Ҹ����Դϴ�. �����Ҵ��� �� name ������ �޸� ������ �մϴ�.
		delete[] name;	// name ������ �޸� ������ �մϴ�.
		cout << "Person object's destructor was called" << endl;	// �Ҹ��ڸ� �˸��� ���� ����մϴ�.
	}
	void printAddr(const char* obj_name) {
		/*
		name ������ ����Ű�� �޸� �ּҸ� ����ϴ� �Լ��Դϴ�.
		shallow copy�� �̷����ٸ� name ������ �ּҰ� ������ ���Դϴ�.
		*/
		printf("%s's object\n", obj_name);
		printf("address of name variable : %X\n", name);		// �Ʒ� ������ �ٸ��� &�� ������ �ʰ� ���� �״�� �ִ� ������ name�� ������ �����̱� ������ ������ ���� �ȿ��� �ּҰ� �ֱ� �����Դϴ�.
		printf("address of age variable : %X\n", &age);			// ���� �տ� &�� ���̸� �ش� ������ �޸� �ּҸ� ��ȯ�մϴ�. ������ ���� �տ� &�� ���δٸ� ������ ������ ����Ű�� �ִ� �޸� �ּҰ� �ƴ� 
		printf("address of height variable : %X\n", &height);	// '������ ����'�� �޸� �ּҸ� ��ȯ�մϴ�. 
	}
};

int main() {
	Person man1(20, 180.0, "John");	// man1 ��ü�� ���������� ������ �˴ϴ�.
	Person man2 = man1;				// Person man2(man1); �� �����ϸ� ��������ڸ� ȣ���Ͽ� �����ϴ� ����Դϴ�.


	man1.ShowPersonInfo();			// �� ��ü�� ������ ������ ������� �� ��ġ ���������� �޸� ������ ��� ���簡 �̷��� ��ó�� ���Դϴ�.
	man2.ShowPersonInfo();

	man1.printAddr("man1");			// �ռ� ������ �޸� ����Ʈ ���� �����ڰ� �ƴ� ����� ���� ���� �����ڸ� ���� ���� �޸� ������ �Ҵ��Ͽ�
	man2.printAddr("man2");			// deep copy�� �Ͽ� �� ��ü�� name ������ ����Ű�� �ִ� �޸� �ּҰ� �ٸ��ϴ�. ���� �Ҹ��� ���� 2�� ȣ��Ǹ� 2���� �����Ҵ� ���� �޸� ������ ���������� �����˴ϴ�.

	return 0;
}