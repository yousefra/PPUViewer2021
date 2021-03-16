//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.04.2018
//

#include "renderwidget.h"
#include "ppuviewer.h"

#include <QtWidgets>

PPUViewer::PPUViewer()
{
  renderWidget = new RenderWidget;

  QGridLayout* mainLayout = new QGridLayout;
  mainLayout->addWidget(renderWidget, 0, 0, 1, 4);
  setLayout(mainLayout);

  setWindowTitle(tr("2D Graphics: Drawing Elementary Shapes"));
}
