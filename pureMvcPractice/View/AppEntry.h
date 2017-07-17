#pragma once
#include <wx/wx.h>
 
class AppEntry : public wxApp
{
  public:
	  ~AppEntry();
	  virtual bool OnInit();
};