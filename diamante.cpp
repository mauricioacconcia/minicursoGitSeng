//modificação para alterar algo no arquivo para subir par ao github


#include <iostream>
#include <string>

using namespace std;

//----------- Definição de classes-----------------------

class B{
public:
    B();
    void metodo();
};

class C{
public:
    C();
    void metodo();
};

class D : public B, public C{
public:
    D();
};


B::B(){
    cout<<"Classe B - Base"<<endl;
}

void B::metodo(){}

C::C(){
    cout<<"Classe C - Base"<<endl;
}

void C::metodo(){}

D::D(){
    cout<<"Classe D - Derivada de B e C nesta ordem"<<endl;
}

int main(){

    B B1;
    cout<<"---------------"<<endl;
    C C1;
    cout<<"---------------"<<endl;
    D D1;

    //heranca multipla com problema diamante
    D1.metodo();

    return 0;

}


