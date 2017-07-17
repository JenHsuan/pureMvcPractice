#ifndef BASICCOMMAND_H
#define BASICCOMMAND_H

#include <string>

#include <PureMVC.hpp>
#include <Interfaces/ICommand.hpp>
#include <Patterns/Command/SimpleCommand.hpp>


class MainWindow;
class MainProxy;

using namespace PureMVC::Interfaces;
using namespace PureMVC::Patterns;

class BasicCommand : virtual public ICommand, public SimpleCommand
{
public:
    virtual void execute(INotification const& aNotification) = 0;

protected:
    MainProxy* getMainProxy();
    MainWindow* getMainWindow();
};

#endif