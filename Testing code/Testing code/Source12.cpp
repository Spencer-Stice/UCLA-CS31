#include <iostream>
using namespace std;

#include <iostream>
#include <string>
using namespace std;
const int MAXSODA = 100;
class Soda
{
public:
	Soda();
	void setName(string name);
	string getName() const;
private:
	string name;
};
Soda::Soda()
{
	name = "no name";
}
void Soda::setName(string name) {
	name = name;
}
string Soda::getName() const{
	return name;
}
int main()
{
	
	cout << "Testing";
	

}