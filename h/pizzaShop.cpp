#include <iostream>
#include <string>
using namespace std;

struct Customer
{
    std::string name = "";
    std::string pizzaType = "";
    std::string crustType = "";
    std::string size = "";
    std::string address = "";

     // Custom constructor
    Customer(std::string _name, std::string _pizzaType, std::string _crustType, std::string _size, std::string _address)
        : name(_name), pizzaType(_pizzaType), crustType(_crustType), size(_size), address(_address) {
    }
};


class Pizza
{
public:
    bool ready = false;
    bool typeReady = false;
    bool sizeReady = false;
    bool crustReady = false;
    virtual ~Pizza(){};
    virtual void SelectType(string pizzaType) = 0;
    virtual void SelectSize(string size) = 0;
    virtual void SelectCrust(string crustType) = 0;
    virtual bool NotifyReady() const = 0;
};

class Outlet1 : public Pizza
{
public:
    // Implement virtual functions from Pizza class
    void SelectType(std::string pizzaType) override
    {
        // Implementation
        cout<<"You ordered : "<<pizzaType<<endl;
        typeReady = true;
        // return true;
    }

    void SelectSize(string size) override
    {
        // Implementation
        cout<<"size : "<<size<<endl;
        sizeReady = true;
    }

    void SelectCrust(string curstType) override
    {
        // Implementation
        cout<<"Crust "<<curstType<<endl;
        crustReady = true;

    }

    bool NotifyReady() const override
    {
        // Implementation
        return (typeReady && sizeReady && crustReady);
    }
};

class Outlet2 : public Pizza
{
public:
    // Implement virtual functions from Pizza class
    void SelectType(std::string pizzaType) override
    {
        // Implementation
        cout<<"You ordered : "<<pizzaType<<endl;
        typeReady = true;
        // return true;
    }

    void SelectSize(string size) override
    {
        // Implementation
        cout<<"size : "<<size<<endl;
        sizeReady = true;
    }

    void SelectCrust(string curstType) override
    {
        // Implementation
        cout<<"Crust "<<curstType<<endl;
        crustReady = true;

    }

    bool NotifyReady() const override
    {
        // Implementation
        return (typeReady && sizeReady && crustReady);
    }
};


class DeliveryAgent
{
public:
    // Add delivery-related methods and properties here
    void DeliverPizza(const std::string &address) const
    {
        // Implementation
        std::cout << "Pizza delivered to " << address << std::endl;
    }
};


class OrderingAgent
{
    private:
    DeliveryAgent deliveryAgent;
    Pizza *p;
public:

    // Constructor to initialize the pointer to nullptr
    // OrderingAgent() : p(nullptr) {}

    // Add ordering-related methods and properties here
    void PlaceOrder(const Customer customer1)
    {
        // Call functions in the outlet to prepare the pizza
        // Pizza p;
        // 1941
        p = new Outlet1();
        p->SelectType(customer1.pizzaType);
        p->SelectSize(customer1.size) ;
        p->SelectCrust(customer1.crustType);
        // Check if the pizza is ready
        if ( p->NotifyReady())
        {
            // Notify that the pizza is ready and initiate delivery
            std::cout << "Pizza is ready! Initiating delivery to " << customer1.address << std::endl;
            
        }
        else
        {
            std::cout << "Pizza is not ready yet." << std::endl;
        }
    }


};




int main()
{
    // Implement your pizza shop logic here
    Customer customer1("John Doe", "Pepperoni", "Thin Crust", "Large", "123 Main Street");
    OrderingAgent orderingAgent;

    // Example: Place order from Outlet1
    orderingAgent.PlaceOrder(customer1);

    // Example: Place order from Outlet2
    // orderingAgent.PlaceOrder(outlet2, "456 Oak Avenue");

    // Implement more logic as needed

    return 0;
}
