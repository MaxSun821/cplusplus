#include <memory>
#include <string>
#include "SmartPtr.h"

using std::string;

struct list_node {
	int data;
	max::weak_ptr<list_node> next;
	max::weak_ptr<list_node> prev;

	~list_node() {
		std::cout << "list_node destructor called for data: " << std::endl;
	}
};

int main() {
	//std::auto_ptr<int> p1(new int);
	//std::auto_ptr<int> p2(p1); // p2 now owns the memory, p1 is null
	//std::auto_ptr<int> p3(new int(5)); // p3 owns a new int with value 5
	//p3 = p2; // p3 now takes ownership of the memory owned by p2, p2 is null

	//max::auto_ptr<int> p1(new int);
	//max::auto_ptr<int> p2(p1); // p2 now owns the memory, p1 is null
	//max::auto_ptr<int> p3(new int(5)); // p3 owns a new int with value 5
	//p3 = p2; // p3 now takes ownership of the memory owned by p2, p2 is null

	//std::unique_ptr<int> p1(new int(7));
	//std::unique_ptr<int> p2(p1);
	//std::unique_ptr<int> p3(new int(5)); // p3 owns a new int with value 5
	//p3 = p1;

	//max::unique_ptr<int> p1(new int(7));
	//max::unique_ptr<int> p2(p1);
	//max::unique_ptr<int> p3(new int(5)); // p3 owns a new int with value 5
	//p3 = p1;

	//max::shared_ptr<string> p1(new string("xxxxxxxxxxx"));
	//max::shared_ptr<string> p2(p1); // p2 shares ownership with p1
	//max::shared_ptr<string> p3(new string("yyyyyyyyyyy")); // p3 owns a new string

	//p1 = p3; // p1 now shares ownership with p3, p2 still shares ownership with the original string
	//p3 = p1; // p3 now shares ownership with p1, p2 still shares ownership with the original string


	//max::shared_ptr<list_node> p1(new list_node);
	//max::shared_ptr<list_node> p2(new list_node);

	//std::cout << p1.use_count() << std::endl; // Should print 1
	//std::cout << p2.use_count() << std::endl; // Should print 1

	//p1->next = p2; // p1 points to p2
	//p2->prev = p1; // p2 points back to p1

	//std::cout << p1.use_count() << std::endl; // Should print 1
	//std::cout << p2.use_count() << std::endl; // Should print 1

	max::shared_ptr<int> p1(new int[10], [](int* p) { delete[] p; });



	return 0;
}