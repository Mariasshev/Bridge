#include <iostream>
#include <string>
using namespace std;


//Bridge pattern

class Devices abstract 
{
protected:
    int memory;
    int price;
    int energyConsumption;
    string name;
    string connector;

public:
    virtual void Print() abstract;
    virtual void SetName() abstract;
    virtual void SetConnector() abstract;
    virtual void SetMemory() abstract;
    virtual void SetPrice() abstract;
    virtual void SetEnergyConsumption() abstract;
};

class GPU : public Devices 
{
    void Print() override 
    {
        cout << "Name: " << name << "\n" << "Connector: " << connector << "\n" << "memory: " << memory << "\n" << "Price: " << price << "\n" << "Consumption: " << energyConsumption << endl;
    }
    void SetName() override 
    {
        name = "GeForce RTX 4060";
    }
    void SetConnector() override 
    {
        connector = "PCI-Express 5.0";
    }
    void SetMemory() override 
    {
        memory = 16;
    }
    void SetPrice() override 
    {
        price = 1999;
    }
    void SetEnergyConsumption() override 
    {
        energyConsumption = 350;
    }
};
class CPU : public Devices 
{
    void Print() override 
    {
        cout << "Name: " << name << "\n" << "Connector: " <<  connector << "\n" << "memory: " <<  memory << "\n" << "Price: " <<  price << "\n" << "Consumption: " << energyConsumption << endl;
    }
    void SetName() override 
    {
        name = "Intel CORE i7";
    }
    void SetConnector() override 
    {
        connector = "Socket 3466";
    }
    void SetMemory() override 
    {
        memory = 16;
    }
    void SetPrice() override 
    {
        price = 899;
    }
    void SetEnergyConsumption() override 
    {
        energyConsumption = 265;
    }
};
class HDD : public Devices 
{
    void Print() override 
    {
        cout << "Name: " << name << "\n" << "Connector: " << connector << "\n" << "memory: " << memory << "\n" << "Price: " << price << "\n" << "Consumption: " << energyConsumption << endl;
    }
    void SetName() override 
    {
        name = "Barracuda25";
    }
    void SetConnector() override 
    {
        connector = "SATA";
    }
    void SetMemory() override 
    {
        memory = 4;
    }
    void SetPrice() override 
    {
        price = 2222;
    }
    void SetEnergyConsumption() override 
    {
        energyConsumption = 6;
    }
};


class IPrint 
{
    Devices* devices;
public:
    void SetDevices(Devices* devices) 
    {
        this->devices = devices;
        devices->SetConnector();
        devices->SetEnergyConsumption();
        devices->SetMemory();
        devices->SetName();
        devices->SetPrice();
    }

    void ShowInfo() 
    {
        devices->Print();
    }
};


void Client(Devices* devices, IPrint* IPrintDevices) 
{
    IPrintDevices->SetDevices(devices);
    devices->Print();
}


int main() 
{
    Devices* devices = new GPU();
    IPrint* IPrintDevices = new IPrint();
    Client(devices, IPrintDevices);
    cout << endl;
    delete devices;
    delete IPrintDevices;


    devices = new CPU();
    IPrintDevices = new IPrint();
    Client(devices, IPrintDevices);
    cout << endl;
    delete devices;
    delete IPrintDevices;


    devices = new HDD();
    IPrintDevices = new IPrint();
    Client(devices, IPrintDevices);

    delete devices;
    delete IPrintDevices;

    system("pause");
    return 0;
}