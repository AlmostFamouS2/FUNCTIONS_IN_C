#include <iostream>

using namespace std;

int main(void){
	short int a=0;
	char v[10]={'A','B','C','D','E','E','D','C','B','A'};
	char g[10]; // Criando um array para receber o gabarito em letras minusculas para indiferenciar na hora que o usuario fazer o input de dados...
	
	for(int c=0;c<10;c++){
		g[c]=v[c]+32;  //  Criando e colocando cada elemento de v[] em g[]
	}
	
	char q;
	for(int i=0;i<10;i++){
		cout << "Digite o gabarito da nota " << i+1 << " de A-E: ";
		cin >> q;
		
		while (q != 'A' || q!='B'||q!='C'||q!='D'||q!='E'){
		    cout << "Digite o gabarito da nota " << i+1 << " de A-E: ";
		    cin >> q;
		}
		
		if(q!=v[i] && q!=g[i]) {
			cout << "Questao " << i+1 << ", ERRADO!!";
		}
		else {
			cout << "Questao " << i+1 << ", CORRETO!";
		}
	}

return 0;
}
