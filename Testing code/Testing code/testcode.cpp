#include <iostream>
using namespace std;

int mian()
{
	int codeSection;
	cin >> codeSection;
	switch (codeSection) {
	case 321:
	case 322:
		cout << "selling illegal lottery tickets";
		break;
	case 281:
		cout << "bigamy";
		break;
	case 383:
		cout << "selling rancid butter";
		break;
	case 598:
		cout << "injuring a bird in a public cemetary";
		break;
	default:
		cout << "some other crime";
		break;
	}
	return 1;
}