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
class SimpleFactory
{
public:
    ProductPtr createProduct(ProductType type)
    {
        ProductPtr product = nullptr;
        switch(type)
        {
            case TYPE_A:
                product = std::make_shared<ProductA>();
                break;
            case TYPE_B:
                product = std::make_shared<ProductA>();
                break;
            default:
                break;
        }
        return product;
    }
};
#include <iostream>
int main(int argc, char** argv) {
    SimpleFactory factory;
    ProductPtr product = factory.createProduct(TYPE_A);
    std::cout<<"product type "<<product->getProductType()<<std::endl;
    return 0;
}
