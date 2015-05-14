#include <iostream>  
#include <memory>  
  
class Woman;  
class Man{  
private:  
    std::weak_ptr<Woman> _wife;  
    //std::shared_ptr<Woman> _wife;  
public:  
    void setWife(std::shared_ptr<Woman> woman){  
        _wife = woman;  
    }  
  
    void doSomthing(){  
        if(_wife.lock()){  
        }  
    }  
  
    ~Man(){  
        std::cout << "kill man\n";  
    }  
};  
  
class Woman{  
private:  
    //std::weak_ptr<Man> _husband;  
    std::shared_ptr<Man> _husband;  
public:  
    void setHusband(std::shared_ptr<Man> man){  
        _husband = man;  
    }  
    ~Woman(){  
        std::cout <<"kill woman\n";  
    }  
};  
  
  
int main(int argc, char** argv){  
    std::shared_ptr<Man> m(new Man());  
    std::shared_ptr<Woman> w(new Woman());  
    if(m && w) {  
        m->setWife(w);  
        w->setHusband(m);  
    }  
    return 0;  
}  
