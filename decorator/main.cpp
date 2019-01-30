#include "decorator.h"
int main(int argc, char** argv) {
    VisualComponent component;
    VisualComponent * newComponent = new BorderDecorator(&component,10);
    newComponent->draw();
    delete newComponent;
    return 0;
}
