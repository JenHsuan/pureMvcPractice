#pragma once
#include <wx/wx.h>
#include <PureMVC.hpp>
#include <boost/shared_ptr.hpp>

class ApplicationFacade;
 
class AppEntry : public wxApp
{
  public:
	  ~AppEntry();
	  virtual bool OnInit();
   private:
	   boost::shared_ptr<ApplicationFacade> _facade;
};