#include <iostream>

using namespace std;


int main(void){
	// Fa�a um programa para uma loja de tintas. O programa dever� pedir o tamanho em metros quadrados da �rea a ser pintada. Considere que a cobertura da tinta � de 1 litro para cada 3 metros quadrados e que a tinta � vendida em latas de 18 litros, que custam R$ 80,00.
	// Informe ao usu�rio a quantidades de latas de tinta a serem compradas e o pre�o total.
	
	int metros;
	cout << "Tamanho em metros quadrados da area: ";
	cin >> metros;

	float litros = metros/3;
	cout << "\n\n" << litros << " LITROS.  |  ";

	if (litros <= 18)
		cout << "R$80,00" << endl;
	else if ((int)litros % 18 != 0)
		cout << "R$" << (((int)litros/18)+1) * 80 << ",00" << endl;
	else
		cout << "R$" << ((int)litros/18) * 80 << ",00" << endl;

	return 0;
}

// 		int met;
// 		float litros=1/3;
// 		float preco;
//
// 		cout << "Informe a quantidade de metros quadrados a ser pintado ==> ";
// 		cin >> met;
//
//
// 		while(met>54){
//
// 		}
//
// 		preco=80*
// 		cout << "Preco: " << preco;
// 		cout << "Latas a serem compradas: " <<
// 		}

