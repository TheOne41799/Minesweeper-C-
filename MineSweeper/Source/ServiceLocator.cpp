#include "../Header/ServiceLocator.h"


namespace Global 
{
    using namespace Input;
    using namespace Board;


    ServiceLocator::ServiceLocator() : inputService(nullptr), boardService(nullptr) 
    {
        CreateServices();
    }

    ServiceLocator::~ServiceLocator() 
    {
        DestroyServices();
    }

    void ServiceLocator::CreateServices() 
    {
        inputService = new InputService();
        boardService = new BoardService();
    }

    void ServiceLocator::DestroyServices() 
    {
        delete inputService;
        delete boardService;
    }

    ServiceLocator* ServiceLocator::GetInstance()
    {
        static ServiceLocator instance;
        return &instance;
    }
}