#include "intermediate.h"
#include "toolswindow.h"

Intermediate::Intermediate()
{
    toolsWindow.SetPaintWindow(&paintWindow);
    toolsWindow.show();
    paintWindow.show();
}

