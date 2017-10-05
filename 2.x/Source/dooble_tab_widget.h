/*
** Copyright (c) 2008 - present, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Dooble without specific prior written permission.
**
** DOOBLE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** DOOBLE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef dooble_tab_widget_h
#define dooble_tab_widget_h

#include <QTabWidget>

class QFrame;
class QToolButton;
class dooble_page;
class dooble_tab_bar;

class dooble_tab_widget: public QTabWidget
{
  Q_OBJECT

 public:
  dooble_tab_widget(QWidget *parent);
  dooble_page *page(int index) const;
  QIcon tabIcon(int index) const;
  QToolButton *tabs_menu_button(void) const;
  void setTabIcon(int index, const QIcon &icon);
  void setTabTextColor(int index, const QColor &color);

 protected:
  void tabRemoved(int index);

 private:
  QFrame *m_corner_widget;
  QToolButton *m_add_tab_tool_button;
  QToolButton *m_tabs_menu_button;
  dooble_tab_bar *m_tab_bar;
  void prepare_icons(void);
  void prepare_tab_label(int index, const QIcon &icon);

 private slots:
  void slot_load_finished(void);
  void slot_load_started(void);
  void slot_set_visible_corner_button(bool state);
  void slot_settings_applied(void);

 signals:
  void decouple_tab(int index);
  void empty_tab(void);
  void new_tab(void);
  void open_tab_as_new_window(int index);
  void reload_tab(int index);
  void tabs_menu_button_clicked(void);
};

#endif
