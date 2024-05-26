#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Pessoa {
private:
    string nome;
    string cpf;
    double rendaAnual;
    int dependentes;
public:
    void ler();
    void mostrar() const;
    double calcularIRPF() const;
};
void Pessoa::ler(){
    getline(cin,nome);
    getline(cin,cpf);
    cin >> rendaAnual;
    cin >> dependentes;
}
double Pessoa::calcularIRPF() const {
    double rendMensal = rendaAnual / 12.00;
    double rendAnualAjustado = rendaAnual - (200.00 * dependentes);
    double impostoAnual = 0.00;
    int faixa;
     if (rendMensal > 4664.68) {
        faixa = 4;
    } else if (rendMensal > 3751.05) {
        faixa = 3;
    } else if (rendMensal > 2825.65) {
        faixa = 2;
    } else if (rendMensal > 1903.98) {
        faixa = 1;
    } else {
        faixa = 0;
    }

    switch (faixa) {
    case 1:
       
        impostoAnual =rendAnualAjustado *0.075;
        break;
    case 2:
        impostoAnual =rendAnualAjustado * 0.15;
        break;
    case 3:
        impostoAnual =rendAnualAjustado * 0.225;
        break;
    case 4:
        impostoAnual =rendAnualAjustado * 0.275;
        break;
    case 0:
        impostoAnual = rendAnualAjustado * 1.00;
        break;
    }
    return impostoAnual;
}

void Pessoa::mostrar() const{
    double irpf = calcularIRPF();
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Valor Anual: R$" << setw(10) << fixed << setprecision(2) << right << rendaAnual << endl;
    cout << "Dependentes: " << dependentes << endl;
    if (irpf > 0) {
        cout << "IRPF: R$" << setw(10) << fixed << setprecision(2) << right << irpf << endl;
    } else {
        cout << "IRPF: isento" << endl;
    }
}
int main() {
    Pessoa pessoa;
    pessoa.ler();
    pessoa.mostrar();
    return 0;
}
