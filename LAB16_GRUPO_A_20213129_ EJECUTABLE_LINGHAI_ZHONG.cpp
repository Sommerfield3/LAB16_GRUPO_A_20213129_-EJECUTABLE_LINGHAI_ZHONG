#include <iostream>
using namespace std;

class WinFactory{
public:
	virtual ~WinFactory(){};
	virtual string Draw() const=0;
};
class WinButton: public WinFactory{
public:
	string Draw() const override{
		return "Button Windows";
	}
};
class WinCheckBox: public WinFactory{
public:
	string Draw() const override{
		return "CheckBox Windows";
	}
};
class MacFactory{
public:
	virtual ~MacFactory(){};
	virtual string Draw() const=0;
	virtual string draw(const WinFactory& ayuda) const=0;
};
class MacButton: public MacFactory{
public:
	string Draw() const override{
		return "Dibujando Button Mac";
	}
	string draw(const WinFactory& ayuda) const override{
		const string result=ayuda.Draw();
		return "Dibujando "+result;
	}
};
class MacCheckBox: public MacFactory{
public:
	string Draw() const override{
		return "Dibujando CheckBox Mac";
	}
	string draw(const WinFactory& ayuda) const override{
		const string result=ayuda.Draw();
		return "Dibujando "+result;
	}
};
class GUIFactory {
public:
	virtual WinFactory* CrearControlW() const = 0;
	virtual MacFactory* CrearControlM() const = 0;
};
class Button: public GUIFactory{
public:
	WinFactory* CrearControlW() const override{
		return new WinButton();
	}
	MacFactory* CrearControlM() const override{
		return new MacButton();
	}
};
class CheckBox: public GUIFactory{
public:
	WinFactory* CrearControlW() const override{
		return new WinCheckBox();
	}
	MacFactory* CrearControlM() const override{
		return new MacCheckBox();
	}
};
void Aplication(const GUIFactory& f,int sistemaIndicador){/*Según el modelo es "Application", pero en el main es "aplication", se seguirá lo indicado en el main.*/
	const WinFactory* sistema1=f.CrearControlW();
	const MacFactory* sistema2=f.CrearControlM();
	if (sistemaIndicador==1){
		cout<<endl<<sistema2->draw(*sistema1)<<endl;
	}
	else if (sistemaIndicador==2){
		cout<<endl<<sistema2->Draw()<<endl;
	}
	else{
		cout<<"ERROR: Sistema no registrado. "<<endl;
	}
	delete sistema1;
	delete sistema2;
}
int main(int argc, char *argv[]) {
	std::cout << "Cliente: Windows ";
	Button* f1 = new Button();
	Aplication(*f1, 1); // 1 - Windows
	delete f1;
	std::cout << std::endl;
	std::cout << "Cliente: Mac ";
	Button* f2 = new Button();
	Aplication(*f2, 2); // 2 - Mac
	delete f2;
	return 0;
}

