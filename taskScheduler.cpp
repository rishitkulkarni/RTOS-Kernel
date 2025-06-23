#include <thread>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

typedef size_t TaskHandle_t;
enum taskState{
    Ready,
    Deleted,
};

struct TCB{
    std::string name;
    std::function<void()> function;
    taskState state;
    TaskHandle_t handle;
};

class RTOS{
    public:
    TaskHandle_t xTaskCreate(std::function<void()> taskFunc, const std::string& name);
    void xTaskDelete(TaskHandle_t handle);
    void vTaskStartScheduler();

    private:
    std::vector<TCB> tasks;
    TaskHandle_t nextHandle = 0 ;
    
};

TaskHandle_t RTOS::xTaskCreate (std::function<void()> taskFunc , const std::string& name){
    TCB tcb = {name,taskFunc,Ready,nextHandle};
    tasks.push_back(tcb);
    std::cout<<"handle "<<nextHandle;
    return nextHandle++;
}

void RTOS::xTaskDelete(TaskHandle_t handle){
    for(auto& tcb:tasks){
        if (tcb.handle == handle ){
            tcb.state = Deleted;
            std::cout<<"task deleted"<<tcb.name<<std::endl;
            return ;

        }
    }
}

void RTOS::vTaskStartScheduler(){
    while (true){
        bool allDeleted  = true ;
        for(auto& tcb: tasks){
            if (tcb.state == Ready){
                tcb.function();
                allDeleted = false;
            }
        }
        if (allDeleted) {
            std::cout << "all tasks are dleleted " << std::endl;
            break;
        }
    }
}



TaskHandle_t t1,t2;
RTOS rtos;

void Task1(){
    static int i = 0;
    std::cout << "Task1 is running for  " << i++ << std::endl;
    if (i > 4) rtos.xTaskDelete(t1);
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Task2(){
    static int i = 0;
    std::cout << "Task2 is running for  " << i++ << std::endl;
    if (i > 4) rtos.xTaskDelete(t1);
   // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main(){
    t1 =rtos.xTaskCreate(Task1, "Task1");
    rtos.xTaskDelete(t1); 
    t2 =rtos.xTaskCreate(Task2, "Task2");
    rtos.xTaskDelete(t2);
    rtos.vTaskStartScheduler();
    std::cout<<"hello world ";
}



