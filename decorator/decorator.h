#ifndef DECORATOR_H_
#define DECORATOR_H_
#include <iostream>
class VisualComponent
{
public:
    VisualComponent(){};
    virtual void draw()
    {
        std::cout<<"draw a square with the area is 100  "<<std::endl;
    }
    virtual void resize()
    {
        std::cout<<"resize the square with the area is 400  "<<std::endl;
    }
};
class Decorator :public VisualComponent
{
public:
    Decorator(VisualComponent * component):_component(component)
    {       
    }
    virtual void draw()
    {
        _component->draw();
    }
    virtual void resize()
    {
        _component->resize();
    }
private:
    VisualComponent * _component;
};
class BorderDecorator :public Decorator
{
public:
    BorderDecorator(VisualComponent * component,int borderWidth):Decorator(component),_width(borderWidth)
    {
    }
    virtual void draw()
    {
        Decorator::draw();
        drawBorder(_width); //extended function
    }
private:
    void drawBorder(int width)
    {
        std::cout<<"add border for the square with the border width is "<<width<<std::endl;
    }
private:
    int _width;
};
#endif
