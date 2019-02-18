#include <iostream>
#include <memory>
enum ProductType
{
    TYPE_A,
    TYPE_B
};
class Product
{
public:
    virtual const ProductType getProductType() = 0 ;
    virtual ~Product()
    {
        std::cout<<"base destroyed"<<std::endl;
    }
};

typedef std::shared_ptr<Product> ProductPtr;
class ProductA :public Product
{
public:
    const ProductType getProductType()
    {
        return TYPE_A;
    }
    ~ProductA()
    {
        std::cout<<"ProductA destroyed"<<std::endl;
    }   
};
class ProductB :public Product
{
public:
    const ProductType getProductType()
    {
        return TYPE_B;
    }
    ~ProductB()
    {
        std::cout<<"ProductB destroyed"<<std::endl;
    }   
};
class Factory
{
public:
    virtual ~Factory()
    {       
    }
    virtual ProductPtr createProduct() = 0;
};
class ProductAFactory:public Factory
{
public:
    ProductPtr createProduct()
    {
        return std::make_shared<ProductA>();
    }
};
class ProductBFactory:public Factory
{
public:
    ProductPtr createProduct()
    {
        return std::make_shared<ProductB>();
    }
};
int main(int argc, char** argv) {
    std::unique_ptr<Factory> fac(new ProductBFactory);
   // std::unique_ptr<Facitory> fac = std::make_unique<ProductBFactory>();//C++14

    ProductPtr product = fac->createProduct();
    std::cout<<"product type "<<product->getProductType()<<std::endl;
    return 0;
}
