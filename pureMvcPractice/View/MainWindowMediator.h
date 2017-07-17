#pragma once

#include <PureMVC.hpp>
#include <Patterns/Mediator/Mediator.hpp>
using namespace PureMVC::Interfaces;
using namespace PureMVC::Patterns;

class MainWindow;
class MainProxy;

class MainWindowMediator : public Mediator
{
public:
    static const std::string NAME;

    MainWindowMediator(const void* aViewComponent);

    void handleNotification(INotification const& aNotification) override;
    static MainWindow* GetMainWindow();

private:
	#pragma region EventHandler
    void OnValueChange(int value);
    #pragma endregion EventHandler

    MainWindow* getMainWindow();
    MainProxy* getMainProxy();
};
