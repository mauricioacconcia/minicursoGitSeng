#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class Tipo>
class Calculadora{
private:
    Tipo Op1;
    Tipo Op2;
public:
    Calculadora();
    Calculadora(Tipo Op1, Tipo Op2);
    Tipo getOp1();
    Tipo getOp2();
    void setOp1(Tipo Op1);
    void setOp2(Tipo Op2);
    Tipo soma();
    Tipo subtracao();
    Tipo multiplicacao();
    Tipo divisao();
    friend vector<Tipo> operator+(const vector<Tipo> &V1, const vector<Tipo> &V2);
};

template <class Tipo>
Calculadora<Tipo>::Calculadora(){}

template <class Tipo>
Calculadora<Tipo>::Calculadora(Tipo Op1, Tipo Op2){
    this->Op1 = Op1;
    this->Op2 = Op2;
}

template <class Tipo>
Tipo Calculadora<Tipo>::getOp1(){
    return this->Op1;
}

template <class Tipo>
Tipo Calculadora<Tipo>::getOp2(){
    return this->Op2;
}

template <class Tipo>
void Calculadora<Tipo>::setOp1(Tipo Op1){
   this->Op1 = Op1;
}

template <class Tipo>
void Calculadora<Tipo>::setOp2(Tipo Op2){
   this->Op2 = Op2;
}

template <class Tipo>
Tipo Calculadora<Tipo>::soma(){
    return(this->Op1 + this->Op2);
}

template <class Tipo>
Tipo Calculadora<Tipo>::subtracao(){
    return(this->Op1 - this->Op2);
}
template <class Tipo>
Tipo Calculadora<Tipo>::multiplicacao(){
    return(this->Op1 * this->Op2);
}
template <class Tipo>
Tipo Calculadora<Tipo>::divisao(){
    return(this->Op1 / this->Op2);
}

template <class Tipo>
vector<Tipo> operator+(const vector<Tipo> &V1, const vector<Tipo> &V2){
    vector<Tipo> temp;
    temp.resize(V1.size());
    if((V1.size()) != (V2.size())){
        cout<<"Erro de tamanho"<<endl;
        return temp;
    }else{
        for(int i = 0; i < V1.size(); i++){
            temp[i] = V1[i]+V2[i];
        }
    }
    return temp;
}

int main(){

    srand(time(0));

    vector<float> V1, V2, V3;

    V1.resize(10);
    V2.resize(10);
    V3.resize(10);

    for(int i = 0; i < 10; i++){
            V1[i] = rand()%11;
            V2[i] = rand()%11;
    }

    Calculadora< vector<float> > Ci(V1,V2);

    V3 = Ci.soma();

    for(int i = 0; i < 10; i++){
        cout<<"Soma "<<V1[i]<<"+"<<V2[i]<<" = "<<V3[i]<<endl;
    }

    //cout<<"Soma: "<<Ci.soma()<<endl;
    //cout<<"Subtracao: "<<Ci.subtracao()<<endl;
    //cout<<"Multiplicacao: "<<Ci.multiplicacao()<<endl;
    //cout<<"Divisao: "<<Ci.divisao()<<endl;

    return 0;

}
