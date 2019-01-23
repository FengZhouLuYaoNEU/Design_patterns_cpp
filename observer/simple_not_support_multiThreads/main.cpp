#include <iostream>
#include "subject.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    SubjectObserved subj;
    subj.registerObjs(new FirstObserver);
    subj.registerObjs(new SecondObserver);
    subj.registerObjs(new ThirdObserver);
    
    subj.notifyAllObjs();
    
    subj.setData(200);
    
    subj.notifyAllObjs();
    return 0;
}
