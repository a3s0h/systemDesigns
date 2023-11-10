// #include <string>
// #include <iostream>
// #include <memory>
// #include<bits/stdc++.h>
// using namespace std;

// // "Product"
// class Pizza
// {
// public:
// 	void setDough(const string& dough)
// 	{
// 		m_dough = dough;
// 	}
// 	void setSauce(const string& sauce)
// 	{
// 		m_sauce = sauce;
// 	}
// 	void setTopping(const string& topping)
// 	{
// 		m_topping = topping;
// 	}
// 	void open() const
// 	{
// 		cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
// 			<< m_topping << " topping. Mmm." << endl;
// 	}
// private:
// 	string m_dough;
// 	string m_sauce;
// 	string m_topping;
// };

// // "Abstract Builder"
// class PizzaBuilder
// {
// public:
// 	virtual ~PizzaBuilder() {};

// 	Pizza* getPizza()
// 	{
// 		return m_pizza.get();
// 	}
// 	void createNewPizzaProduct()
// 	{
// 		m_pizza = make_unique<Pizza>();
// 	}
// 	virtual void buildDough() = 0;
// 	virtual void buildSauce() = 0;
// 	virtual void buildTopping() = 0;
// protected:
// 	unique_ptr<Pizza> m_pizza;
// };

// //----------------------------------------------------------------

// class HawaiianPizzaBuilder : public PizzaBuilder
// {
// public:
// 	virtual ~HawaiianPizzaBuilder() {};

// 	virtual void buildDough()
// 	{
// 		m_pizza->setDough("cross");
// 	}
// 	virtual void buildSauce()
// 	{
// 		m_pizza->setSauce("mild");
// 	}
// 	virtual void buildTopping()
// 	{
// 		m_pizza->setTopping("ham+pineapple");
// 	}
// };

// class SpicyPizzaBuilder : public PizzaBuilder
// {
// public:
// 	virtual ~SpicyPizzaBuilder() {};

// 	virtual void buildDough()
// 	{
// 		m_pizza->setDough("pan baked");
// 	}
// 	virtual void buildSauce()
// 	{
// 		m_pizza->setSauce("hot");
// 	}
// 	virtual void buildTopping()
// 	{
// 		m_pizza->setTopping("pepperoni+salami");
// 	}
// };

// //----------------------------------------------------------------

// class Cook
// {
// public:
// 	void openPizza()
// 	{
// 		m_pizzaBuilder->getPizza()->open();
// 	}
// 	void makePizza(PizzaBuilder* pb)
// 	{
// 		m_pizzaBuilder = pb;
// 		m_pizzaBuilder->createNewPizzaProduct();
// 		m_pizzaBuilder->buildDough();
// 		m_pizzaBuilder->buildSauce();
// 		m_pizzaBuilder->buildTopping();
// 	}
// private:
// 	PizzaBuilder* m_pizzaBuilder;
// };

// int main()
// {
// 	Cook cook;
// 	HawaiianPizzaBuilder hawaiianPizzaBuilder;
// 	SpicyPizzaBuilder    spicyPizzaBuilder;

// 	cook.makePizza(&hawaiianPizzaBuilder);
// 	cook.openPizza();

// 	cook.makePizza(&spicyPizzaBuilder);
// 	cook.openPizza();
// }
// You can also use the latest version c++17 standard

#include <iostream>
#include <memory>
class Pizza{
public:
    void setDough(const std::string& dough){
        m_dough = dough;
    }
    void setSauce(const std::string& sauce){
        m_sauce = sauce;
    }
    void setTopping(const std::string& topping){
        m_topping = topping;
    }
    void open() const {
        std::cout<<"The Pizza have "<<
        m_dough<<" dough, "<<
        m_sauce<<" sauce, "<<
        m_topping<<" topping."<<
        std::endl;
    }
private:
    std::string m_dough;
    std::string m_sauce;
    std::string m_topping;
};

class PizzaBuilder{
public:
    virtual ~PizzaBuilder() = default;
    void createNewPizza(){
        m_pizza = std::make_unique<Pizza>();
    }
    Pizza* getPizza() {
        return m_pizza.release();
    }
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
protected:
    std::unique_ptr<Pizza> m_pizza;
};

class HawaiianPizzaBuilder:public PizzaBuilder{
public:
    ~HawaiianPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Hawaiian dough");
    }
    void buildSauce() override {
        m_pizza->setSauce("Hawaiian sauce");
    }
    void buildTopping() override {
        m_pizza->setTopping("Hawaiian topping");
    }
};

class SpicyPizzaBuilder:public PizzaBuilder{
public:
    ~SpicyPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Spicy dough");
    }
    void buildSauce() override {
        m_pizza->setSauce("Spicy sauce");
    }
    void buildTopping() override {
        m_pizza->setTopping("Spicy topping");
    }
};

class Cook{
public:
    void openPizza() const {
        m_pizzaBuilder->getPizza()->open();
    }
    void createPizza(PizzaBuilder* pizzaBuilder){
        m_pizzaBuilder = pizzaBuilder;
        m_pizzaBuilder->createNewPizza();
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }
private:
    PizzaBuilder* m_pizzaBuilder;
};

int main(){
    Cook cook{};
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    cook.createPizza(&hawaiianPizzaBuilder);
    cook.openPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    cook.createPizza(&spicyPizzaBuilder);
    cook.openPizza();
}